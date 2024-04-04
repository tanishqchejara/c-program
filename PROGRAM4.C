

#include <STDIO.H>
#include <CONIO.H>
#include <GRAPHICS.H>

int main() {
    int x0, y0, x, y, a, b, pk, plk, p2k,screenWidth,screenHeight;

    printf("Ellipse algorithm\n");
    printf("Enter the coordinate values for(x0 & y0):");
    scanf("%d%d", &x0, &y0);
    printf("Enter the radius(a & b):");
    scanf("%d%d", &a, &b);


    // scaling factor
    int scale_factor = 6;

    // Scale up the coordinates
    x0 *= scale_factor;
    y0 *= scale_factor;
    a *= scale_factor;
    b *= scale_factor;

    x0 = x0 + 150;
    y0 = y0 + 150;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");



    settextstyle(DEFAULT_FONT, HORIZ_DIR, 8);

    x = 0;
    y = b;

    pk = (b * b) - (a * a * b) + ((a * a) / 4);

    while (2 * b * b * x < 2 * a * a * y) {
        if (pk < 0) {
            x = x + 1;
            pk = pk + 2 * b * b * x + b * b;
        } else {
            x = x + 1;
            y = y - 1;
            pk = pk + 2 * b * b * x - 2 * a * a * y + b * b;
        }
        putpixel(x0 + x, y0 + y, WHITE);
        putpixel(x0 - x, y0 + y, WHITE);
        putpixel(x0 - x, y0 - y, WHITE);
        putpixel(x0 + x, y0 - y, WHITE);
    }

    pk = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;

    while (y > 0) {
        if (pk > 0) {
            y = y - 1;
            pk = pk - 2 * a * a * y + a * a;
        } else {
            x = x + 1;
            y = y - 1;
            pk = pk + 2 * b * b * x - 2 * a * a * y + a * a;
        }
        putpixel(x0 + x, y0 + y, WHITE);
        putpixel(x0 - x, y0 + y, WHITE);
        putpixel(x0 - x, y0 - y, WHITE);
        putpixel(x0 + x, y0 - y, WHITE);
    }

    line(x0 + a, y0, x0 - a, y0);
    line(x0, y0 + b, x0, y0 - b);

    getch();
    closegraph();
    return 0;
}
