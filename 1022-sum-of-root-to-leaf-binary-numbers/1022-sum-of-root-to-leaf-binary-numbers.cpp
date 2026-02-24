/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int find_val(string tmp)
    {
        int res =0 , base = 0;

        for(int i =tmp.size()-1;i>=0;i--)
        {
            int val = tmp[i]-'0';

            res += (pow(2,base)*val);

            base++;
        }
        return res;
    }
    int solve(TreeNode* root , string tmp)
    {

        if(root->left == NULL and root->right==NULL){
            return find_val(tmp+(root->val==0?'0':'1'));
        }

        int lf = 0,rg =0;

        if(root->left!=NULL)
        {
            lf = solve(root->left , tmp+(root->val==0?'0':'1'));
        }

        if(root->right!=NULL)
        {
            rg = solve(root->right, tmp+(root->val==0?'0':'1'));
        }

        return rg+lf;

    }
    int sumRootToLeaf(TreeNode* root) {
        
        return solve(root , "");

    }
};
