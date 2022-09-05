#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (!root)
            return {};
        queue<Node *> q{};
        q.push(root);
        vector<vector<int>> res{};
        int count = 1;
        int levelcount = 0;
        while (!q.empty())
        {
            res.push_back({});
            for (auto i = 0; i < count; i++)
            {
                auto node = q.front();
                q.pop();
                res[res.size() - 1].push_back(node->val);
                for (auto j : node->children)
                {
                    q.push(j);
                    levelcount++;
                }
            }
            count = levelcount;
            levelcount = 0;
        }
        return res;
    }
};