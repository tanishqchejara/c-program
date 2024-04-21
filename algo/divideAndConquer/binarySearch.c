//Binary search 
#include<stdio.h>

#define MAX_CHAR 64
/*
it used to find a position of a given
element in a sorted array.

it repeatedly divides the search interval in half,narrowing down 
the search space.

*/

/*
  working
  given a sorted array arr and element x.
  1.set the two pointer, low and high in array's lowest and highest position.
  2.calculate the mid = (low + high)/2.
  3.compare the x with mid
    1.if x equals arr[mid] then, found the element => return the mid.
    2.if x > arr[mid] then,
      search the right half by updating low = mid + 1.
    3.else search the left half by updating high = mid - 1
  4.repeate step 2 & 3,untill element is found.  
*/


int binarySearch(int arr[],int x,int low,int high){
  while(low <= high){
    int mid = (low + high)/2;
    if(x == arr[mid]){
      printf("Found Given Element: %d",arr[mid]);
      return arr[mid];
    }else if (x > arr[mid]){
      low = mid + 1;
    }else{
      high = mid - 1;
    }
  }
  return -1;
}

int main()
{
  int arr[] = {1,2,3,4,5,6,7,8,9,10,11}; 
  int high,low;
  low = 0;
  high = sizeof(arr)/sizeof(int) - 1;
  // printf("SIZE: %d",sizeof(arr)/sizeof(int));
  int result = binarySearch(arr,1,low,high);
  if(result == -1){
    printf("Element Not Found.");
  }
  return 0;
}
