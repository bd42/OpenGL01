#include "h/render.hpp"
#include "h/Object.hpp"

#include <math.h>

#define CUBE_X 0.5f
#define CUBE_Y_LIMIT 2.0f
#define CUBE_Z -4.0f
#define CUBE_LENGTH 0.25f

const float startY[8] = { -2.0f, -1.5f, -1.0f, -0.5f, 0.0f, 0.5f, 1.0f, 1.5f };

Cube* cubes[16] =
{
	new Cube(-CUBE_X, startY[0], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(-CUBE_X, startY[1], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(-CUBE_X, startY[2], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(-CUBE_X, startY[3], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(-CUBE_X, startY[4], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(-CUBE_X, startY[5], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(-CUBE_X, startY[6], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(-CUBE_X, startY[7], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(CUBE_X, startY[0], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(CUBE_X, startY[1], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(CUBE_X, startY[2], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(CUBE_X, startY[3], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(CUBE_X, startY[4], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(CUBE_X, startY[5], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(CUBE_X, startY[6], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH),
	new Cube(CUBE_X, startY[7], CUBE_Z, CUBE_LENGTH, CUBE_LENGTH, CUBE_LENGTH)
};

bool firstRun = true;
float timePassed = 0.0f;

void render(const double deltaTime)
{
	if(firstRun)
	{
		for(int i = 0; i < 16; i++)
		{
			cubes[i]->SetColor(0.8f, 1.0f, 0.8f);
		}
		firstRun = false;
	}

	timePassed += deltaTime;

	for (int i = 0; i < 8; i++)
	{
		if(cubes[i]->GetY() < -CUBE_Y_LIMIT)
			cubes[i]->SetPosition(-CUBE_X, CUBE_Y_LIMIT, CUBE_Z);
		else
			cubes[i]->Move(sinf(timePassed) * 0.005f, -deltaTime, cosf(timePassed) * 0.005f);

		cubes[i]->Rotate(deltaTime * 90.0f * i, deltaTime * 60.0f * i, deltaTime * 30.0f * i);
		cubes[i]->Draw();
	}
	for (int i = 8; i < 16; i++)
	{
		if(cubes[i]->GetY() < -CUBE_Y_LIMIT)
			cubes[i]->SetPosition(CUBE_X, CUBE_Y_LIMIT, CUBE_Z);
		else
			cubes[i]->Move(-sinf(timePassed) * 0.005f, -deltaTime, -cosf(timePassed) * 0.005f);

		cubes[i]->Rotate(deltaTime * -90.0f * i, deltaTime * -60.0f * i, deltaTime * -30.0f * i);
		cubes[i]->Draw();
	}
}
