#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> dp(n);
        long long mod = 1e9 + 7;
        long long ans = 0 ;
        

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                /* code */
            }
            
        }
    }
};


int main(){

    // vector<int> nums{1,2,3,0,0,0};
    vector<int> arr{3,1,2};

    Solution sol;
    sol.sumSubarrayMins(arr);
    // cout << ans << endl;
    return 0;

}

/*class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        double res = numeric_limits<double>::max();
        for (int i = 0; i < n / 2; i++) {
            res = min(res, (nums[i] + nums[n - 1 - i]) / 2.0);
        }
        return res;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/minimum-average-of-smallest-and-largest-elements/solutions/2943777/zui-xiao-yuan-su-he-zui-da-yuan-su-de-zu-2kab/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
