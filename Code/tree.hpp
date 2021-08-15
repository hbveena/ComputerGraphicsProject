//Tree drawing in scene 4
#include <iostream>
#include <GL/glut.h>
#include "triangle.hpp"
Rectangle rec;
Ellipse elli;
Triangle triangle;
class Tree
{
private:
	void drawtree()
	{

		triangle.setColor(0.5f, 0.35f, 0.05f);
		triangle.draw(2700, 1900, 2700, 2500, 2600, 2500, 1);
		triangle.draw(2600, 500, 2700, 500, 2700, 1100, 1);
		triangle.draw(3100, 500, 3000, 500, 3000, 1100, 1);
		triangle.draw(3000, 1900, 3000, 2500, 3100, 2500, 1);

		rec.setColor(0.5f, 0.35f, 0.05f);
		rec.draw(2700, 500, 3000, 500, 3000, 2500, 2700, 2500, false, 0);
		elli.setColor(0.0, 1.0f, 0.0f);
		elli.draw(2600, 2500, 200, 200, 10, false, 0, 360);
		elli.draw(2800, 2500, 200, 200, 10, false, 0, 360);
		elli.draw(3000, 2500, 200, 200, 10, false, 0, 360);

		elli.setColor(0.0, 1.0f, 0.0f);
		elli.draw(2400, 2800, 300, 300, 10, false, 0, 360);
		elli.draw(2600, 2800, 300, 300, 10, false, 0, 360);
		elli.draw(2800, 2800, 300, 300, 10, false, 0, 360);
		elli.draw(3000, 2800, 300, 300, 10, false, 0, 360);
		elli.draw(3200, 2800, 300, 300, 10, false, 0, 360);

		elli.draw(2200, 3100, 300, 300, 10, false, 0, 360);
		elli.draw(2600, 3100, 300, 300, 10, false, 0, 360);
		elli.draw(2800, 3100, 300, 300, 10, false, 0, 360);
		elli.draw(3000, 3100, 300, 300, 10, false, 0, 360);
		elli.draw(3200, 3100, 300, 300, 10, false, 0, 360);
		elli.draw(3400, 3100, 300, 300, 10, false, 0, 360);

		elli.draw(2000, 3400, 300, 330, 10, false, 0, 360);
		elli.draw(2200, 3400, 300, 300, 10, false, 0, 360);
		elli.draw(2600, 3400, 300, 300, 10, false, 0, 360);
		elli.draw(2800, 3400, 300, 300, 10, false, 0, 360);
		elli.draw(3000, 3400, 300, 300, 10, false, 0, 360);
		elli.draw(3200, 3400, 300, 300, 10, false, 0, 360);
		elli.draw(3400, 3400, 300, 300, 10, false, 0, 360);
		elli.draw(3600, 3400, 300, 330, 10, false, 0, 360);

		elli.draw(2200, 3700, 300, 300, 10, false, 0, 360);
		elli.draw(2600, 3700, 300, 300, 10, false, 0, 360);
		elli.draw(2800, 3700, 300, 300, 10, false, 0, 360);
		elli.draw(3000, 3700, 300, 300, 10, false, 0, 360);
		elli.draw(3200, 3700, 300, 300, 10, false, 0, 360);
		elli.draw(3400, 3700, 300, 300, 10, false, 0, 360);

		elli.draw(2400, 4000, 300, 300, 10, false, 0, 360);
		elli.draw(2600, 4000, 300, 300, 10, false, 0, 360);
		elli.draw(2800, 4000, 300, 300, 10, false, 0, 360);
		elli.draw(3000, 4000, 300, 300, 10, false, 0, 360);
		elli.draw(3200, 4000, 300, 300, 10, false, 0, 360);

		//elli.draw(2400,2900,300,300,10,false,0,360);
		elli.draw(2600, 4300, 300, 350, 10, false, 0, 360);
		elli.draw(2800, 4300, 300, 310, 10, false, 0, 360);
		elli.draw(3000, 4300, 300, 350, 10, false, 0, 360);
		//elli.draw(3200,2900,300,300,10,false,0,360);
	}

public:
	void drawtree(float xpos, float ypos, float scale)
	{
		glPushMatrix();
		glTranslatef(xpos, ypos, 0);
		glScalef(scale, scale, scale);
		drawtree();
		glPopMatrix();
	}
};