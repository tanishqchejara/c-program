#include <GRAPHICS.H>
#include <CONIO.H>
main()
{
int gd = DETECT, gm;
char *drivername;
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
drivername = getdrivername();
outtextxy(200, 200, drivername);
getch();
closegraph();
return 0;
}