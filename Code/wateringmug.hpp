#include <iostream>
#include <GL/glut.h>

class Wmug
{
private:
  void drawmug()
  {
    rectangle.setColor(0.443, 0.474, 0.494);
    // rectangle.setColor(1,1,0);
    rectangle.draw(500, 1000, 880, 1000, 880, 300, 500, 300, false, 0); //height:700 width:380
    rectangle.draw(880, 600, 880, 450, 1100, 800, 1100, 1000, false, 0);
    ellipse.setColor(0.443, 0.474, 0.494);
    //ellipse.setColor(1,1,0);
    ellipse.draw(1109, 880, 50, 120, 3, false, 0, 360);

    glColor3f(0, 0, 0);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex3f(1112, 810, 1);
    glVertex3f(1140, 860, 1);
    glVertex3f(1117, 950, 1);
    glVertex3f(1110, 880, 1);
    glEnd();
    circle.setColor(0, 0, 0);
    circle.drawarc(670, 650, 300, 90, 180);
    rectangle.setColor(0.9, 0.71, 0.63);
    rectangle.draw(360 - 30, 650, 360 - 30, 540, 450 - 70, 520, 450 - 70, 620, false, 0);
  }
  void drawdroplets()
  {
    glColor3f(0, 0, 1);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex3f(1244, 585, 1);
    glVertex3f(1284, 585, 1);
    glVertex3f(1284, 685, 1);
    glVertex3f(1237, 515, 1);
    glVertex3f(1273, 495, 1);
    glVertex3f(1323, 495, 1);
    glVertex3f(1245, 415, 1);
    glVertex3f(1295, 415, 1);
    glVertex3f(1345, 415, 1);
    glVertex3f(1273, 315, 1);
    glVertex3f(1355, 315, 1);
    glVertex3f(1253, 200, 1);
    glVertex3f(1293, 200, 1);
    glVertex3f(1425, 200, 1);
    glVertex3f(1356, 200, 1);
    glVertex3f(1263, 40, 1);
    glVertex3f(1333, 38, 1);
    glVertex3f(1393, 40, 1);
    glVertex3f(1463, 40, 1);
    glVertex3f(1269, -110, 1);
    glVertex3f(1333, -110, 1);
    glVertex3f(1396, -110, 1);
    glVertex3f(1475, -110, 1);
    glVertex3f(1266, -300, 1);
    glVertex3f(1363, -300, 1);
    glVertex3f(1426, -300, 1);
    glVertex3f(1505, -300, 1);
    glVertex3f(1296, -500, 1);
    glVertex3f(1393, -500, 1);
    glVertex3f(1456, -500, 1);
    glVertex3f(1535, -500, 1);
    glEnd();
  }

public:
  void drawwmug(int xpos, int ypos, float scale)
  {
    glPushMatrix();
    glTranslatef(xpos, ypos, 0);
    glScalef(scale, scale, scale);
    glRotatef(-10, 0, 0, 1);
    drawmug();
    glPopMatrix();
  }
  void drawdroplets(int xpos, int ypos, float scale)
  {
    glPushMatrix();
    glTranslatef(xpos, ypos, 0);
    glScalef(scale, scale, scale);
    drawdroplets();
    glPopMatrix();
  }
  void drawhumanwithmug(int xpos, int ypos, int hxpos, int wxpos)
  {
    glPushMatrix();
    glTranslatef(xpos, ypos, 0);
    Wmug wmug;
    wmug.drawwmug(wxpos, 1100, 1);

    Human human;
    human.drawhuman2(hxpos, 1500, 1);
    glPopMatrix();
  }
};