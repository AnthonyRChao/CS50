// Resizes a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{

    /**
     *
     * open file
     * update outfile's header info
     * read infile's scanline, pixel by pixel
     * resize horizontally
     * remember padding
     * resize vertically
     *
     **/

    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize n infile outfile\n");
        return 1;
    }

    // confirm n less than equal to 100 or greater than 0
    int n = atoi(argv[1]);
    if (n > 100 || n < 0)
    {
        fprintf(stderr, "n must be less than or equal to 100 and greater than 0");
        return 2;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    // initialize two structs as copies of bi and bf
    BITMAPINFOHEADER bi_out = bi;
    BITMAPFILEHEADER bf_out = bf;

    // scale bi_out.biWidth & bi_out.biHeight
    bi_out.biWidth *= n;
    bi_out.biHeight *= n;

    // calculate padding for scanlines
    int padding_in = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding_out = (4 - (bi_out.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // calculate bi_out.biSizeImage & bf_out.bfSize
    bi_out.biSizeImage = abs(bi_out.biHeight) * (bi_out.biWidth * sizeof(RGBTRIPLE) + padding_out);
    bf_out.bfSize = bi_out.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_out, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_out, sizeof(BITMAPINFOHEADER), 1, outptr);

    /**
     *
     * Pseudocode: resize vertically
     *
     * "rewrite" methods, remember pixels in array
     *     write array as many times as needed
     *
     * for each row
     *     for each pixel
     *         write to array n times
     *     for n times
     *         write array to outfile
     *         write outfile padding
     *     skip over infile padding
     *
     * "re-copy" methods, go back to the start of the original scanline
     *     re-scale scanline
     *
     * for each row
     *     for n-1 times
     *         write pixels, padding to outfile
     *         send infile cursor back
     *     write pixels, padding to outfile
     *     skip over infile padding
     *
     **/

    // for each row
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // temporary storage
        RGBTRIPLE triple;

        // for n-1 times
        for (int j = 0; j < n - 1; j++)
        {
            // write pixels
            for (int k = 0; k < bi.biWidth; k++)
            {
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int q = 0; q < n; q++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // padding to outfile
            for (int l = 0; l < padding_out; l++)
            {
                fputc(0x00, outptr);
            }

            // send infile cursor back
            fseek(inptr, (-1) * bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
        }

        // write pixels
        for (int m = 0; m < bi.biWidth; m++)
        {
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for (int r = 0; r < n; r++)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }

        // padding to outfile
        for (int p = 0; p < padding_out; p++)
        {
            fputc(0x00, outptr);
        }

        // skip over infile padding
        fseek(inptr, padding_in, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
