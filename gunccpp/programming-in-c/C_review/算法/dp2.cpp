#include <stdio.h>
#include<stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;
int a,b;
int map[1000];

int main(){
	cin>>a>>b;
	memset(map,1,sizeof(map));
	map[a]=0;
	for(int i=a;i<=b;i++){
		for(int j=1;j*j<i;j++){
			if(i%j==0){
				
				if(i+j<=b && map[i+j]>map[i]+1)//剪枝优化
					map[i+j]=map[i]+1;
				if(i+i/j<=b && map[i+i/j]>map[i]+1)
					map[i+i/j]=map[i]+1;
			}
		}
	}
	cout<<map[b];
}
/* 
4 13 
*/