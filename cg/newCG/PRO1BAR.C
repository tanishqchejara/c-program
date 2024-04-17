#include<CONIO.H>
#include<GRAPHICS.H>


int main(){
  int gd = DETECT,gm;
  initgraph(&gd,&gm,(char *)"C://TURBOC3//BGI");
  bar(100,100,200,200);
  getch();
  closegraph();
}
