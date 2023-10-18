#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void dda(float, float, float, float);

int main()
{

    float a1, b1, a2, b2;
    cout << "< DDA Line Drawing Algorithm >" << endl << endl;
    cout << "Enter Cordinates of point 1: ";
    cin >> a1 >> b1;
    cout << "Enter Cordinates of point 2: ";
    cin >> a2 >> b2;

    int gm, gd = DETECT;
    initgraph(&gd, &gm, NULL);
    dda(a1, b1, a2, b2);
    getch();
    closegraph();
    return 0;
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
