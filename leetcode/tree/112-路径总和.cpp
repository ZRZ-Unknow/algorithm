#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if(!root)  return false;
    if(!root->left && !root->right){
	if(root->val == targetSum)
	    return true;
        return false;
    }
    bool l = hasPathSum(root->left, targetSum-root->val);
    bool r = hasPathSum(root->right, targetSum-root->val);
    return l || r;
}

int main(){
    struct TreeNode node1(1), node3(2);
    struct TreeNode node2(2, NULL, &node3);
    struct TreeNode root(0, &node1, &node2);
    auto res = hasPathSum(&root, 4);
    cout<<res<<endl; 
    return 0;
}