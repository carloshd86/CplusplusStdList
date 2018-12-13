#include "stdafx.h"
#include "entities.h"
#include "consola.h"



void checkScreenLimits(TEntity * entity)
{
	short screenOffsetX;
	short screenOffsetY;
	const short consoleWidth = getConsoleWidth();
	const short consoleHeight = getConsoleHeight();
	if ((*entity).m_ix >= 0)
	{
		screenOffsetX = consoleWidth - (*entity).m_ix;
		if (screenOffsetX <= 0)
			(*entity).m_ix = screenOffsetX * -1;
	}
	else
	{
		screenOffsetX = (*entity).m_ix + consoleWidth;
		if (screenOffsetX >= 0)
			(*entity).m_ix = screenOffsetX;
	}

	if ((*entity).m_iy >= 0)
	{
		screenOffsetY = consoleHeight - (*entity).m_iy;
		if (screenOffsetY <= 0)
			(*entity).m_iy = screenOffsetY * -1;
	}
	else
	{
		screenOffsetY = (*entity).m_iy + consoleHeight;
		if (screenOffsetY >= 0)
			(*entity).m_iy = screenOffsetY;
	}
}

void spotEntity(TEntity * entity)
{
	gotoxy((*entity).m_ix, (*entity).m_iy);
	hidecursor();
}


/************* Random *************/
void setRandomMovement(TEntity * entity)
{
	short randomX = rand() % 5;
	short randomY = rand() % 5;

	(*entity).m_ix += randomX;
	(*entity).m_iy += randomY;
	checkScreenLimits(entity);
}

void randomPaint(TEntity * entity)
{
	spotEntity(entity);
	if (!entity->m_hasSymbol)
	{
		int randomNumber = rand() % 100;
		entity->m_symbol = randomNumber;
		entity->m_hasSymbol = true;
	}
	printf("%d", entity->m_symbol);
}
/*****************************/