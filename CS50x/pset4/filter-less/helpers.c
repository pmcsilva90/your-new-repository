#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg = 0;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            avg = round((image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed) / 3.0);
            image[h][w].rgbtBlue = avg;
            image[h][w].rgbtGreen = avg;
            image[h][w].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            sepiaRed = round(0.393 * image[h][w].rgbtRed + 0.769 * image[h][w].rgbtGreen + 0.189 * image[h][w].rgbtBlue);
            sepiaGreen = round(0.349 * image[h][w].rgbtRed + 0.686 * image[h][w].rgbtGreen + 0.168 * image[h][w].rgbtBlue);
            sepiaBlue = round(0.272 * image[h][w].rgbtRed + 0.534 * image[h][w].rgbtGreen + 0.131 * image[h][w].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[h][w].rgbtBlue = sepiaBlue;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tempR = 0;
    int tempG = 0;
    int tempB = 0;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            tempR = image[h][width - 1 - w].rgbtRed;
            tempG = image[h][width - 1 - w].rgbtGreen;
            tempB = image[h][width - 1 - w].rgbtBlue;
            image[h][width - 1 - w].rgbtRed = image[h][w].rgbtRed;
            image[h][width - 1 - w].rgbtGreen = image[h][w].rgbtGreen;
            image[h][width - 1 - w].rgbtBlue = image[h][w].rgbtBlue;
            image[h][w].rgbtRed = tempR;
            image[h][w].rgbtGreen = tempG;
            image[h][w].rgbtBlue = tempB;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copy[h][w] = image[h][w];
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float avgRed = 0.0;
            float avgGreen = 0.0;
            float avgBlue = 0.0;
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            float pixelCount = 0.0;
            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    if (h + r >= 0 && h + r < height && w + c >= 0 && w + c < width)
                    {
                        pixelCount++;
                        sumRed += copy[h + r][w + c].rgbtRed;
                        sumGreen += copy[h + r][w + c].rgbtGreen;
                        sumBlue += copy[h + r][w + c].rgbtBlue;
                    }
                }
            }
            avgRed = round(sumRed / pixelCount);
            avgGreen = round(sumGreen / pixelCount);
            avgBlue = round(sumBlue / pixelCount);
            image[h][w].rgbtRed = avgRed;
            image[h][w].rgbtGreen = avgGreen;
            image[h][w].rgbtBlue = avgBlue;
        }
    }
    return;
}
