#include <iostream>
#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "human.hpp"
#include "wateringmug.hpp"
#include "tree.hpp"
#include "sapling.hpp"
#include "plant.hpp"
#include "apple.hpp"
#include "message.hpp"
#define SPACEBAR 32
#define ENTER 13
void timer(int value);
bool humanmovement = true;
bool watering = false;
bool tree1 = false;
bool tree2 = false;
bool tree3 = false;
bool dismsg = false;
bool flag = true;
unsigned int intro, bg1, intro1, moral;
int scene = 0;
int framenumber = 0;
int count = 0;
int hxpos = 10;
int wxpos;
int hwxpos = 10;
int aypos = 2600;
int aypos1 = 2700;
int aypos2 = 3600;
int aypos3 = 2500;
int aypos4 = 3400;
int aypos5 = 3000;
int apple = 0;
Message message;
Human human;
//first introduction page
void loadIntro(void)
{
    glGenTextures(1, &intro);
    glBindTexture(GL_TEXTURE_2D, intro);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    stbi_set_flip_vertically_on_load(true);
    int width, height, nrChannels;
    unsigned char *data = stbi_load("intropage56.png", &width, &height, &nrChannels, STBI_rgb_alpha);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    else
    {
        std::cout << "Failed to load front page" << std::endl;
    }
    stbi_image_free(data);
}
//second summary page
void loadIntro1(void)
{
    glGenTextures(1, &intro1);
    glBindTexture(GL_TEXTURE_2D, intro1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    stbi_set_flip_vertically_on_load(true);
    int width, height, nrChannels;
    unsigned char *data = stbi_load("secondpage.png", &width, &height, &nrChannels, STBI_rgb_alpha);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    else
    {
        std::cout << "Failed to load front page" << std::endl;
    }
    stbi_image_free(data);
}
//background
void loadbackground1(void)
{
    glGenTextures(1, &bg1);
    glBindTexture(GL_TEXTURE_2D, bg1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    stbi_set_flip_vertically_on_load(true);
    int width, height, nrChannels;
    unsigned char *data = stbi_load("bg1.png", &width, &height, &nrChannels, STBI_rgb_alpha);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    else
    {
        std::cout << "Failed to load bg1" << std::endl;
    }
    stbi_image_free(data);
}
//moral page
void loadmoral(void)
{
    glGenTextures(1, &moral);            //change
    glBindTexture(GL_TEXTURE_2D, moral); //change
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    stbi_set_flip_vertically_on_load(true);
    int width, height, nrChannels;
    unsigned char *data = stbi_load("moral.png", &width, &height, &nrChannels, STBI_rgb_alpha);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    else
    {
        std::cout << "Failed to load front page" << std::endl;
    }
    stbi_image_free(data);
}
void doFrame(int v)
{
    framenumber++;
    glutPostRedisplay();
    glutTimerFunc(30, doFrame, 0);
}
//drawing wind mill
void drawWindmill()
{
    glPushMatrix();
    glTranslatef(500, 3900, 1);
    int i;

    glTranslatef(0, 3, 0);
    glRotated(framenumber * (180.0 / 46), 0, 0, 1);
    glColor3f(0.75f, 0.6f, 0.41f);
    for (i = 0; i < 3; i++)
    {
        glRotated(120, 0, 0, 1); // Note: These rotations accumulate.
        glBegin(GL_POLYGON);
        glVertex2f(10, 10);
        glVertex2f(200, 90);
        glVertex2f(600, 10);
        glVertex2f(200, -70);
        glEnd();
    }
    glPopMatrix();
    glPushMatrix();
    glTranslatef(500, 3900, 1);
    glColor3f(0.52f, 0.36f, 0.25f);
    glBegin(GL_POLYGON);
    glVertex2f(50, -1200);
    glVertex2f(-20, -1200);
    glVertex2f(-20, 20);
    glVertex2f(50, 20);
    glEnd();
    glPopMatrix();
}
//displaying the scenel
void displayscene1()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    human.drawhuman1(hxpos, 1500, 1);
    message.drawtext(10, 4700, "CLICK SPACEBAR TO CHANGE THE SCENE");
    drawWindmill();
    //draw sun
    glPushMatrix();
    glTranslatef(1850, 4610, 1);
    glRotated(-framenumber * 0.2, 0, 0, 1);
    human.drawsun();
    glPopMatrix();
    //draw seed
    circle.setColor(0.627, 0.321, 0.176);
    circle.draw(25, 1200, 300, 2, false, 0, 360);
    //sapling
    if (dismsg)
    {
        message.displaymessage(1500, 2800, "Let me water the plant!", 500, 300, true);
    }

    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);

    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, bg1);

    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();
}
void secondpage()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);

    glColor3f(1, 1, 1);
    if (scene == 5)
    {
        glBindTexture(GL_TEXTURE_2D, intro1);
    }
    else if (scene == 6)
    {
        glBindTexture(GL_TEXTURE_2D, moral); //change
    }

    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();
}
void displaywatermug()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawWindmill();
    message.drawtext(10, 4700, "CLICK SPACEBAR TO CHANGE THE SCENE");
    Wmug wmug;
    Human human;
    Tree tree;
    Apple apple;
    if (scene == 2 || scene == 3)
    {    //draw sun
    glPushMatrix();
    glTranslatef(1850, 4610, 1);
    glRotated(-framenumber * 0.2, 0, 0, 1);
    human.drawsun();
    glPopMatrix();
        wmug.drawhumanwithmug(hwxpos, 0, 10, 410);
    }
    else if (scene == 4)
    {
       
        human.drawhuman1(hxpos, 1600, 1.02);
        tree.drawtree(-350, 110, 1);
        apple.draw(1000, aypos5, 1); //3000
        apple.draw(1290, aypos, 1);
        apple.draw(1500, aypos2, 1); //3600
        apple.draw(2100, 3600, 1);
        apple.draw(2150, aypos3, 1); //2500
        apple.draw(2600, aypos1, 1); //2700
        apple.draw(2400, aypos4, 1); //3400
        apple.draw(1800, 2900, 1);   //2900
        ellipse.setColor(0.54, 0.474, 0.364);
        ellipse.draw(2350, 550, 1200, 400, 1, false, 0, 360);
    }
    else
    {

        wmug.drawwmug(1000, 1100, 1);
        human.drawhuman2(hxpos, 1500, 1);
    }

    Plant plant;
    if (watering)
    {
        wmug.drawdroplets(1000, 1100, 1);
    }
    if (tree1)
    {
        Sapling sapling;
        sapling.drawsapling1(-100, -390, 1);
        flag = true;
    }
    if (tree2)
    {
        Sapling sapling;
        sapling.drawsapling2(-100, -390, 1);
        flag = true;
    }
    if (tree3)
    {
        plant.drawplant(-100, -30, 1);
    }

    if (scene == 3)
    {
        glPushMatrix();

        //glTranslatef(1800, 3800, 0);
        glTranslatef(2400, 3800, 0);
        ellipse.setColor(0.77, 0.97, 0.427);
        ellipse.draw(680, 400, 1000, 700, 1, false, 0, 360);
        message.drawtext(0, 550, "Trees and shrubs improve soil and water");
        message.drawtext(-200, 420, "conservation,moderate local climate by providing shade,");
        message.drawtext(-200, 290, "regulate temperature extremes, increase wildlife habitat");
        message.drawtext(0, 160, "and improve the land's capacity to adapt ");
        message.drawtext(100, 30, " to climate change.");

        glPopMatrix();
    }

    //draw seed
    circle.setColor(0.627, 0.321, 0.176);
    circle.draw(25, 1200, 300, 2, false, 0, 360);
    if (dismsg)
    {
        switch (count)
        {
        case 1:
            if (scene == 1)
            {
                if (tree1)
                {
                    message.displaymessage(2500, 500, "The seed grows to Sprout!!", 600, 300, flag);
                    glutTimerFunc(8000, timer, 0);
                    
                }
                else
                {
                    message.displaymessage(2500, 1100, "  After few days...", 400, 300, flag);
                    glutTimerFunc(8000, timer, 0);
                   
                }
                break;
            }

        case 2:
            if (scene == 2)
            {
                if (tree2)
                {
                    ellipse.setColor(1, 1, 1);
                    ellipse.draw(3100, 1900, 550, 300, 1, false, 0, 360);
                    message.drawtext(2750, 1980, "After few weeks, the ");
                    message.drawtext(2700, 1830, "sprout grows to sapling");
                    glutTimerFunc(10000, timer, 0);
                    flag = false;
                }
                else if (!watering && scene == 2)
                {
                    ellipse.setColor(1, 1, 1);
                    ellipse.draw(2000, 3300, 700, 300, 1, false, 0, 360);
                    message.drawtext(1470, 3300, "Ohh!!! let me water the plant again");
                    glutTimerFunc(4000, timer, 0);
                    humanmovement = true;
                    flag = false;
                }
            }
            break;
        case 3:
            if (scene == 3)
            {
                flag = true;
                ellipse.setColor(1, 1, 1);
                ellipse.draw(3400, 1700, 550, 300, 1, false, 0, 360);
                message.drawtext(3150, 1780, "After few months, the ");
                message.drawtext(3000, 1630, "sapling grows to a plant");
                glutTimerFunc(10000, timer, 0);
                flag = false;

                break;
            }
        case 4:
            if (scene == 4)
            {
                flag = true;
                message.displaymessage(3000, 1000, "Tree provides shade", 500, 300, flag);
                glutTimerFunc(5000, timer, 0);
                flag = false;
            }
            break;
        case 5:
            if (scene == 4)
            {
                flag = true;
                message.displaymessage(100, 2000, "Tree provides food", 500, 300, flag);
                glutTimerFunc(5000, timer, 0);
                flag = false;
            }
            break;
        case 6:
            if (scene == 4)
            {
                flag = true;
                message.displaymessage(3200, 3800, "Tree provides oxygen", 500, 300, flag);
                glutTimerFunc(5000, timer, 0);
                flag = false;
            }
            break;

        default:
            // count--;
            break;
        }
    }
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, bg1);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();
}
void movehuman()
{
    if (humanmovement)
    {
        if (hxpos <= 500)
        {
            hxpos += 5;
            glutPostRedisplay();
        }
        else
        {
            humanmovement = false;
        }
    }
}
void applefall()
{
    while (aypos >= 1100)
    {
        aypos -= 30;

        if (aypos < 1100)
        {
            apple = 1;
            break;
        }
        glutPostRedisplay();
    }
}

void applefall1()
{
    while (aypos1 >= 100)
    {
        aypos1 -= 30;

        if (aypos1 < 100)
        {
            apple = 2;
            break;
        }
        glutPostRedisplay();
    }
}
void applefall2()
{
    while (aypos2 >= 100)
    {
        aypos2 -= 30;

        if (aypos2 < 100)
        {
            apple = 3;
            break;
        }
        glutPostRedisplay();
    }
}
void applefall3()
{
    while (aypos3 >= 100)
    {
        aypos3 -= 30;

        if (aypos3 < 100)
        {
            apple = 4;
            break;
        }
        glutPostRedisplay();
    }
}
void applefall4()
{
    while (aypos4 >= 100)
    {
        aypos4 -= 30;

        if (aypos4 < 100)
        {
            apple = 5;
            break;
        }
        glutPostRedisplay();
    }
}
void applefall5()
{
    while (aypos5 >= 100)
    {
        aypos5 -= 30;

        if (aypos5 < 100)
        {
            apple = 6;
            break;
        }
        glutPostRedisplay();
    }
}

void movehumanwithmug()
{
    if (humanmovement)
    {
        if (hwxpos <= 600)
        {
            // hxpos += 5;
            hwxpos += 5;
            glutPostRedisplay();
        }
    }
    else
    {
        humanmovement = false;
    }
}
void idleplant(int value)
{
    tree1 = true;
    //flag=true;
    glutDisplayFunc(displaywatermug);
    glutPostRedisplay();
}
void idleplant1(int value)
{
    tree1 = false;
    tree2 = true;
    glutDisplayFunc(displaywatermug);
    glutPostRedisplay();
}
void idleplant2(int value)
{
    tree1 = false;
    tree2 = false;
    tree3 = true;
    glutDisplayFunc(displaywatermug);
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    if (scene == 0)
    {
        if (key == SPACEBAR)
        {
            scene = 5;
            glutDisplayFunc(secondpage);

            glutPostRedisplay();
        }
    }
    else if (scene == 5)
    {
        if (key == SPACEBAR)
        {
            scene = 1;
            glutDisplayFunc(displayscene1);

            glutPostRedisplay();
        }
    }
    else if (scene == 1)
    {
        if (key == ENTER)
        {
            if (humanmovement)
            {
                //glutDisplayFunc(displayseed);
                glutIdleFunc(movehuman);

                glutPostRedisplay();
            }
            else
            {
                if (dismsg)
                {
                    wxpos = 1000;
                    glutDisplayFunc(displaywatermug);
                    dismsg = false;
                    glutPostRedisplay();
                }
            }
        }
        else if (key == SPACEBAR)
        {
            scene += 1;
            dismsg = false;
            watering = false;
            glutDisplayFunc(displaywatermug);
            glutPostRedisplay();
        }
    }
    else if (scene == 2)
    {
        if (key == ENTER)
        {
            if (true)
            {
                flag = false;
                dismsg = true;

                glutIdleFunc(movehumanwithmug);

                glutPostRedisplay();
            }
            else
            {
                if (dismsg)
                {

                    glutDisplayFunc(displaywatermug);
                    dismsg = false;
                    glutPostRedisplay();
                }
            }
        }

        else if (key == SPACEBAR)
        {
            humanmovement = false;
            watering = false;
            scene += 1;
            hwxpos = 540;
            tree3 = true;
            tree2 = false;
            glutDisplayFunc(displaywatermug);
            glutPostRedisplay();
        }
    }
    else if (scene == 3)
    {
        dismsg = false;
        if (key == ENTER)
        {
            flag = false;
            dismsg = true;
            glutDisplayFunc(displaywatermug);
            glutPostRedisplay();
        }

        else if (key == SPACEBAR)
        {
            scene += 1;
            hxpos = 540;
            tree2 = false;
            tree3 = false;
            watering = false;
            glutDisplayFunc(displaywatermug);
            glutPostRedisplay();
        }
    }
    else if (scene == 4)
    {
        if (key == ENTER)
        {
            if (apple == 0)
            {
                glutIdleFunc(applefall);

                glutPostRedisplay();
            }
            if (apple == 1)
            {
                glutIdleFunc(applefall1);

                glutPostRedisplay();
            }
            if (apple == 2)
            {
                glutIdleFunc(applefall2);

                glutPostRedisplay();
            }
            if (apple == 3)
            {
                glutIdleFunc(applefall3);

                glutPostRedisplay();
            }
            if (apple == 4)
            {
                glutIdleFunc(applefall4);

                glutPostRedisplay();
            }
            if (apple == 5)
            {
                glutIdleFunc(applefall5);

                glutPostRedisplay();
            }
        }
        else if (key == SPACEBAR)
        {
            scene = 6;
            glutDisplayFunc(secondpage);
            glutPostRedisplay();
        }
    }
    else if (scene == 6)
    {
        exit(0);
    }
}
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (scene == 1)
        {
            dismsg = true;
            count = 1;
        }
        else if (scene == 2)
        {
            dismsg = true;
            count = 2;
        }
        else if (scene == 3)
        {
            dismsg = true;
            count = 3;
        }
        else if (scene == 4)
        {
            dismsg = true;
            count++;
        }
        glutPostRedisplay();
    }
}

void init(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 5000, 0, 5000, 0, -500);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1, 1, 1, 1);
}
void displayIntro()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, intro);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void timer(int value)
{
    glutPostRedisplay();
}
void menuoptions(int option)
{
    switch (option)
    {

    case 1:
        watering = true;
        glutDisplayFunc(displaywatermug);
        if (scene == 1)
        {
            glutTimerFunc(8000, idleplant, 0);
        }
        else if (scene == 2)
        {
            glutTimerFunc(5000, idleplant1, 0);
        }
        glutPostRedisplay();
        break;
    case 2:
        watering = false;
        glutDisplayFunc(displaywatermug);
        glutPostRedisplay();

        break;

    case 3:
        exit(0);
        break;
    }
}
void menu(void)
{
    int menu;
    menu = glutCreateMenu(menuoptions);
    glutAddMenuEntry("start Watering", 1);
    glutAddMenuEntry("stop Watering", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1280, 640);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Gift of nature- Trees");
    glutDisplayFunc(displayIntro);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    loadIntro();
    loadIntro1();
    loadbackground1();
    loadmoral();
    glutTimerFunc(500, timer, 0);
    glutTimerFunc(200, doFrame, 0);
    glEnable(GL_DEPTH_TEST);
    init();
    menu();
    glutMainLoop();
}
