/* day-23-review-and-binary-trees.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-23-review-and-binary-trees
 * by @mabernardo
 */
#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

class Node
{
public:
    int data;
    Node *left,*right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

class Solution
{
public:
    Node* insert(Node* root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node* cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }

    void levelOrder(Node* root)
    {
        if (root == NULL) {
           return;
        }

        queue<Node*> queue;

        queue.push(root);
        while (!queue.empty())
        {
            Node* node = queue.front();
            queue.pop();
            cout << node->data << " ";
            if (node->left)
                queue.push(node->left);
            if (node->right)
                queue.push(node->right);
        }
    }
}; //End of Solution

int main()
{
    Solution myTree;
    Node* root = NULL;
    int T, data;
    cin >> T;
    while (T--)
    {
        cin >> data;
        root = myTree.insert(root, data);
    }
    myTree.levelOrder(root);
    return 0;
}
