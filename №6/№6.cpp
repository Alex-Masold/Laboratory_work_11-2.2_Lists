#include <iostream>
#include <fstream>
using namespace std;

class Node
{
public:
    int data;
    Node* next, * prev;
public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Loop_list
{
private:

public:
    Node* head, * tail;
    int Size;

public:
    Loop_list()
    {
        Size = 0;
        head = tail = NULL;
    }

    void push_back(int data)
    {
        Node* ptr = new Node(data);
        ptr->prev = tail;
        ptr->next = head;

        if (tail != NULL)
        {
            tail->next = ptr;
            head->prev = ptr;
        }
        if (head == NULL)
        {
            head = ptr;
        }
        tail = ptr;
        Size++;
    }

    void pop_front()
    {
        if (head == NULL) return;
        if (head == tail)
        {
            delete tail;
            head = tail = NULL;
            return;
        }
        Node* ptr = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;

        delete ptr;
    }

    void pop_back()
    {
        if (tail == NULL) return;
        if (head->next == NULL)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* ptr = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete ptr;
    }

    Node* erase(Node* node)
    {
        Node* ptr = node;
        node = node->next;
        if (ptr == NULL)
            return node;
        if (ptr == head)
        {
            pop_front();
            return node;
        }
        if (ptr == tail)
        {
            pop_back();
            return node;
        }

        Node* left = ptr->prev;
        Node* right = ptr->next;
        left->next = right;
        right->prev = left;
        delete ptr;

        return node;
    }
};


int main()
{
    Loop_list lst;

    ifstream in("input.txt", ios::in);
    int diap, num, cnt;
    in >> diap >> num;
    in.close();

    for (int i = 1; i <= diap; i++)
    {
        lst.push_back(i);
    }

    Node* node = lst.head;

    while (diap != 1)
    {
        for (cnt = 1; cnt < num; cnt++)
        {
            node = node->next;
        }

        node = lst.erase(node);

        diap--;
    }
    ofstream out("output.txt");

    cout << lst.head->data;
    out.close();

}