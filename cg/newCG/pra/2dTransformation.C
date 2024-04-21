#include <stdio.h>
#include <graphics.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to apply translation
void translation(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty) {
    x1 += tx;
    y1 += ty;
    x2 += tx;
    y2 += ty;
    x3 += tx;
    y3 += ty;
    drawTriangle(x1, y1, x2, y2, x3, y3);
}

// Function to apply rotation
void rotation(int x1, int y1, int x2, int y2, int x3, int y3, double angle) {
    int xr1 = x1 * cos(angle * PI / 180) - y1 * sin(angle * PI / 180);
    int yr1 = x1 * sin(angle * PI / 180) + y1 * cos(angle * PI / 180);
    int xr2 = x2 * cos(angle * PI / 180) - y2 * sin(angle * PI / 180);
    int yr2 = x2 * sin(angle * PI / 180) + y2 * cos(angle * PI / 180);
    int xr3 = x3 * cos(angle * PI / 180) - y3 * sin(angle * PI / 180);
    int yr3 = x3 * sin(angle * PI / 180) + y3 * cos(angle * PI / 180);
    drawTriangle(xr1, yr1, xr2, yr2, xr3, yr3);
}

// Function to apply scaling
void scaling(int x1, int y1, int x2, int y2, int x3, int y3, double sx, double sy) {
    int xs1 = x1 * sx;
    int ys1 = y1 * sy;
    int xs2 = x2 * sx;
    int ys2 = y2 * sy;
    int xs3 = x3 * sx;
    int ys3 = y3 * sy;
    drawTriangle(xs1, ys1, xs2, ys2, xs3, ys3);
}

// Function to apply reflection about x-axis
void reflectionX(int x1, int y1, int x2, int y2, int x3, int y3) {
    y1 = -y1;
    y2 = -y2;
    y3 = -y3;
    drawTriangle(x1, y1, x2, y2, x3, y3);
}

// Function to apply reflection about y-axis
void reflectionY(int x1, int y1, int x2, int y2, int x3, int y3) {
    x1 = -x1;
    x2 = -x2;
    x3 = -x3;
    drawTriangle(x1, y1, x2, y2, x3, y3);
}

// Function to apply shear along x-axis
void shearX(int x1, int y1, int x2, int y2, int x3, int y3, double shx) {
    int xsx1 = x1 + shx * y1;
    int xsx2 = x2 + shx * y2;
    int xsx3 = x3 + shx * y3;
    drawTriangle(xsx1, y1, xsx2, y2, xsx3, y3);
}

// Function to apply shear along y-axis
void shearY(int x1, int y1, int x2, int y2, int x3, int y3, double shy) {
    int ysy1 = y1 + shy * x1;
    int ysy2 = y2 + shy * x2;
    int ysy3 = y3 + shy * x3;
    drawTriangle(x1, ysy1, x2, ysy2, x3, ysy3);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Original triangle
    int x1 = 100, y1 = 100, x2 = 200, y2 = 100, x3 = 150, y3 = 200;
    outtext("Original Triangle");
    drawTriangle(x1, y1, x2, y2, x3, y3);

    getch();
    cleardevice();
    outtext(" translation...");
    translation(x1, y1, x2, y2, x3, y3, 50, 50);
    getch();
    cleardevice();
    

    outtext(" rotation...");
    rotation(x1, y1, x2, y2, x3, y3, 45);
    getch();
    cleardevice();

    outtext(" scaling...");
    scaling(x1, y1, x2, y2, x3, y3, 1.5, 1.5);
    getch();
    cleardevice();

    outtext(" reflection about x-axis...");
    reflectionX(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    outtext(" reflection about y-axis...");
    reflectionY(x1, y1, x2, y2, x3, y3);
    getch();
    cleardevice();

    outtext(" shear along x-axis...");
    shearX(x1, y1, x2, y2, x3, y3, 0.5);
    getch();
    cleardevice();

    outtext(" shear along y-axis...");
    shearY(x1, y1, x2, y2, x3, y3, 0.5);
    getch();
    cleardevice();

    outtext("Press any key to exit...");
    getch();
    closegraph();
    return 0;
}