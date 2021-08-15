#include <GL/glut.h>



class Apple
{

public:
    void draw(int xpos, int ypos, float scale)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        glScalef(scale, scale, scale);
        ellipse.setColor(1,0,0);
        ellipse.draw(600, 600, 50, 70, 1, false, 0, 360);
        ellipse.draw(625, 600, 50, 70, 1, false, 0, 360);
        glColor3f(0.3,0.3,0.3);
        glLineWidth(2);
        glBegin(GL_LINES);
			glVertex2f(625,635);
			glVertex2f(625,745);
			glEnd();
        glPopMatrix();
    }
};