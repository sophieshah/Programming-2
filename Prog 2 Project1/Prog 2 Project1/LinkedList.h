#include <iostream>
#include <string>
#include <sstream>
#include <vector>
//#include "leaker.h"
using namespace std;

/*
remove head
remove tail
remove at
remove
clear
print forward recursive
print reverse recursive
*/

template <typename T>
class LinkedList {
public:
	struct Node {
		T data;
		Node* next;
		Node* prev;

		Node() {
			next = nullptr;
			prev = nullptr;
			data = {};
		}
	};
private:
	unsigned int _nodeCount = 0;
	Node* _head = nullptr;
	Node* _tail = nullptr;
	Node* _current;
public:

	LinkedList() {
		_nodeCount = 0;
		_head = nullptr;
		_tail = nullptr;
		_current = nullptr;
		//_head = new Node();
	}
	LinkedList(const LinkedList<T>& list) {
		//this->_head = list._head;
		//this->_tail = list._tail;
		//this->_nodeCount = list._nodeCount;
		//_head = nullptr;
		//_tail = nullptr;

		/*
		for (int i = 0; i < _nodeCount; i++) {
			_head = _head->next;
		}
		_tail = _head;
		_head = list._head;
		*/


		/*
		for (unsigned int i = 0; i < list._nodeCount; i++) {
			this->AddTail(list.GetNode(i)->data);
		}
		*/
		* this = list;


		/*
		Node* temp = new Node();
		this->_head = list._head;
		this->_tail = list._tail;

		//_tail = _head;
		while (_tail != nullptr) {
			//_tail->next = _tail;
			temp->next = nullptr;
			temp->prev = _tail;
			_tail->next = temp;
			_tail = temp;
			_nodeCount++;
		}
		*/

		/*
		Node* temp = new Node();
		this->_head = list._head;

		for (int i = 0; i < list._nodeCount; i++) {
			temp->next = nullptr;
			temp->prev = _head;
			_head->next = temp;
			_head = temp;
			_nodeCount++;
		}
		//_tail = _head;
		//_head = list._head;
		*/
	}

	LinkedList& operator=(const LinkedList<T>& rhs) {

		/*
		_head = nullptr;
		_tail = nullptr;
		//this->_head = list._head;
		//this->_tail = list._tail;
		//this->_nodeCount = rhs._nodeCount;

		//_head = nullptr;
		//_tail = nullptr;

		*/
		Node* temp;
		while (_head != nullptr) {
			temp = _head->next;
			delete _head;
			_head = temp;
		}
		_head = nullptr;
		_tail = nullptr;
		_nodeCount = 0;
		for (unsigned int i = 0; i < rhs._nodeCount; i++) {
			AddTail(rhs.GetNode(i)->data);
		}
		return *this;

	}

	~LinkedList() {
		if (_nodeCount == 0) {
			_head = nullptr;
			_tail = nullptr;
		}
		Node* temp = _head;
		//Node* temp = _head;
		while (temp != nullptr) {
			_head = _head->next;
			delete temp;
			temp = _head;
		}
	}
	T& operator[](unsigned int index) {
		if (index >= _nodeCount) {
			throw out_of_range("Out of Range");
		}
		GetNode(index);
	}
	const T& operator[](unsigned int index) const {
		if (index >= _nodeCount) {
			throw out_of_range("Out of Range");
		}
		GetNode(index);
	}
	bool operator==(const LinkedList<T>& rhs) {
		if (_nodeCount != rhs._nodeCount) {
			return false;
		}
		else {
			//cout << "count same" << endl;
			for (unsigned int i = 0; i < _nodeCount; i++) {
				//cout << "node " << GetNode(i)->data << "and other node " << GetNode(i)->data << endl;
				if (GetNode(i)->data != rhs.GetNode(i)->data) {
					return false;
				}
			}
		}
		return true;
	}
	void AddHead(const T& data) {
		if (_nodeCount == 0) {
			Node* temp = new Node();
			temp->data = data;
			_tail = temp;
			_head = temp;
		}
		else {
			Node* temp = new Node();
			temp->data = data;
			temp->next = _head;
			temp->prev = nullptr;
			_head->prev = temp;
			_head = temp;


			/*
			_tail = _head;
			while (_tail->next != nullptr) {

				_tail = _tail->next;

			}
			*/
		}
		_nodeCount++;
		//cout << "added head " << _head->data << endl;
		//cout << "current head " << _head << endl;
		//cout << "head next " << _head->next << endl;
		//2cout << "head prev " << _head->prev << endl;
		//cout << "current tail " << _tail << endl;
	}
	void AddTail(const T& data) {
		Node* temp = new Node();
		temp->data = data;

		if (_nodeCount == 0) {
			_tail = temp;
			_head = temp;
			//temp->data = data;

		}
		else {
			//_tail = _head;
			//while (_tail->next != nullptr) {
			//	_tail = _tail->next;
			//}
			//Node* temp = new Node();
			//temp->data = data;
			temp->next = nullptr;
			temp->prev = _tail;
			_tail->next = temp;
			//delete temp;
			_tail = temp;


		}
		//_tail->prev = _tail;



		//cout <<"added tail "<< _tail->data << endl;
		//cout << "current tail " << _tail << endl;
		//cout << "tail next " << _tail->next << endl;
		//cout << "tail prev " << _tail->prev << endl;
		//cout << "added head " << _head->nodeData << endl;

		_nodeCount++;
	}
	void AddNodesHead(const T* data, unsigned int count) {
		for (unsigned int i = count - 1; i >= 0; i--) {
			AddHead(data[i]);
		}
	}
	void AddNodesTail(const T* data, unsigned int count) {
		for (unsigned int i = 0; i < count; i++) {
			AddTail(data[i]);
		}
	}
	void InsertAfter(Node* node, const T& data) {
		Node* inserted = new Node();
		inserted->data = data;
		inserted->next = node->next;
		node->next = inserted;
		inserted->prev = node;
		_nodeCount++;

	}
	void InsertBefore(Node* node, const T& data) {
		Node* inserted = new Node();
		inserted->data = data;
		inserted->prev = node->prev;
		//cout <<"inserted prev "<< inserted->prev->data << endl;
		node->prev = inserted;
		//cout << "new node prev " << node->prev->data << endl;
		inserted->next = node;
		//cout << "inserted next " << inserted->next->data << endl;
		if (inserted->prev == nullptr) {
			_head = inserted;
		}
		else {
			inserted->prev->next = inserted;
		}
		_nodeCount++;

	}
	void InsertAt(const T& data, unsigned int index) {
		if (index > _nodeCount) {
			throw out_of_range("Out of Range");
		}
		if (index == _nodeCount) {
			//cout << "adding tail" << endl;
			AddTail(data);
		}
		else if (index == 0) {
			//cout << "adding head" << endl;
			AddHead(data);
			//cout << data << endl;
		}
		else {
			Node* temp = _head;
			for (unsigned int i = 0; i < index; i++) {
				temp = temp->next;
				//cout << "temp increase" << temp << endl;
			}
			InsertBefore(temp, data);
		}
		
	}
	unsigned int NodeCount() const {
		return _nodeCount;
	}
	void PrintForward() const {
		Node* temp = _head;
		while (temp != nullptr) {
			cout << temp->data << endl;
			temp = temp->next;
			//cout << temp->next << " ";
		}
	}
	void PrintReverse() const {
		Node* temp = _tail;

		while (temp != nullptr) {
			cout << temp->data << endl;
			temp = temp->prev;
			//cout << "new temp " << temp << endl;
		}
	}
	void PrintForwardRecursive(const Node* node) const {
		if (node == nullptr) {
			
		}
		else {
			cout << node->data << endl;
			node = node->next;
			PrintForwardRecursive(node);
		}
	}
	void PrintReverseRecursive(const Node* node) const {
		if (node == nullptr) {

		}
		else {
			cout << node->data << endl;
			node = node->prev;
			PrintReverseRecursive(node);
		}
	}
	Node* Head() {
		return _head;
	}
	const Node* Head() const {
		return _head;
	}
	Node* Tail() {
		return _tail;
	}
	const Node* Tail() const {
		return _tail;
	}
	Node* GetNode(unsigned int index) {
		if (index >= _nodeCount) {
			throw out_of_range("Out of Range");
		}
		Node* temp = _head;
		for (unsigned int i = 0; i < index-1; i++) {
			temp = temp->next;
		}
		return temp;
	}
	const Node* GetNode(unsigned int index) const {
		if (index >= _nodeCount) {
			throw out_of_range("Out of Range");
		}
		Node* temp = _head;
		for (unsigned int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp;
	}
	Node* Find(const T& data) {
		Node* temp = _head;
		for (unsigned int i = 0; i < _nodeCount; i++) {
			if (temp->data == data) {
				return temp;
			}
			else {
				temp = temp->next;
			}
		}
		return nullptr;
	}
	const Node* Find(const T& data) const {
		Node* temp = _head;
		for (unsigned int i = 0; i < _nodeCount; i++) {
			if (temp->data == data) {
				return temp;
			}
			else {
				temp = temp->next;
			}
		}
		return nullptr;
	}
	void FindAll(vector<Node*>& outData, const T& value) {
		Node* temp = _head;
		for (unsigned int i = 0; i < _nodeCount; i++) {
			if (temp->data == value) {
				outData.push_back(temp);
				//cout <<"data added " << _head->data;
				temp = temp->next;
			}
			else {
				temp = temp->next;
			}
		}
	}
	bool RemoveHead() {
		
		if (_nodeCount == 0) {
			//cout << "node count is 0 "<< endl;
			_head = nullptr;
			return false;
		}
		//cout << "removing " << _head->data << endl;
		if (_head->data == _tail->data) {
			//cout << "head=tail" << endl;
			delete _head;
			//delete _tail;
			//_head = nullptr;
			//_tail = nullptr;
			_nodeCount--;
			//cout << "node count " << _nodeCount << endl;
		}
		else {
			Node* temp = _head->next;
			delete _head;
			_head = temp;
			_head->prev = nullptr;
			_nodeCount--;
			//cout << "node count " << _nodeCount << endl;
			
		}
		return true;
	}
	bool RemoveTail() {
		if (_nodeCount == 0) {
			//cout << "node count is 0 " << endl;
			_tail = nullptr;
			return false;
		}
		//cout << "removing " << _tail->data << endl;
		if (_tail->data == _head->data) {
			//cout << "head=tail" << endl;
			delete _tail;
			_nodeCount--;
			//cout << "node count " << _nodeCount << endl;
		}
		else {
			Node* temp = _tail->prev;
			delete _tail;
			_tail = temp;
			_tail->next = nullptr;
			_nodeCount--;
			//cout << "node count " << _nodeCount << endl;
		}
		
		return true;
	}
	bool RemoveAt(unsigned int index) {
		if (_nodeCount == 0) {
			return false;
		}
		if (index == 0) {
			//cout << "removing head" << endl;
			RemoveHead();
			return true;
		}
		else if (index == _nodeCount) {
			//cout << "removing tail" << endl;
			RemoveTail();
			return true;
		}
		else if (index > _nodeCount) {
			//cout << "index out of range" << endl;
			return false;
		}
		else {
			//cout << "removing at index " << index << endl;
			Node* temp = _head;
			for (unsigned int i = 0; i < index; i++) {
				temp = temp->next;
			}
			Node* before = temp->prev;
			before->next = temp->next;
			temp->next->prev = before;
			delete temp;

			_nodeCount--;
		}
		return true;
	}
	unsigned int Remove(const T& data) {
		//cout << "testing remove of " << data << endl;
		unsigned int count = 0;
		Node* findRemove = _head;
		unsigned int nodeCountCopy = _nodeCount;
		if (_nodeCount == 0) {
			return 0;
		}
		for (unsigned int i = 0; i < nodeCountCopy; i++) {
			//cout << "new i value " << i << endl;
			if (findRemove->data == data) {
				//cout << "removed from index " << i << endl;
				Node* before = findRemove->prev;
				before->next = findRemove->next;
				findRemove->next->prev = before;
				delete findRemove;
				_nodeCount--;
				findRemove = before->next;
				count++;
				//cout << "node count " << _nodeCount << endl;
			}
			else {
				findRemove = findRemove->next;
				//cout << "new temp " << findRemove->data << endl;
			}
			
		}
		//cout << "count " << count << endl;
		return count;
	}
	void Clear() {
		while (RemoveHead()) {
			continue;
		}
		_head = nullptr;
		_tail = nullptr;
	}
};