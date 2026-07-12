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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> result;

        queue<TreeNode*> q;
        q.push(root);


        while(!q.empty()){
            double size = q.size();
            double s = size;
            double sum = 0;

            while(s--){
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left != NULL)
                    q.push(node->left);

                if(node->right != NULL)
                    q.push(node->right);
            }
            double avg =(double)sum/size;
            result.push_back(avg);
        }

        return result;
    }
};