#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;
FILE *img = NULL;

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Source file not found.\n");
        return 1;
    }

    BYTE block[512];
    int count = 0;
    bool image_found = false;
    while (fread(block, sizeof(block), 1, file))
    {
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            if (count != 0)
            {
                fclose(img);
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", count);
            count++;
            img = fopen(filename, "w");
            image_found = true;
            fwrite(block, sizeof(block), 1, img);
        }
        else
        {
            if (image_found == true)
            {
                fwrite(block, sizeof(block), 1, img);
            }
        }
    }
    fclose(img);
}