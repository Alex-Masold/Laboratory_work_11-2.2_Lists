#include <iostream>
#include <fstream>
using namespace std;

template <typename type>
class List
{
public:

    List();
    ~List();



    bool is_empty();
    void push_back(type data);
    void push_front(type data);
    void print();
    void sort();
    bool find(int key);
    int Lenght() { return Size; }
    type& operator[](const int index);
    void insert(type data, int index);
    void pop_front();
    void clear();
    void remove(int index);



    template <typename type>
    class Node
    {
    public:
        Node* next;
        type data;
        Node(type data = type(), Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };
    Node<type>* head;
    Node<type>* tail;
    int Size;
};

template <typename type>
List<type>::List()
{
    Size = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename type>
List<type>::~List()
{
}

template<typename type>
bool List<type>::is_empty()
{
    return head == nullptr;
}

template<typename type>
void List<type>::push_back(type data)
{
    if (is_empty())
    {
        head = new Node<type>(data);
    }
    else
    {
        Node<type>* new_Node = head;

        while (new_Node->next != nullptr)
        {
            new_Node = new_Node->next;
        }
        new_Node->next = new Node<type>(data);
        tail = new_Node->next;
    }
    Size++;

}

template<typename type>
void List<type>::push_front(type data)
{
    head = new Node<type>(data, head);
    Size++;
}

template<typename type>
void List<type>::print()
{
    if (is_empty())
    {
        cout << "This list is empty";
        return;
    }
    Node<type>* p = head;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template<typename type>
void List<type>::sort()
{
    Node<type>* node, * max;
    Node<type>* el = head; // меняемый эл

    while (el != tail)
    {
        max = node = el;
        for (; node != NULL; node = node->next)
        {
            if (node->data > max->data)
            {
                max = node;
            }
        }
        swap(el->data, max->data);
        el = el->next;
    }
}



template<typename type>
bool List<type>::find(int data)
{
    Node<type>* current = this->head;

    while (current != nullptr)
    {
        if (data == current->data)
        {
            return true;
        }
        current = current->next;
    }
}

template<typename type>
type& List<type>::operator[](const int index)
{
    int count = 0;
    Node<type>* current = this->head;

    while (current != nullptr)
    {
        if (count == index)
        {
            return current->data;
        }
        current = current->next;
        count++;
    }
}

template<typename type>
void List<type>::insert(type data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else if (index == Lenght() - 1)
    {
        push_back(data);
    }
    else
    {
        Node<type>* previuos = this->head;
        for (int i = 0; i < index; i++)
        {
            previuos = previuos->next;
        }
        Node<type>* New_Node = new Node<type>(data, previuos->next);
        previuos->next = New_Node;
        Size++;
    }
}

template<typename type>
void List<type>::pop_front()
{
    Node<type>* temp = head;

    head = head->next;
    delete temp;

    Size--;
}

template<typename type>
void List<type>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template<typename type>
void List<type>::remove(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<type>* previuos = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previuos = previuos->next;
        }

        Node<type>* deleted = previuos->next;
        previuos->next = deleted->next;

        delete deleted;
        Size--;
    }
}


// 1 1 7 9 2 3 7 8 9
int main()
{
    int n, m, num;
    List<int> lst1, lst2, res;
    ifstream in("input.txt");

    in >> n;
    in >> m;

    while (n > 0 && in >> num)
    {
        lst1.push_back(num);
        n--;
    }

    while (m > 0 && in >> num)
    {
        lst2.push_back(num);
        m--;
    }
    in.close();


    lst1.tail->next = lst2.head;

    lst2.head = lst1.head;
    lst1.tail = lst2.tail;

    lst1.sort();
   /* lst1.print();*/
    ofstream out("output.txt");
    for (int i = 0; i < lst1.Lenght() + lst2.Lenght(); i++)
    {
        out << lst1[i] << " ";
    }

    out.close();

    

    return 0;
}