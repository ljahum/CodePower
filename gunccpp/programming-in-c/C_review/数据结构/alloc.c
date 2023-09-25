#include<stdio.h>
#include <malloc.h>
int main(){
  printf("hello world\n");
  int * pArr = (int*)malloc(sizeof(int)*20);
  //malloc仅返回该连续内存的首地址
  *(pArr) = 10;
  pArr[1]=20;
  printf("%d %d\n",pArr[0],*(pArr+1));
  free(pArr);

  return 0;
}
