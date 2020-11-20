// Made by PMBC
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

// Detects if a file is a JPEG

int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }

    // Read first three bytes
    BYTE buffer[512];
    char filename[8];
    int img_counter = -1;
    FILE *img;
    while (fread(buffer, sizeof(BYTE), 512, file) == 512)
    {
        // Check first three bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            if ((buffer[3] & 0xf0) == 0xe0)
            {
                if (img_counter == -1)
                {
                    img_counter++;
                    sprintf(filename, "%03i.jpg", img_counter);
                    img = fopen(filename, "w");
                    fwrite(buffer, sizeof(BYTE), 512, img);
                }
                else if (img_counter >= 0)
                {
                    fclose(img);
                    img_counter++;
                    sprintf(filename, "%03i.jpg", img_counter);
                    img = fopen(filename, "w");
                    fwrite(buffer, sizeof(BYTE), 512, img);
                }
            }
        }
        else
        {
            if (img_counter != -1)
            {
                fwrite(buffer, sizeof(BYTE), 512, img);
            }
        }
    }
    // Close file
    fclose(file);
    fclose(img);
}
