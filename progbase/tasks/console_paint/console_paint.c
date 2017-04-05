#include <stdio.h>
#include <pbconsole.h>

int main(void)
{
    int x = 0;
    int y = 0;
    
    conClear();
    
     conSetAttr(BG_WHITE);
     for (y =1; y < 17; y++)
    {
        for (x = 1; x < 29; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    
    conSetAttr(BG_BLUE);
    for (x = 1; x < 5; x++)
	{
	   conMove(1, x);
        putchar(' ');
	}
	
    conSetAttr(BG_BLUE);
    for (x = 27; x < 29; x++)
	{
	   conMove(4, x);
        putchar(' ');
	}
    
    conSetAttr(BG_BLUE);
    for (x = 24; x < 25; x++)
	{
	   conMove(2, x);
        putchar(' ');
	}
    
    conSetAttr(BG_BLUE);
    for (x = 23; x < 25; x++)
	{
	   conMove(1, x);
        putchar(' ');
	}
    
    conSetAttr(BG_BLUE);
     for (y =1; y < 4; y++)
    {
        for (x = 25; x < 29; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    
    conSetAttr(BG_BLUE);
    for (x = 1; x < 5; x++)
	{
	   conMove(1, x);
        putchar(' ');
	}
    
    conSetAttr(BG_BLACK);
    for (x = 17; x < 18; x++)
	{
	   conMove(3, x);
        putchar(' ');
	}
    
    conSetAttr(BG_RED);
    for (x = 10; x < 12; x++)
	{
	   conMove(3, x);
        putchar(' ');
	}
    
    conSetAttr(BG_RED);
    for (x = 7; x < 8; x++)
	{
	   conMove(3, x);
        putchar(' ');
	}
    
     conSetAttr(BG_BLACK);
    for (x = 12; x < 13; x++)
	{
	   conMove(3, x);
        putchar(' ');
	}
    
  conSetAttr(BG_BLACK);
     for (y =2; y < 4; y++)
    {
        for (x = 13; x < 17; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
  
    conSetAttr(BG_BLACK);
    for (x = 17; x < 18; x++)
	{
	   conMove(4, x);
        putchar(' ');
	}
    
    conSetAttr(BG_RED);
    for (x = 12; x < 17; x++)
	{
	   conMove(4, x);
        putchar(' ');
	}
    
    conSetAttr(BG_BLACK);
    for (x = 11; x < 13; x++)
	{
	   conMove(4, x);
        putchar(' ');
	}
    
     conSetAttr(BG_RED);
    for (x = 8; x < 10; x++)
	{
	   conMove(4, x);
        putchar(' ');
	}
    
    conSetAttr(BG_BLACK);
    for (x = 11; x < 13; x++)
	{
	   conMove(5, x);
        putchar(' ');
	}
    
    conSetAttr(BG_RED);
    for (x = 10; x < 11; x++)
	{
	   conMove(5, x);
        putchar(' ');
	}
    
    conSetAttr(BG_BLUE);
    for (x = 1; x < 4; x++)
	{
	   conMove(5, x);
        putchar(' ');
	}
    
    conSetAttr(BG_BLUE);
    for (x = 1; x < 4; x++)
	{
	   conMove(5, x);
        putchar(' ');
	}
    
    conSetAttr(BG_YELLOW);
     for (y =5; y < 7; y++)
    {
        for (x = 13; x < 17; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }
    
    conSetAttr(BG_BLACK);
    for (x = 11; x < 13; x++)
	{
	   conMove(6, x);
        putchar(' ');
	}
    
    conSetAttr(BG_RED);
    for (x = 8; x < 10; x++)
	{
	   conMove(6, x);
        putchar(' ');
	}
    
    conSetAttr(BG_BLUE);
    for (x = 1; x < 2; x++)
	{
	   conMove(6, x);
        putchar(' ');
	}
    
    conSetAttr(BG_YELLOW);
    for (x = 18; x < 19; x++)
	{
	   conMove(7, x);
        putchar(' ');
	}
    
    conSetAttr(BG_GREEN);
    for (x = 17; x < 18; x++)
	{
	   conMove(7, x);
        putchar(' ');
	}
    
   
    conSetAttr(BG_BLACK);
    for (x = 11; x < 12; x++)
	{
	   conMove(7, x);
        putchar(' ');
	}
	
	 conSetAttr(BG_INTENSITY_BLACK);
    for (x = 12; x < 17; x++)
	{
	   conMove(7, x);
        putchar(' ');
	}
    
    
    conSetAttr(BG_YELLOW);
    for (x = 18; x < 20; x++)
	{
	   conMove(8, x);
        putchar(' ');
	}
	
	conSetAttr(BG_YELLOW);
    for (x = 18; x < 20; x++)
	{
	   conMove(9, x);
        putchar(' ');
	}
    
    conSetAttr(BG_GREEN);
    for (x = 10; x < 11; x++)
	{
	   conMove(7, x);
        putchar(' ');
	}
    
    conSetAttr(BG_GREEN);
    for (x = 10; x < 11; x++)
	{
	   conMove(7, x);
        putchar(' ');
	} 
    
    conSetAttr(BG_YELLOW);
    for (x = 8; x < 10; x++)
	{
	   conMove(7, x);
        putchar(' ');
	} 
    
    conSetAttr(BG_YELLOW);
    for (x = 7; x < 10; x++)
	{
	   conMove(8, x);
        putchar(' ');
	} 
    
    conSetAttr(BG_GREEN);
     for (y = 8; y < 10; y++)
    {
        for (x = 10; x < 18; x++)
        {
            conMove(y, x);
            putchar(' ');
        }
    }

	conSetAttr(BG_YELLOW);
    for (x = 7; x < 10; x++)
	{
	   conMove(9, x);
        putchar(' ');
	} 

    conSetAttr(BG_INTENSITY_BLACK);
    for (x = 9; x < 23; x++)
	{
	   conMove(10, x);
        putchar(' ');
	} 
    
    conSetAttr(BG_YELLOW);
    for (x = 7; x < 9; x++)
	{
	   conMove(10, x);
        putchar(' ');
	}
    
     conSetAttr(BG_YELLOW);
    for (x = 18; x < 20; x++)
	{
	   conMove(11, x);
        putchar(' ');
	}
    conSetAttr(BG_INTENSITY_BLACK);
    for (x = 22; x < 23; x++)
	{
	   conMove(9, x);
        putchar(' ');
	}
    
    conSetAttr(BG_INTENSITY_BLACK);
    for (x = 12; x < 18; x++)
	{
	   conMove(11, x);
        putchar(' ');
	}
    
    conSetAttr(BG_YELLOW);
    for (x = 8; x < 12; x++)
	{
	   conMove(11, x);
        putchar(' ');
	}
    
    conSetAttr(BG_BLUE);
    for (x = 16; x < 19; x++)
	{
	   conMove(12, x);
        putchar(' ');
	}
    
    conSetAttr(BG_RED);
    for (x = 9; x < 16; x++)
	{
	   conMove(12, x);
        putchar(' ');
	}
    
    conSetAttr(BG_BLUE);
    for (x = 17; x < 19; x++)
	{
	   conMove(13, x);
        putchar(' ');
	}
    
    conSetAttr(BG_RED);
    for (x = 9; x < 17; x++)
	{
	   conMove(13, x);
        putchar(' ');
	}
    
    conSetAttr(BG_GREEN);
    for (x = 27; x < 28; x++)
	{
	   conMove(14, x);
        putchar(' ');
	}
    
    conSetAttr(BG_GREEN);
    for (x = 22; x < 23; x++)
	{
	   conMove(14, x);
        putchar(' ');
	}
    
    conSetAttr(BG_INTENSITY_BLACK);
    for (x = 16; x < 18; x++)
	{
	   conMove(14, x);
        putchar(' ');
	}
    
    conSetAttr(BG_INTENSITY_BLACK);
    for (x = 9; x < 11; x++)
	{
	   conMove(14, x);
        putchar(' ');
	}
    
    conSetAttr(BG_GREEN);
    for (x = 6; x < 7; x++)
	{
	   conMove(14, x);
        putchar(' ');
	}
    
    conSetAttr(BG_GREEN);
    for (x = 3; x < 4; x++)
	{
	   conMove(14, x);
        putchar(' ');
	}
    
    conSetAttr(BG_GREEN);
    for (x = 26; x < 28; x++)
	{
	   conMove(15, x);
        putchar(' ');
	}
	
    conSetAttr(BG_GREEN);
    for (x = 24; x < 25; x++)
	{
	   conMove(15, x);
        putchar(' ');
	}
    
    conSetAttr(BG_GREEN);
    for (x = 21; x < 23; x++)
	{
	   conMove(15, x);
        putchar(' ');
	}
 
    conSetAttr(BG_INTENSITY_BLACK);
    for (x = 16; x < 19; x++)
	{
	   conMove(15, x);
        putchar(' ');
	}
	
    conSetAttr(BG_INTENSITY_BLACK);
    for (x = 9; x < 12; x++)
	{
	   conMove(15, x);
        putchar(' ');
	}
    
    conSetAttr(BG_GREEN);
    for (x = 5; x < 7; x++)
	{
	   conMove(15, x);
        putchar(' ');
	}
	
    conSetAttr(BG_GREEN);
    for (x = 2; x < 4; x++)
	{
	   conMove(15, x);
        putchar(' ');
	}
	
    conSetAttr(BG_GREEN);
    for (x = 1; x < 29; x++)
    {
        conMove(16, x);
        putchar(' ');
    }
    
    conReset();
    puts("");
    return 0;
}

