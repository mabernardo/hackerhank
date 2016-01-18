/* day-15-linked-list.cpp
 * https://www.hackerrank.com/contests/30-days-of-code/challenges/day-15-linked-list
 */
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            cout << "Deleting " << next->data << endl;
            delete next;
        }
        //cout << "Deleting " << this->data << endl;
        //delete this;
    }
};

class Solution
{
private:
    Node* head;

public:
    Node* insert(Node *head, int data)
    {
        if (head == NULL)
        {
            this->head = new Node(data);
            return this->head;
        }

        Node* prev = head;
        Node* current = head->next;
        while (current)
        {
            prev = current;
            current = current->next;
        }
        prev->next = new Node(data);
        return head;
    }

    void display(Node *head)
    {
        Node *start = head;
        while (start)
        {
            cout << start->data << " ";
            start = start->next;
        }
    }
    ~Solution()
    {
        cout << "Deleting " << head->data << endl;
        delete head;
    }

/*
    ~Solution()
    {
        Node* current = head;
        while (current->next)
        {
            Node* parent = current;
            current = current->next;
            delete parent;
        }
        delete current;
    }
*/
};

int main()
{
    Node* head = NULL;
    Solution mylist;
    int T, data;

    cin >> T;
    while (T--)
    {
        cin >> data;
        head = mylist.insert(head, data);
    }
    mylist.display(head);
    return 0;
}
