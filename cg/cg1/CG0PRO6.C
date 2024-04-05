#include <GRAPHICS.H>
#include <CONIO.H>
main()
{
int gd = DETECT, gm, bkcolor;
char a[100];
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
bkcolor = getbkcolor();
sprintf(a,"Current background color = %d", bkcolor);
outtextxy( 10, 10, a);
getch();
closegraph();
return 0;
}
