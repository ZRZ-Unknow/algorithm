#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
记录从根到叶的每条路径的前缀和，若有两个的前缀和差刚好是target
或者：
记录到达当前结点的所有路径的和，只需要count一下就行
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//内存消耗严重
int dfs(TreeNode *node, int targetSum, vector<int> sumlist){
    if(!node) return 0;
    for_each(sumlist.begin(), sumlist.end(), [&](int &a){a += node->val;});
    sumlist.push_back(node->val);
    int cnt = 0;
    for(auto v:sumlist){
        if(v == targetSum)
	    cnt++;
    }
    int l = dfs(node->left, targetSum, sumlist);
    int r = dfs(node->right, targetSum, sumlist);
    return cnt + l + r;
}
int pathSum(TreeNode* root, int targetSum) {
    int res = 0;
    if(!root) return res;
    vector<int> sumlist;
    sumlist.push_back(root->val);
    res = dfs(root->left, targetSum, sumlist) + dfs(root->right, targetSum, sumlist) + (root->val == targetSum);
    return res;
}

int prefix(TreeNode *node, int targetSum, unordered_map<int, int> &hash, int curr_sum){   //当前路径前缀和
    if(!node) return 0;
    curr_sum += node->val;
    int res = 0;
    //看是否存在某父节点到当前节点的前缀和之差为目标和
    if(hash.count(curr_sum-targetSum)>0){
        res += hash[curr_sum - targetSum];
    }
    if(hash.count(curr_sum)>0){          // 更新路径上当前节点前缀和的个数
        hash[curr_sum] += 1;
    }else{
	hash[curr_sum] = 1;
    }
    res += prefix(node->left, targetSum, hash, curr_sum);
    res += prefix(node->right, targetSum, hash, curr_sum);
    hash[curr_sum] -= 1;
    return res;
}

int main(){
    struct TreeNode node1(1), node3(2);
    struct TreeNode node2(2, NULL, &node3);
    struct TreeNode root(0, &node1, &node2);
    auto res = pathSum(&root, 4);
    cout<<res<<endl; 
    return 0;
}