#include <iostream>
#include <GL/glut.h>
#include "circle.hpp"
#include "rectangle.hpp"
#include "ellipse.hpp"
Circle circle;
Rectangle rectangle;
Ellipse ellipse;
class Human
{
private:
    void drawhat()
    {
        circle.setColor(0, 0, 0);
        circle.draw(200, 505, 600, 1, false, 0, 180);
        ellipse.setColor(0, 0, 0);
        ellipse.draw(1000, 1200, 300, 50, 3, false, 0, 360);
    }
    void drawface()
    {

        ellipse.setColor(0.9, 0.71, 0.63);
        ellipse.draw(1000, 1000, 200, 300, 3, false, 0, 360);

        //circle.draw(100, 750, 2000, 2, false, 0, 180);
    }
    void draweyes()
    {
        circle.setColor(0, 0, 0);
        circle.draw(17, 462, 520, 1, false, 0, 360);
        circle.draw(17, 552, 520, 1, false, 0, 360);
        circle.setColor(1.0, 1.0, 1.0);
        circle.draw(32, 462, 520, 1, false, 0, 360);
        circle.draw(32, 552, 520, 1, false, 0, 360);
    }
    void drawnose()
    {
        circle.setColor(1.0, 0.86, 0.69);
        circle.draw(25, 505, 480, 1, false, 0, 360);
    }
    void drawmouth()
    {
        circle.setColor(1, 1, 1);
        //circle.drawarc(505,440,20,0,36);
        circle.draw(50, 250, 1900, 1, false, 180, 360);
        circle.draw(80, 505, 440, 1, false, 180, 360);
    }
    void drawears()
    {

        circle.setColor(0.9, 0.71, 0.63);
        circle.draw(70, 420, 520, 4, false, 0, 360);

        circle.setColor(0.9, 0.71, 0.63);
        circle.draw(70, 580, 520, 4, false, 0, 360);
    }
    void drawshirt()
    {
        rectangle.setColor(0.9, 0.71, 0.63);
        rectangle.draw(480 + 480, 420 + 300, 590 + 480, 420 + 300, 1070, 610, 960, 610, false, 0);
        circle.setColor(0.0, 0.0, 0.0);
        circle.draw(90, 508, 320, 1, false, 180, 360);
        rectangle.setColor(0.27, 0.509, 0.70);
        rectangle.draw(820, 600, 900 + 300, 600, 900 + 300, 0, 820, 0, false, 0);
    }
    void drawhands1()
    {
        //hands
        rectangle.setColor(0.27, 0.509, 0.70);
        rectangle.draw(820, 600, 820, 200, 800, 100, 700, 90, false, 0);
        rectangle.setColor(0.27, 0.509, 0.70);
        rectangle.draw(900 + 300, 600, 900 + 300, 200, 1220, 100, 1320, 90, false, 0);
        //palms
        rectangle.setColor(0.9, 0.71, 0.63);
        rectangle.draw(780, 100, 720, 90, 710, 20, 790, 20, false, 0);
        rectangle.setColor(0.9, 0.71, 0.63);
        rectangle.draw(1240 + 20, 200, 1220, 20, 1310, 20, 1280 + 20, 90, false, 0);
    }
    void drawhands2()
    {
        //left hand
        rectangle.setColor(0.27, 0.509, 0.70);
        rectangle.draw(820, 600, 820, 300, 760, 140, 700, 90, false, 0);
        rectangle.draw(760, 240, 700, 90, 900, 160, 900, 110, false, 0);
        rectangle.setColor(0, 0, 0);
        //rectangle.setColor(0.9, 0.71, 0.63);
        rectangle.draw(1000, 200, 960, 20, 1050, 20, 1040, 90, false, 0);
        //right hand
        rectangle.setColor(0.27, 0.509, 0.70);
        rectangle.draw(900 + 300, 600, 900 + 300, 200, 1220, 100, 1320, 90, false, 0);
    }
    void drawpant()
    {
        rectangle.setColor(0.0, 0.0, 0.0);
        rectangle.draw(400 + 420, 10, 500 + 520, 10, 500 + 520 - 1, -400, 400 + 420, -400, false, 0);
        rectangle.setColor(0.0, 0.0, 0.0);
        rectangle.draw(500 + 520, 10, 500 + 520 + 180, 10, 500 + 520 + 180, -400, 500 + 520 + 1, -400, false, 0);
    }
    void drawlegs()
    {
        rectangle.setColor(0.9, 0.71, 0.63);
        rectangle.draw(400 + 450, -400, 500 + 520 - 40, -400, 500 + 520 - 40, -850, 400 + 450, -850, false, 0);
        rectangle.setColor(0.9, 0.71, 0.63);
        rectangle.draw(500 + 550, -400, 500 + 520 + 180 - 30, -400, 500 + 520 + 180 - 30, -850, 500 + 550, -850, false, 0);
    }
    void drawshoe()
    {
        rectangle.setColor(0.27, 0.509, 0.70);
        rectangle.draw(400 + 450, -850, 500 + 520 - 40, -850, 500 + 520 - 40, -1020, 400 + 450, -1020, false, 0);
        circle.setColor(0.27, 0.509, 0.70);
        circle.draw(84, 482, -470, 1, false, 0, 360);

        rectangle.setColor(0.27, 0.509, 0.70);
        rectangle.draw(500 + 550, -850, 500 + 520 + 180 - 30, -850, 500 + 520 + 180 - 30, -1020, 500 + 550, -1020, false, 0);
        circle.setColor(0.27, 0.509, 0.70);
        circle.draw(84, 575, -470, 1, false, 0, 360);
    }
    

public:
    void drawhuman1(int xpos, int ypos, float scale)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        glScalef(scale, scale, scale);
        drawhat();
        drawface();

        draweyes();
        drawears();

        drawnose();
        drawshirt();
        drawhands1();
        drawpant();
        drawlegs();
        drawshoe();
        drawmouth();
        // drawshirt();

        glPopMatrix();
    }
    void drawhuman2(int xpos, int ypos, float scale)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        glScalef(scale, scale, scale);
        drawhat();
        drawface();

        draweyes();
        drawears();

        drawnose();
        drawshirt();
        drawhands2();
        drawpant();
        drawlegs();
        drawshoe();
        drawmouth();
        // drawshirt();

        glPopMatrix();
    }
    // void drawsun(int xpos, int ypos, float scale){
    //      glPushMatrix();
         
    //     glTranslatef(xpos, ypos, 0);
    //     glScalef(scale, scale, scale);
    //     drawsun();
    //     glPopMatrix();
    // }
void drawDisk(double radius)
{
    int d;
    glBegin(GL_POLYGON);
    for (d = 0; d < 32; d++)
    {
        double angle = 2 * M_PI / 32 * d;
        glVertex2d(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}
void drawsun(){
    // Circle circle;
    // circle.setColor(0.98, 0.83, 0.25);
    // circle.draw(200, 950, 2300, 1, false, 0, 360);
     int i;
    glColor3f(0.98, 0.83, 0.25);
    glLineWidth(3.0f);
    for (i = 0; i < 13; i++)
    {                                 // Draw 13 rays, with different rotations.
        glRotatef(360 / 13, 0, 0, 1); // Note that the rotations accumulate!
        glBegin(GL_LINES);
        glVertex2f(0, 0);
        glVertex2f(370, 0);
        glEnd();
    }
    glLineWidth(1.0f);
    drawDisk(180);
    glColor3f(0, 0, 0);
    
}




};
