#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <set>
#include <queue>
using namespace std;
class Codec
{
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs)
    {
        string header = "";
        string body = "";
        for (auto i : strs)
        {
            header = header + to_string(i.size()) + '#';
            body += i;
        }
        return header + '!' + body;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {
        vector<int> lengtharr{};
        string currentlength = "";
        int startstring = 0;
        for (auto i : s)
        {
            if (i == '!')
                break;
            if (i == '#')
            {
                lengtharr.push_back(stoi(currentlength));
                currentlength = "";
            }
            else
                currentlength += i;
            startstring++;
        }
        startstring++;
        vector<string> res{};
        string currentstring = "";
        for (int i = 0; i < lengtharr.size(); i++)
        {
            for (int j = 0; j < lengtharr[i]; j++)
            {
                currentstring += s[startstring];
                startstring++;
            }
            res.push_back(currentstring);
            currentstring = "";
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));