#pragma once
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

enum colors {
	cl_light_green = 0,
	cl_red = 1,
	cl_green = 2,
	cl_yellow = 3,
	cl_blue = 4,
	cl_magenta = 5,
	cl_cyan = 6,
	cl_white = 7,
	cl_default = 8,
};

void mt_clrscr ();								// производит очистку и перемещение курсора в левый верхний угол экрана;
int mt_gotoXY (int x, int y);					// перемещает курсор в указанную позицию. Первый параметр номер строки, второй - номер столбца;
int mt_getscreensize (int *rows, int *cols);	// определяет размер экрана терминала (количество строк и столбцов);
int mt_setfgcolor (enum colors);			// устанавливает цвет последующих выводимых символов. В качестве параметра передаѐтся константа из созданного Вами перечислимого типа colors , описывающего цвета терминала;
int mt_setbgcolor (enum colors);			// устанавливает цвет фона последующих выводимых символов. В качестве параметра передаѐтся константа из созданного Вами перечислимого типа colors , описывающего цвета терминала.

/*infocmp -L -1 | grep 
clear_screen=\E[H\E[2J
cursor_address=\E[%i%p1%d;%p2%dH  \E[;H
set_a_background=\E[%?%p1%{8}%<%t4%p1%d%e%p1%{16}%<%t10%p1%{8}%-%d%e48;5;%p1%d%;m,  \E[4m,
set_a_foreground=\E[%?%p1%{8}%<%t3%p1%d%e%p1%{16}%<%t9%p1%{8}%-%d%e38;5;%p1%d%;m,
cursor_invisible=\E[?25l,
cursor_visible=\E[?12;25h,
*/