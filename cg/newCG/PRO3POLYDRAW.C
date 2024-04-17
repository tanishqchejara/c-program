#include<CONIO.H>
#include<GRAPHICS.H>

int main(){
  int gd = DETECT,gm,points[]={100,100,200,100,200,200,100,200};
  initgraph(&gm,&gd,(char *)"C://TURBOC3//BGI");
  drawpoly(4,points);
  getch();
  closegraph();
  return 0;
}
