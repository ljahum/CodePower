#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int map[3000][3000];
void debug(){
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(map[i][j]!=16843009)
				cout<<map[i][j]<<" ";
			else
				cout<<"x ";
		}
		cout<<endl;
	}
	cout<<endl;
	system("pause");
}
int main(){
	memset(map,1,sizeof(map));
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>map[a][b];
		map[b][a]=map[a][b];
		map[i][i]=0;
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			for(int c=1;c<=n;c++){
				if(map[a][b]>(map[a][c]+map[c][b])){
					map[a][b]=map[a][c]+map[c][b];
					map[b][a]=map[a][b];
					
					
				}
				
			}
				
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<map[1][i]<<" ";
//		
//	}
	cout<<map[1][n];
	return 0;
}
/*
5 5
1 2 20
2 3 30
3 4 20
4 5 20
1 5 100
*/