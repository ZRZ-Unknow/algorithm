#include<string>
#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
}

int main(){
    struct TreeNode node1(1), node3(2);
    struct TreeNode node2(2, NULL, &node3);
    struct TreeNode root(0, &node1, &node2);
}