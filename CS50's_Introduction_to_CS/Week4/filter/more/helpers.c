#include "helpers.h"

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
            {-1, 0, 1}, // row 0
            {-2, 0, 2}, // row 1
            {-1, 0, 1}  // row 2
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
    
    int answers[2][3] = {
            {-1, 0, 1}, // row 0
            {-2, 0, 2}, // row 1
    };

    // Loop for iterating over image rows:
    for (int i = 0; i < height; i++)
    {
        // Loop for iterating over image columns:
        for (int j = 0; j < width; j++)
        {
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
                        matrix[1][1] = newimage[i][j][k]
                    }
                    else if (j == width - 1)
                    {
    
                    }
                    else
                    {
    
                    }
                }
                else if(i == height - 1)
                {
                    if (j == 0)
                    {
    
                    }
                    else if (j == width - 1)
                    {
    
                    }
                    else
                    {
    
                    }
                }
                else{
                    if (j == 0)
                    {
    
                    }
                    else if (j == width - 1)
                    {
    
                    }
                    else
                    {
    
                    }
                }
            }
        }
    }
    return;
}


