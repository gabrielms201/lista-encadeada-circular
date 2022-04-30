#include "List.h"

// Node Class

// Construtor do N�
Node::Node(TYPE& data, Node* nextNode)
	: _data(data), _nextNode(nextNode) {}

// <---------------------------------------------------------> \\

// List Class

// Construtor da lista
List::List()
{
	_head = nullptr;
	_size = 0;
}
// Destrutor da lista
List::~List()
{
	clear();
}
// Verifica se a lista est� vazia
bool List::isEmpty() const
{
	return _size == 0;
}
// Verifica se a lista est� cheia
bool List::isFull() const
{
	return false;
}
// Insere um elemento no final da lista
bool List::insert(TYPE& data)
{
	if (find(data))
	{
		std::cout << "N�o pode existir um soldado com mesmo nome e ID!" << std::endl;
		return false;
	}
	Node* node = new Node(data, nullptr);
	// Caso a lista estiver vazia, ent�o adicionar o n� na cabe�a e fazer ele apontar pra ele mesmo
	if (isEmpty())
	{
		_head = node;
		_head->setNextNode(_head);
		_size++;
		return true;
	}
	// Caso o contr�rio, andar at� o final da lista, apontar pro novo elemento e fazer o novo elemento apontar pra cabe�a
	Node* ptr = _head;
	while (ptr->getNextNode() != _head)
	{
		ptr = ptr->getNextNode();
	}
	ptr->setNextNode(node);
	node->setNextNode(_head);
	_size++;
	return true;
}
// Remove o elemento da lista pelo objeto passado
bool List::remove(TYPE& data)
{
	if (isEmpty())
	{
		return false;
	}

	Node* ptr = _head;
	Node* bkpPtr = nullptr;

	// Se a pr�pria cabe�a j� guarda o elemento que precisamos, apenas removemos ele:
	if (ptr->getData() == data)
	{
		_head = ptr->getNextNode();
		
		// Agora precisamos percorrer a lista para fazer com que o �ltimo elemento aponte para a nova cabe�a:
		bkpPtr = _head;
		while (bkpPtr->getNextNode() != ptr && bkpPtr->getData() != data)
		{
			//bkpPtr = wptr;
			bkpPtr = bkpPtr->getNextNode();
		}
		bkpPtr->setNextNode(_head);
		_size--;
		delete ptr;
		return true;
	}
	// Se esse n�o for o caso, a gente "anda" at� encontrar (ou n�o), o elemento dado
	while (ptr->getNextNode() != _head && ptr->getData() != data)
	{
		bkpPtr = ptr;
		ptr = ptr->getNextNode();
	}

	// Se o pr�ximo n� for igual a cabe�a, e o elemento for diferente do procurado, ent�o n�o encontramos
	if (ptr->getNextNode() == _head && ptr->getData() != data)
	{
		return false;
	}
	// Caso encontramos, apenas precisamos apontar o n� anterior para o pr�ximo do que desejamos remover
	bkpPtr->setNextNode(ptr->getNextNode());
	_size--;
	delete ptr;
	return true;
}
// Remove o elemento da lista pelo id do Soldado
bool List::removeById(unsigned int id)
{
	if (isEmpty())
	{
		return false;
	}

	Node* ptr = _head;
	Node* bkpPtr = nullptr;

	// Se a pr�pria cabe�a j� guarda o elemento que precisamos, apenas removemos ele:
	if (ptr->getData().getId() == id)
	{
		_head = ptr->getNextNode();

		// Agora precisamos percorrer a lista para fazer com que o �ltimo elemento aponte para a nova cabe�a:
		bkpPtr = _head;
		while (bkpPtr->getNextNode() != ptr && bkpPtr->getData().getId() != id)
		{
			//bkpPtr = wptr;
			bkpPtr = bkpPtr->getNextNode();
		}
		bkpPtr->setNextNode(_head);
		_size--;
		delete ptr;
		return true;
	}
	// Se esse n�o for o caso, a gente "anda" at� encontrar (ou n�o), o elemento dado
	while (ptr->getNextNode() != _head && ptr->getData().getId() != id)
	{
		bkpPtr = ptr;
		ptr = ptr->getNextNode();
	}

	// Se o pr�ximo n� for igual a cabe�a, e o elemento for diferente do procurado, ent�o n�o encontramos
	if (ptr->getNextNode() == _head && ptr->getData().getId() != id)
	{
		return false;
	}
	// Caso encontramos, apenas precisamos apontar o n� anterior para o pr�ximo do que desejamos remover
	bkpPtr->setNextNode(ptr->getNextNode());
	_size--;
	delete ptr;
	return true;
}
bool List::removeByName(std::string name)
{
	if (isEmpty())
	{
		return false;
	}

	Node* ptr = _head;
	Node* bkpPtr = nullptr;

	// Se a pr�pria cabe�a j� guarda o elemento que precisamos, apenas removemos ele:
	if (ptr->getData().getName() == name)
	{
		_head = ptr->getNextNode();

		// Agora precisamos percorrer a lista para fazer com que o �ltimo elemento aponte para a nova cabe�a:
		bkpPtr = _head;
		while (bkpPtr->getNextNode() != ptr && bkpPtr->getData().getName() != name)
		{
			//bkpPtr = wptr;
			bkpPtr = bkpPtr->getNextNode();
		}
		bkpPtr->setNextNode(_head);
		_size--;
		delete ptr;
		return true;
	}
	// Se esse n�o for o caso, a gente "anda" at� encontrar (ou n�o), o elemento dado
	while (ptr->getNextNode() != _head && ptr->getData().getName() != name)
	{
		bkpPtr = ptr;
		ptr = ptr->getNextNode();
	}

	// Se o pr�ximo n� for igual a cabe�a, e o elemento for diferente do procurado, ent�o n�o encontramos
	if (ptr->getNextNode() == _head && ptr->getData().getName() != name)
	{
		return false;
	}
	// Caso encontramos, apenas precisamos apontar o n� anterior para o pr�ximo do que desejamos remover
	bkpPtr->setNextNode(ptr->getNextNode());
	_size--;
	delete ptr;
	return true;
}
// Limpa a lista
bool List::clear()
{
	// Se j� estiver vazio, retornar true
	if (isEmpty())
	{
		return true;
	}
	Node* ptr = _head;
	Node* lastPtr = nullptr;
	while (ptr->getNextNode() != _head)
	{
		ptr = ptr->getNextNode();
	}
	lastPtr = ptr;

	while (!isEmpty())
	{
		Node* ptr = _head;
		_head = ptr->getNextNode();
		lastPtr->setNextNode(_head);
		delete ptr;
		_size--;
	}
	return true;
}
// Procura na lista um soldado com os mesmos valores de nome e id
bool List::find(const TYPE &data) const
{
	if (isEmpty())
	{
		return false;
	}
	Node* ptr = _head;
	if (ptr->getData() == data)
	{
		return true;
	}
	while (ptr->getNextNode() != _head && ptr->getData() != data)
	{
		ptr = ptr->getNextNode();
	}
	if (ptr != _head && ptr->getData() == data)
	{
		return true;
	}
	return false;
}
// Procura na lista um soldado pelo ID
Soldier& List::findById(unsigned int id) const
{
	if (isEmpty())
	{
		assert(0); // Soldado n�o encontrado
	}
	Node* ptr = _head;
	if (ptr->getData().getId() == id)
	{
		return ptr->getData();
	}
	while (ptr->getNextNode() != _head && ptr->getData().getId() != id)
	{
		ptr = ptr->getNextNode();
	}
	if (ptr != _head && ptr->getData().getId() == id)
	{
		return ptr->getData();
	}
	assert(0); // // Soldado n�o encontrado
}
// Encontra o soldado com o nome dado
Soldier& List::findByName(std::string name) const
{
	if (isEmpty())
	{
		assert(0);
	}
	Node* ptr = _head;
	if (ptr->getData().getName() == name)
	{
		return ptr->getData();
	}
	while (ptr->getNextNode() != _head && ptr->getData().getName() != name)
	{
		ptr = ptr->getNextNode();
	}
	if (ptr != _head && ptr->getData().getName() == name)
	{
		return ptr->getData();
	}
	assert(0);
}
// Encontra o soldado na posi��o X
Soldier& List::findByPosition(unsigned int position) const
{
	Node* ptr = _head;
	int count = 0;
	do
	{
		if (count == position)
		{
			return ptr->getData();
		}
		count++;
		ptr = ptr->getNextNode();
	} while (ptr != _head);
	assert(0);
}
// Encontra a posi��o do soldado
unsigned int List::findPosition(Soldier& soldier) const
{
	Node* ptr = _head;
	int count = 0;
	do
	{
		if (ptr->getData() == soldier)
		{
			return count;
		}
		count++;
		ptr = ptr->getNextNode();
	} while (ptr != _head);
	assert(0);
}
// Converte o conte�do da lista para string
std::string List::toString() const
{
	if (isEmpty())
	{
		return "null";
	}
	std::stringstream ss;
	Node* ptr = _head;
	// Se tiver mais de um elemento
	while (ptr->getNextNode() != _head)
	{
		ss << ptr->getData();
		ss << ";";
		ptr = ptr->getNextNode();
	}
	// Para o �ltimo n�:
	ss << ptr->getData();

	return ss.str();
}
