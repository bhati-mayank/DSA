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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        int maxSum = INT_MIN;
        int resultLevel = 0;
        int currLevel = 1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int sum = 0;

            while(size--){
                TreeNode* temp = q.front();
                q.pop();

                sum = sum + temp->val;

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(sum > maxSum){
                maxSum = sum;
                resultLevel = currLevel;
            }
            currLevel++;
        }

        return resultLevel;
    }
};