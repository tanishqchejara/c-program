#include<STDIO.H> 

#include<CONIO.H> 

#include<GRAPHICS.H> 

int main() 
{ 
  int gd=DETECT,gm; 
  initgraph(&gd,&gm,(char*)"C:\\TURBOC3\\BGI"); 
  putpixel(50,50,RED); 
  getch(); 
  closegraph(); 
  return 0; 

} 

 