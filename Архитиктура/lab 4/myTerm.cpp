#include "myTerm.h"

void mt_clrscr ()
{
	printf("\E[H\E[2J");
}

int mt_gotoXY (int x, int y)
{
	int rows=100, cols=100;
	if ((y > rows) || (x > cols) || (x < 0) || (y < 0))
	    return -1;
	    
	printf("\E[%d;%dH", y, x);
	return 0;
}

int mt_getscreensize (int *rows, int *cols)
{
	struct winsize w;

    if(!ioctl(STDOUT_FILENO, TIOCGWINSZ, &w));
	{
	   *rows = w.ws_row;
	    *cols = w.ws_col;
	    
	    return 0;
	}
	return -1;
}


int mt_setfgcolor (enum colors color)
{
    if((color > 9)||(color < 0))
        return -1;
        
	printf("\E[3%dm", color);
	
	return 0;
}


int mt_setbgcolor (enum colors color)
{
    if((color > 9)||(color < 0))
        return -1;
    
	printf("\E[4%dm", color);
	
	return 0;
}
