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

void dfs(TreeNode *node, int targetSum, vector<vector<int>> &res, vector<int> s){
    if(!node)  return;
    if(!node->left && !node->right){
        if(targetSum == node->val){
	    s.push_back(node->val);
	    res.push_back(s);
	}
    }else{
	s.push_back(node->val);
	dfs(node->left, targetSum-node->val, res, s);
        dfs(node->right, targetSum-node->val, res, s);
    }
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum){
    vector<vector<int>> res;
    if(!root){
        return res;
    } 
    vector<int> s;
    dfs(root, targetSum, res, s);
    return res;
}
int main(){
    struct TreeNode node1(1), node3(2);
    struct TreeNode node2(2, NULL, &node3);
    struct TreeNode root(0, &node1, &node2);
    auto res = pathSum(&root, 4);
    cout<<res.size()<<endl;
    return 0;
}