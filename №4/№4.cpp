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
	int Lenght() { return Size; }
	type& operator[](const int index);
	void insert(type data, int index);
	void pop_front();
	void clear();
	void remove(int index);


private:
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
		tail = new_Node;
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

int main()
{
	List<int> list;
	int key;

	ifstream in("input.txt", ios::in);
	int temp;
	in >> key;
	for (int i = 0; in >> temp; ++i)
	{
		list.push_front(temp);
	}
	list.print();
	cout << endl;


	for (int i = 1; i < list.Lenght(); i++)
	{
		if (list[i] == key)
		{
			list.remove(i-1);
			i--;
		}
		
	}
	/*list.print();
	cout << endl;*/
	ofstream out("output.txt");
	for (int i = 0; i < list.Lenght(); i++)
	{
		out << list[i] << " ";
	}

	out.close();

	//cout << list.Lenght();
}
