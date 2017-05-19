/* Ellipse Generation using Mid-Pt algorithm  */
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void ellipsemidpt(int a, int b, int xc, int yc)
{
    int y = b;
    int x = 0;
    int p = b*b - a*a*b + a*a/4;
    while(b*b*x<=a*a*y)
    {
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        if(p>=0)
        {
            p+=2*b*b*x-2*a*a*y+3*b*b+2*a*a;
            y--;
        }
        else
        {
            p+=b*b*(2*x+3);
        }
        x++;
    }
    int q = b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
    while(y>=0)
    {
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        if(q>=0)
        {
            q+=a*a*(3-2*y);
        }
        else
        {
            q+=a*a*(3-2*y)+b*b*(2*x+2);
            x++;
        }
        y--;

    }
}
int main()
{
    int a,b;
    cout<<"\nEnter Major and Minor Axes of the Ellipse:";
    cin>>a>>b;
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    ellipsemidpt(a,b,getmaxx()/2,getmaxy()/2);
    getch();
    closegraph();
}
