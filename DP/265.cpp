
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <set>
#include <queue>
using namespace std;
class Solution
{
public:
    int minCostII(vector<vector<int>> &costs)
    {
        vector<int> dp = costs[0];
        vector<int> dpcurrent = {};

        for (int i = 1; i < costs.size(); i++)
        {
            priority_queue<int, vector<int>, greater<int>> pq{};
            for (auto i : dp)
                pq.push(i);
            int max = pq.top();
            pq.pop();
            int secondmax = pq.top();
            for (int j = 0; j < costs[0].size(); j++)
            {
                if (dp[j] != max)
                {
                    dpcurrent.push_back(costs[i][j] + max);
                }
                else
                    dpcurrent.push_back(costs[i][j] + secondmax);
            }
            while (!pq.empty())
                pq.pop();
            dp.clear();
            dp = dpcurrent;
            dpcurrent.clear();
        }
        int res = INT_MAX;
        for (auto i : dp)
            res = min(i, res);
        return res;
    }
};