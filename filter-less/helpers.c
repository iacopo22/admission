#include "helpers.h"
#include <math.h>
#include <stdio.h>

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
                int average = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);

                // Assign the average to the RGB values of the pixel
                image[i][j].rgbtBlue = average;
                image[i][j].rgbtRed = average;
                image[i][j].rgbtGreen = average;
            }
        }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over every pixels
    for (int i = 0; i < height; i++)
    {
            for (int j = 0; j < width; j++)
            {
                int Red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
                Red = less(Red);
                int Green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
                Green = less(Green);
                int Blue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
                Blue = less(Blue);

                image[i][j].rgbtRed = Red;
                image[i][j].rgbtBlue = Blue;
                image[i][j].rgbtGreen = Green;
             }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
            for (int j = 0; j < width; j++)
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
