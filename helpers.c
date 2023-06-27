

#include "helpers.h"
#include<math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculating average
        avg =  round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / (float)3);
        image[i][j].rgbtRed=avg;
        image[i][j].rgbtBlue=avg;
        image[i][j].rgbtGreen=avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaBlue, sepiaGreen;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculating sephia colour
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if(sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if(sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if(sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int  mid = (width)/2;

     RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j =0 ; j <mid ; j++)
        {
            temp[i][j]=image[i][j];
            image[i][j]=image[i][(width - j - 1)];
            image[i][(width - j - 1)] = temp[i][j];

        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
        int i, j, k, m, avgblue, avggreen, avgred, x, y;
        float count;
    for (i = 0 ; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            //copying pixels

            copy[i][j] = image[i][j];
        }
    }
      for (i = 0; i < height; i++)
      {
        for ( j = 0; j < width; j++)
        {
            avgred=0,avggreen=0,avgblue=0;
            count=0;

      for ( k = -1; k < 2; k++)
   {
      for (m = -1; m < 2; m++)
     {
      x = i + k;
      y = j + m;

       if (x < 0 || x > (height - 1) || y < 0 || y > (width - 1))
      {
          continue;
       }
      avgred += image[x][y].rgbtRed;
       avgblue += image[x][y].rgbtBlue;
         avggreen += image[x][y].rgbtGreen;

        count++;
     }
                    copy[i][j].rgbtRed = round(avgred/count);
                    copy[i][j].rgbtGreen = round(avggreen/count);
                    copy[i][j].rgbtBlue = round(avgblue/count);
     }

        }
     }
            for ( i = 0;i < height; i++)
            {
                for ( j = 0;j < width; j++)
                {
                    image[i][j] = copy[i][j];
                }
    }
   return;
 }


