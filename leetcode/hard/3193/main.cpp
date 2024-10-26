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
            return 0; // ������ֻ��һ��Ԫ���Ҳ�Ϊ0ʱ�������ܴ�����������ֱ�ӷ���0
        }

        // �ҵ�req����������Ԫ��ֵ
        auto max_it = max_element(req.begin(), req.end());
        int m = *max_it;
        // ��ʼ����̬�滮�Ķ�ά���飬���ڻ����м�������߼���Ч��
        vector<vector<int>> memo(n, vector<int>(m + 1, -1));

        // ʹ��lambda���ʽ������������������������ڼ���������
        //N -> ��ǰλ�� req_new -> ��ǰλ�õ��Ѿ����������
        auto dfs = [&](auto&& dfs, int N, int req_new) -> int {
            // �����������鿪ͷʱ�����سɹ���һ�ַ�����
            if (N == 0) {
                return 1;
            }
            // ʹ�����ú͵�ǰ״̬��memo���������洢���
            int& res = memo[N][req_new];
            // ����Ѿ��������ǰ״̬����ֱ�ӷ��ؽ��
            if (res != -1) {
                return res;
            }
            // ��ʼ����ǰ״̬�Ľ��Ϊ0
            res = 0;
            // ���req[N-1]�Ǹ����������ض����������㵥���ݹ���
            // int req_n = req[N - 1]; // ǰnλ��Ҫ�ṩ�ĸ���
            if (  req[N - 1]>= 0) { // ��Լ����k=req[N - 1]
                int k = req[N - 1]; //��ǰλ���ṩ�ĸ����ǹ̶���
                if (req_new -k >= 0     // N-2 ..... N=0�����ṩ0�� �ܺ����
                && req_new -k <= N) { 
//�ṩ 0 ..... req-k k
//�±� ........N-1   N
                    // k �ķ�Χ�� 0-N
                    //  req - k �ķ�ΧҲӦ���� 0-N                    
                    res = dfs(dfs, N - 1, k);
                }
            } else {
                // ���req[N-1]Ϊ�����������п��ܵ�ѡ����ۼӽ��
                for (int k = 0; k <= min(N, req_new); k++) { //���� k

                    int next_req = req_new - k;
                    int next_N = N - 1;
                    res = (res + dfs(dfs, next_N, next_req)) % MOD;
                }
            }
            // ���ص�ǰ״̬�Ľ��
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
