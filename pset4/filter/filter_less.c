// Made by PMBC
#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            float r = (float) image[row][column].rgbtRed;
            float g = (float) image[row][column].rgbtGreen;
            float b = (float) image[row][column].rgbtBlue;
            int average = (int) round((r + g + b) / 3);
            image[row][column].rgbtRed = average;
            image[row][column].rgbtGreen = average;
            image[row][column].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            // separate the original colors
            int originalRed = image[row][column].rgbtRed;
            int originalGreen = image[row][column].rgbtGreen;
            int originalBlue = image[row][column].rgbtBlue;

            // define the new sepia colors
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // set the new sepia colors
            image[row][column].rgbtRed = sepiaRed;
            image[row][column].rgbtGreen = sepiaGreen;
            image[row][column].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        int half_row = width / 2;
        for (int j = 0; j < half_row; j++)
        {
            // reflected pixel coord
            int jr = width - (1 + j);

            // gets the colors of the pixel at the left
            int originalRed = image[row][j].rgbtRed;
            int originalGreen = image[row][j].rgbtGreen;
            int originalBlue = image[row][j].rgbtBlue;

            //puts the color fo the pixel at most right in the pixel at the most left
            image[row][j].rgbtRed = image[row][jr].rgbtRed;
            image[row][j].rgbtGreen = image[row][jr].rgbtGreen;
            image[row][j].rgbtBlue = image[row][jr].rgbtBlue;

            // puts the original colors at the most left pixel in the most right pixel
            image[row][jr].rgbtRed = originalRed;
            image[row][jr].rgbtGreen = originalGreen;
            image[row][jr].rgbtBlue = originalBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy the array image into a new array: original_rgb, the porpuse of original_rgb is to remember the original colors of the image
    RGBTRIPLE org_rgb[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            org_rgb[row][column].rgbtRed = image[row][column].rgbtRed;
            org_rgb[row][column].rgbtGreen = image[row][column].rgbtGreen;
            org_rgb[row][column].rgbtBlue = image[row][column].rgbtBlue;
        }
    }
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            float r = 0;
            float g = 0;
            float b = 0;
            int counter = 0;
            
            for (int i = row - 1; i <= row + 1; i++)
            {
                if (i < 0 || i >= height)
                {
                    continue;
                }
                for (int j = column - 1; j <= column + 1; j++)
                {
                    if (j < 0 || j >= width)
                    {
                        continue;
                    }
                    r += (float) org_rgb[i][j].rgbtRed;
                    g += (float) org_rgb[i][j].rgbtGreen;
                    b += (float) org_rgb[i][j].rgbtBlue;
                    counter++;
                }
            }
            
            // designate the correct colors
            image[row][column].rgbtRed = (int) round(r / counter);
            image[row][column].rgbtGreen = (int) round(g / counter);
            image[row][column].rgbtBlue = (int) round(b / counter);
        }
    }    
    return;
}
