#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupStrings(vector<string> &strings)
    {
        int count = 1;
        unordered_map<string, int> ump{};
        vector<vector<string>> res{};
        for (int i = 0; i < strings.size(); i++)
        {
            string temp = strings[i];
            int gap = temp[0] - 'a';
            for (int j = 0; j < temp.size(); j++)
            {
                temp[j] = temp[j] - gap >= 'a' ? temp[j] - gap : temp[j] - gap + 26;
            }
            if (ump[temp] != 0)
            {
                res[ump[temp] - 1].push_back(strings[i]);
            }
            else
            {
                ump[temp] = count;
                count++;
                res.push_back({strings[i]});
            }
        }
        return res;
    }
};