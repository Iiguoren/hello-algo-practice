#include <iostream>
#include <queue>
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
        if(root == nullptr){
            root =  new TreeNode(val);
            return;
        }
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

    vector<int> levelorder(){
    queue<TreeNode *> queue;
    queue.push(root);
    vector<int> vec;
    while(!queue.empty()){
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
};  

int main(){
    BinarySearchTree tree = BinarySearchTree();
    tree.insert(5);
    TreeNode *node = tree.search(1);

    tree.insert(6);

    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    node = tree.search(5);
    cout<<node->val<<endl;
    vector<int> vec = tree.levelorder();
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" !";
    cout<<endl;

}