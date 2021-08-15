//to display message in the ellipse
#include <GL/glut.h>
class Message{
     public:
    void drawtext(float x, float y, char *s)
    {
        glColor3f(0, 0, 0);
        glRasterPos2f(x, y);
        for (int i = 0; s[i] != '\0'; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
    }
   
    void displaymessage(int xpos, int ypos, char *line,int xlen,int ylen,bool flag)
    {
        if(flag){
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        Ellipse ellipse;
        ellipse.setColor(1, 1, 1);
        ellipse.draw(680, 400, xlen, ylen, 1, false, 0, 360);
        drawtext(300, 390, line);
        
        glPopMatrix();
        
        }
    }

};