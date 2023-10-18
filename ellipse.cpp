#include <iostream>
#include <graphics.h>
using namespace std;
void plotpoints(int, int, int, int);
void ellipse(int xcenter, int ycenter, int rx, int ry)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;
    plotpoints(xcenter, ycenter, x, y);
    while (dx < dy)
    {
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
        plotpoints(xcenter, ycenter, x, y);
        delay(100);
    }
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0)
    {
        plotpoints(xcenter, ycenter, x, y);
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
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
int main()
{
    int gDriver = DETECT, gMode;
    initgraph(&gDriver, &gMode, NULL);
    int a, b, c, d;
    cout << "Enter center of ellipse\n";
    cin >> a >> b;
    cout << "Enter x radius of ellipse\n";
    cin >> c;
    cout << "Enter y radius of ellipse\n";
    cin >> d;
    ellipse(a, b, c, d);
    getch();
    closegraph();
    return 0;
}