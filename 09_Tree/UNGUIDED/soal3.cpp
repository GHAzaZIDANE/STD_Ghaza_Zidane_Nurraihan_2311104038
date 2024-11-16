#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int data) {
    return new TreeNode{data, NULL, NULL};
}

int cari_simpul_daun(TreeNode* node) {
    if (!node) return 0; 
    if (!node->left && !node->right) return 1;
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

int main() {
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);

    cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << endl;

    return 0;
}
