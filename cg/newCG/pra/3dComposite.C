#include<GRAPHICS.H>
#include<CONIO.H>
#include<STDIO.H>
#include<MATH.H>

void drawcube(int arr[7][3]){
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
    outtext("composite cube");
    // Apply translation (100, 100, 100)
    translateCube(points, 100, 100, 100);
    drawcube(points);
    getch();
    cleardevice(); 
    outtext("composite cube");
   
    // Apply scaling by a factor of 0.5 in all dimensions
    scaleCube(points, 0.5, 0.5, 0.5);
    drawcube(points);
    getch();
    cleardevice(); 

    closegraph();
    return 0;
}
