#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
    sort(rewardValues.begin(), rewardValues.end());
    int dp_size = *max_element(rewardValues.begin(), rewardValues.end()); 
    
    // 最大元素，可以遍历的范围，再高就不得行了
    vector<int> dp(dp_size*2+1,0);
    dp[0]=1;
    for (int x: rewardValues)
    {
        dp[x] = 1;    
    }
    int ans=0;
    for (int last : rewardValues)
    {
        if(dp[last] == 1){
            for (int pre = 0; pre <= last -1 ; pre++)//额额，保证遍历的大小不超过lastone就行了。。。。简单dp
            {
                if(dp[pre]==1){
                    int tot = pre+last;
                    dp[tot] = 1;
                    ans = max(ans,tot);
                }   
            }
        }
    }
    return ans;
    }
};

int main() {
    Solution s;

    // vector<int> rewardValues{1,6,4,3,2};`
    // 1,1,3,3
    vector<int> rewardValues{1,1,3,3};
    cout<<s.maxTotalReward(rewardValues);
    return 0;
}