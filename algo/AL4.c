//Boyer Moore String Matching Algorithm
#include <stdio.h>
#include <string.h>
int search(char *str, char *pattern){
  int n = strlen(str);
  int m = strlen(pattern);
  int lps[m];
  int i = 0;
  int j = 0;
  lps[0] = 0;
  while(i<m-1){
    if(pattern[i] == pattern[j]){
      lps[i+1] = j+1;
      i++;
      j++;
    }
    else{
      if(j!=0){
        j = lps[j-1];
      }
      else{
        lps[i+1] = 0;
        i++;
      }
    }
  }
  i = 0;
  j = 0;
  while(i<n){
    if(str[i] == pattern[j]){
      i++;
      j++;
    }
    if(j == m){
      printf("Pattern found at index %d\n",i-j);
      j = lps[j-1];
    }
    else if(i<n && str[i] != pattern[j]){
      if(j!=0){
        j = lps[j-1];
      }
      else{
        i++;
      }
    }
  }
  return 0;
}
int main(){
  char str[100] = "foxjumpsoverthelazydog";
  char pattern[100] = "ov";
  search(str,pattern);
  return 0;
}