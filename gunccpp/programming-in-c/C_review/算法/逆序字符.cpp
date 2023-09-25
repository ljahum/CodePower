#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int main(){
    string str;
    cin>>str;
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    return 0;


}