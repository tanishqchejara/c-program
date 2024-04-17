//pattern search algorithm
#include <stdio.h>
#include<string.h>

void search(char *str, char *pattern){
  int n = strlen(str);
  int m = strlen(pattern);
  for(int i = 0;i<=n-m;i++){
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
}

int main(){
  char str[100] = "foxjumpsoverthelazydog";
  char pattern[100] = "lazy";
  search(str,pattern);
  return 0;
}