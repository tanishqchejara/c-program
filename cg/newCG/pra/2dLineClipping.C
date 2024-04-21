#include <GRAPHICS.H>
#include <conio.h>
#include <STDIO.h>
#include <STDLIB.H>

int main()
{
  int gd = DETECT, gm;
  int x1, y1, x2, y2;

  int w[] = {
      100, 100, 200, 100, 200, 200, 100, 200, 100, 100};
  initgraph(&gd, &gm, (char *)"C://TURBOC3//BGI");
  setcolor(RED);
  drawpoly(5, w);

  printf("Enter vertices of Line: ");
  printf("x1 y1 x2 y2");
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  setcolor(WHITE);
  line(x1, y1, x2, y2);
  printf("\nPress a button to clip a polygon..");
  getch();
  setcolor(RED);
  drawpoly(5, w);

  setfillstyle(SOLID_FILL, BLACK);
  floodfill(0, 0, RED);

  printf("\nThis is the clipped polygon..");
  getch();

  cleardevice();
  closegraph();
  return 0;
}