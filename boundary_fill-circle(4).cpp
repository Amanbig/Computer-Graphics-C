#include<iostream>
#include<graphics.h>
using namespace std;
void plotpoints(int,int,int,int);
void circles(int xcenter,int ycenter,int r){
    int p=1-r;
    int x=0;
    int y=r;
    plotpoints(xcenter,ycenter,x,y);
    while(x<y){
        x++;
        if(p<0){
            p+=2*x+1;
        }
        else{
            y--;
            p+=2*x+1-2*y;
        }
        plotpoints(xcenter,ycenter,x,y);
        delay(100);
    }
}
void plotpoints(int xcenter,int ycenter,int x,int y){
    putpixel(xcenter+x,ycenter+y,WHITE);
    putpixel(xcenter+x,ycenter-y,WHITE);
    putpixel(xcenter-x,ycenter+y,WHITE);
    putpixel(xcenter-x,ycenter-y,WHITE);
    putpixel(xcenter+y,ycenter+x,WHITE);
    putpixel(xcenter+y,ycenter-x,WHITE);
    putpixel(xcenter-y,ycenter+x,WHITE);
    putpixel(xcenter-y,ycenter-x,WHITE);
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
int main(){
    int gDriver = DETECT, gMode;
    initgraph(&gDriver, &gMode, NULL);
    int a,b,c;
    cout<<"Enter center of circle\n";
    cin>>a>>b;
    cout<<"Enter radius of circle\n";
    cin>>c;
    circles(a,b,c);
    fills(a,b,RED,WHITE);
    getch();
    closegraph();
    return 0;
}