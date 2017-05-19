/* Plotting Lines with DDA line algorithm and Bresenham's method */
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int round(float x)
 {
     return int(x+0.5);
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
  
   
     cin>>ch;
initgraph(&gd,&gm,"");
int xm  = getmaxx();
int ym  = getmaxy();
   DDA(x1,y1,x2,y2);
     getch();
     closegraph();

 }

