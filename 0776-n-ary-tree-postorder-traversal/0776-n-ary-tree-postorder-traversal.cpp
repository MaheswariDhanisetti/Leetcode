/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

void solve(Node* root , vector<int>&res){
    if(root==NULL) return;

    for(auto child:root->children){
        solve(child,res);
    }
    res.push_back(root->val);
}

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>res;
        solve(root,res);
        return res;
    }
};