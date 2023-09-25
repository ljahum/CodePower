#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
typedef struct Queue {
  int *pBase;
  int front;
  int rear;

}QUEUE;
void init(QUEUE *);
bool en_queue(QUEUE *,int val);
bool full(QUEUE *);
void traverse(QUEUE *); 
bool out_queue(QUEUE *,int *);
bool isempty(QUEUE *);
//
int main(void)
{
  QUEUE Q;
  int  val;
  init(&Q);
  en_queue(&Q,1);
  en_queue(&Q,2);
  en_queue(&Q,3);
  en_queue(&Q,4);
  en_queue(&Q,5);
  traverse(&Q);
  out_queue(&Q,&val);
  printf("取出队首元素%d\n",val);
  en_queue(&Q,10);
  traverse(&Q);
  return 0;
}
//
//void
//
bool isempty(QUEUE *pQ){
  if(pQ->rear==pQ->front)
    return true;
  return false;

}
bool out_queue(QUEUE *pQ,int * val){
  if(isempty(pQ)){
    printf("队空\n");
    return false;
  }
  *val = pQ->pBase[pQ->front];
  pQ->front=(pQ->front+1)%6;

}
void traverse(QUEUE * pQ){
  int i=pQ->front;
  while(i!=pQ->rear){
    printf("%d \n",pQ->pBase[i]);
    i = (i+1)%6;
  }
  return;
}
bool full(QUEUE * pQ){
  if((pQ->rear+1)%6==pQ->front){
    return true;
  }
  return false;

}
void init(QUEUE * pQ){
  pQ->pBase=(int*)malloc(sizeof(int)*6);//默认队只有6个空位
  pQ->front=0;
  pQ->rear=0;

}

bool en_queue(QUEUE * pQ,int val){//入队
  if (full(pQ)) {
    printf("队满\n");
    return false;
  }  
  pQ->pBase[pQ->rear]=val;
  pQ->rear = (pQ->rear+1)%6;
  return true;
  
}


