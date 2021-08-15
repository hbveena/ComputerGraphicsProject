#include <GL/glut.h>
#include <math.h>
class Circle
{
private:
    int depthIndex;
    float color[3];
public:
    void setColor(float r, float g, float b)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }
    
    void drawarc(float x,float y,float radius,float rot,float sweep){
        int n=200;
        double angle=rot*3.141592/180;
        double angleinc=sweep*3.141592/(180*n);
        glLineWidth(5);
        glBegin(GL_LINE_STRIP);
        for(int i=0;i<n;i++){
            glVertex2f(radius*cos(angle)+x,radius*sin(angle)+y);
            angle+=angleinc;
        }
        glEnd();
        //glFlush();
    }
    void draw(int r, float xpos, float ypos, int depthIndex, bool hollow, int startAngle, int endAngle)
    {
        this->depthIndex = depthIndex;
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        glColor3fv(color);
        if (!hollow)
            glBegin(GL_POLYGON);
        else
{
            glPointSize(5);
            glBegin(GL_POINTS);
        }
        for (int i = startAngle; i <endAngle; i++)
        {   float theta=i*3.142/180;

            float x = r * cos((i * 3.142) / 180);
            float y = r * sin((i * 3.142) / 180);
            glVertex3f(xpos+x,ypos+y, depthIndex);
        }
        glEnd();
        glPopMatrix();
    }
};