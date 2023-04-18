#pragma once

template <typename T>
class Node {
private:
	T data;
	Node<T>* next;
public:
	Node(T data) {
		this->data = data;
		next = nullptr;
	}
	Node(T data, Node<T>* next) {
		this->data = data;
		this->next = next;
	}
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
	RotatableTrio(T data1, T data2, T data3) {
		Node<T>* node3 = new Node<T>{ data3 };
		Node<T>* node2 = new Node<T>{ data2, node3 };
		Node<T>* node1 = new Node<T>{ data1, node2 };
		node3->setNext(node1);
		first = node1;
	}

	T getFirst() {
		return first->getData();
	}

	T getMiddle() {
		return first->getNext()->getData();
	}

	T getLast() {
		return first->getNext()->getNext()->getData();
	}

	void rotate() {
		first = first->getNext()->getNext();
	}

	void setFirst(T d) { throw "Setters not used"; }
	void setMiddle(T d) { throw "Setters not used"; }
	void setLast(T d) { throw "Setters not used"; }

};
