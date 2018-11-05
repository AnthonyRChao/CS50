# Questions

## What's `stdint.h`?

stdint.h is about portability between different system architectures. It is
a header file in the C standard library introduced in the C99 standard library
section 7.18 to allow programmers to write more portable code by providing a
set of typedefs that specify exact-width integer types, together with the
defined minimum and maximum allowable values for each type, using macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

uint8_t, uint32_t, int32_t and unint16_t are used to ensure that whatever
system is running your code, knows how to define the size of an int.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE (uint8_t, unsigned int with 8 bits) is one byte.
DWORD (uint32_t, unsigned int with 32 bits) is four bytes.
LONG (int32_t, integer with 32 bits) is four bytes.
WORD (uint16_t, unsigned integer with 16 bits) is two bytes.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

First two bytes of any BMP file are 'B' and 'M' in ASCII.

## What's the difference between `bfSize` and `biSize`?

The BITMAPFILEHEADER file contains information about the type, size and
    layout of a file that contains a device independent bitmap (DIB).
The BITMPAINFOHEADER file contains information about the dimensions and
    color format of a DIB.
bfSize (BITMAPFILEHEADER) is size of the file in bytes.
biSize (BITMAPINFOHEADER) is the amount of space needed by the structures (DIB).

## What does it mean if `biHeight` is negative?

biHeight represents the height of the bitmap in pixels. If positive, bitmap
is bottoms-up file and origin is at lower left corner. If negative, bitmap
is top-down file where origin is at top left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount represents the number of bits-per-pixel.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

fopen opens a file. fopen takes two inputs: filename and
mode (r, w, a). If the file does not exist, fopen will return
NULL - it is important to always check for this. Also of note,
fopen in write mode will create a new file even if one with the
same name already exists.

## Why is the third argument to `fread` always `1` in our code?

```C
#include <stdio.h>
size_t fread(void* ptr, size_t size, size_t blocks, FILE* fp);
```

fread reads in from a file "fp" an element of "size" bytes "blocks" number of times.
So, if size = 50 bytes & blocks = 10, fread will read 500 bytes total from fread (50 bytes, 10 times).
For each "read", fread will store the bytes in a buffer pointer to by ptr.
fread returns the total "number of chunks" read in, this should correspond to the blocks parameter.
If blocks != fread return value, then either ran into an error or EOF reached.

The third argument to fread is always 1 because we want to read in one "block" of "size" from "fp".

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

RGBTRIPLE is a struct that contains three "BYTE"'s.

(4 - (3 * sizeof(RGBTRIPLE)) % 4) % 4);
(4 - (3 * 3) % 4) % 4);
(4 - (9 % 4) % 4);
(4 - (1 % 4));
(4 - 1);
(3);

If bi.biWidth is 3, line 65 of assigns 3 to padding.

## What does `fseek` do?

fseek sets the file position. fseek does this by changing the offset of file pointer fp.

`#include <stdio.h>`
`int fseek(FILE* fp, long int offset, int from_where);`

offset refers to the number of bytes you want to change the current position of the file pointer, fp.
positive refers to moving forward, negative refers to moving back.

from_where refers to where in the file you are referencing:
    beginning of file: set to SEEK_SET
    current position: set to SEEK_CUR
    end of file: SEEK_END

fseek returns 0 if successful & some non-zero value if unsuccessful.

What is file pointer fp? fp is a pointer variable that points to a FILE

Example:

```C
FILE* out = fopen("out.txt", "w+");

fputs("Team Bowden Fever!", out);

char buffer[50];

fseek(out, 0, SEEK_SET);

fgets(buffer, 50, out);
printf("%s\n", buffer);

fclose(out);
```

## What is `SEEK_CUR`?

SEEK_CUR is a parameter in the fseek() function to determine where in the file to offset the location
of file pointer, fp.
