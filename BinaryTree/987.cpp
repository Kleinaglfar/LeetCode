#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <set>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct CoordTreeNode
{
    TreeNode *node;
    vector<int> coord;
    CoordTreeNode(TreeNode *n, int i, int j) : node(n), coord({i, j}) {}
};
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        auto comp = [](vector<int> a, vector<int> b) -> bool
        {
            if (a[1] < b[1])
                return false;
            if (a[1] > b[1])
                return true;
            if (a[0] > b[0])
                return true;
            if (a[0] < b[0])
                return false;
            if (a[2] > b[2])
                return true;
            else
                return false;
        };
        vector<vector<int>> res{};
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> samelevelsort(comp);
        queue<CoordTreeNode *> bfsq{};
        int count = 1;
        int levelcount = 0;
        CoordTreeNode *croot = new CoordTreeNode(root, 0, 0);
        bfsq.push(croot);
        while (!bfsq.empty())
        {
            auto node = bfsq.front();
            samelevelsort.push({node->coord[0], node->coord[1], node->node->val});
            bfsq.pop();
            if (node->node->left)
            {
                CoordTreeNode *lefttnode = new CoordTreeNode(node->node->left, node->coord[0] + 1, node->coord[1] - 1);
                bfsq.push(lefttnode);
            }
            if (node->node->right)
            {
                CoordTreeNode *righttnode = new CoordTreeNode(node->node->right, node->coord[0] + 1, node->coord[1] + 1);
                bfsq.push(righttnode);
            }
        }
        int offset = -samelevelsort.top()[1];
        while (!samelevelsort.empty())
        {
            auto current = samelevelsort.top();
            if (current[1] + offset >= res.size())
                res.push_back({});
            res[current[1] + offset].push_back(current[2]);
            samelevelsort.pop();
        }
        return res;
    }
};