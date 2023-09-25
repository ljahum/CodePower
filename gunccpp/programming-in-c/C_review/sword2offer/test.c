#include<stdio.h>

void func(){
    static n=10;
    n++;
    printf("n=%d\n",n);
    if(n==20){
        return;
    }
    func();

}
int main()
{
    func();
    // func();
    return 0;
}
