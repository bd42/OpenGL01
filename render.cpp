#include "h/render.hpp"
#include "h/ObjectGL.hpp"

#include <math.h>

#define OBJLEN 512
ObjectGL* objects[OBJLEN];

#define OBJX 0.5f
#define OBJY 4.5f
#define OBJYHALF 2.25f
#define OBJZ 5.0f
#define OBJSIZE 0.04f

double timePassed = 0;

void render(const double deltaTime)
{
	timePassed += deltaTime;
	
	if(timePassed == 0)
	{
		for (int i = 0; i < OBJLEN; i++)
		{
			float _x = ((i % 8) - 4) * OBJX + OBJX / 2;
			float _y = (i / 8) * (OBJY / (OBJLEN / 8)) - OBJYHALF;
			objects[i] = new CubeGL(_x, _y, -OBJZ, OBJSIZE, OBJSIZE, OBJSIZE);
		}
	}

	for (int i = 0; i < OBJLEN; i++)
	{
		objects[i]->Move(0.0f, 1.0f * -deltaTime, 0.0f);
		
		while(objects[i]->GetY() < -OBJYHALF)
		{
			objects[i]->Move(0.0f, OBJY, 0.0f);
		}
	}

	for (int i = 0; i < OBJLEN; i++)
	{
		objects[i]->Draw();
	}
}
