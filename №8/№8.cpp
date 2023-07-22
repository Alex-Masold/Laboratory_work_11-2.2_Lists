#include <iostream>
#include <fstream>
using namespace std;

class stringList
{
public:
    string mystr;
    stringList* next;

    stringList(string str)
    {
        mystr = str;
        next = NULL;
    }
};

class Link
{
public:
    stringList* head, * tail;
public:
    Link()
    {
        this->head = this->tail = NULL;
    }

    void push_back_str(string str)
    {
        stringList* mystr = new stringList(str);
        if (head == NULL)
            head = mystr;
        if (tail != NULL)
            tail->next = mystr;
        tail = mystr;
    }
};

int main()
{
    Link* lst = new Link[1000001];
    ifstream in("input.txt");
    int n, key;
    string str;

    in >> n;

    for (int i = 0; i < n; i++)
    {
        in >> key >> str;
        lst[key].push_back_str(str);
    }

    stringList* el;

    for (int i = 0; i < 1000001; i++)
    {
        if (lst[i].head != NULL)
        {
            el = lst[i].head;
            while (el != NULL)
            {
                cout << i << ' ' << el->mystr << endl;
                el = el->next;
            }
        }
    }
}