#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 *
 * Pseudocode
 *
 * open card file
 * repeat until end of card
 *     read 512 bytes into a buffer
 *     start of a new JPEG?
 *         yes -> ...
 *         no  -> ...
 *     already found a JPEG?
 *         no  -> ...
 *         yes -> ...
 * close any remaining files
 *
 **/

int main (int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover file\n");
        return 1;
    }

    // remember filename
    char *file = argv[1];

    // open input file
    FILE *ptr = fopen(argv[1], "r");
    if (ptr == NULL)
    {
        fprintf(stderr, "Could not open %s. \n", file);
        return 2;
    }

    // define buffer for 512 byte blocks
    uint8_t buffer[512];

    // declare char array to hold name of file, based on counter
    char filename[10];
    uint8_t counter = 0;

    // declare null pointer variable
    FILE *img = NULL;

    // iterate until end of card
    while (fread(buffer, 512, 1, ptr) == 1)
    {
        // check first four bytes for JPG signature using bitwise & operator & if is first file
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // if img file is open, close
            if (img != NULL)
            {
                fclose(img);
            }

            // store name of JPG file in string variable based on counter
            sprintf(filename, "%03d.jpg", counter);

            // open new img file
            img = fopen(filename, "w");

            // printf for checking purposes
            printf("%s \n", filename);

            // increment counter
            counter++;
        }

        // if img open, write buffer contents
        if (img != NULL)
        {
            // write buffer content into opened file
            fwrite(buffer, 512, 1, img);
        }
    }

    // close file pointers
    fclose(ptr);

    return 0;
}