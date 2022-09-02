#include <algorithm>
#include <vector>
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
     vector<double> res{};
    vector<int> levelCount{};
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
       
        helper(root,0);
        for(auto i=0;i<res.size();i++){
            res[i]=res[i]/levelCount[i];
        }
        return res;
    }
    void helper(TreeNode* root,int level){
        if(!root) return;
        if(res.size()<=level){
            res.push_back(root->val);
            levelCount.push_back(1);
        }
        else{
            res[level]+=root->val;
            levelCount[level]++;
        }
        helper(root->left,level+1);
        helper(root->right,level+1);
    }
};