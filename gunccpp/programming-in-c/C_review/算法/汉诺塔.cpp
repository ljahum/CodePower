
#include<iostream>
#include<stdio.h>
using namespace std;
int tot=0;
void move(int n,char a,char b,char c){
	cout<<"n="<<n<<endl;
	if(n==1){
		printf("\t%c->%c\n",a,c);
		tot++;
	}else{
		move(n-1,a,c,b); //n-1 from a by c to b
		printf("\t%c->%c\n",a,c);
		tot++;
		move(n-1,b,a,c); //n-1 from b by a to c

	}
}
int main(){
	int n;
	cin>>n;
	move(n,'a','b','c');
	cout<<tot<<endl;
	return 0;
}