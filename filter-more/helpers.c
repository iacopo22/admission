#include "helpers.h"
#include <math.h>

int less(int colour);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over every pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Average of the RGB of the pixel
            int average =
                round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);

            // Assign the average to the RGB values of the pixel
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
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
            int Red = image[i][j].rgbtRed;
            int Blue = image[i][j].rgbtBlue;
            int Green = image[i][j].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtRed = Red;
            image[i][width - j - 1].rgbtBlue = Blue;
            image[i][width - j - 1].rgbtGreen = Green;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    // Copy of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize the sum for every colour to calculate the average
            float sum_red = copy[i][j].rgbtRed;
            float sum_blue = copy[i][j].rgbtBlue;
            float sum_green = copy[i][j].rgbtGreen;

            // Float to preserve the .x
            float counter = 1.0;

            // Every possible cases
            int check[8][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 0},
                               {0, 1},   {-1, 0}, {0, -1}, {1, 1}};

            for (int z = 0; z < 8; z++)
            {
                // If the pixel exists I add it to the sum
                if (i + check[z][0] >= 0 && i + check[z][0] <= height - 1 && j + check[z][1] >= 0 &&
                    j + check[z][1] <= width - 1)
                {
                    sum_red = sum_red + copy[i + check[z][0]][j + check[z][1]].rgbtRed;
                    sum_blue = sum_blue + copy[i + check[z][0]][j + check[z][1]].rgbtBlue;
                    sum_green = sum_green + copy[i + check[z][0]][j + check[z][1]].rgbtGreen;

                    counter++;
                }
            }
            // Calculate the average and assign it to the i-th j-th pixel
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sum_red_X = 0;
            float sum_blue_X = 0;
            float sum_green_X = 0;

            float sum_red_Y = 0;
            float sum_blue_Y = 0;
            float sum_green_Y = 0;

            int check[8][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 0},
                               {0, 1},   {-1, 0}, {0, -1}, {1, 1}};

            // Matrix for the X and the Y axis
            int Gx_matrix[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
            int Gy_matrix[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

            for (int z = 0; z < 8; z++)
            {
                // if the pixel exists
                if (i + check[z][0] >= 0 && i + check[z][0] <= height - 1 && j + check[z][1] >= 0 &&
                    j + check[z][1] <= width - 1)
                {
                    // A certain colour value of the pixel has to be matched with the value of the
                    // matrix
                    int Gx_value = Gx_matrix[check[z][0] + 1][check[z][1] + 1];
                    int Gy_value = Gy_matrix[check[z][0] + 1][check[z][1] + 1];

                    sum_red_X =
                        sum_red_X + Gx_value * copy[i + check[z][0]][j + check[z][1]].rgbtRed;
                    sum_blue_X =
                        sum_blue_X + Gx_value * copy[i + check[z][0]][j + check[z][1]].rgbtBlue;
                    sum_green_X =
                        sum_green_X + Gx_value * copy[i + check[z][0]][j + check[z][1]].rgbtGreen;

                    sum_red_Y =
                        sum_red_Y + Gy_value * copy[i + check[z][0]][j + check[z][1]].rgbtRed;
                    sum_blue_Y =
                        sum_blue_Y + Gy_value * copy[i + check[z][0]][j + check[z][1]].rgbtBlue;
                    sum_green_Y =
                        sum_green_Y + Gy_value * copy[i + check[z][0]][j + check[z][1]].rgbtGreen;
                }
            }
            image[i][j].rgbtRed = less(round(sqrt(pow(sum_red_X, 2) + pow(sum_red_Y, 2))));
            image[i][j].rgbtBlue = less(round(sqrt(pow(sum_blue_X, 2) + pow(sum_blue_Y, 2))));
            image[i][j].rgbtGreen = less(round(sqrt(pow(sum_green_X, 2) + pow(sum_green_Y, 2))));
        }
    }
    return;
}

int less(int colour)
{
    if (colour >= 255)
    {
        colour = 255;
    }
    return colour;
}
