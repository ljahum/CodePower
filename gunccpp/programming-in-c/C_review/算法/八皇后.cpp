#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int map[8][8];
int find(int y);
bool istaken(int x,int y);
// void lock(int x,int y);
// void unlock(int x,int y);
int main(){
    int tot;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        map[i][j]=1;
    }
    tot=find(0);
    cout<<tot<<endl;

    return 0;
}

void debug(){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout<<map[j][i];
        cout<<endl;
    }
    getchar();
}
int find(int y){
    
    int ans=0;
    if(y == 8){
        // debug();
        
        return 1;
    }else{
        
        for (int x = 0; x < 8; x++)
        {
            if(istaken(x,y)==false){
                map[x][y]=0;            
                ans += find(y+1);
                map[x][y]=1;
            }
        }
        return ans;
    }
}

bool istaken(int x,int y){
    for (int i = 0; i < 8; i++)
    {
        if(map[x][i]==0||map[i][y]==0)
            return true;
        
    }
    for (int i = 0; i < 8; i++)
    {
        if(x+i<8 && y+i<8)
        {
            if(map[x+i][y+i]==0){
                return true;
            }
        }else{
            break;
        }
        
    }
    for (int i = 0; i < 8; i++)
    {
        if(x-i>=0 && y-i>=0)
        {
            if(map[x-i][y-i]==0){
                return true;
            }
        }else{
            break;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if(x+i<8 && y-i>=0)
        {
            if(map[x+i][y-i]==0){
                return true;
            }
        }else{
            break;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if(x-i>=0 && y+i<8)
        {
            if(map[x-i][y+i]==0){
                return true;
            }
        }else{
            break;
        }
    }
    return false;
    
}
