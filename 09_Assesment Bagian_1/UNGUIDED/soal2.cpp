#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
};

TreeNode* createNode(int data) {
    return new TreeNode{data, NULL, NULL};
}

bool is_valid_bst(TreeNode* node, int min_val, int max_val) {
    if (node == NULL) {
        return true; 
    }

    if (node->data <= min_val || node->data >= max_val) {
        return false;
    }

    return is_valid_bst(node->left, min_val, node->data) &&
           is_valid_bst(node->right, node->data, max_val);
}

bool isValidBST(TreeNode* root) {
    return is_valid_bst(root, INT_MIN, INT_MAX);
}

void test_tree(TreeNode* root, const string& tree_name) {
    cout << "Pohon " << tree_name << " adalah ";
    if (isValidBST(root)) {
        cout << "VALID BST.\n";
    } else {
        cout << "TIDAK VALID sebagai BST.\n";
    }
}

int main() {
    TreeNode* root1 = createNode(10);
    root1->left = createNode(5);
    root1->right = createNode(15);
    root1->left->left = createNode(3);
    root1->left->right = createNode(7);
    root1->right->left = createNode(13);
    root1->right->right = createNode(18);

    TreeNode* root2 = createNode(10);
    root2->left = createNode(5);
    root2->right = createNode(15);
    root2->left->left = createNode(3);
    root2->left->right = createNode(12);

    TreeNode* root3 = NULL;

    test_tree(root1, "Contoh 1");
    test_tree(root2, "Contoh 2");
    test_tree(root3, "Contoh 3");

    return 0;
}
