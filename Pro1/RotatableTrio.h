//Elijah Turany
//CS244-002
#pragma once

//Node class
template <typename T>
class Node {
private:
	T data;
	Node<T>* next;
public:
	//Constructors
	Node(T data) {
		this->data = data;
		next = nullptr;
	}
	Node(T data, Node<T>* next) {
		this->data = data;
		this->next = next;
	}
	//Getters, setters
	T getData() { return data; }
	Node<T>* getNext() { return next; }
	void setData(T d) { data = d; }
	void setNext(Node<T>* n) { next = n; }
};

template <typename T>
class RotatableTrio {
private:
	Node<T>* first{ nullptr };
public:
	//Constructor
	RotatableTrio(T data1, T data2, T data3) {
		//Creates the last node first
		Node<T>* node3 = new Node<T>{ data3 };
		//Creates the middle and first node and sets the next one to the next node
		Node<T>* node2 = new Node<T>{ data2, node3 };
		Node<T>* node1 = new Node<T>{ data1, node2 };
		//Sets the last node's next field to the first
		node3->setNext(node1);
		//Updates the first pointer to the first node
		first = node1;
	}

	//Getters
	T getFirst() {
		return first->getData();
	}

	T getMiddle() {
		return first->getNext()->getData();
	}

	T getLast() {
		return first->getNext()->getNext()->getData();
	}

	//Sets the next pointer to the previous node
	void rotate() {
		first = first->getNext()->getNext();
	}

	//Setters that throw exceptions
	void setFirst(T d) { throw "Setters not used"; }
	void setMiddle(T d) { throw "Setters not used"; }
	void setLast(T d) { throw "Setters not used"; }

};
