#include<STDIO.H> 

#include<CONIO.H> 

#include<GRAPHICS.H> 

int main() 

{ 

  int gd=DETECT,gm; 
  int x,y; 
  initgraph(&gd,&gm,(char*)"C:\\TURBOC3\\BGI"); 
  x=getmaxx()/2; 
  y=getmaxy()/2; 
  line(x-50,y,x+50,y); 
  rectangle(x-100,y-100,x+100,y+100); 
  circle(x,y,50); 
  ellipse(x,y,0,360,200,150); 
  getch(); 
  closegraph(); 

} 

 