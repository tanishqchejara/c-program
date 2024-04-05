#include <GRAPHICS.H>
#include <CONIO.H>

main()
{
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\TURBOC3\\BGII");
outtext("Press any key to clear the screen.");
getch();
cleardevice();
outtext("Press any key to exit...");
getch();
closegraph();
return 0;
}
