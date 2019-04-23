#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#define P(x) (3.14/180)*x 
#define fx(x) (getmaxx()/2+x)
#define fy(y) (getmaxy()/2-y)
#define Appx(x) ((int)(x+0.5))
void calPoints(double angle[11],int points[11][2]);
void drawLines(int points[][2]);
void fillCol(double angle[11],int points[][2]);
void index(int ,int,int);

int x=400,y=300;
int main()
{
    initwindow(1200,800);
    circle(x,y,151);
    circle(x,y,150);
    
    int a[11];
    double angle[11];
    int points[11][2];
    int i;
    double eachRun=0;
    int totalRun=0;
    
    printf("\n*** PIE CHART ***\n");
    //Taking user input
    for(i=0;i<11;i++)
    {
            //printf("\nPlease enter the contribution(run) of Batsman %d : ",i+1);
            //scanf("%d",&a[i][0]);        
            a[i]=10*i+10;
            totalRun+=a[i];  //Calculating the total run
    }
    //Calculating the angle for each run
    eachRun=(360.0/totalRun);
    
    //Initializing the angle of each player according to his contribution
    for(i=0;i<11;i++)
                     angle[i]=a[i]*eachRun;
    
    
    
    printf("\n\nDISPLAYING THE RUNS: ");
    printf("\nTotal Run= %d ,Each Run= %f ",totalRun,eachRun);
    for(i=0;i<11;i++)
    {
            printf("\n Batsman %d : %d --> %0.6f",i+1,a[i],angle[i]);       
    }
    calPoints(angle,points);
    drawLines(points);
    fillCol(angle,points);
    getch();
}

void calPoints(double angle[11],int points[11][2])
{
       int i;
       int x1=550;
       int y1=300;
       //circle(x1,y1,5);
       
       //Calculating points for first player
       points[0][0]=x+(x1-x)*cos(P(angle[0]))-(y1-y)*sin(P(angle[0]));
       points[0][1]=y+(x1-x)*sin(P(angle[0]))+(y1-y)*cos(P(angle[0]));
       
       for(i=1;i<11;i++)
       {
                        points[i][0]=x+1+(points[i-1][0]-x)*cos(P(angle[i]))-(points[i-1][1]-y)*sin(P(angle[i]));
		                points[i][1]=y+(points[i-1][0]-x)*sin(P(angle[i]))+(points[i-1][1]-y)*cos(P(angle[i]));
       
                     //To adjust error due to approximation
		              if(points[i][0]<400)
		                       points[i][0]-=1;   
       }
       printf("\nDISPLAYING POINTS: \n");
       for(i=0;i<11;i++)
                        printf(" point %d : (%d , %d)\n",i,points[i][0],points[i][1]);
       
                                
}

void drawLines(int points[][2])
{
     int i;
     line(x,y,550,300);
     printf("\nDRAWING LINES: \n");
       for(i=0;i<10;i++)
                        line(x,y,(points[i][0]),(points[i][1]));
       
}
void fillCol(double angle[11],int points[][2])
{
     int i,a,b;
     int x1=550;
     int y1=300;
       
     a=(x1+points[0][0])/2-1;
     b=(y1+points[0][1])/2-1;
     setfillstyle(SOLID_FILL,2);
     floodfill(a,b,WHITE);
     index(a,b,0);
                      
     for(i=1;i<11;i++)
     {
                      delay(1000);
                      //To find co-ordinates of a point lying inside the area 
                      a=(points[i-1][0]+points[i][0]-2)/2; 
                      b=(points[i-1][1]+points[i][1])/2;
                      //Coloring the respective area
                      setfillstyle(SOLID_FILL,i+2);
                      floodfill(a,b,WHITE);
                      index(a,b,i);
                      //circle(a,b,2);
                        
     }
}


void index(int a,int b,int i)
{
     int m,n,j;
     m=700;
     n=500+25*i;
     char s[2];
     char str[9];
     char message[]="Player ";
     sprintf(s,"%d",i+1);
     circle(m,n,7);
     setfillstyle(SOLID_FILL,i+2);
     floodfill(m,n,WHITE);
     outtextxy(m+20,n-9,message);
     outtextxy(m+85,n-9,s);
                      
}
