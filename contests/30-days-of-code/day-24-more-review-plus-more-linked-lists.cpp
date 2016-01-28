/* day-24-more-review-plus-more-linked-lists.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-24-more-review-plus-more-linked-lists
 * by @mabernardo
 */
#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(NULL) { }
};

class Solution
{
public:
    Node* removeDuplicates(Node *head)
    {
        Node *start = head;
        while (start != NULL && start->next != NULL)
        {
            if (start->data == start->next->data)
            {
                Node *tmp = start->next;
                start->next = start->next->next;
                if (tmp != NULL)
                    delete tmp;
            }
            else
            {
                start = start->next;
            }
        }
        return head;
    }

    Node* insert(Node *head, int data)
    {
        Node* p = new Node(data);
        if (head == NULL)
        {
            head = p;
        }
        else if (head->next == NULL)
        {
            head->next = p;
        }
        else
        {
            Node *start = head;
            while (start->next != NULL)
            {
                start = start->next;
            }
            start->next = p;
        }
        return head;
    }

    void display(Node *head)
    {
        Node *start = head;
        while(start)
        {
            cout << start->data << " ";
            start = start->next;
        }
    }
};

int main()
{
    Node* head = NULL;
    Solution mylist;
    int T, data;
    cin >> T;
    while(T--)
    {
        cin >> data;
        head = mylist.insert(head, data);
    }
    head = mylist.removeDuplicates(head);
    mylist.display(head);
}
