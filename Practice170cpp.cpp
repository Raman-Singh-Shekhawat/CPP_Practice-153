// 171. ZigZag tree: Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.

/**********************************************************
    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include <stack>

void zigZagOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<BinaryTreeNode<int> *> s1, s2;
    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            BinaryTreeNode<int> *front = s1.top();
            s1.pop();
            cout << front->data << " ";
            if (front->left != NULL)
            {
                s2.push(front->left);
            }
            if (front->right != NULL)
            {
                s2.push(front->right);
            }
        }

        cout << "\n";

        while (!s2.empty())
        {
            BinaryTreeNode<int> *front = s2.top();
            s2.pop();
            cout << front->data << " ";
            if (front->right != NULL)
            {
                s1.push(front->right);
            }
            if (front->left != NULL)
            {
                s1.push(front->left);
            }
        }

        cout << "\n";
    }
}