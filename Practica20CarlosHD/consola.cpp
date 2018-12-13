#include "stdafx.h"
#include <windows.h>
#include <assert.h>

// ***************************************************************************************
// FUNCIONES AUXILIARES DE PINTADO
// ***************************************************************************************
void gotoxy(short x, short y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void hidecursor(void) {
	HANDLE hdl;
	hdl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO t;
	t.bVisible = false;
	SetConsoleCursorInfo(hdl, &t);
}

void clear()
{
	system("cls");
}

short getConsoleWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	{
		return (csbi.srWindow.Right - csbi.srWindow.Left + 1);
	}
	else
		return 0;
}

short getConsoleHeight()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
	{
		return (csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
	}
	else
		return 0;
}