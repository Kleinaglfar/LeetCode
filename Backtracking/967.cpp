#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int gap;
    vector<int> numsSameConsecDiff(int n, int k)
    {
        gap = k;
        vector<int> res{};
        helper(res, 0, n, 0);
        return res;
    }
    void helper(vector<int> &res, int current, int n, int cur)
    {
        if (current == 0)
        {
            if (gap <= 5)
            {
                for (auto i = 1; i <= 9; i++)
                    helper(res, i, n, 1);
            }
            else
            {
                for (auto i = 1; i <= 9 - gap; i++)
                    helper(res, i, n, 1);
                for (auto i = 9; i >= gap; i--)
                    helper(res, i, n, 1);
            }
        }
        else
        {
            if (cur == n)
            {
                res.push_back(current);
                return;
            }
            else
            {
                int lastnum = current % 10;
                if (gap == 0)
                    helper(res, current * 10 + lastnum, n, cur + 1);
                else
                {
                    if (lastnum + gap < 10)
                    {
                        helper(res, current * 10 + lastnum + gap, n, cur + 1);
                    }
                    if (lastnum - gap >= 0)
                    {
                        helper(res, current * 10 + lastnum - gap, n, cur + 1);
                    }
                }
            }
        }
    }
};