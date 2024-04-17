//rabin krap algorithem
#include <stdio.h>
#include <string.h>

int search(char *str, char *pattern){
  int n = strlen(str);
  int m = strlen(pattern);  
  int d = 256;
  int q = 101;
  int h = 1;
  int p = 0;
  int t = 0;
  for(int i = 0;i<m-1;i++){
    h = (h*d)%q;
  }
  for(int i = 0;i<m;i++){
    p = (d*p + pattern[i])%q;
    t = (d*t + str[i])%q;
  }
  for(int i = 0;i<=n-m;i++){
    if(p == t){
      int j;
      for(j = 0;j<m;j++){
        if(str[i+j] != pattern[j]){
          break;
        }
      }
      if(j == m){
        printf("Pattern found at index %d\n",i);
      }
    }
    if(i < n-m){
      t = (d*(t-str[i]*h) + str[i+m])%q;
      if(t < 0){
        t = t + q;
      }
    }
  }
}
int main(){
  char str[100] = "foxjumpsoverthelazydog";
  char pattern[100] = "lazy";
  search(str,pattern);
  return 0;
}
