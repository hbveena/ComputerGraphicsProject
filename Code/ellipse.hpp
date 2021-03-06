#include <GL/glut.h>
#include <math.h>
class Ellipse
{
private:
    float color[4];
    int depthIndex;

public:
    void setColor(float r, float g, float b)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;
        //color[3]=1;
    }
    // void setColor(float r, float g, float b,float a)
    // { color[0] = r;
    //     color[1] = g;
    //     color[2] = b;
    //     color[3]=a;

    // }
    void draw(int xCenter, int yCenter, int Rx, int Ry, int depthIndex, bool hollow, int startAngle, int stopAngle)
    {
        glPushMatrix();
        glTranslatef(xCenter, yCenter, 0);
        glColor3fv(color);
       // glColor4fv(color);
        if (hollow)
        {
            glPointSize(4);
            glBegin(GL_POINTS);
        }
        else if (!hollow)
            glBegin(GL_POLYGON);
        for (float i = startAngle; i <= stopAngle; i++)
        {
            float x = Rx * cos((i * 3.142) / 180);
            float y = Ry * sin((i * 3.142) / 180);
            glVertex3f(x, y, depthIndex);
        }
        glEnd();
        glPopMatrix();
    }

    void draw(int xCenter, int yCenter, int Rx, int Ry, int depthIndex, bool hollow, int startAngle, int stopAngle, int lw)
    {
        glPushMatrix();
        glTranslatef(xCenter, yCenter, 0);
        glColor3fv(color);
        if (hollow)
        {
            glPointSize(lw);
            glBegin(GL_POINTS);
        }
        else if (!hollow)
            glBegin(GL_POLYGON);
        for (float i = startAngle; i <= stopAngle; i++)
        {
            float x = Rx * cos((i * 3.142) / 180);
            float y = Ry * sin((i * 3.142) / 180);
            glVertex3f(x, y, depthIndex);
        }
        glEnd();
        glPopMatrix();
    }
};