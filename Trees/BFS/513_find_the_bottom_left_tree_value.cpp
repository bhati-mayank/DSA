#include<bits/stdc++.h>
using namespace std;


  struct TreeNode {
     int val;
     TreeNode *left;     TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int maxDepth;
    int ans;
    void Solve(TreeNode* root, int depth){
        if(root == NULL) return;
        if(depth > maxDepth){
            ans = root->val;
            maxDepth = depth;
        }
        Solve(root->left, depth+1);
        Solve(root->right, depth+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        maxDepth = -1;
        Solve(root, 0);
        return ans;
    }
};