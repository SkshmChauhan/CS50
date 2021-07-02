#include "helpers.h"
#include <math.h>

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
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE newimage[height][width][3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE newimage[height][width][3];

    // Declaring g(x) array:
    int gx[3][3] = {
            {-1, 0, 1}, // row 0
            {-2, 0, 2}, // row 1
            {-1, 0, 1}  // row 2
    };

    // Declaring g(y) array:
    int gy[3][3] = {
            {-1, -2, -1}, // row 0
            {0, 0, 0}, // row 1
            {1, 2, 1}  // row 2
    };

    // Duplicating image color in a separate matrix:
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newimage[i][j][0] = image[i][j].rgbtBlue;
            newimage[i][j][1] = image[i][j].rgbtGreen;
            newimage[i][j][2] = image[i][j].rgbtRed;
        }
    }

    // Loop for iterating over image rows:
    for (int i = 0; i < height; i++)
    {
        // Loop for iterating over image columns:
        for (int j = 0; j < width; j++)
        {
            double rootblue, rootgreen, rootred;
            int valblue, valgreen, valred

            int answers[2][3] = {
                    // Column represent: blue, green, red:
                    {0, 0, 0}, // row gx
                    {0, 0, 0}, // row gy
            };

            int matrix[3][3] = {
                    {0, 0, 0}, // row 0
                    {0, 0, 0}, // row 1
                    {0, 0, 0}  // row 2
            };

            // Loop for iterating over three different colors:
            // k = 0: blue
            // k = 1: green
            // k = 2: red
            for (int k = 0; k < 3; k++)
            {
                if (i == 0)
                {
                    if (j == 0)
                    {
                        matrix[1][1] = newimage[i][j][k];
                        matrix[1][2] = newimage[i][j + 1][k];
                        matrix[2][1] = newimage[i + 1][j][k];
                        matrix[2][2] = newimage[i + 1][j + 1][k];
                    }
                    else if (j == width - 1)
                    {
                        matrix[1][1] = newimage[i][j][k];
                        matrix[1][0] = newimage[i][j - 1][k];
                        matrix[2][0] = newimage[i + 1][j - 1][k];
                        matrix[2][1] = newimage[i + 1][j][k];
                    }
                    else
                    {
                        matrix[1][0] = newimage[i][j - 1][k];
                        matrix[1][1] = newimage[i][j][k];
                        matrix[1][2] = newimage[i][j + 1][k];
                        matrix[2][0] = newimage[i + 1][j - 1][k]
                        matrix[2][1] = newimage[i + 1][j][k];
                        matrix[2][2] = newimage[i + 1][j + 1][k];
                    }
                }
                else if (i == height - 1)
                {
                    if (j == 0)
                    {
                        matrix[0][1] = newimage[i - 1][j][k];
                        matrix[0][2] = newimage[i - 1][j + 1][k];
                        matrix[1][1] = newimage[i][j][k];
                        matrix[1][2] = newimage[i][j + 1][k];
                    }
                    else if (j == width - 1)
                    {
                        matrix[0][0] = newimage[i - 1][j - 1][k];
                        matrix[0][1] = newimage[i - 1][j][k];
                        matrix[1][0] = newimage[i][j - 1][k];
                        matrix[1][1] = newimage[i][j][k];
                    }
                    else
                    {
                        matrix[0][0] = newimage[i - 1][j - 1][k];
                        matrix[0][1] = newimage[i - 1][j][k];
                        matrix[0][2] = newimage[i - 1][j + 1][k];
                        matrix[1][0] = newimage[i][j - 1][k];
                        matrix[1][1] = newimage[i][j][k];
                        matrix[1][2] = newimage[i][j + 1][k];
                    }
                }
                else
                {
                    if (j == 0)
                    {
                        matrix[0][1] = newimage[i - 1][j][k];
                        matrix[0][2] = newimage[i - 1][j + 1][k];
                        matrix[1][1] = newimage[i][j][k];
                        matrix[1][2] = newimage[i][j + 1][k];
                        matrix[2][1] = newimage[i + 1][j][k];
                        matrix[2][2] = newimage[i + 1][j + 1][k];
                    }
                    else if (j == width - 1)
                    {
                        matrix[0][0] = newimage[i - 1][j - 1][k];
                        matrix[0][1] = newimage[i - 1][j][k];
                        matrix[1][0] = newimage[i][j - 1][k];
                        matrix[1][1] = newimage[i][j][k];
                        matrix[2][0] = newimage[i + 1][j - 1][k];
                        matrix[2][1] = newimage[i + 1][j][k];
                    }
                    else
                    {
                        matrix[0][0] = newimage[i - 1][j - 1][k];
                        matrix[0][1] = newimage[i - 1][j][k];
                        matrix[0][2] = newimage[i - 1][j + 1][k];
                        matrix[1][0] = newimage[i][j - 1][k];
                        matrix[1][1] = newimage[i][j][k];
                        matrix[1][2] = newimage[i][j + 1][k];
                        matrix[2][0] = newimage[i + 1][j - 1][k];
                        matrix[2][1] = newimage[i + 1][j][k];
                        matrix[2][2] = newimage[i + 1][j + 1][k];
                    }
                }

                // Now we have matrix ready for k color:
                float valgx = 0;
                float valgy = 0;
                for (int x = 0; x < 3; x++)
                {
                    for (int y = 0; y < 3; y++)
                    {
                        valgx = valgx + (matrix[i][j] * gx[i][j]);
                        valgy = valgy + (matrix[i][j] * gy[i][j]);
                    }
                }
                answers[0][k] = valgx;
                answers[1][k] = valgy;
            }

            rootblue = sqrt((answers[0][0] * answers[0][0]) + (answers[1][0] * answers[1][0]));
            rootgreen = sqrt((answers[0][1] * answers[0][1]) + (answers[1][1] * answers[1][1]));
            rootred = sqrt((answers[0][2] * answers[0][2]) + (answers[1][2] * answers[1][2]));

            valblue = round(rootblue);
            valgreen = round(rootgreen);
            valred = round(rootred);

            if (valblue > 255)
            {
                valblue = 255;
            }else if (valblue < 0)
            {
                valblue = 0;
            }

            if (valgreen > 255)
            {
                valgreen = 255;
            }else if (valgreen < 0)
            {
                valgreen = 0;
            }

            if (valred > 255)
            {
                valred = 255;
            }else if (valred < 0)
            {
                valred = 0;
            }

            image[i][j].rgbtBlue = valblue;
            image[i][j].rgbtGreen = valgreen;
            image[i][j].rgbtRed = valred;
        }
    }
    return;
}


