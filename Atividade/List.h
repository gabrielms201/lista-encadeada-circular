/*
LICAO LISTA ENCADEADA CIRCULAR - ESTRUTURA DE DADOS
GRUPO:

MAYARA MENEGHETTI HONDA                  :  32152280
PAULO HENRIQUE BRAGA CECHINEL            :  32151128
RICARDO GABRIEL MARQUES DOS SANTOS RUIZ  :  32134908

*/

#ifndef LIST_H
#define LIST_H
#if !(__cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1900))
	#define nullptr NULL
#endif

#include "Soldier.h"
#include <string.h>
#include <iostream>
#include <sstream>
#include <ostream>
#include <stdexcept>

typedef Soldier TYPE;

// Node Class
class Node
{
public:
	Node(TYPE& data, Node* nextNode);
	TYPE& getData() { return _data; }
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
	Soldier& findByPosition(unsigned int position) const;
	unsigned int findPosition(Soldier& soldier) const;
	unsigned int getSize() const { return _size; }
	std::string toString(const bool verbose = false) const;
private:
	unsigned int _size;
	Node* _head;
};

inline std::ostream& operator <<(std::ostream& str, const List& list)
{
	return str << list.toString();
}
#endif
