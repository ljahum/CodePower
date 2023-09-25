#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Node {
  int data;
  struct Node * pNext;
}Node, *pNode;//Node = struct Node , pNode = struct Node * 
              //
pNode creatList();
void traverseList(pNode pHead);
bool isempty(pNode);
bool insert(pNode phead,int index,int val);
bool delet(pNode phead,int index);
int main(){
  printf("helloworld\n");
  pNode phead=NULL;
  phead = creatList();
  traverseList(phead);
  insert(phead,1,10);
  isempty(phead);
  delet(phead,1);
  free(phead);
  return 0;
}

bool delet(pNode phead,int index){
  printf("申请删%d号节点\n",index );
  pNode p=phead;
  int i=0;
  while(i<index-1 && p->pNext!=NULL){
    p = p->pNext;
    i++;
  }
  if(i>index-1||p->pNext==NULL)
  {
    printf("删除失败\n");
    return false;
  }

  pNode p_next_one = p->pNext;
  p->pNext = p->pNext->pNext;
  free(p_next_one);
  printf("删除后的列表为\n");
  traverseList(phead);
  return true;
}

bool insert(pNode phead,int index,int val){
  printf("在%d号后插入%d\n",index,val);
  pNode p = phead->pNext;
  int i = 0;
  while(i<index-1 && p!=NULL){
    p = p->pNext;
    i++;
  }
  if(i>index-1||p==NULL)
  {
    printf("插入失败\n");
    return false;
  }
  pNode pNew = (pNode)malloc(sizeof(Node));
  pNew->data=val;
  pNew->pNext = p->pNext;
  p->pNext = pNew;
  printf("插入后链表值:\n");
  traverseList(phead);
}

void traverseList(pNode pHead){
  printf("输出所有元素\n");
  pNode pNew = pHead->pNext;
  while(pNew!=NULL)
  {
    printf("%d ",pNew->data);
    pNew=pNew->pNext;
  }
  printf("\n");
}
bool isempty(pNode phead){
  pNode pNew = phead->pNext;
  if(pNew == NULL){
    printf("数组为空\n");
    return true;
  }
  printf("数组不为空\n");
  return false;
}

pNode creatList(){
  int len;
  int tmp;
  printf("lenth:"); 
  scanf("%d", &len);
  
  pNode pHead = (pNode)malloc(sizeof(Node));
  pNode pTail = pHead;
  pTail->pNext = NULL;

  for(int i=0;i<len;i++){
    pNode pNew= (pNode)malloc(sizeof(Node));
  
    printf("%dth val:",i);
    scanf("%d",&tmp);
    pNew->data = tmp;
    pTail->pNext = pNew;//注意 头结点不存数据
    pNew->pNext = NULL;
    pTail = pNew;//尾巴向后移动
  } 
  return pHead;
}
