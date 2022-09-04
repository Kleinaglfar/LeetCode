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
    int shortestWordDistance(vector<string> &wordsDict, string word1, string word2)
    {
        int pointer1 = -1;
        int pointer2 = -1;
        int res = INT_MAX;
        for (int i = 0; i < wordsDict.size(); i++)
        {
            string currentword = wordsDict[i];
            if (word1 == currentword && word2 == word1)
            {
                pointer1 <= pointer2 ? pointer1 = i : pointer2 = i;
                if (pointer2 != -1)
                    res = min(res, abs(pointer1 - pointer2));
            }
            else
            {
                if (word1 == currentword)
                {
                    pointer1 = i;
                    if (pointer2 != -1)
                        res = min(res, abs(pointer1 - pointer2));
                }
                if (word2 == currentword)
                {
                    pointer2 = i;
                    if (pointer1 != -1)
                        res = min(res, abs(pointer1 - pointer2));
                }
            }
        }
        return res;
    }
};