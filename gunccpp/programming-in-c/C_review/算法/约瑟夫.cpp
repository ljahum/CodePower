#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int arr[100];
int n,m;
int add(int p){
    p=(p+1)%(n);  
    while (arr[p]==0)
    {
        p=(p+1)%(n);
    }
    return p;
    
}

int main(){
    
    
    
    cin>>n>>m;
    int left=n;
    int p=0,time=0;


    for (int i = 0; i < n; i++)
    {
        arr[i]=1;
    }
    while (left>1)
    {
        if(time==m-1){
            arr[p]=0;//出队
            left--;
            getchar();
        }
        time=(time+1)%m;
        p=add(p);

        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<"time"<<time<<" "<<"p"<<p<<" left"<<left<<endl;
        getchar();
    }
    
    
}