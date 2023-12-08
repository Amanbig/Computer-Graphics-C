#include <iostream>
#include <graphics.h>
#include<cmath>

using namespace std;

void plotpoints(int, int, int, int);

void circles(int xcenter, int ycenter, int r)
{
    int p = 1 - r;
    int x = 0;
    int y = r;

    plotpoints(xcenter, ycenter, x, y);
    
    while (x < y)
    {
        x++;
        if (p < 0)
        {
            p += 2 * x + 1;
        }
        else
        {
            y--;
            p += 2 * x + 1 - 2 * y;
        }
        plotpoints(xcenter, ycenter, x, y);
    }
}

void plotpoints(int xcenter, int ycenter, int x, int y)
{
    putpixel(xcenter + x, ycenter + y, WHITE);
    putpixel(xcenter + x, ycenter - y, WHITE);
    putpixel(xcenter - x, ycenter + y, WHITE);
    putpixel(xcenter - x, ycenter - y, WHITE);
    putpixel(xcenter + y, ycenter + x, WHITE);
    putpixel(xcenter + y, ycenter - x, WHITE);
    putpixel(xcenter - y, ycenter + x, WHITE);
    putpixel(xcenter - y, ycenter - x, WHITE);
}

void dda(float x1, float y1, float x2, float y2)
{

    int xMax = max(x1, x2);
    int xMin = min(x1, x2);
    int yMin = min(y1, y2);
    int yMax = max(y1, y2);
    float slope = (y2 - y1) / (x2 - x1);
    cout << slope << endl;

    if ((slope <= 1) && (slope >= -1))
    {
        float yTemp;
        if (slope > 0)
        {
            yTemp = yMin;
        }
        else
        {
            yTemp = yMax;                                                           
        }

        for (int x = xMin; x <= xMax; x++)
        {
            yTemp = yTemp + slope;
            int y = round(yTemp);
            putpixel(x, y, YELLOW);
        }
    }

    else
    {

        float xTemp;
        if (slope > 0)
        {
            xTemp = xMin;
        }
        else
        {
            xTemp = xMax;
        }

        for (int y = yMin; y <= yMax; y++)
        {
            xTemp = xTemp + (1.0 / slope);
            int x = round(xTemp);
            putpixel(x, y, YELLOW);
        }
    }
}

void rotate(float &x, float &y, float tx, float ty, float angle)
{
    float new_x = tx + (x - tx) * cos(angle) + (y - ty) * sin(angle);
    float new_y = ty - (x - tx) * sin(angle) + (y - ty) * cos(angle);
    x = new_x;
    y = new_y;
}



void drawpendulum(int a,int b,int c,int d){
     // 100 100 300 100
    dda(a,b,c,d); // 150 100 150 400
    circles(c,d,15);
}
int main(){
    initwindow(800,800);
    dda(100,100,700,100);
    drawpendulum(150,100,150,400);
    int i=0;
    float a=150,b=400,c=200,d=500;
    bool moveup = true;
    while(1){
        cleardevice();
        if(moveup){
            i++;
        }
        else{
            i--;
        }
        if(i>10){
            moveup = false;
        }
        else if(i<-10){
            moveup = true;
        }
        dda(100,100,700,100);
        rotate(a,b,150,100,(3.14/180)*i*0.1);
        rotate(c,d,400,100,(3.14/180)*i*0.8);
        drawpendulum(150,100,a,b);
        drawpendulum(400,100,c,d);
        delay(80);
    }
    // drawpendulum(500,100,400);
    getch();
    closegraph();
}