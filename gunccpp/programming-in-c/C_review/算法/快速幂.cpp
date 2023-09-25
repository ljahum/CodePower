#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int a=m;
    int ans=1;
    while (n!=0)
    {
        if(n&1==1){
            ans=ans*a;
        }
        a=a*a;
        n=n>>1;

    }
    cout<<ans;
}