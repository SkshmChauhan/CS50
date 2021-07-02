#include "helpers.h"
#include <stdlib.h>
#include <math.h>

typedef uint8_t BYTE;

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float val = 0;
            val = val + image[i][j].rgbtBlue;
            val = val + image[i][j].rgbtGreen;
            val = val + image[i][j].rgbtRed;
            val = val / 3;
            if (val < 0)
            {
                val = 0;
            }
            else if (val > 255)
            {
                val = 255;
            }
            int value = round(val);

            image[i][j].rgbtBlue = value;
            image[i][j].rgbtGreen = value;
            image[i][j].rgbtRed = value;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float val = 0;
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            if (sepiaRed < 0)
            {
                sepiaRed = 0;
            }
            else if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen < 0)
            {
                sepiaGreen = 0;
            }
            else if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue < 0)
            {
                sepiaBlue = 0;
            }
            else if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = round(sepiaBlue);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtRed = round(sepiaRed);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            BYTE colour;
            colour = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = colour;

            colour = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = colour;

            colour = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtRed = colour;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
    BYTE newimage[height][width][3];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            newimage[i][j][0] = image[i][j].rgbtBlue;
            newimage[i][j][1] = image[i][j].rgbtGreen;
            newimage[i][j][2] = image[i][j].rgbtRed;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Case for first row:
            if (i == 0)
            {
                // Case for first column of first row:
                if (j == 0)
                {
                    float val = 0;
                    val = val + newimage[i + 1][j + 1][0];
                    val = val + newimage[i + 1][j][0];
                    val = val + newimage[i][j + 1][0];
                    val = val + newimage[i][j][0];
                    image[i][j].rgbtBlue = round(val / 4);

                    val = 0;
                    val = val + newimage[i + 1][j + 1][1];
                    val = val + newimage[i + 1][j][1];
                    val = val + newimage[i][j + 1][1];
                    val = val + newimage[i][j][1];
                    image[i][j].rgbtGreen = round(val / 4);

                    val = 0;
                    val = val + newimage[i + 1][j + 1][2];
                    val = val + newimage[i + 1][j][2];
                    val = val + newimage[i][j + 1][2];
                    val = val + newimage[i][j][2];
                    image[i][j].rgbtRed = round(val / 4);
                }
                // Case for last column of first row:
                else if (j == width - 1)
                {
                    float val = 0;
                    val = val + newimage[i + 1][j - 1][0];
                    val = val + newimage[i + 1][j][0];
                    val = val + newimage[i][j - 1][0];
                    val = val + newimage[i][j][0];
                    image[i][j].rgbtBlue = round(val / 4);

                    val = 0;
                    val = val + newimage[i + 1][j - 1][1];
                    val = val + newimage[i + 1][j][1];
                    val = val + newimage[i][j - 1][1];
                    val = val + newimage[i][j][1];
                    image[i][j].rgbtGreen = round(val / 4);

                    val = 0;
                    val = val + newimage[i + 1][j - 1][2];
                    val = val + newimage[i + 1][j][2];
                    val = val + newimage[i][j - 1][2];
                    val = val + newimage[i][j][2];
                    image[i][j].rgbtRed = round(val / 4);
                }
                // Case for columns other than first and last of first row:
                else
                {
                    float val = 0;
                    val = val + newimage[i][j][0];
                    val = val + newimage[i][j - 1][0];
                    val = val + newimage[i][j + 1][0];
                    val = val + newimage[i + 1][j - 1][0];
                    val = val + newimage[i + 1][j][0];
                    val = val + newimage[i + 1][j + 1][0];
                    image[i][j].rgbtBlue = round(val / 6);

                    val = 0;
                    val = val + newimage[i][j][1];
                    val = val + newimage[i][j - 1][1];
                    val = val + newimage[i][j + 1][1];
                    val = val + newimage[i + 1][j - 1][1];
                    val = val + newimage[i + 1][j][1];
                    val = val + newimage[i + 1][j + 1][1];
                    image[i][j].rgbtGreen = round(val / 6);

                    val = 0;
                    val = val + newimage[i][j][2];
                    val = val + newimage[i][j - 1][2];
                    val = val + newimage[i][j + 1][2];
                    val = val + newimage[i + 1][j - 1][2];
                    val = val + newimage[i + 1][j][2];
                    val = val + newimage[i + 1][j + 1][2];
                    image[i][j].rgbtRed = round(val / 6);
                }
            }
            // Case for last row:
            else if (i == height - 1)
            {
                // Case for first column of last row:
                if (j == 0)
                {
                    float val = 0;
                    val = val + newimage[i][j][0];
                    val = val + newimage[i - 1][j + 1][0];
                    val = val + newimage[i - 1][j][0];
                    val = val + newimage[i][j + 1][0];
                    image[i][j].rgbtBlue = round(val / 4);

                    val = 0;
                    val = val + newimage[i][j][1];
                    val = val + newimage[i - 1][j + 1][1];
                    val = val + newimage[i - 1][j][1];
                    val = val + newimage[i][j + 1][1];
                    image[i][j].rgbtGreen = round(val / 4);

                    val = 0;
                    val = val + newimage[i][j][2];
                    val = val + newimage[i - 1][j + 1][2];
                    val = val + newimage[i - 1][j][2];
                    val = val + newimage[i][j + 1][2];
                    image[i][j].rgbtRed = round(val / 4);
                }
                // Case for last column of last row:
                else if (j == width - 1)
                {
                    float val = 0;
                    val = val + newimage[i][j][0];
                    val = val + newimage[i - 1][j - 1][0];
                    val = val + newimage[i - 1][j][0];
                    val = val + newimage[i][j - 1][0];
                    image[i][j].rgbtBlue = round(val / 4);

                    val = 0;
                    val = val + newimage[i][j][1];
                    val = val + newimage[i - 1][j - 1][1];
                    val = val + newimage[i - 1][j][1];
                    val = val + newimage[i][j - 1][1];
                    image[i][j].rgbtGreen = round(val / 4);

                    val = 0;
                    val = val + newimage[i][j][2];
                    val = val + newimage[i - 1][j - 1][2];
                    val = val + newimage[i - 1][j][2];
                    val = val + newimage[i][j - 1][2];
                    image[i][j].rgbtRed = round(val / 4);
                }
                // Case for columns other than first and last of last row:
                else
                {
                    float val = 0;
                    val = val + newimage[i][j][0];
                    val = val + newimage[i][j - 1][0];
                    val = val + newimage[i][j + 1][0];
                    val = val + newimage[i - 1][j - 1][0];
                    val = val + newimage[i - 1][j][0];
                    val = val + newimage[i - 1][j + 1][0];
                    image[i][j].rgbtBlue = round(val / 6);

                    val = 0;
                    val = val + newimage[i][j][1];
                    val = val + newimage[i][j - 1][1];
                    val = val + newimage[i][j + 1][1];
                    val = val + newimage[i - 1][j - 1][1];
                    val = val + newimage[i - 1][j][1];
                    val = val + newimage[i - 1][j + 1][1];
                    image[i][j].rgbtGreen = round(val / 6);

                    val = 0;
                    val = val + newimage[i][j][2];
                    val = val + newimage[i][j - 1][2];
                    val = val + newimage[i][j + 1][2];
                    val = val + newimage[i - 1][j - 1][2];
                    val = val + newimage[i - 1][j][2];
                    val = val + newimage[i - 1][j + 1][2];
                    image[i][j].rgbtRed = round(val / 6);
                }
            }
            // Case for all other rows and columns:
            else
            {
                if (j == 0)
                {
                    float val = 0;
                    val = val + newimage[i][j][0];
                    val = val + newimage[i - 1][j][0];
                    val = val + newimage[i - 1][j + 1][0];
                    val = val + newimage[i][j + 1][0];
                    val = val + newimage[i + 1][j][0];
                    val = val + newimage[i + 1][j + 1][0];
                    image[i][j].rgbtBlue = round(val / 6);

                    val = 0;
                    val = val + newimage[i][j][1];
                    val = val + newimage[i - 1][j][1];
                    val = val + newimage[i - 1][j + 1][1];
                    val = val + newimage[i][j + 1][1];
                    val = val + newimage[i + 1][j][1];
                    val = val + newimage[i + 1][j + 1][1];
                    image[i][j].rgbtGreen = round(val / 6);

                    val = 0;
                    val = val + newimage[i][j][2];
                    val = val + newimage[i - 1][j][2];
                    val = val + newimage[i - 1][j + 1][2];
                    val = val + newimage[i][j + 1][2];
                    val = val + newimage[i + 1][j][2];
                    val = val + newimage[i + 1][j + 1][2];
                    image[i][j].rgbtRed = round(val / 6);
                }
                else if (j == width - 1)
                {
                    float val = 0;
                    val = val + newimage[i][j][0];
                    val = val + newimage[i - 1][j - 1][0];
                    val = val + newimage[i - 1][j][0];
                    val = val + newimage[i][j - 1][0];
                    val = val + newimage[i + 1][j - 1][0];
                    val = val + newimage[i + 1][j][0];
                    image[i][j].rgbtBlue = round(val / 6);

                    val = 0;
                    val = val + newimage[i][j][1];
                    val = val + newimage[i - 1][j - 1][1];
                    val = val + newimage[i - 1][j][1];
                    val = val + newimage[i][j - 1][1];
                    val = val + newimage[i + 1][j - 1][1];
                    val = val + newimage[i + 1][j][1];
                    image[i][j].rgbtGreen = round(val / 6);

                    val = 0;
                    val = val + newimage[i][j][2];
                    val = val + newimage[i - 1][j - 1][2];
                    val = val + newimage[i - 1][j][2];
                    val = val + newimage[i][j - 1][2];
                    val = val + newimage[i + 1][j - 1][2];
                    val = val + newimage[i + 1][j][2];
                    image[i][j].rgbtRed = round(val / 6);
                }
                else
                {
                    float val = 0;
                    val = val + newimage[i][j][0];
                    val = val + newimage[i - 1][j - 1][0];
                    val = val + newimage[i - 1][j][0];
                    val = val + newimage[i - 1][j + 1][0];
                    val = val + newimage[i][j - 1][0];
                    val = val + newimage[i][j + 1][0];
                    val = val + newimage[i + 1][j - 1][0];
                    val = val + newimage[i + 1][j][0];
                    val = val + newimage[i + 1][j + 1][0];
                    image[i][j].rgbtBlue = round(val / 9);

                    val = 0;
                    val = val + newimage[i][j][1];
                    val = val + newimage[i - 1][j - 1][1];
                    val = val + newimage[i - 1][j][1];
                    val = val + newimage[i - 1][j + 1][1];
                    val = val + newimage[i][j - 1][1];
                    val = val + newimage[i][j + 1][1];
                    val = val + newimage[i + 1][j - 1][1];
                    val = val + newimage[i + 1][j][1];
                    val = val + newimage[i + 1][j + 1][1];
                    image[i][j].rgbtGreen = round(val / 9);

                    val = 0;
                    val = val + newimage[i][j][2];
                    val = val + newimage[i - 1][j - 1][2];
                    val = val + newimage[i - 1][j][2];
                    val = val + newimage[i - 1][j + 1][2];
                    val = val + newimage[i][j - 1][2];
                    val = val + newimage[i][j + 1][2];
                    val = val + newimage[i + 1][j - 1][2];
                    val = val + newimage[i + 1][j][2];
                    val = val + newimage[i + 1][j + 1][2];
                    image[i][j].rgbtRed = round(val / 9);
                }
            }
        }
    }
    return;
}
