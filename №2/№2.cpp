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

struct Mylist // односвязный список
{
	Node* head;
	Node* tail;

	Mylist() : head(nullptr), tail(nullptr) {};

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

	void add(Node* node, int a)
	{
		Node* temp = new Node(a);
		if (node == head)
		{
			temp->next = head;
			head = temp;
			return;
		}
		else if (node == tail)
		{
			tail->next = temp;
			tail = temp;
			return;
		}
		Node* p = node->next; // сохраняем указатель на следующий узел
		node->next = temp; // предыдущий узел указывает на новый
		temp->data = a; // сохранение поля 
		temp->next = p;
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

	void pop_head()
	{
		if (is_empty())
			return;
		Node* temp = head->next;
		delete(head);
		head = temp;
	}

	void free_list()
	{
		
		while (head != nullptr)
		{
			this->pop_head();
		}
		tail = head;
	}



	int arithmetic_mean()
	{
		Node* plist = head;
		int count = 0;
		int sum = 0;
		int arithmetic_mean;
		while (plist)
		{
			count++;
			sum += plist->data;
			plist = plist->next;
		}
		arithmetic_mean = sum / count;
		return arithmetic_mean;
	}
	
	
};

int main()
{
	Mylist Mylist;
	int temp;
	int arithmetic_mean;

	ifstream in("input.txt", ios::in);
	while (in >> temp)
	{
		Mylist.add_in_tail(temp);
	}
	in.close();

	arithmetic_mean = Mylist.arithmetic_mean();
	ofstream out("output.txt");
	out << arithmetic_mean;
	out.close();

	/*cout << list[1];*/

	Mylist.free_list();


}
