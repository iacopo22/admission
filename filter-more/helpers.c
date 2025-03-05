#include "helpers.h"
#include <math.h>

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
            if (i == 0 && j == 0)
            {
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed +
                                             copy[i][j + 1].rgbtRed + copy[i + 1][j + 1].rgbtRed) /
                                            4.0);
                image[i][j].rgbtBlue =
                    round((copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                           copy[i + 1][j + 1].rgbtBlue) /
                          4.0);
                image[i][j].rgbtGreen =
                    round((copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen +
                           copy[i][j + 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) /
                          4.0);
            }
            else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed +
                                             copy[i][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed) /
                                            4.0);
                image[i][j].rgbtBlue =
                    round((copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue +
                           copy[i + 1][j - 1].rgbtBlue) /
                          4.0);
                image[i][j].rgbtGreen =
                    round((copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen +
                           copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen) /
                          4.0);
            }
            else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed +
                                             copy[i][j + 1].rgbtRed + copy[i - 1][j + 1].rgbtRed) /
                                            4.0);
                image[i][j].rgbtBlue =
                    round((copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                           copy[i - 1][j + 1].rgbtBlue) /
                          4.0);
                image[i][j].rgbtGreen =
                    round((copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen +
                           copy[i][j + 1].rgbtGreen + copy[i - 1][j + 1].rgbtGreen) /
                          4.0);
            }
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed +
                                             copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed) /
                                            4.0);
                image[i][j].rgbtBlue =
                    round((copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue +
                           copy[i - 1][j - 1].rgbtBlue) /
                          4.0);
                image[i][j].rgbtGreen =
                    round((copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen +
                           copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen) /
                          4.0);
            }
            else if (i == height - 1 && j != 0)
            {
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed +
                                             copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                                             copy[i - 1][j + 1].rgbtRed + copy[i][j + 1].rgbtRed) /
                                            6.0);
                image[i][j].rgbtBlue =
                    round((copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue +
                           copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j + 1].rgbtBlue +
                           copy[i][j + 1].rgbtBlue) /
                          6.0);
                image[i][j].rgbtGreen =
                    round((copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen +
                           copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                           copy[i - 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen) /
                          6.0);
            }
            else if (i != 0 && j == width - 1)
            {
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed +
                                             copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                                             copy[i + 1][j].rgbtRed + copy[i + 1][j - 1].rgbtRed) /
                                            6.0);
                image[i][j].rgbtBlue =
                    round((copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue +
                           copy[i - 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue +
                           copy[i + 1][j - 1].rgbtBlue) /
                          6.0);
                image[i][j].rgbtGreen =
                    round((copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen +
                           copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                           copy[i + 1][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen) /
                          6.0);
            }
            else if (i == 0 && j != 0)
            {
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed +
                                             copy[i][j + 1].rgbtRed + copy[i + 1][j + 1].rgbtRed +
                                             copy[i][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed) /
                                            6.0);
                image[i][j].rgbtBlue =
                    round((copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                           copy[i + 1][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue +
                           copy[i + 1][j - 1].rgbtBlue) /
                          6.0);
                image[i][j].rgbtGreen =
                    round((copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen +
                           copy[i][j + 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen +
                           copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen) /
                          6.0);
            }
            else if (i != 0 && j == 0)
            {
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed +
                                             copy[i][j + 1].rgbtRed + copy[i + 1][j + 1].rgbtRed +
                                             copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed) /
                                            6.0);
                image[i][j].rgbtBlue =
                    round((copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                           copy[i + 1][j + 1].rgbtBlue + copy[i - 1][j].rgbtBlue +
                           copy[i - 1][j + 1].rgbtBlue) /
                          6.0);
                image[i][j].rgbtGreen =
                    round((copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen +
                           copy[i][j + 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen +
                           copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen) /
                          6.0);
            }
            else
            {
                image[i][j].rgbtRed =
                    round((copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i][j + 1].rgbtRed +
                           copy[i][j - 1].rgbtRed + copy[i + 1][j + 1].rgbtRed +
                           copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed +
                           copy[i - 1][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed) /
                          9.0);
                image[i][j].rgbtBlue =
                    round((copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                           copy[i][j - 1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue +
                           copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue +
                           copy[i - 1][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue) /
                          9.0);
                image[i][j].rgbtGreen = round(
                    (copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
                     copy[i][j - 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen +
                     copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen +
                     copy[i - 1][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen) /
                    9.0);
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
