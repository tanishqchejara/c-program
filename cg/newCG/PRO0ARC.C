#include<CONIO.H>
#include<GRAPHICS.H>

int main(){
  int gd = DETECT , gm;
  initgraph(&gd,&gm,(char *)"C://TURBOC3//BGI");
  arc(200,200,0,180,100);
  getch();
  closegraph();
  return 0;
}