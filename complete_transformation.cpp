#include <bits/stdc++.h>
#include <graphics.h>
#define PI 3.141
using namespace std;
int a, b, c, d;

void translate(int tx, int ty)
{
    setcolor(YELLOW);
    a += tx;
    b += ty;
    c += tx;
    d += ty;
    rectangle(a, b, c, d);
}

int uniform(){
    cout<<"Enter choice 1 - uniform and 2 - non uniform\n";
    int choice;
    cin>>choice;
    return choice;
}

void scaling_pivot(int sx, int sy, int e, int f)
{
    setcolor(YELLOW);
    a = sx * a - sx * e + e;
    b = sy * b - sy * f + f;
    c = sx * c - sx * e + e;
    d = sy * d - sy * f + f;
    rectangle(a, b, c, d);
}

void scaling_origin(int sx, int sy)
{
    setcolor(YELLOW);
    a = sx * a;
    b = sy * b;
    c = sx * c;
    d = sy * d;
    rectangle(a, b, c, d);
}

void rotate(float &x, float &y, float tx, float ty, float angle)
{
    float new_x = tx + (x - tx) * cos(angle) - (y - ty) * sin(angle);
    float new_y = ty + (x - tx) * sin(angle) + (y - ty) * cos(angle);
    x = new_x;
    y = new_y;
}

void rotation_origin(float angle)
{
    setcolor(YELLOW);
    float x1 = a, y1 = b, x2 = c, y2 = b;
    float x3 = c, y3 = d, x4 = a, y4 = d;
    float pivotX = 0, pivotY = 0;

    rotate(x1, y1, pivotX, pivotY, angle);
    rotate(x2, y2, pivotX, pivotY, angle);
    rotate(x3, y3, pivotX, pivotY, angle);
    rotate(x4, y4, pivotX, pivotY, angle);

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);
}

void rotation_pivot(float angle, int pivotX, int pivotY)
{
    setcolor(YELLOW);
    float x1 = a, y1 = b, x2 = c, y2 = b;
    float x3 = c, y3 = d, x4 = a, y4 = d;

    rotate(x1, y1, pivotX, pivotY, angle);
    rotate(x2, y2, pivotX, pivotY, angle);
    rotate(x3, y3, pivotX, pivotY, angle);
    rotate(x4, y4, pivotX, pivotY, angle);

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);
}

int main()
{
    float tx, ty, e, f, sx, sy, angle;
    int choice,sel;
    system("cls");
    cout << "Enter the top-left corner for a rectangle : ";
    cin >> a >> b;
    cout << "Enter the bottom-right corner for a reactangle : ";
    cin >> c >> d;
    initwindow(800, 800);
    rectangle(a, b, c, d);

    cout << "Enter the transformation method : " << endl;
    cout << "1. Translation." << endl;
    cout << "2. Scaling with respect to a pivot point." << endl;
    cout << "3. Scaling with respect to origin." << endl;
    cout << "4. Rotation about origin." << endl;
    cout << "5. Rotation about a Pivot." << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter the translation coordinates (x and y) : ";
        cin >> tx >> ty;
        translate(tx, ty);
        break;
    case 2:
        sel=uniform();
        if(sel == 1){
            cout << "Enter the scaling factor (x and y) : ";
            cin >> sx;
            sy=sx;
        }
        else{
            cout << "Enter the scaling factor (x and y) : ";
            cin >> sx >> sy;
        }
        cout << "Enter the coordinates of the pivot point : ";
        cin >> e >> f;
        scaling_pivot(sx, sy, e, f);

        break;
    case 3:
        sel=uniform();
        if(sel == 1){
            cout << "Enter the scaling factor (x and y) : ";
            cin >> sx;
            sy=sx;
        }
        else{
            cout << "Enter the scaling factor (x and y) : ";
            cin >> sx >> sy;
        }
        scaling_origin(sx, sy);
        break;
    case 4:
        cout << "Enter the rotation angle : ";
        cin >> angle;
        angle = angle * (PI / 180);
        int cl;
        cout << "Enter 1 for clockwise or 0 for anticlockwise : ";
        cin >> cl;
        switch (cl)
        {
        case 0:
            rotation_origin(-angle);
            break;
        case 1:
            rotation_origin(angle);
            break;
        default:
            cout << "Invalid choice.";
            break;
        }
        break;
    case 5:
        cout << "Enter the rotation angle : ";
        cin >> angle;
        angle = angle * (PI / 180);
        cout << "Enter the pivot point : ";
        cin >> e >> f;
        cout << "Enter 1 for clockwise or 0 for anticlockwise : ";
        cin >> cl;
        switch (cl)
        {
        case 0:
            rotation_pivot(-angle, e, f);
            break;
        case 1:
            rotation_pivot(angle, e, f);
            break;
        default:
            cout << "Invalid choice.";
            break;
        }
        break;
    default:
        cout << "Invalid Choice.";
        break;
    }
    getch();
    closegraph();
}