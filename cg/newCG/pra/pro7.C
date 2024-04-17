#include <CONIO.H>
#include <GRAPHICS.H>
#include <STDIO.H>

int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, (char *)"C://TURBOC3//BGI");

  //vertices of the triangle
  int triangle[4][2] = {
      {100, 100}, 
      {200, 200}, 
      {50, 200},  
      {100, 100}};

  outtext("Inital Triangle");
  // initial triangle
  drawpoly(4, (int *)triangle);

  getch();
  cleardevice();

  // Translation 
  int tx = 100;
  int ty = 50;
  outtext("Translation Applied(100,50)");
  // Apply translation to the triangle
  for (int i = 0; i < 4; i++)
  {
    triangle[i][0] += tx;
    triangle[i][1] += ty;
  }

  //translated triangle
  drawpoly(4, (int *)triangle);

  getch();
  cleardevice();

  // Scaling factors
  double scaleX = 1.5;
  double scaleY = 0.8;
  outtext("Scaling Applied(1.5,0.8)");
  // scaling triangle
  for (int i = 0; i < 4; i++)
  {
    triangle[i][0] = triangle[i][0] * scaleX;
    triangle[i][1] = triangle[i][1] * scaleY;
  }

  // scaled triangle;
  drawpoly(4, (int *)triangle);

  getch();
  closegraph();
  return 0;
}