import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class node {
    node left;
    node right;
    int data;

    public node(int data) {
        this.data = data;
    }
}

public class binarytrees1 {
    static Scanner sc = null;

    // Tree construction using array input
    static node buildTree(int arr[], int n) {
        if (n <= 0 || arr[0] == -1) return null;
        node root = new node(arr[0]);
        Queue<node> q = new LinkedList<>();
        q.add(root);

        int i = 1;
        while (i < n && !q.isEmpty()) {
            node parent = q.peek();
            q.remove();

            // If left child exists
            if (arr[i] != -1) {
                parent.left = new node(arr[i]);
                q.add(parent.left);
            }
            i++;

            // If right child exists
            if (i < n && arr[i] != -1) {
                parent.right = new node(arr[i]);
                q.add(parent.right);
            }
            i++;
        }
        return root;
    }

    // Tree construction using user input
    static node createtree() {
        node root = null;
        System.out.println("Enter data: ");
        int data = sc.nextInt();
        if (data == -1) return null;

        root = new node(data);
        System.out.println("Enter left for " + data);
        root.left = createtree();
        System.out.println("Enter right for " + data);
        root.right = createtree();
        return root;
    }

     // Level Order Traversal with level-wise line breaks (converted LOT function)
     public static void LOT(node root) {
        if (root == null) return;

        Queue<node> q = new LinkedList<>();
        q.add(root);
        q.add(null); // Adding null to mark the end of the current level

        while (!q.isEmpty()) {
            node temp = q.poll(); // Use poll() instead of pop() in Java's Queue

            if (temp == null) {
                System.out.println(); // New line for new level
                if (!q.isEmpty()) {
                    q.add(null); // Mark the end of the next level
                }
            } else {
                System.out.print(temp.data + " "); // Print current node's data
                if (temp.left != null) {
                    q.add(temp.left); // Add left child if exists
                }
                if (temp.right != null) {
                    q.add(temp.right); // Add right child if exists
                }
            }
        }
    }


    // Inorder traversal (LNR)
    static void inorder(node root) {
        if (root == null) return;
        inorder(root.left);
        System.out.println(root.data);
        inorder(root.right);
    }

    // Preorder traversal (NLR)
    static void preorder(node root) {
        if (root == null) return;
        System.out.println(root.data);
        preorder(root.left);
        preorder(root.right);
    }

    // Postorder traversal (LRN)
    static void postorder(node root) {
        if (root == null) return;
        postorder(root.left);
        postorder(root.right);
        System.out.println(root.data);
    }

    // Height function
    public static int height(node root) {
        if (root == null) {
            return 0;
        }

        int leftHeight = height(root.left);
        int rightHeight = height(root.right);
        return Math.max(leftHeight, rightHeight) + 1;
    }

    // Diameter function
    public static int diameter(node root) {
        if (root == null) {
            return 0;
        }

        int left = diameter(root.left);
        int right = diameter(root.right);
        int dia = height(root.left) + height(root.right);

        return Math.max(left, Math.max(right, dia));
    }

    // Symmetry check between two subtrees
    public static boolean isSymmetric(node left, node right) {
        if (left == null || right == null) {
            return left == right;  // true if both are null
        }
        if (left.data != right.data) {
            return false;  // false if data doesn't match
        }

        // Recursively check symmetry of subtrees
        return isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
    }

    // Wrapper function to check if the entire tree is symmetric
    public static boolean isSymmetric(node root) {
        if (root == null) {
            return true;  // An empty tree is symmetric
        }
        return isSymmetric(root.left, root.right);
    }

    public static void main(String args[]) {
        sc = new Scanner(System.in);
        node root = createtree();

        System.out.println("Inorder traversal: ");
        inorder(root);

        System.out.println("Preorder traversal: ");
        preorder(root);

        System.out.println("Postorder traversal: ");
        postorder(root);

        // Calculate the height of the tree
        int treeHeight = height(root);
        System.out.println("Height of the tree: " + treeHeight);

        // Calculate the diameter of the tree
        int treeDiameter = diameter(root);
        System.out.println("Diameter of the tree: " + treeDiameter);

        // Check if the tree is symmetric
        if (isSymmetric(root)) {
            System.out.println("The tree is symmetric.");
        } else {
            System.out.println("The tree is not symmetric.");
        }
    }
}