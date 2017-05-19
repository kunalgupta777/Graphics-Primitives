/* Plotting Lines with DDA line algorithm and Bresenham's method */
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int round(float x)
 {
     return int(x+0.5);
 }
 void bresenham(int x1,int y1, int x2, int y2,int ym, int xm)
 {
    int dx = x2-x1;
    int dy = y2-y1;

    putpixel(x1,ym-y1,WHITE);
    int x=x1;
    int y=y1;

    float m = float(dy)/float(dx);
    if ( abs(m)<=1 && abs(m) >=0)
    {int d = 2*dy - dx;
        while(x<x2)
    {
        x++;
        if(d<0)
        {
            d+=2*dy;
        }
        else
        {
            if(y1<y2)
            {
                y++;
            }

        }

        putpixel(x,ym-y,WHITE);
    }
    }

    else if (abs(m)>1)
    {
        int d = 2*dx - dy;
        while(y<y2)
        {
            y++;
            if(d<0)
            {
                d+=2*dx;
            }
            else
            {
                x++;
                d+=2*(dx-dy);
            }
            putpixel(x,ym-y,WHITE);
        }

    }

 }

 void DDA(int x1,int y1, int x2, int y2,int ym, int xm)
 {
     float m ;
     if(x2==x1){}
     else{ m  = float((y2-y1))/float((x2-x1));

     }

     if(abs(m)<=1)
     {     float y =y1;
             for(int x=x1;x<=x2;x++)
             {
                 putpixel(x,ym-round(y),WHITE);
                 y+=m;

             }
     }
     else
     {
         float x =x1;
           if(y2>y1)
            {
              for(int y=y1;y<=y2;y++)
             {
                 putpixel(round(x),ym-y,WHITE);
                 x+=1/m;


             }
            }
            else if( y2<y1)
            {
             for(int y=y1;y>=y2;y--)
             {
                 putpixel(-round(x),ym-y,WHITE);
                 x+=1/m;
                cout<<x<<" "<<y<<"\n";
             }
            }
     }
 }
 int main()
{
     int x1,y1,x2,y2;
     cout<<"Line Drawing Algorithms";
     cout<<"\nEnter coordinates";
     cin>>x1>>y1>>x2>>y2;
     int gd = DETECT,gm;
     cout<<"choose method : 1.) DDA 2.) Bresenham";
     int ch;
     cin>>ch;
initgraph(&gd,&gm,"");
int xm  = getmaxx();
int ym  = getmaxy();
   if(ch==0)

     {DDA(x1,y1,x2,y2,ym,xm);}
     else
     {
         bresenham(x1,y1,x2,y2,xm,ym);
     }
     getch();
     closegraph();

 }

