#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    //LOOPING FOR EACH ROW AND PIXEL

    for(int row = 0; row < height; row ++)
    {
        for (int pixel = 0; pixel < width; pixel++)
        {
            int rgbtpixel =  (int) round((image[row][pixel].rgbtBlue + image[row][pixel].rgbtGreen + image[row][pixel].rgbtRed) / 3.0);
            image[row][pixel].rgbtBlue = rgbtpixel;
            image[row][pixel].rgbtGreen = rgbtpixel;
            image[row][pixel].rgbtRed = rgbtpixel;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row = 0; row < height; row ++)
    {
        for (int pixel = 0; pixel < width / 2; pixel++)
        {
            RGBTRIPLE temp = image[row][pixel];
            image[row][pixel] = image[row][width - 1 - pixel];
            image[row][width - 1 - pixel] = temp;
        }
    }

    return;
    }

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //CREATE A TEMPORARY COPY OF THE IMAGE
    RGBTRIPLE temp[height][width];
    for (int row = 0; row < height; row++)
    {
        for(int pixel = 0; pixel < width; pixel++)
        {
            temp[row][pixel] = image[row][pixel];
        }
    }

    //LOOP THROUGH EACH PIXEL AND FIND ITS NEIGHBOURING PIXELS

    for (int row = 0; row < height; row++)
    {
        for(int pixel = 0; pixel < width; pixel++)
        {
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;

            //GET NEIGHBOURING PIXELS
            for (int x = -1; x < 2; x++)
            {
               for(int y = -1; y < 2; y++)
               {
                   int currentX = row + x;
                   int currentY = pixel + y;

                   //CHECK IF THE PIXEL IS VALID
                   if (currentX < 0 || currentX > (height -1) || currentY < 0 || currentY > (width - 1))
                   {
                        continue;
                   }

                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    counter++;
               }

                //CALCULATE AVERAGE OF NEIGHBOURING PIXELS
                temp[row][pixel].rgbtRed = round(totalRed / counter);
                temp[row][pixel].rgbtGreen = round(totalGreen / counter);
                temp[row][pixel].rgbtBlue = round(totalBlue / counter);
            }
        }
    }

    //COPY NEW PIXELS INTO ORIGINAL IMAGE
    for (int row = 0; row < height; row++)
    {
        for(int pixel = 0; pixel < width; pixel++)
        {
            image[row][pixel].rgbtRed = temp[row][pixel].rgbtRed;
            image[row][pixel].rgbtBlue = temp[row][pixel].rgbtBlue;
            image[row][pixel].rgbtGreen = temp[row][pixel].rgbtGreen;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //CREATE A TEMPORARY COPY OF THE IMAGE
    RGBTRIPLE temp[height][width];
    for (int row = 0; row < height; row++)
    {
        for(int pixel = 0; pixel < width; pixel++)
        {
            temp[row][pixel] = image[row][pixel];
        }
    }

    //INITIALIZING Gx e Gy
    int Gx[3][3] = {{-1, 0, 1},
                    {-2, 0, 2},
                    {-1, 0, 1}};

    int Gy[3][3] = {{-1, -2, -1},
                    {0, 0, 0},
                    {1, 2, 1}};

    //LOOP THROUGH EACH ROW AND COLUMN

    for (int row = 0; row < height; row++)
    {
        for(int pixel = 0; pixel < width; pixel++)
        {
            int redX = 0;
            int greenX = 0;
            int blueX = 0;
            int redY = 0;
            int greenY = 0;
            int blueY = 0;

            //LOOP THROUGH EACH PIXEL FOR NEIGHBOURING PIXELS

            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    //Check for valid pixels
                    if (row - 1 + x < 0 || row - 1 + x > height - 1 || pixel - 1 + y < 0  || pixel - 1 + y > width - 1)
                    {
                        continue;
                    }

                    //Calculate Gx for each colour
                    redX = redX + (image[row - 1 + x][pixel - 1 + y].rgbtRed * Gx[x][y]);
                    greenX = greenX + (image[row - 1 + x][pixel - 1 + y].rgbtGreen * Gx[x][y]);
                    blueX = blueX + (image[row - 1 + x][pixel - 1 + y].rgbtBlue * Gx[x][y]);

                    //Calculate Gy for each colour
                    redY = redY + (image[row - 1 + x][pixel - 1 + y].rgbtRed * Gy[x][y]);
                    greenY = greenY + (image[row - 1 + x][pixel - 1 + y].rgbtGreen * Gy[x][y]);
                    blueY = blueY + (image[row - 1 + x][pixel - 1 + y].rgbtBlue * Gy[x][y]);

                    //Calculate square root of Gx2 and Gy2
                    int red = round(sqrt((redX * redX) + (redY * redY)));
                    int green = round(sqrt((greenX * greenX) + (greenY * greenY)));
                    int blue = round(sqrt((blueX * blueX) + (blueY * blueY)));

                    //Cap value at 255 if exceeds
                    if (red > 255)
                    {
                        red = 255;
                    }
                    if (green > 255)
                    {
                        green = 255;
                    }
                    if (blue > 255)
                    {
                        blue = 255;
                    }

                    //Copy values into temp image
                    temp[row][pixel].rgbtRed = red;
                    temp[row][pixel].rgbtGreen = green;
                    temp[row][pixel].rgbtBlue = blue;
                }
            }
        }
    }

    //Copy new pixels into original image

    for (int row = 0; row < height; row++)
    {
        for(int pixel = 0; pixel < width; pixel++)
        {
            image[row][pixel].rgbtRed = temp[row][pixel].rgbtRed;
            image[row][pixel].rgbtBlue = temp[row][pixel].rgbtBlue;
            image[row][pixel].rgbtGreen = temp[row][pixel].rgbtGreen;
        }
    }

    return;
}
