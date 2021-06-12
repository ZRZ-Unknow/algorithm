#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int get_sum(TreeNode *node, unordered_map<int,int> &hash, int &max_num){
    if(!node) return 0;
    int l = get_sum(node->left, hash, max_num);
    int r = get_sum(node->right, hash, max_num);
    int res = l+r+node->val;
    if(hash.count(res)>0){
        hash[res] = hash[res] + 1;
    }else{
        hash[res] = 1;
    }
    if(hash[res] > max_num)  max_num = hash[res];
    return node->val + l + r; 
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> res;
    unordered_map<int, int> hash;
    int max_num = 0;
    get_sum(root, hash, max_num);
    for(auto v: hash){
        if(v.second == max_num)
	    res.push_back(v.first);
    }
    return res;
}


int main(){
    struct TreeNode node1(1), node3(2);
    struct TreeNode node2(2, NULL, &node3);
    struct TreeNode root(0, &node1, &node2);
    auto res = findFrequentTreeSum(&root);
    for_each(res.begin(), res.end(), [](int x){cout<<x<<" ";});
    return 0;
}
