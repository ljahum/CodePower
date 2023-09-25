#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int n;
int map[100][100];
//int step[100];
bool in_set[100];
int cloestPoint_toset[100]={0};//需要维护两个链表
int lowestStep_pointToset[100]={0};
int tot=0;

void debug(){
	cout<<"next point to set\n";
	for(int i=1;i<=n;i++)	
	{
		cout<<cloestPoint_toset[i]<<" ";
	}
	cout<<endl;
	cout<<"coast of next way\n";
	for(int i=1;i<=n;i++)	
	{
		
		cout<<lowestStep_pointToset[i]<<" ";
	}
	system("pause");
}	
void add_newp_toset(){
	int newpoint=-1;
	int step=0xffff;
	for(int b=1;b<=n;b++){
		if(in_set[b]==false && step>lowestStep_pointToset[b])
		{
			step = lowestStep_pointToset[b];
			newpoint = b;
		}
	}
	if(newpoint!=-1){
		in_set[newpoint]=true;
		cout<<"new point added "<<newpoint<<endl;
		tot+=step;
	}
	//updata lowestStep
	for(int c=1;c<=n;c++){
		if(in_set[c]==false && lowestStep_pointToset[c]> map[c][newpoint])
		{
			lowestStep_pointToset[c]=map[c][newpoint];
		}
	}
	
	debug();
}

void Prime(){
	//init frist point
	for(int i=1;i<=n;i++){
		lowestStep_pointToset[i]=map[1][i];
		in_set[i]=false;
		cloestPoint_toset[i]=1;
	}	
	in_set[1]=true;
	for(int i=1;i<=n;i++)
	{
		add_newp_toset();	
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>map[i][j];
	Prime();
	cout<<"lowest coast:"<<tot<<endl;
}

/*
4
0 1 10 10 
1 0 1 10
10 1 0 1
10 10 1 0

*/