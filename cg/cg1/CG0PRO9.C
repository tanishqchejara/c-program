#include <GRAPHICS.H>
#include <CONIO.H>
main()
{
int gd = DETECT, gm, max_y;
char array[100];
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
max_y = getmaxy();
sprintf(array, "Maximum Y coordinate for current graphics mode and driver is = %d.",max_y);
outtext(array);
getch();
closegraph();
return 0;
}