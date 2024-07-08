#include <queue>
#include <iostream>
using namespace std;
/* 二叉树节点结构体 */
struct TreeNode {
    int val;
 // 节点值
    TreeNode *left; // 左子节点指针
    TreeNode *right; // 右子节点指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ~TreeNode() {
        // 递归删除左子节点和右子节点
        delete left;
        delete right;
    }
 };

 
vector<int> levelorder(TreeNode *root){
    queue<TreeNode *> queue;
    queue.push(root);
    vector<int> vec;
    while(queue.empty()){
        TreeNode *node = queue.front();
        queue.pop();
        vec.push_back(node->val);
        if(node->left!=nullptr){
            queue.push(node->left);
        }
        if(node->right!=nullptr){
            queue.push(node->right);
        }
    }
    return vec;
}