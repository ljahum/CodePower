#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int map[100][100];
void debug(int n){
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if(map[i][j]==0xffff)
                printf("X ");
            else
                printf("%-2d",map[i][j]);
        }
        cout<<endl;
    }
    getchar();
    cout<<endl;
}
int main(){
    int n,m ;
    int p1,p2;
    int value;
    cin>>n>>m;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++){
            if(i==j)
                map[i][j]=0;
            else
                map[i][j]=0xffff;
        }
    }
    // debug(n);   
    for (int i = 1; i <=m; i++)
    {
        cin>>p1>>p2>>value;
        map[p1][p2]=value;
        map[p2][p1]=value;
    }
    // debug(n);
    for(int p1=1;p1<n;p1++){
        for (int p2 = 1; p2 <=n; p2++)
        {
            if(p1!=p2){
                for (int p3 = 1; p3 <=n; p3++)
                {
                    if((p3!=p1 && p3!=p2) && (map[p1][p3]+map[p3][p2])<map[p1][p2]){
                        int newValue=map[p1][p3]+map[p3][p2];
                        map[p1][p2]=map[p2][p1]=newValue;
                    }

                }
            }
        }
        // debug(n);
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<map[1][i]<<" ";
    }
    cout<<endl;
    
}