#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int map[8][8];
int find(int x,int y);
bool istaken(int x,int y);
void lock(int x,int y);
void unlock(int x,int y);
int main(){
    int tot;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        map[i][j]=1;
    }
    tot=find(0);
    

    return 0;
}


int find(int y){
    int ans=0;
    if(y=8){
        return 1;
    }else{
        
        for (int x = 0; x < 8; x++)
        {
            if(istaken(x,y)==true){
                map[x][y]==0;
                ans++;
                
            }
        }
    
    }
}

bool istaken(int x,int y){
    for (int i = 0; i < 8; i++)
    {
        if(map[x][i]==0||map[y][x]==0)
            return false;
    }
    
}
