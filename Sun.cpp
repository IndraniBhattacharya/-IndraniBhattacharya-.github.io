#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define P(x) (3.14/180)*x 
#define fx(x) (getmaxx()/2+x)
#define fy(y) (getmaxy()/2-y)
#define Appx(x) ((int)(x+0.5))
void drawSun();
void drawRay();
void drawRotatedRay(int a,int x1,int y1,int x2,int y2);

int x=350,y=350; //The center of the circle
int main()
{
    int r,g,b,i;
    initwindow(700,700);
    drawSun();
    drawRay();
    getch();
}
void drawSun()
{
     setcolor(RGB(221,169,30));
     circle(x,y,25);
     //setfillstyle(1,RGB(248,223,5));
     setfillstyle(1,RGB(253,222,2));
     floodfill(x,y,RGB(221,169,30));
     
     setcolor(RGB(167,128,22));
     circle(x,y,26);
     setcolor(RGB(154,117,20));
     circle(x,y,27);
}
void drawRay()
{
     int i=1;
     int j;
     setcolor(RGB(154,139,3));
     while(i)
     {
             //RAY 1
                       
                        //setcolor(RGB(64,49,9));
                        setcolor(RGB(52,39,7));
                        for(j=0;j<10;j++)
                                         drawRotatedRay(36*j+i%35,x+27,y-4,x+35,y-4);
              //RAY 2          
                        setcolor(RGB(64,49,9));
                        for(j=0;j<10;j++)
                                         drawRotatedRay(36*j+i%35,x+27,y-2,x+37,y-2);
               //RAY 3         
                        setcolor(RGB(85,72,12));
                        //setcolor(RGB(154,139,3));
                        for(j=0;j<10;j++)
                                         drawRotatedRay(36*j+i%35,x+27,y,x+39,y);
              //RAY 4          
                        //setcolor(RGB(137,104,18));
                        setcolor(RGB(64,49,9));
                        for(j=0;j<10;j++)
                                         drawRotatedRay(36*j+i%35,x+27,y+2,x+38,y+2);
               //RAY 5        
                        setcolor(RGB(52,39,7));
                        for(j=0;j<10;j++)
                                         drawRotatedRay(36*j+i%35,x+27,y+4,x+35,y+4);
                                         
                        delay(50);
                        cleardevice();
                        drawSun();
                        i+=1;
                        if(i==500)
                                  i=1;
                        
     }
}
void drawRotatedRay(int a,int x1,int y1,int x2,int y2)
{
        int x11,x21,y11,y21;
        x11=x+(x1-x)*cos(P(a))-(y1-y)*sin(P(a));
		y11=y+(x1-x)*sin(P(a))+(y1-y)*cos(P(a));
        x21=x+(x2-x)*cos(P(a))-(y2-y)*sin(P(a));
		y21=y+(x2-x)*sin(P(a))+(y2-y)*cos(P(a));   
		
		line(x11,y11,x21,y21);
}
