#include <iostream>
using namespace std;

class Node
{
public:
	int dane;
	Node* prev;
	Node* next;

	Node(int wartosc)
	{
		dane = wartosc;
		prev = nullptr;
		next = nullptr;
	}
};

class List
{
public:
	List() 
	{
		head = nullptr;
		tail = nullptr;
		rozmiar = 0;
	}

	void append(int wartosc)
	{
		Node* newNode = new Node(wartosc);
		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		rozmiar++;
	}

	void prepend(int wartosc)
	{
		Node* newNode = new Node(wartosc);
		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		rozmiar++;
	}

	void add(int index, int wartosc)
	{
		if (index == 0)
		{
			prepend(wartosc);
			return;
		}
		else if (index == rozmiar)
		{
			append(wartosc);
			return;
		}
		else
		{
			Node* newNode = new Node(wartosc);
			Node* iterator = head;
			for (int i = 0; i < index; i++)
			{
				iterator = iterator->next;
			}
			newNode->next = iterator;
			newNode->prev = iterator->prev;
			iterator->prev->next = newNode;
			iterator->prev = newNode;
			rozmiar++;
		}
	}

	void remove(int index)
	{
		Node* iterator;

		if (index < rozmiar / 2)
		{
			iterator = head;
			for (int i = 0; i < index; i++)
			{
				iterator = iterator->next;
			}
		}
		else
		{
			iterator = tail;
			for (int i = rozmiar - 1; i > index; i--)
			{
				iterator = iterator->prev;
			}
		}
		if (iterator == head)
		{
			head = iterator->next;
		}
		else if (iterator == tail)
		{
			tail = iterator->prev;
		}
		else if (iterator -> prev)
		{
			iterator->prev->next = iterator->next;
		}
		else
		{
			iterator->next->prev = iterator->prev;
		}

		delete iterator;
		rozmiar--;
	}

	void show()
	{
		Node* temp = head;
		cout << "Lista: ";
		while (temp != nullptr)
		{
			cout << temp->dane << ", ";
			temp = temp->next;
		}
		cout << "null" << endl;
	}

	int find(int wartosc)
	{
		Node* iterator = head;
		int index = 0;
		while (iterator->dane != wartosc)
		{
			iterator = iterator->next;
			index++;
		}
		cout << "Wartosc (" << wartosc << ") znajduje sie na indeksie : " << index << endl;
		return index;
	}

	~List()
	{
		Node* temp;
		while (head != nullptr)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}


private:
	Node* head;
	Node* tail;
	int rozmiar;
};
