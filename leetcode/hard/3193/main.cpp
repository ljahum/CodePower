#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    const int MOD = 1'000'000'007;
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<int> req(n, -1);
        req[0] = 0;
        for (auto& p : requirements) {
            cout << "req["<< p[0]<<"] = "<<p[1]<<endl;
            req[p[0]] = p[1];
        }
    
        if (req[0] != 0) {
            return 0; // 当数组只有一个元素且不为0时，不可能存在逆序数，直接返回0
        }

        // 找到req数组中最大的元素值
        auto max_it = max_element(req.begin(), req.end());
        int m = *max_it;
        // 初始化动态规划的二维数组，用于缓存中间结果，提高计算效率
        vector<vector<int>> memo(n, vector<int>(m + 1, -1));

        // 使用lambda表达式定义深度优先搜索函数，用于计算逆序数
        //N -> 当前位置 req_new -> 当前位置的已经满足的组数
        auto dfs = [&](auto&& dfs, int N, int req_new) -> int {
            // 当遍历到数组开头时，返回成功的一种方案数
            if (N == 0) {
                return 1;
            }
            // 使用引用和当前状态的memo数组索引存储结果
            int& res = memo[N][req_new];
            // 如果已经计算过当前状态，则直接返回结果
            if (res != -1) {
                return res;
            }
            // 初始化当前状态的结果为0
            res = 0;
            // 如果req[N-1]非负，且满足特定条件，计算单个递归项
            // int req_n = req[N - 1]; // 前n位需要提供的个数
            if (  req[N - 1]>= 0) { // 有约束，k=req[N - 1]
                int k = req[N - 1]; //当前位置提供的个数是固定的
                if (req_new -k >= 0     // N-2 ..... N=0至少提供0个 很好理解
                && req_new -k <= N) { 
//提供 0 ..... req-k k
//下标 ........N-1   N
                    // k 的范围是 0-N
                    //  req - k 的范围也应该是 0-N                    
                    res = dfs(dfs, N - 1, k);
                }
            } else {
                // 如果req[N-1]为负，遍历所有可能的选项，并累加结果
                for (int k = 0; k <= min(N, req_new); k++) { //遍历 k

                    int next_req = req_new - k;
                    int next_N = N - 1;
                    res = (res + dfs(dfs, next_N, next_req)) % MOD;
                }
            }
            // 返回当前状态的结果
            return res;
        };

        return dfs(dfs, n - 1, req[n - 1]);

    }
};
int main()  {


    int n =3;
    vector<vector<int>> req = {{2,2},{1,1},{0,0}};

    // double ans = tmp.minimumAverage(nums);
    int ans = Solution().numberOfPermutations(n, req);
    cout << ans << endl;
    return 0;

}
