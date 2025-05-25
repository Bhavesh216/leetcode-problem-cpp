#include <iostream>
#include <vector>
#include <queue>

// Definition for a binary tree node.
struct node {
    int val;
    node *left;
    node *right;
    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to convert array to binary tree
node* arrayToTree(const std::vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }

    node* root = new node(arr[0]);
    std::queue<node*> q;
    q.push(root);

    for (int i = 1; i < arr.size(); i += 2) {
        node* current = q.front();
        q.pop();

        if (arr[i] != NULL) {
            current->left = new node(arr[i]);
            q.push(current->left);
        }

        if (i + 1 < arr.size() && arr[i + 1] != NULL) {
            current->right = new node(arr[i + 1]);
            q.push(current->right);
        }
    }

    return root;
}

// Function to perform a preorder traversal of the binary tree
void preorderTraversal(node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    // Input the array representation from the user
    std::cout << "Enter the size of the array: ";
    int size;
    std::cin >> size;

    std::vector<int> arr(size);
    std::cout << "Enter the array elements (use 'null' for NULL): ";
    for (int i = 0; i < size; ++i) {
        std::string element;
        std::cin >> element;
        if (element == "null") {
            arr[i] = NULL;
        } else {
            arr[i] = std::stoi(element);
        }
    }

    // Convert array to binary tree
    node* root = arrayToTree(arr);

    // Perform preorder traversal to verify the tree structure
    std::cout << "Preorder Traversal: ";
    preorderTraversal(root);

    // Clean up allocated memory
    // You can implement a function to delete the tree nodes

    return 0;
}
