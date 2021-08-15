//drawing sprout in scene1 and sapling in scene2
#include <iostream>
#include <GL/glut.h>
#include "leaf.hpp"
Leaf leaf;
class Sapling
{
private:
    void drawsapling1()     //sprout in scene 1
    {
        leaf.setColor(0.13, 0.545, 0.13); //stem
        leaf.drawstem(2500, 1000, 2500, 1200);
    }
    void drawsapling2()     //sapling in scene 2
    {

        leaf.setColor(0.5f, 0.35f, 0.05f); //stem
        leaf.drawstem(2500, 1000, 2500, 1600);
        leaf.setColor(0, 0, 0); //leafline
        leaf.drawleafline(2515, 1200, 2560, 1300);
        leaf.setColor(0, 0, 0); //leafline
        leaf.drawleafline(2500, 1400, 2440, 1500);
        //glRotatef(10,0,0,1);
        leaf.setColor(0, 1, 0); //leaf
        leaf.drawleaf(2648, 1300, 100, 80, 1, false, 0, 360);

        //glRotatef(20,0,0,1);
        leaf.setColor(0, 1, 0); //leaf
        leaf.drawleaf(2355, 1500, 100, 80, 1, false, 0, 360);
	
	glPushMatrix();
	leaf.drawleaf(2560, 1675, 115, 60, 10, false, 0, 360);//top leaf
	glPopMatrix();
    }

public:
    void drawsapling1(int xpos, int ypos, float scale)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        glScalef(scale, scale, scale);
        drawsapling1();
        glPopMatrix();
    }
    void drawsapling2(int xpos, int ypos, float scale)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        glScalef(scale, scale, scale);
        drawsapling2();
        glPopMatrix();
    }
};