

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

int main() {
    int gdrive = DETECT, gm;
    int x1, y1, x2, y2;
    int dx, dy, steps, x, y, increment;
    int delay_time;


    printf("Initial value for x1 = ");
    scanf("%d", &x1);
    printf("Initial value for y1 = ");
    scanf("%d", &y1);
    printf("Initial value for x2 = ");
    scanf("%d", &x2);
    printf("Initial value for y2 = ");
    scanf("%d", &y2);
    printf("Enter Time Delay = ");
    scanf("%d", &delay_time);

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (dx >= dy)
        steps = dx;
    else
        steps = dy;

    dx = (x2 - x1) / steps;
    dy = (y2 - y1) / steps;

    x = x1;
    y = y1;

    initgraph(&gdrive, &gm, "C:\\TURBOC3\\BGI");
    for (increment = 0; increment < steps; increment++) {
        putpixel(x, y, 4);
        x = x + dx;
        y = y + dy;
        delay(delay_time);
    }

    getch();
    closegraph();
    return 0;
}
