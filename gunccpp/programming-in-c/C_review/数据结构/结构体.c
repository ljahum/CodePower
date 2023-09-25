#include <stdio.h>
#include <string.h>
#define EXIT_SUCCES 0
#include <string.h>
struct Student{
    int sid;
    char name[20];
    int age;
} ;

void debug(struct Student * pst){
  printf("%d %s %d\n",pst->sid,pst->name,pst->age);
}

void func(struct Student * pst){//传入地址用指针接受
                                //用时存较小
  (*pst).sid = 98;
//  pst->nam/* e */
  strcpy(pst->name,"yuanhaitaoshiwoer");
  pst->age=19;
}
int main()
{
    
  struct Student st={1000,"ljahum",20};//只有这里申请的内存
  st.sid=1001;//第一种写法
  struct Student * pst;
  pst = &st;
  pst->sid=99;//等价(*pst).sid=st.sid
  debug(&st);            
  func(&st);    
  debug(&st);//如果不传入地址而是传入整个结构体则会将原来的结构体赋值一边送进去
             //所谓形参
  return 0;

}
