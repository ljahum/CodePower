#include<stdio.h>
int main(){
    int n,m,s=0;
    scanf("%d %d",&n,&m);
    for(int i=2;i<=n;i++){
        s=(s+m)%i;
    }
    printf("%d",s);//666
}