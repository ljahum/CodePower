#include<iostream>
#include<stdio.h>
using namespace std;
int map[100][100];
int main(){
	
	
	int n,x=0,y=0;
	cin >>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			map[i][j]=0;
		}
	
	}
	map[0][0]=1;
	int k=1;
	while(k<n*n){
		while(x+1<n && map[x+1][y]==0){
			x++;k++;map[x][y]=k;
		}
		while(y+1<n && map[x][y+1]==0){
			y++;k++;map[x][y]=k;
		}
		
		while(x-1 >= 0 && map[x-1][y]==0){
			x--;k++;map[x][y]=k;
		}
		while(y-1 >= 0 && map[x][y-1]==0){
			y--;k++;map[x][y]=k;
		}
		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%-2d",map[j][i]);
		}
		printf("\n");
	}
}