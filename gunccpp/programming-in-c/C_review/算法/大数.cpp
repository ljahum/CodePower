#include<stdio.h>
#include<iostream>
using namespace std;
char str[100000];
int main(){
	int ans=0;
	scanf("%s",&str);
	int len=strlen(str);
	if(str[0]=='-')
	{
		for(int i=1;i<len;i++){
			ans=(ans*10+str[i]-'0')%9;
		}	
		ans = 9-ans;
	}else{
		for(int i=0;i<len;i++){
			ans=(ans*10+str[i]-'0')%9;
		}	
		
	}
	printf("%d",ans);
	return 0;
	
}