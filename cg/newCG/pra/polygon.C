#include<GRAPHICS.H>
#include<conio.h>
#include<STDIO.h>
#include<STDLIB.H>


int main(){
  int gd = DETECT,gm;
  int n, *x, i , k =0;

  int w[] = {
    100, 100, 200, 100, 200, 200, 100, 200,100,100
  };
  initgraph(&gd,&gm,(char *)"C://TURBOC3//BGI");
  setcolor(RED);
  drawpoly(5,w);
  
  printf("Enter number of vertices of polygon: ");
  scanf("%d",&n);

x = (int *)malloc(n * 2 * sizeof(int));

  printf("Enter vertices of polygon: ");
  k = 0;
  for(i=0;i<n*2;i+=2){
    printf("x%d y%d",k,k);
    scanf("%d %d",&x[i],&x[i+1]);
    k++;
  }
  x[n*2] = x[0];
  x[n*2+1] = x[1];
  setcolor(WHITE);
  drawpoly(n+1,x);
   printf("\nPress a button to clip a polygon..");
    getch();
    setcolor(RED);
    drawpoly(5,w);

    setfillstyle(SOLID_FILL, BLACK);
    floodfill(0, 0, RED);

    printf("\nThis is the clipped polygon..");
    getch();

    cleardevice();
    closegraph();
    free(x);
  return 0;
}