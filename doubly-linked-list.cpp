#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *previous;
};
class DoublyLinkedList
{
public:
    node *head;
    int size;
    node *CreateNode(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->next = NULL;
        newNode->previous = NULL;
        return newNode;
    }
    DoublyLinkedList()
    {
        head = NULL;
        size = 0;
    }
    void InsertAtHead(int value)
    {
        node *newNode = CreateNode(value);
        size++;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            node *current = head;
            current->previous = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    void InsertAtLast(int value)
    {
        if (size == 0)
        {
            InsertAtHead(value);
        }
        else
        {
            node *newNode = CreateNode(value);
            size++;
            node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->previous = current;
        }
    }
    void InsertAt(int index, int value)
    {
        if (index == 0)
        {
            InsertAtHead(value);
        }
        else if (index == size)
        {
            InsertAtLast(value);
        }
        else if (index < 0 || index > size)
        {
            cout << "Index not Available" << endl;
        }
        else
        {
            node *newNode = CreateNode(value);
            size++;
            node *current = head;
            int countIndex = 0;
            while (index != countIndex)
            {
                current = current->next;
                countIndex++;
            }
            node *previousNode = current->previous;
            newNode->previous = current->previous;
            newNode->next = current;
            current->previous = newNode;
            previousNode->next = newNode;
        }
    }
    void TraverseList()
    {
        node *current = head;
        while (current != NULL)
        {
            current->next != NULL ? cout << current->data << " -> " : cout << current->data;
            current = current->next;
        }
    }
};
int main()
{
    DoublyLinkedList list;
    list.InsertAtLast(5230);
    list.InsertAtLast(2230);
    list.InsertAtLast(520);
    list.InsertAtLast(523);
    list.InsertAt(1, 20);
    list.InsertAt(1, 200);
    list.TraverseList();
    return 0;
}