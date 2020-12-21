#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

void printDoubleDirection();
void insertNode_InOrder(int a);
void insertNode(int a);

class Node
{
public:

    Node* next;
    Node* prev;
    int val;

    Node();

};
/*****************************************************************/
Node::Node()
{
    prev = 0;
    next = 0;
}

/*****************************************************************/

Node* root = 0; 
int main()
{
    srand(time(NULL));

    // create double linked list with no sorting
    /*
    for (int i = 0; i < 20; i++)
    {
        insertNode_InOrder(rand() % 100);
        printDoubleDirection();
    }
    */

    // create doubly linked list with sorted element
    for (int i = 0; i < 20; i++)
    {
        insertNode_InOrder(rand() % 100);
        printDoubleDirection();
    }  
    return 0;
}


/*****************************************************************/
void insertNode_InOrder(int a)
{
    Node* newElement = new Node;
    newElement->val = a;
    cout << "Insert value " << a << "    ";

    if (root == 0)
    {
        root = newElement;
        newElement->prev = 0;
    }
    else
    {
        Node* itr = root;
        if (a < root->val)
        {
            newElement->next = root;
            root->prev = newElement;
            root = newElement;
        }
        else
        {
            while (itr->next != 0 && a > itr->next->val)
            {
                itr = itr->next;
            }
            if (itr->next == 0)
            {
                itr->next = newElement;
                newElement->prev = itr;
            }
            else
            {
                Node* pointer = itr->next;
                itr->next = newElement;
                newElement->prev = itr;
                newElement->next = pointer;
                pointer->prev = newElement;
            }
        }
    }

    cout << "Root value: " << root->val << endl;
}


/*****************************************************************/
void insertNode(int a)
{
    Node* newElement = new Node;
    newElement->val = a;

    if (root == 0)
    {
        newElement->next = 0;
        newElement->prev = 0;
        root = newElement;
    }
    else
    {
        Node* tmp = root;
        while (tmp->next != 0)
        {
            tmp = tmp->next;
        }
        tmp->next = newElement;
        newElement->prev = tmp;
    }
}

/*****************************************************************/
void printDoubleDirection()
{
    Node* tmp = root;
    cout << "H->";
    while (tmp->next != 0)
    {
        cout << tmp->val << " -> ";
        tmp = tmp->next;
    }
    cout << tmp->val;
    cout << "->T";
    cout << endl;

    cout << "T->";
    while (tmp->prev != 0)
    {
        cout << tmp->val << " -> ";
        tmp = tmp->prev;
    }
    cout << tmp->val;
    cout << "->H";
    cout << endl << endl << endl;
}
