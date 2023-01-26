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
        if (index < 0 || index > size)
        {
            cout << "Index not Available" << endl;
        }
        else if (index == size)
        {
            InsertAtLast(value);
        }

        else if (index == 0)
        {
            InsertAtHead(value);
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
    void DeleteAtHead()
    {
        if (head == NULL)
        {
            cout << "List is empty";
        }
        else if (head->next == NULL)
        {
            head = NULL;
            size--;
        }
        else
        {
            node *current = head;
            node *newHead = head->next;
            newHead->previous = NULL;
            head = newHead;
            size--;
            delete current;
        }
    }
    void DeleteAtLast()
    {
        if (head == NULL)
        {
            cout << "List is empty";
        }
        else if (head->next == NULL)
        {
            head = NULL;
            size--;
        }
        else
        {
            node *newLast = head;
            while (newLast->next->next != NULL)
            {
                newLast = newLast->next;
            }
            node *will_delete = newLast->next;
            newLast->next = NULL;
            size--;
            delete will_delete;
        }
    }
    void DeleteAt(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index not Available" << endl;
        }
        else if (index == size - 1)
        {
            DeleteAtLast();
        }

        else if (index == 0)
        {
            DeleteAtHead();
        }
        else
        {
            node *current = head;
            int countIndex = 0;
            while (index != countIndex)
            {
                current = current->next;
                countIndex++;
            }
            size--;
            current->previous->next = current->next;
            current->next->previous = current->previous;
            delete current;
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
    int Size()
    {
        return size;
    }
};
int main()
{
    DoublyLinkedList list;
    list.InsertAtLast(5230);
    list.InsertAtLast(5300);
    list.InsertAtLast(530);
    list.InsertAtLast(5);
    list.InsertAt(3, 2);
    list.DeleteAt(3);
    list.TraverseList();
    return 0;
}