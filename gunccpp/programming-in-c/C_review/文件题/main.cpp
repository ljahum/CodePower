#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;

int main(){
    int tot=0;
    freopen("./text.txt","r",stdin);//stdin 表示占用输入流
    freopen("./out.txt","w",stdout);
    char str[1000];
    scanf("%s",str);
    for(int i = 0;i < strlen(str);i++){
        if(str[i]=='1')
            tot++;

    }
    printf("%d",tot);
    return 0;
}

