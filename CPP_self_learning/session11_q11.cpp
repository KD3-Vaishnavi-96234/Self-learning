#include <iostream>
using namespace std;    
class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
class LinkedList
{
private:
    Node *head;
public:
    LinkedList() : head(nullptr) {}
    void add_first(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void add_last(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};
int main()
{
    LinkedList list;
    list.add_last(10);
    list.add_last(20);
    list.add_first(5);
    list.add_first(1);
    cout << "Linked List: ";
    list.display();
    return 0;
}

