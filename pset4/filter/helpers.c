// Made by PMBC
// filter_more
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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

    // implement the edges algorithm
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            double gx_red = 0;// gx values holders
            double gx_green = 0;
            double gx_blue = 0;
            
            double gy_red = 0;// Gy values holders
            double gy_green = 0;
            double gy_blue = 0;

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
                    if (i == row - 1 && j == column - 1)
                    {
                        gx_red += org_rgb[i][j].rgbtRed * (-1);
                        gx_green += org_rgb[i][j].rgbtGreen * (-1);
                        gx_blue += org_rgb[i][j].rgbtBlue * (-1);
                        gy_red += org_rgb[i][j].rgbtRed * (-1);
                        gy_green += org_rgb[i][j].rgbtGreen * (-1);
                        gy_blue += org_rgb[i][j].rgbtBlue * (-1);
                        continue;
                    }
                    if (i == row && j == column - 1)
                    {
                        gx_red += org_rgb[i][j].rgbtRed * (-2);
                        gx_green += org_rgb[i][j].rgbtGreen * (-2);
                        gx_blue += org_rgb[i][j].rgbtBlue * (-2);
                        continue;
                    }
                    if (i == row + 1 && j == column - 1)
                    {
                        gx_red += org_rgb[i][j].rgbtRed * (-1);
                        gx_green += org_rgb[i][j].rgbtGreen * (-1);
                        gx_blue += org_rgb[i][j].rgbtBlue * (-1);
                        gy_red += org_rgb[i][j].rgbtRed;
                        gy_green += org_rgb[i][j].rgbtGreen;
                        gy_blue += org_rgb[i][j].rgbtBlue;
                        continue;
                    }
                    if (i == row - 1 && j == column)
                    {
                        gy_red += org_rgb[i][j].rgbtRed * (-2);
                        gy_green += org_rgb[i][j].rgbtGreen * (-2);
                        gy_blue += org_rgb[i][j].rgbtBlue * (-2);
                        continue;
                    }
                    if (i == row + 1 && j == column)
                    {
                        gy_red += org_rgb[i][j].rgbtRed * (2);
                        gy_green += org_rgb[i][j].rgbtGreen * (2);
                        gy_blue += org_rgb[i][j].rgbtBlue * (2);
                        continue;
                    }
                    if (i == row - 1 && j == column + 1)
                    {
                        gx_red += org_rgb[i][j].rgbtRed;
                        gx_green += org_rgb[i][j].rgbtGreen;
                        gx_blue += org_rgb[i][j].rgbtBlue;
                        gy_red += org_rgb[i][j].rgbtRed * (-1);
                        gy_green += org_rgb[i][j].rgbtGreen * (-1);
                        gy_blue += org_rgb[i][j].rgbtBlue * (-1);
                        continue;
                    }
                    if (i == row && j == column + 1)
                    {
                        gx_red += org_rgb[i][j].rgbtRed * 2;
                        gx_green += org_rgb[i][j].rgbtGreen * 2;
                        gx_blue += org_rgb[i][j].rgbtBlue * 2;
                        continue;
                    }
                    if (i == row + 1 && j == column + 1)
                    {
                        gx_red += org_rgb[i][j].rgbtRed;
                        gx_green += org_rgb[i][j].rgbtGreen;
                        gx_blue += org_rgb[i][j].rgbtBlue;
                        gy_red += org_rgb[i][j].rgbtRed;
                        gy_green += org_rgb[i][j].rgbtGreen;
                        gy_blue += org_rgb[i][j].rgbtBlue;
                        continue;
                    }
                }
            }
            int new_red = (int) round(sqrt(pow(gx_red, 2) + pow(gy_red, 2)));
            int new_green = (int) round(sqrt(pow(gx_green, 2) + pow(gy_green, 2)));
            int new_blue = (int) round(sqrt(pow(gx_blue, 2) + pow(gy_blue, 2)));
            if (new_red > 255)
            {
                new_red = 255;
            }
            if (new_green > 255)
            {
                new_green = 255;
            }
            if (new_blue > 255)
            {
                new_blue = 255;
            }

            // designate the correct colors
            image[row][column].rgbtRed = new_red;
            image[row][column].rgbtGreen = new_green;
            image[row][column].rgbtBlue = new_blue;
        }
    }
    return;
}
