// Topological sort when considering dependencies between
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <set>
#include <queue>
using namespace std;
struct Node
{
    unordered_set<Node *> prev;
    unordered_set<Node *> next;
    char val;
    Node(char v) : val(v), next({}), prev({}) {}
};
class Solution
{
    unordered_map<char, Node *> track{};

public:
    string alienOrder(vector<string> &words)
    {
        if (words.size() == 1)
        {
            set<char> temp{};
            for (auto i : words[0])
                temp.insert(i);
            string res = "";
            set<char>::iterator it;
            for (it = temp.begin(); it != temp.end(); it++)
                res += *it;
            return res;
        }
        for (auto i = 0; i < words.size() - 1; i++)
        {
            string word1 = words[i];
            string word2 = words[i + 1];
            int pos = 0;
            for (int j = 0; j < min(word1.size(), word2.size()); j++)
            {
                pos++;
                addrelation(word1[j], word2[j]);
                if (word1[j] != word2[j])
                {
                    goto end;
                }
            }
            if (word2.size() < word1.size())
            {
                return "";
            }
        end:
            for (int k = pos; k < word2.size(); k++)
            {
                if (!track[word2[k]])
                {
                    Node *pointer = new Node(word2[k]);
                    track[word2[k]] = pointer;
                }
            }
            for (int k = pos; k < word1.size(); k++)
            {
                if (!track[word1[k]])
                {
                    Node *pointer = new Node(word1[k]);
                    track[word1[k]] = pointer;
                }
            }
        }
        auto k = track;
        string res = "";
        toposort(res);
        return res;
    }
    void addrelation(char a, char b)
    {
        Node *apointer;
        Node *bpointer;
        if (!track[a])
        {
            apointer = new Node(a);
            track[a] = apointer;
        }
        else
            apointer = track[a];
        if (!track[b])
        {
            bpointer = new Node(b);
            track[b] = bpointer;
        }
        else
            bpointer = track[b];
        if (a != b && apointer->next.find(bpointer) == apointer->next.end())
        {
            apointer->next.insert(bpointer);
            bpointer->prev.insert(apointer);
        }
    }
    void toposort(string &res)
    {
        queue<char> q{};
        unordered_set<char> s{};
        unordered_map<char, Node *>::iterator it;
        for (it = track.begin(); it != track.end(); it++)
        {
            char c = it->first;
            if (track[c]->prev.size() == 0)
            {
                q.push(c);
                s.insert(c);
            }
        }
        while (!q.empty())
        {
            char temp = q.front();
            res += temp;
            q.pop();
            for (auto i : track[temp]->next)
            {
                i->prev.erase(track[temp]);
            }
            for (it = track.begin(); it != track.end(); it++)
            {
                char c = it->first;
                if (s.find(c) != s.end())
                    continue;
                if (track[c]->prev.size() == 0)
                {
                    q.push(c);
                    s.insert(c);
                }
            }
        }
        if (track.size() > res.size())
            res = "";
    }
};