#include <algorithm>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res=0;
        helper(root,root->val,res);
        return res;
    }
    void helper(TreeNode* root,int max,int& res){
        if(!root) return;
        if(max<=root->val){
            res++;
            max=root->val;
        }
        helper(root->left,max,res);
        helper(root->right,max,res);
    }
};