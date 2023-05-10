#include <iostream>
using namespace std;

template <class T>
class Node {
private:
	T info;
	Node<T>* next, * back;

public:
	Node() {
		next = NULL;
		back = NULL;
	}
	//getters
	T get_info() {
		return info;
	}
	Node<T>* get_next() {
		return next;
	}
	Node<T>* get_back() {
		return back;
	}

	//setters
	void set_info(T info_p) {
		info = info_p;
	}
	void set_next(Node<T>* n) {
		next = n;
	}
	void set_back(Node<T>* b) {
		back = b;
	}

	~Node() {

	}
};

template <class T>
class My_list {
private:
	Node<T>* head, * tail;

public:
	My_list() {
		head = NULL;
		tail = NULL;
	}

	Node<T>* get_head() {
		return head;
	}

	Node<T>* get_tail() {
		return tail;
	}

	void append(T info_p) {
		Node<T>* temp = new Node<T>();
		temp->set_info(info_p);
		if (head == NULL) {
			//first element in the list
			head = temp;
			tail = head;

		}
		else {
			//not the first element
			/*
			1.temp becomes tail
			2.temp->next = NULL
			3.temp->back = old tail
			4.old tail->next = temp
			*/
			temp->set_back(tail);
			tail->set_next(temp);
			temp->set_next(NULL);
			tail = tail->get_next();
		}
		
	}
	//write a method insertMid(node* curr, info)
	//it should insert a new node after curr in the linked list containing info
	
	void inserMid(Node<T>* curr, T info)
	{
		Node<T>* temp = new Node<T>;
		temp->set_info(info);
		if (head == NULL)
		{
			cout << "empty";
		}
		else if (tail == curr)
		{
			tail->set_next(temp);
			temp->set_back(tail);
			temp->set_next(NULL);
			tail = temp;
		}
		
		else
		{
			curr->get_next()->set_back(temp);
			temp->set_next(curr->get_next());
			temp->set_back(curr);
			curr->set_next(temp);
		}

	}
	void display()
	{
		Node<T>* temp = new Node<T>;
		temp = head;
		if (head == NULL)
		{
			cout << "empty" << endl;
		}
		else
		{
			while (temp != NULL)
			{
				cout << temp->get_info() << endl;
				temp = temp->get_next();
			}
		}
	}
	~My_list() {}

};

int main() {
	My_list <int>a;
	a.append(9);
	a.append(2);
	a.append(4);
	a.append(5);
	a.inserMid(a.get_head(), 10);
	a.display();

	return 0;
}