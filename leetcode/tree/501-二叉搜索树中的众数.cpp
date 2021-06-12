#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <assert.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode *node, unordered_map<int,int> &hash, int &max_num){
    if(node == NULL) return;
    inorder(node->left, hash, max_num);
    if(hash.count(node->val) > 0){
	int tmp = hash[node->val];
        hash[node->val] = tmp+1;
    }else{
	hash[node->val] = 1;
    } 
    if(max_num < hash[node->val])
        max_num = hash[node->val];
    inorder(node->right, hash, max_num);
}

vector<int> findMode(TreeNode* root){
    unordered_map<int,int> hash;
    int max_num = 0;
    inorder(root, hash, max_num);
    vector<int> res;
    for(auto &v: hash){                          //字典的遍历
        if(v.second == max_num){
	    res.push_back(v.first);
	}
    }
    return res;
}


int main(){
    struct TreeNode node1(1), node3(2);
    struct TreeNode node2(2, NULL, &node3);
    struct TreeNode root(0, &node1, &node2);
    auto res = findMode(&root);
    return 0;
}