#ifndef LIST_H
#define LIST_H
#if __cplusplus < 199711L
	#define nullptr NULL
#endif

#include "Soldier.h"
#include <string.h>
#include <iostream>
#include <sstream>
#include <ostream>
#include <assert.h>

typedef Soldier TYPE;

// Node Class
class Node
{
public:
	Node(TYPE& data, Node* nextNode);
	TYPE getData() const { return _data; }
	Node* getNextNode() const { return _nextNode; }
	void setData(TYPE& data) { _data = data; }
	void setNextNode(Node* nextNode) { _nextNode = nextNode; }
private:
	TYPE _data;
	Node* _nextNode;
};

// <---------------------------------------------------------> \\

// List Class
class List
{
public:
	List();
	~List();
	bool isEmpty() const;
	bool isFull() const;
	bool insert(TYPE& data);
	bool remove(TYPE& data);
	bool removeById(unsigned int id);
	bool removeByName(std::string name);
	bool clear();
	bool find(const TYPE& data) const;
	Soldier& findById(unsigned int id) const;
	Soldier& findByName(std::string name) const;
	Soldier& List::findByPosition(unsigned int position) const;
	unsigned int List::findPosition(Soldier& soldier) const;
	unsigned int getSize() const { return _size; }
	std::string toString() const;
private:
	unsigned int _size;
	Node* _head;
};

inline std::ostream& operator <<(std::ostream& str, const List& list)
{
	return str << list.toString();
}
#endif