//plant drawing with plant stem,plant line and plant in scene 3
#include <iostream>
#include <GL/glut.h>
Ellipse el;
class Plant
{
private:
	float color[3];

	void setColor(float r, float g, float b)
	{
		color[0] = r;
		color[1] = g;
		color[2] = b;
	}
	void drawplantstem(float x1, float y1, float x2, float y2)
	{
		glLineWidth(8);
		glColor3fv(color);
		glBegin(GL_LINES);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glEnd();
	}
	void drawplantline(float x1, float y1, float x2, float y2)
	{
		glLineWidth(6);
		glColor3fv(color);
		glBegin(GL_LINES);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glEnd();
	}

	void drawplant()
	{
		setColor(0.13, 0.545, 0.13);
		drawplantstem(2500, 600, 2500, 2400);
		drawplantline(2500, 1000, 2800, 1200);
		drawplantline(2500, 1300, 2200, 1500);
		drawplantline(2500, 1600, 2800, 1800);
		drawplantline(2500, 1900, 2200, 2100);
		drawplantline(2540, 1020, 2680, 965);
		drawplantline(2570, 1065, 2600, 1270);
		drawplantline(2590, 1825, 2545, 1640);
		drawplantline(2650, 1615, 2600, 1670);
		drawplantline(2450, 1340, 2340, 1280);
		drawplantline(2465, 1340, 2375, 1570);
		drawplantline(2330, 1890, 2450, 1930);
		drawplantline(2465, 1915, 2355, 2190);
		drawplantline(2500, 2200, 2600, 2270); //stem without leaf
		el.setColor(0, 1, 0);
		glPushMatrix();
		glRotatef(10, 0, 0, 1);
		el.draw(3040, 720, 80, 60, 10, false, 0, 360);	//bottom-right center leaf
		el.draw(3145, 1320, 80, 60, 10, false, 0, 360); //top-right center
		el.draw(3000, 1770, 80, 60, 10, false, 0, 360); //right-single leaf
		glPopMatrix();
		glPushMatrix();
		glRotatef(40, 0, 0, 1);
		el.draw(2880, -730, 80, 60, 10, false, 0, 360); //bottom-right up
		el.draw(3240, -260, 80, 60, 10, false, 0, 360); //top-right up
		glPopMatrix();
		glPushMatrix();
		glRotatef(-15, 0, 0, 1);
		el.draw(2400, 1650, 80, 60, 10, false, 0, 360); //bottom-right down
		el.draw(2220, 2250, 80, 60, 10, false, 0, 360); //top-right down
		glPopMatrix();
		glPushMatrix();
		glRotatef(-20, 0, 0, 1);
		el.draw(1500, 2160, 80, 60, 10, false, 0, 360); //bottom-left center
		el.draw(1290, 2740, 80, 60, 10, false, 0, 360); //top-left center
		glPopMatrix();
		glPushMatrix();
		glRotatef(30, 0, 0, 1);
		el.draw(2600, -50, 80, 60, 10, false, 0, 360); //bottom-left down
		el.draw(2890, 500, 80, 60, 10, false, 0, 360); //top-left down
		glPopMatrix();
		glPushMatrix();
		glRotatef(-35, 0, 0, 1);
		el.draw(980, 2650, 80, 60, 10, false, 0, 360); //bottom-left up
		el.draw(600, 3150, 80, 60, 10, false, 0, 360); //top-left up
		glPopMatrix();
		el.draw(2500, 2470, 35, 150, 10, false, 0, 360); //topmost leaf
	}

public:
	void drawplant(int xpos, int ypos, float scale)
	{
		glPushMatrix();
		glTranslatef(xpos, ypos, 0);
		glScalef(scale, scale, scale);
		drawplant();
		glPopMatrix();
	}
};