#include <stdio.h>
#include <progbase.h>
#include <pbconsole.h>

int main(void) {
    /* colors encoding table */
    const unsigned long MILLIS = 17;
    int colorImageLength;
    int temporary = 0;
    const char colorsTable[16][2] = {
        {'0', BG_BLACK},
        {'1', BG_INTENSITY_BLACK},
        {'2', BG_RED },
        {'3', BG_INTENSITY_RED},
        {'4', BG_GREEN},
        {'5', BG_INTENSITY_GREEN},
        {'6', BG_YELLOW},
        {'7', BG_INTENSITY_YELLOW},
        {'8', BG_BLUE},
        {'9', BG_INTENSITY_BLUE},
        {'A', BG_MAGENTA},
        {'B', BG_INTENSITY_MAGENTA},
        {'C', BG_CYAN},
        {'D', BG_INTENSITY_CYAN},
        {'E', BG_WHITE},
        {'F', BG_INTENSITY_WHITE}
    };
    int colorsTableLength = sizeof(colorsTable) / sizeof(colorsTable[0]);
    char colorsPalette[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char image[28][28] = {
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { 'F','F','F','F','F','F','F','F','F','F','0','0','0','0','0','0','0','0','F','F','F','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','F','F','0','1','1','1','1','1','1','1','1','0','F','F','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','F','0','1','E','E','E','E','E','E','E','E','1','0','F','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','F','0','E','5','0','5','5','5','5','0','5','E','0','F','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','F','0','5','5','5','5','5','5','5','5','5','E','0','F','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','F','0','5','5','0','0','0','0','0','0','5','5','0','F','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','F','0','5','5','5','5','5','5','5','5','5','5','0','F','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','F','0','0','5','5','5','5','5','5','5','5','0','0','F','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','F','0','5','0','0','0','0','0','0','0','0','5','0','F','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','0','5','5','5','5','5','5','5','5','5','5','5','5','0','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','0','5','5','5','5','5','5','5','5','5','5','0','5','5','5','0','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','0','5','5','0','0','5','5','5','5','5','5','0','0','5','5','0','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','0','5','5','5','0','8','8','8','8','8','8','0','5','5','5','0','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','0','0','0','0','8','8','8','8','8','8','0','0','0','0','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','F','F','F','0','8','8','0','0','8','8','0','F','F','F','F','F','F','F','F','F','F' },
        { 'F','F','F','F','F','F','F','F','F','F','0','0','0','F','F','0','0','0','F','F','F','F','F','F','F','F','F','F' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
        { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' }
    };
    int colorsPaletteLength = sizeof(colorsPalette) / sizeof(colorsPalette[0]);
    int i = 0;
    int j = 0;
    int colorPairIndex = 0;
    for (i = 0; i < colorsPaletteLength; i++)
    {
        char colorCode = '\0';
        char color = '\0';
        /* get current color code from colorsPalette */
        colorCode = colorsPalette[i];
        /* find corresponding color in table */
        for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
        {
            char colorPairCode = colorsTable[colorPairIndex][0];
            char colorPairColor = colorsTable[colorPairIndex][1];
            if (colorCode == colorPairCode)
            {
                color = colorPairColor;
                break;  /* we have found our color, break the loop */
            }
        }
        /* print space with founded color background */
        conSetAttr(color);
        putchar(' ');
        conReset();

    }
    puts(" ");
    conReset();

    printf("\n");
    
/*task2*/


    colorImageLength = sizeof(image) / sizeof(image[0]);
    for (i = 0; i < colorImageLength - 1; i++)
    {
        for(j = 0; j < colorImageLength - 1; j++)
        {
            char colorCode = '\0';
            char color = '\0';
            /* get current color code from colorsPalette */
            colorCode = image[i][j];
            /* find corresponding color in table */
            for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
            {
                char colorPairCode = colorsTable[colorPairIndex][0];
                char colorPairColor = colorsTable[colorPairIndex][1];
                if (colorCode == colorPairCode)
                {
                    color = colorPairColor;
                    break;  /* we have found our color, break the loop */
                }
            }
            /* print space with founded color background */
            conSetAttr(color);

            putchar(' ');
        }
        puts(" ");
    }
    puts("");
    conReset();



    for( i = 0; i < colorImageLength*2; i++) {   /*here we  make space between images*/
        puts(" ");
    }

/*task3*/


    for (i = colorImageLength - 1; i >= 0; i--)
    {

        if(i % 2 == 0) {

            for(j = colorImageLength - 1; j >= 0; j--)
            {
                char colorCode = '\0';
                char color = '\0';
                /* get current color code from colorsPalette */
                colorCode = image[i][j];
                /* find corresponding color in table */
                for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
                {
                    char colorPairCode = colorsTable[colorPairIndex][0];
                    char colorPairColor = colorsTable[colorPairIndex][1];
                    if (colorCode == colorPairCode)
                    {
                        color = colorPairColor;
                        break;  /* we have found our color, break the loop */
                    }
                }
                /* print space with founded color background */
                conSetAttr(color);
                fflush(stdout);  /* to see output in time */
                sleepMillis(MILLIS);  /* to make time delay */
                conMove(i+1, j+1);
                putchar(' ');
            }
        }


        else {
            for(j = 0; j <= colorImageLength-1; j++)
            {
                char colorCode = '\0';
                char color = '\0';
                /* get current color code from colorsPalette */
                colorCode = image[i][j];
                /* find corresponding color in table */
                for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
                {
                    char colorPairCode = colorsTable[colorPairIndex][0];
                    char colorPairColor = colorsTable[colorPairIndex][1];
                    if (colorCode == colorPairCode)
                    {
                        color = colorPairColor;
                        break;  /* we have found our color, break the loop */
                    }
                }
                /* print space with founded color background */
                conSetAttr(color);
                fflush(stdout);  /* to see output in time */
                sleepMillis(MILLIS);  /* to make time delay */
                conMove(i+1, j+1);
                putchar(' ');
            }
        }
        puts("");
    }
    puts("");
    conReset();
    
    
/*task4*/
	
	 colorImageLength = sizeof(image) / sizeof(image[0]);
	 conMove (30, 1);
    for (i = 0; i < colorImageLength; i++) {
            for (j = i; j < colorImageLength; j++) {
                temporary = image[i][j];
                image[i][j] = image[j][i];
                image[j][i] = temporary;
            }
        }
        for (i = 0; i <= colorImageLength / 2; i++) {
            for (j = 0; j < 28; j++) {
                temporary = image[i][j];
                image[i][j] = image[colorImageLength - 1 - i][j];
                image[colorImageLength - 1 - i][j] = temporary;
            }
        }
        
    for (i = 0; i <= colorImageLength - 1; i++)
    {
        for(j = 0; j <= colorImageLength - 1; j++)
        {
            char colorCode = '\0';
            char color = '\0';
            /* get current color code from colorsPalette */
            colorCode = image[i][j];
            /* find corresponding color in table */
            for (colorPairIndex = 0; colorPairIndex < colorsTableLength;colorPairIndex++)
            {
                char colorPairCode = colorsTable[colorPairIndex][0];
                char colorPairColor = colorsTable[colorPairIndex][1];
                if (colorCode == colorPairCode)
                {
                    color = colorPairColor;
                    break;  /* we have found our color, break the loop */
                }
            }
            /* print space with founded color background */
            conSetAttr(color);
	
            putchar(' ');
            conReset();
        }
        puts(" ");
    }
    puts("");
    conReset();
    
    
return 0;
}
