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
    typedef unsigned long long ll;
    
    int widthOfBinaryTree(TreeNode* root) {
        int maxW = INT_MIN;

        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});

        while(!q.empty()){
            ll L = q.front().second;
            ll R = q.back().second;

            maxW = max(maxW, (int)(R-L+1));

            ll size = q.size();

            while(size--){
                TreeNode* node = q.front().first;
                ll indx = q.front().second;

                q.pop();

                if(node->left != NULL)
                    q.push({node->left, 2*indx+1});

                if(node->right != NULL)
                    q.push({node->right, 2*indx+2});
            }
        }

        return maxW;

    }
};