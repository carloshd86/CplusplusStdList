#pragma once

#include <stdlib.h>

struct TEntity;
typedef void(*funcEntity)(TEntity *);


// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	short m_ix;
	short m_iy;
	int m_vit;
	int m_symbol;
	bool m_hasSymbol;
	funcEntity *m_funcs;
	TEntity(funcEntity *funcs, short x, short y)
	{
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;
		m_vit = rand() % 100;
		m_symbol = 0;
		m_hasSymbol = false;
	}
};



/********/
void checkScreenLimits(TEntity * entity);
void spotEntity(TEntity * entity);

void setRandomMovement(TEntity * entity);
void randomPaint(TEntity * entity);
/********/
