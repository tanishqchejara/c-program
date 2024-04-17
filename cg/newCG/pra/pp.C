// #include <graphics.h>
// #include <conio.h>
// #include <dos.h>

// int main() {
//     int gd = DETECT, gm;
//     initgraph(&gd, &gm, "C://TURBOC3//BGI");

//     // Define the coordinates of the cube
//     int x1 = 100, y1 = 100, x2 = 200, y2 = 200;

//     // Draw the front face of the cube
//     line(x1, y1, x2, y1);
//     line(x2, y1, x2, y2);
//     line(x2, y2, x1, y2);
//     line(x1, y2, x1, y1);

//     // Draw the top face of the cube
//     int x3 = x1 + 50, y3 = y1 - 50;
//     int x4 = x2 + 50, y4 = y2 - 50;
//     line(x3, y3, x4, y3);
//     line(x4, y3, x4, y4);
//     line(x4, y4, x3, y4);
//     line(x3, y4, x3, y3);

//     // Draw the side faces of the cube
//     line(x1, y1, x3, y3);
//     line(x2, y1, x4, y3);
//     line(x2, y2, x4, y4);
//     line(x1, y2, x3, y4);

//     getch();
//     closegraph();
//     return 0;
// }


#include <graphics.h>
#include <stdio.h>
#include <math.h>

void drawcube(int arr[8][3]){
   line(arr[0][0],arr[0][1],arr[1][0],arr[1][1]);//AB
  line(arr[1][0],arr[1][1],arr[2][0],arr[2][1]);//BC
  line(arr[2][0],arr[2][1],arr[3][0],arr[3][1]);//CD
  line(arr[3][0],arr[3][1],arr[0][0],arr[0][1]);//DA

  line(arr[4][0]+ 50,arr[4][1]-50,arr[5][0]+ 50,arr[5][1]-50);//EF
  line(arr[5][0]+ 50,arr[5][1]-50,arr[6][0]+ 50,arr[6][1]-50);//FG
  line(arr[6][0]+ 50,arr[6][1]-50,arr[7][0]+ 50,arr[7][1]-50);//GH
  line(arr[7][0]+ 50,arr[7][1]-50,arr[4][0]+ 50,arr[4][1]-50);//HE

  line(arr[0][0],arr[0][1],arr[5][0]+ 50,arr[5][1]-50);//AF
  line(arr[1][0],arr[1][1],arr[6][0]+ 50,arr[6][1]-50);//BG
  line(arr[2][0],arr[2][1],arr[7][0]+ 50,arr[7][1]-50);//CH
  line(arr[3][0],arr[3][1],arr[4][0]+ 50,arr[4][1]-50);//DE
}

//translation on the cube
void translateCube(int cube[8][3], int tx, int ty, int tz) {
    outtext("translated cube(100,100,100)");
    for (int i = 0; i < 8; i++) {
        cube[i][0] += tx;
        cube[i][1] += ty;
        cube[i][2] += tz;
    }
}


void rotateCubeX(int cube[8][3], double angle) {
    outtext("rotated cube 30 deg anti-clockwise on x-axis");
    double radian = angle * (M_PI / 180.0);
    for (int i = 0; i < 8; i++) {
        int x = cube[i][0];
        int y = cube[i][1];
        cube[i][0] = x * cos(radian) - y * sin(radian);
        cube[i][1] = x * sin(radian) + y * cos(radian);
    }
}

//scaling on the cube
void scaleCube(int cube[8][3], double sx, double sy, double sz) {
     outtext("scaled cube by 0.5 in all dimensions");
    for (int i = 0; i < 8; i++) {
        cube[i][0] *= sx;
        cube[i][1] *= sy;
        cube[i][2] *= sz;
    }
}

int main(){
    int points[8][3] = {
       {100,100,100},//A
       {100,200,100},//B
       {200,200,100},//C
       {200,100,100},//D
       {200,100,200},//E
       {100,100,200},//F
       {100,200,200},//G
       {200,200,200}//H
    };
    int copy_points[8][3]= {
       {100,100,100},//A
       {100,200,100},//B
       {200,200,100},//C
       {200,100,100},//D
       {200,100,200},//E
       {100,100,200},//F
       {100,200,200},//G
       {200,200,200}//H
    };

    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char *)"C://TURBOC3//BGI");
    outtext("inital cube");
    // Draw the original cube
    drawcube(points);
    getch();
    cleardevice();
    // Apply translation (100, 100, 100)
    translateCube(points, 100, 100, 100);
    cleardevice(); 
    drawcube(points);
    getch();
    
    rotateCubeX(points, 30);
    cleardevice(); 
    drawcube(points);
    getch();
   
    // Apply scaling by a factor of 0.5 in all dimensions
    scaleCube(points, 0.5, 0.5, 0.5);
    cleardevice(); 
    drawcube(points);
    getch();

    closegraph();
    return 0;
}
