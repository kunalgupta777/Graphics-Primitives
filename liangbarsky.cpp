// Liang Barsky  Line Clipping Algorithm
//  - Kunal Gupta 735/IT/15
#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

// this function gives the maximum
float maxi(float arr[],int n)
{
    float m = 0;
    for(int i = 0;i<n;i++)
    {
        if(m<arr[i])
        {
            m = arr[i];
        }
    }
    return m;
}
// this function gives the minimum

float mini(float arr[],int n)
{
    float m = 1;
    for(int i = 0;i<n;i++)
    {
        if(m>arr[i])
        {
            m = arr[i];
        }
    }
    return m;
}

void liang_barsky_clipper(float xmin,float ymin, float xmax, float ymax, float x1,float y1, float x2, float y2)
{

    // defining variables
    float p1 = -(x2-x1);
    float p2 = -p1;
    float p3 = -(y2-y1);
    float p4 = -p3;

    float q1 = x1-xmin;
    float q2 = xmax - x1;
    float q3 = y1 - ymin;
    float q4 = ymax - y1;

    float posarr[5], negarr[5];
    int posind = 1,negind = 1;
    posarr[0] = 1;
    negarr[0] = 0;

    rectangle(xmin,467 - ymin,xmax,467 - ymax); // drawing the clipping window!

    if(p1==0 || p3 ==0)
    {
            outtextxy(80,80,"Line is Parallel to clipping window!");
            return;

    }
    if(p1!=0)
    {
        float r1 = q1/p1;
        float r2 = q2/p2;
        if(p1<0)
        {
            negarr[negind++] = r1;
            posarr[posind++] = r2;   // for negative p1, add it to negative array  and add p2 to positive array
        }
        else
        {
            negarr[negind++] = r2;
            posarr[posind++] = r1;
        }
    }
    if(p3!=0)
    {
        float r3 = q3/p3;
        float r4 = q4/r4;

        if(p3<0)
        {
            negarr[negind++] = r3;
            posarr[posind++] = r4;
        }
        else
        {
            negarr[negind++] = r4;
            posarr[posind++] = r3;
        }
    }

    float xn1,yn1,xn2,yn2;
    float rn1,rn2;
    rn1 = maxi(negarr,negind);    // maximum of negative array
    rn2 = mini(posarr,posind);   // minimum of positive array

    xn1 = x1 + p2*rn1;
    yn1 = y1 + p4*rn1;    // computing new points

    xn2 = x1 + p2*rn2;
    yn2 = y1 + p4*rn2;

    setcolor(CYAN);

    line(xn1,467 - yn1,xn2,467 - yn2);  // the drawing the new line

    setlinestyle(1,1,0);

    line(x1,467 - y1,xn1,467 - yn1);
    line(x2,467 - y2,xn2,467 - yn2);



}

int main()
{
    cout<<"\nLIANG-BARSKY-LINE-CLIPPING";
    cout<<"\nThe System Window Outlay is:(0,0) at bottom left and (631,467) at top right";
    cout<<"\nEnter the co- ordinates of the window(wxmin,wxmax,wymin,wymax):";
    float xmin,xmax,ymin,ymax;
    cin>>xmin>>ymin>>xmax>>ymax;
    cout<<"\nEnter the End Points of the Line (x1,y1) and (x2,y2):";
    float x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;

    int gd = DETECT, gm;

    // using the winbgim library for C++ , initializing the graphics mode
    initgraph(&gd,&gm,"");

    liang_barsky_clipper(xmin,ymin,xmax,ymax,x1,y1,x2,y2);
    getch();
    closegraph();
}
