#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int rev(int n){
	int ans=0;
	while(n!=0){
		ans*=10;
		ans+=n%10;
		n/=10;
	}
	return ans;
	
}
bool find(int n){
	int arr[100];
	int len=0;
	while(n!=0){
		
		arr[len]=n%10;
		n/=10;
		len++;
	}
//	cout<<"len "<<len<<endl;
	for(int i=0;i<len/2;i++){
//		cout<<"arr[i] != arr[len-i]"<<arr[i]<<" "<<arr[len-i-1]<<endl;
		if(arr[i] != arr[len-i-1]){
			return false;
		}
	}
	return true;
}


int main(){
	int n,time=0;
	cin >> n;
	while(find(n)==false){
		n=n+rev(n);
		time++;
//		cout<<"n "<<n<<endl;
//		system("pause");
	}
	cout<<time<<" "<<n;
}














