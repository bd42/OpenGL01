#include "h/render.hpp"
#include "h/Object.hpp"

Cube* cube = new Cube(0.0f, 0.0f, -3.0f, 1.0f, 1.0f, 1.0f);
void render(const double deltaTime)
{
	cube->Rotate(deltaTime * 90.0f, deltaTime * 60.0f, deltaTime * 30.0f);
	cube->Draw();
}
