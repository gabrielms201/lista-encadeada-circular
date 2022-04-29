#include "List.h"

// Node Class

// Construtor do Nó
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
// Verifica se a lista está vazia
bool List::isEmpty() const
{
	return _size == 0;
}
// Verifica se a lista está cheia
bool List::isFull() const
{
	return false;
}
// Insere um elemento no final da lista
bool List::insert(TYPE& data)
{
	if (find(data))
	{
		std::cout << "Não pode existir um soldado com mesmo nome e ID!" << std::endl;
		return false;
	}
	Node* node = new Node(data, nullptr);
	// Caso a lista estiver vazia, então adicionar o nó na cabeça e fazer ele apontar pra ele mesmo
	if (isEmpty())
	{
		_head = node;
		_head->setNextNode(_head);
		_size++;
		return true;
	}
	// Caso o contrário, andar até o final da lista, apontar pro novo elemento e fazer o novo elemento apontar pra cabeça
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

	// Se a própria cabeça já guarda o elemento que precisamos, apenas removemos ele:
	if (ptr->getData() == data)
	{
		_head = ptr->getNextNode();
		
		// Agora precisamos percorrer a lista para fazer com que o último elemento aponte para a nova cabeça:
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
	// Se esse não for o caso, a gente "anda" até encontrar (ou não), o elemento dado
	while (ptr->getNextNode() != _head && ptr->getData() != data)
	{
		bkpPtr = ptr;
		ptr = ptr->getNextNode();
	}

	// Se o próximo nó for igual a cabeça, e o elemento for diferente do procurado, então não encontramos
	if (ptr->getNextNode() == _head && ptr->getData() != data)
	{
		return false;
	}
	// Caso encontramos, apenas precisamos apontar o nó anterior para o próximo do que desejamos remover
	bkpPtr->setNextNode(ptr->getNextNode());
	_size--;
	delete ptr;
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

	// Se a própria cabeça já guarda o elemento que precisamos, apenas removemos ele:
	if (ptr->getData().getId() == id)
	{
		_head = ptr->getNextNode();

		// Agora precisamos percorrer a lista para fazer com que o último elemento aponte para a nova cabeça:
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
	// Se esse não for o caso, a gente "anda" até encontrar (ou não), o elemento dado
	while (ptr->getNextNode() != _head && ptr->getData().getId() != id)
	{
		bkpPtr = ptr;
		ptr = ptr->getNextNode();
	}

	// Se o próximo nó for igual a cabeça, e o elemento for diferente do procurado, então não encontramos
	if (ptr->getNextNode() == _head && ptr->getData().getId() != id)
	{
		return false;
	}
	// Caso encontramos, apenas precisamos apontar o nó anterior para o próximo do que desejamos remover
	bkpPtr->setNextNode(ptr->getNextNode());
	_size--;
	delete ptr;
}
// Limpa a lista
bool List::clear()
{
	// Se já estiver vazio, retornar true
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
bool List::findById(unsigned int id) const
{
	if (isEmpty())
	{
		return false;
	}
	Node* ptr = _head;
	if (ptr->getData().getId() == id)
	{
		return true;
	}
	while (ptr->getNextNode() != _head && ptr->getData().getId() != id)
	{
		ptr = ptr->getNextNode();
	}
	if (ptr != _head && ptr->getData().getId() == id)
	{
		return true;
	}
	return false;
}
// Converte o conteúdo da lista para string
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
	// Para o último nó:
	ss << ptr->getData();

	return ss.str();
}
