
//  Definition for a binary tree node.
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
    int longestConsecutive(TreeNode* root) {
        int max=0;
        helper(root,max);
        return max;
    }
    int helper(TreeNode* root,int& maxx){
        if(!root) return 0;
        int left=helper(root->left,maxx);
        int right=helper(root->right,maxx);
        if(root->left&&root->left->val==root->val+1)
            left++;
        else left=0;
        if(root->right&&root->right->val==root->val+1)
            right++;
        else right=0;
        maxx=max(maxx,max(left,max(right,1)));
        return max(left,max(right,1));
        
            
    }
};