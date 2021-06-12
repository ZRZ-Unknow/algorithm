#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <assert.h>
using namespace std;

/*
二叉搜索树的中序遍历的序列是递增排序的序列。中序遍历的遍历次序：Left -> Node -> Right

*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==NULL) return NULL;
    if(root->val < key){
        root->right = deleteNode(root->right, key);   // 去右子树删除
    }else if(root->val > key){
        root->left = deleteNode(root->left, key);     // 去左子树删除
    }else{
        if(root->left==NULL) return root->right;   // 情况1，欲删除节点无左子
        if(root->right==NULL) return root->left;   // 情况2，欲删除节点无右子 
        auto successor = root->right;
        while(successor->left){                    // 寻找欲删除节点右子树的最左节点
            successor = successor->left;
        }
        successor->left = root->left;           // 将欲删除节点的左子树成为其右子树的最左节点的左子树
        root = root->right;                      // 欲删除节点的右子顶替其位置，节点被删除
    } 
    return root; 
}


int main(){
    struct TreeNode node1(1), node3(3);
    struct TreeNode node2(2, NULL, &node3);
    struct TreeNode root(0, &node1, &node2);
    struct TreeNode* t = deleteNode(&root, 0);
    return 0;
}