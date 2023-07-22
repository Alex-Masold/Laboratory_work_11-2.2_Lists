#include <iostream>
#include <fstream>

using namespace std;


struct Node // узел
{
	int data; // инф. поле, данные
	// list* prev; // указатель на предыдущий элеент списка
	Node* next; // указатель на следуюий элемент списка
	Node(int _data) : data(_data), next(nullptr) {};
};

struct list // односвязный список
{
	Node* head;
	Node* tail;

	list() : head(nullptr), tail(nullptr) {};

	bool is_empty()
	{
		return head == nullptr;
	}

	void add_in_head(int a)
	{
		Node* new_Node = new Node(a);
		new_Node->next = head; // указываем как следующий элемент содержимое в head
		head = new_Node; // назначаем новый новый элемент head
	}

	void add_in_tail(int a)
	{
		Node* new_Node = new Node(a);
		if (is_empty())
		{
			head = tail = new_Node;
			return;
		}
		tail = head;
		while (tail->next != nullptr)
		{
			tail = tail->next;
		}
		tail->next = new_Node;
		tail = new_Node;
	}

	void add(Node* list, int a)
	{
		Node* temp = new Node(a);
		Node* p = list->next; // сохраняем указатель на следующий узел
		list->next = temp; // предыдущий узел указывает на новый
		temp->data = a; // сохранение поля 
		temp->next = p;
	}

	Node* find(int a)
	{
		Node* p = head;
		while (p && p->data != a)
		{
			p = p->next;
		}
		return (p && p->data == a) ? p : nullptr;
	}


	void print()
	{
		if (is_empty())
		{
			cout << "This list is empty";
			return;
		}
		Node* plist = head;
		while (plist)
		{
			cout << plist->data << " ";
			plist = plist->next;
		}
		cout << endl;
	}

	int count()
	{
		Node* plist = head;
		int count = 0;
		while (plist)
		{
			if ((plist->data < 0) && (plist->data % 7 == 0))
				count++;
			plist = plist->next;
		}
		return count;
	}

};
	


int main()
{
	list* lst = new list();
	int temp;
	int count;

	ifstream in("input.txt", ios::in);
	while (in >> temp)
	{
		lst->add_in_head(temp);
	}
	in.close();
	//list->print();

	count = lst->count();
	ofstream out("output.txt");
	out << count;
	out.close();

}