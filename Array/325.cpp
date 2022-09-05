// prefix sum is useful when it seems like there is only brute force in an array problem
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
    int maxSubArrayLen(vector<int> &nums, int k)
    {
        unordered_map<long, int> ump{};
        long sum = 0;
        int res = 0;
        ump[0] = -1;
        for (auto i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (ump.find(sum) == ump.end())
                ump[sum] = i;
            if (ump.find(sum - k) != ump.end())
            {
                res = max(res, i - ump[sum - k]);
            }
        }
        return res;
    }
};