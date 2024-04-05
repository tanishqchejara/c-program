#include <GRAPHICS.H>
#include <CONIO.H>
main()
{
int gd = DETECT, gm, max_colors;
char a[100];
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
max_colors = getmaxcolor();
sprintf(a,"Maximum number of colors for current graphics mode and driver =%d",max_colors+1);
outtextxy(0, 40, a);
getch();
closegraph();
return 0;
}