/* day-22-binary-search-trees.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-22-binary-search-trees
 * by @mabernardo
 */
#include <iostream>
#include <cstddef>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

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
        if(root == NULL)
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

    int getHeight(Node* root)
    {
        int height = 0, max_height = 1;
        Node* next = root->left;
        if (next != NULL)
        {
            ++height;
            height += getHeight(next);
        }
        if (height > max_height)
        {
            max_height = height;
        }

        height = 0;
        next = root->right;
        if (next != NULL)
        {
            ++height;
            height += getHeight(next);
        }
        if (height > max_height)
        {
            max_height = height;
        }
        return max_height;
    }
}; //End of Solution

int main()
{
    Solution myTree;
    Node* root = NULL;
    int T, data;
    cin >> T;
    while(T--)
    {
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;
    return 0;
}
