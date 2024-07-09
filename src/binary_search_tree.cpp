#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinarySearchTree{
    private:
        TreeNode *root;
    public:
        BinarySearchTree() : root(nullptr) {};
        ~BinarySearchTree(){};

    TreeNode* search(int num){
        TreeNode *cur = root;
        while(cur!=nullptr){
            if(num>cur->val)
                cur = cur->right;
            else if(num<cur->val)
                cur = cur->left;
            else
                break;     
        }
        return cur;
    }

    void insert(int val){
        if(root == nullptr)
            root =  new TreeNode(val);
        TreeNode *pre = nullptr, *cur = root;
        while(cur != nullptr){
            pre = cur;
            if(val>cur->val)
                cur = cur->right;
            else
                cur = cur->left;
        }
        TreeNode *node = new TreeNode(val);
        if(val>pre->val)
                pre->right = node;
            else
                pre->left = node;
    }

    void remove(int num){
        if(root == nullptr)
            return;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while(cur!=nullptr){
            pre = cur;
            if(num>cur->val)
                cur = cur->right;
            else if(num<cur->val)
                cur = cur->left;
            else
                break;     
        }
        if(cur == nullptr)
            return;
        if(cur->left == nullptr || cur->right == nullptr){
            TreeNode *child = cur->left != nullptr ? cur->left:cur->right;
            if(cur != root){
            if(pre->left == cur)
                pre->left = child;
            else
                pre->right = child;
            }
            else
                root = child;
            delete cur;
        }
        else{
            TreeNode *tmp = cur->right;
            while(tmp->left != nullptr){
                tmp = tmp->left;
            }
            int tmpval = tmp->val;
            remove(tmpval);
            cur->val = tmpval;
        }
    }
};  