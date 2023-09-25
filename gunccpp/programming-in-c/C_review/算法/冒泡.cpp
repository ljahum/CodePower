#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int arr[1000],tmp;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n-1;i++){ //最后一个和自己排 省略
		for(int j=0;j<n-i-1;j++){ //倒数第二个和倒数第一个排 否则越界
			if(arr[j]>arr[j+1]){
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}