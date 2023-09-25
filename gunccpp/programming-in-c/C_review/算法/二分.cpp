#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;
int main(){
	int n,m;
	int arr[100];//有序数组
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	cin>>m;
	int p = n/2;
	int p1=1,p2=n;
	while(arr[p]!=m){
		
		if(arr[p]<m){
			p1=p;
			p = (p+p2+1)/2;//考虑精度缺失
		}
		else{
			p2=p;
			p=(p+p1)/2;
		}
		cout<<"p "<<p<<" p1 "<<p1<<" p2 "<<p2<<endl;
		if(p1==p2 || p1+1==p2){
			cout<<"not found"<<endl;
			p=-1;
			break;
		}
		system("pause");
		
	}
	cout<<"index "<<p;
	return 0;
	
	
}

/*
11
1 3 3 3 5 7 9 11 13 15 15
*/
