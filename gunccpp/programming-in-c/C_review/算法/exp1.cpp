#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main(){
	int a,b,top;
	int time,dis;
	while(scanf("%d %d %d",&a,&b,&top)){
		time=0;dis=0;
		while(1){
			time+=1;
			dis+=a;
			if(dis>=top){
				cout<<time<<endl;
				break;
			}
			dis-=b;
		}
	}
}
/*
2 1 5
5 1 6
100 99 1000000000
*/