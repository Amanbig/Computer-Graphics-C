#include <iostream>
#include <graphics.h>
using namespace std;
void plotpoints(int, int, int, int);
void ellipse(int xcenter, int ycenter, int rx, int ry)
{
    float dx, dy, p1, p2, x, y;
    x = 0;
    y = ry;
    p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;
    plotpoints(xcenter, ycenter, x, y);
    while (dx < dy)
    {
        plotpoints(xcenter, ycenter, x, y);
        if (p1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            p1 = p1 + dx - dy + (ry * ry);
        }
        delay(100);
    }
    p2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0)
    {
        plotpoints(xcenter, ycenter, x, y);
        if (p2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            p2 = p2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            p2 = p2 + dx - dy + (rx * rx);
        }
        delay(100);
    }
}
void plotpoints(int xcenter, int ycenter, int x, int y)
{
    putpixel(xcenter + x, ycenter + y, WHITE);
    cout << "(" << xcenter + x << "," << ycenter + y << ")" << endl;
    putpixel(xcenter + x, ycenter - y, WHITE);
    cout << "(" << xcenter + x << "," << ycenter - y << ")" << endl;
    putpixel(xcenter - x, ycenter + y, WHITE);
    cout << "(" << xcenter - x << "," << ycenter + y << ")" << endl;
    putpixel(xcenter - x, ycenter - y, WHITE);
    cout << "(" << xcenter - x << "," << ycenter - y << ")" << endl;
}
void fills(int x,int y,int fill,int boundary){
    int current = getpixel(x,y);
    if((current!=boundary)&&(current!=fill)){
        putpixel(x,y,fill);
        fills(x+1,y,fill,boundary);
        fills(x-1,y,fill,boundary);
        fills(x,y+1,fill,boundary);
        fills(x,y-1,fill,boundary);
    }
}
int main()
{
    int gDriver = DETECT, gMode;
    initgraph(&gDriver, &gMode, NULL);
    int a, b, c, d;
    cout << "Enter center of circle\n";
    cin >> a >> b;
    cout << "Enter x radius of circle\n";
    cin >> c;
    cout << "Enter y radius of circle\n";
    cin >> d;
    ellipse(a, b, c, d);
    fills(a,b,RED,WHITE);
    getch();
    closegraph();
    return 0;
}