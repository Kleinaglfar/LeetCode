#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <set>
#include <queue>
using namespace std;
// what is better than hard code?
// just kidding:)
class Solution
{
public:
    string intToRoman(int num)
    {
        int a = num / 1000;
        int b = (num / 100) % 10;
        int c = (num / 10) % 10;
        int d = num % 10;
        vector<string> A = {"", "M", "MM", "MMM"};
        vector<string> B = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> C = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> D = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return A[a] + B[b] + C[c] + D[d];
    }
};