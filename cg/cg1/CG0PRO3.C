#include <GRAPHICS.H>
#include <CONIO.H>
main()
{
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
outtext("Press any key to close the graphics mode...");
getch();
closegraph();
return 0;
}