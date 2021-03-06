// Practica20CarlosHD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "entities.h"
#include "consola.h"
#include <list>

int main()
{
	std::list<TEntity *> lstEntities;
	funcEntity entityFunctions[2] = { setRandomMovement, randomPaint };
	const int MIN_ENTITIES = 5;
	int i = 0;
	short initialX = 0;
	short initialY = 0;

	while (i < 500)
	{
		clear();
		while (lstEntities.size() < MIN_ENTITIES)
		{
			// Console dimensions may change each time an entity is generated
			initialX = rand() % getConsoleWidth();
			initialY = rand() % getConsoleHeight();

			TEntity * entityToAdd = new TEntity(entityFunctions, initialX, initialY);
			lstEntities.push_front(entityToAdd);
		}

		std::list<TEntity *>::iterator it = lstEntities.begin();
		while (it != lstEntities.end())
		{
			TEntity * currentEntity = *it;
			currentEntity->m_funcs[0](currentEntity);
			currentEntity->m_funcs[1](currentEntity);

			currentEntity->m_vit--;
			if (!currentEntity->m_vit)
			{
				delete currentEntity;
				it = lstEntities.erase(it);
			}
			else
				++it;
		}

		i++;
		Sleep(100);
	}

	std::list<TEntity *>::iterator itDelete = lstEntities.begin();
	while (itDelete != lstEntities.end())
	{
		delete (*itDelete);
		lstEntities.erase(itDelete++);
	}

	return 0;
}

