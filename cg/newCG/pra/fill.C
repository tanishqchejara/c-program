// #include<GRAPHICS.H>
// #include<conio.h>
// #include<STDIO.h>
// #include<STDLIB.H>

// int main(){
//   int gd = DETECT,gm;

//   int w[] = {
//     100, 100, 200, 100, 200, 200, 100, 200,100,100
//   };
//   initgraph(&gd,&gm,(char *)"C://TURBOC3//BGI");
//   setcolor(RED);
//   drawpoly(5,w);
//   line(0,0,200,200);
//   printf("\nPress a button to clip a polygon..");
//     getch();

//     setfillstyle(SOLID_FILL, BLACK);
//     floodfill(100, 100, RED);
//   getch();
//   closegraph();
//   return 0;
// }

#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int gd = DETECT, gm;
    int w[] = {100, 100, 200, 100, 200, 200, 100, 200, 100, 100};

    initgraph(&gd, &gm, "C://TURBOC3//BGI");

    setcolor(RED);
    drawpoly(5, w);

    printf("\nPress a button to clip a polygon..");
    getch();

    setfillstyle(SOLID_FILL, RED);
    floodfill(0, 0, RED); // Fill the entire area with red color

    setcolor(BLACK);
    drawpoly(5, w); // Draw the rectangle in black color

    getch();
    closegraph();
    return 0;
}