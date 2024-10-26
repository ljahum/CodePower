#include <iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        
        int n = skills.size();
        
        int p1=0,bigone=0;
        int winwin=0;
        while (p1 <n-1) // 如果p1没有到底
        {
            int p2=p1+1; // 从 p1 下一位开始
            while (p2<n) //
            {   
                cout<<"p1="<<p1<<" p2="<<p2<<endl;
                system("pause");
                if(skills[p1] > skills[p2]) // 
                    winwin++;
                if(winwin >= k){
                    return p1;//当前元素通关
                }  
                if(skills[p1] < skills[p2])//p1 lose
                {   
                    // cout<<"break p1="<<p1<<" p2="<<p2<<endl;
                    winwin =1;
                    bigone = p2;     
                    break;
                }
  
                p2++;
            }
            
            p1=p2; 
        }

        
        
        return bigone;
        

    }
};


int main(){
    // [4,8,9,7]
    vector<int> skills  = {4,18,17,20,15,12,8,5};//[0,1,2,3,4]
    // vector<int> skills  = {4,8,9,7};//[0,1,2,3,4]
    int k =1;
    Solution sol;
    int ans = sol.findWinningPlayer(skills,k);
    cout << ans;
    return ans;
}