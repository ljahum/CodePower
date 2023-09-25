#include <stdio.h>
#include<stdlib.h>
#include <cstring>
#incldue <iostream>
using namespace std;
int map[10][10];
int step[10][10];
int n;
void debug(){
	for(int i=0;i<n;i++){
		for(int j=0;j<i;i++){
			cout<<step[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	system("pause");
}
int main(){
	
	cin>> n;
	for(int i=0;i<n;i++)
		for(intj=0;j<i;j++)
			cin>>map[i][j];
			
	for(int i=0;i<n;i++){
		step[n-1][i]=map[n-1][i]
	}
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<=i;j++){
			if(step[i+1][j]>step[i+1][j+1]){
				step[i][j]=step[i+1][j]+map[i][j];
			}else{
				step[i][j]=step[i+1][j+1]+map[i][j];
			}
			debug();
		}
	}
	cout<<step[0][0];
}