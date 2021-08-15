//leaf drawing with the stem ,leaf and leaf line used in sapling.hpp
#include <GL/glut.h>
class Leaf
{
private:
    float color[3];

public:
    void setColor(float r, float g, float b)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }
    void drawstem(float x1, float y1, float x2, float y2)
    {
        glLineWidth(5);
        glColor3fv(color);
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
    void drawleaf(int xCenter, int yCenter, int Rx, int Ry, int depthIndex, bool hollow, int startAngle, int stopAngle)
    {
        glPushMatrix();
        glTranslatef(xCenter, yCenter, 0);
        glRotatef(-300, 0, 0, 1);
        glColor3fv(color);
        if (hollow)
        {
            glPointSize(4);
            glBegin(GL_POINTS);
        }
        else if (!hollow)
        {

            glBegin(GL_POLYGON);
        }
        for (float i = startAngle; i <= stopAngle; i++)
        {
            float x = Rx * cos((i * 3.142) / 180);
            float y = Ry * sin((i * 3.142) / 180);
            glVertex3f(x, y, depthIndex);
        }

        glEnd();

        glPopMatrix();
    }
    void drawleafline(float x1, float y1, float x2, float y2)
    {
        glLineWidth(4);
        glColor3fv(color);
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
};