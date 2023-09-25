#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
 
typedef struct Node {
  int data;
  struct Node * pNext;
}NODE,* PNODE;

typedef struct Stack {
  PNODE pTop;
  PNODE pBottom;
}STACK , * pSTACK;

void init(pSTACK);
void push(pSTACK,int);
void pop(pSTACK);
void view(pSTACK);
bool isempty(pSTACK);
int main(void)
{
  
  STACK stk;
  init(&stk);
  push(&stk,1);
  push(&stk,2);
  push(&stk,3);
  view(&stk);
  pop(&stk);
  view(&stk);
  return 0;
}
bool isempty(pSTACK ps){
  if(ps->pTop==ps->pBottom){
    true;
  }
  return false;

}
void pop(pSTACK ps){
  PNODE p;
  if(isempty(ps)==true){
    printf("栈空 操作失败\n"); 
    return;
  }
  p = ps->pTop;
  ps->pTop=p->pNext;
  free(p);
  p=NULL;
  printf("出栈成功\n");
  return;
}

void view(pSTACK ps){
  PNODE p = ps->pTop;
  printf("由顶到底\n");
  while(p!=ps->pBottom){
    printf("%d\n",p->data);
    p=p->pNext;
  }
  printf("\n");
  return;
}

void push(pSTACK pstk,int val){
  PNODE pNew = (PNODE)malloc(sizeof(NODE));
  
  pNew->data = val;
  pNew->pNext=pstk->pTop;
  pstk->pTop=pNew;
  return;
}

void init(pSTACK pstk)
{
  pstk->pTop=(PNODE)malloc(sizeof(NODE));
  if(pstk->pTop!=NULL)
    printf("初始化成功\n");
  
  //该ptop里面的node就是tail节点
  //注意栈在硬件上低进高出top在下bottom在上
  //初始化head->next为空
  pstk->pTop->pNext=NULL;

  pstk->pBottom=pstk->pTop;
  //站长度为0,esp=ebp
}
