#ifndef LIST_H
#define LIST_H

typedef int TYPE;

class Node
{
public:
	Node(TYPE &data, Node* nextNode);
	TYPE getData() const { return _data; }
	Node* getNextNode() const { return _nextNode; }
private:
	TYPE _data;
	Node* _nextNode;

};
#endif