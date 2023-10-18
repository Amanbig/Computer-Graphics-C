#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void drawline(int a, int b, int c, int d) {
    int x = a;
    int y = b;
    int dx = abs(c - a);
    int dy = abs(d - b);
    int xIncrement = (a < c) ? 1 : -1;
    int yIncrement = (b < d) ? 1 : -1;
    int p = 2 * dy - dx;

    putpixel(x, y, WHITE);

    if (dx > dy) {
        while (x != c) {
            cout << "(" << x << "," << y << ")\n";
            x += xIncrement;
            if (p < 0) {
                p += 2 * dy;
            } else {
                p += 2 * dy - 2 * dx;
                y += yIncrement;
            }
            putpixel(x, y, WHITE);
            delay(100);
        }
    } else {
        while (y != d) {
            cout << "(" << x << "," << y << ")\n";
            y += yIncrement;
            if (p < 0) {
                p += 2 * dx;
            } else {
                p += 2 * dx - 2 * dy;
                x += xIncrement;
            }
            putpixel(x, y, WHITE);
            delay(100);
        }
    }
}

int main() {
    int gDriver = DETECT, gMode;
    initgraph(&gDriver, &gMode, NULL);

    int a = 0, b = 0, c = 0, d = 0;
    cout << "Enter first point\n";
    cin >> a >> b;
    cout << "Enter second point\n";
    cin >> c >> d;
    cout << "The points are\n";
    drawline(a, b, c, d);
    getch();
    closegraph();
    return 0;
}
