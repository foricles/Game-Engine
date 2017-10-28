#ifndef _MANAGERNODE_HPP_
#define _MANAGERNODE_HPP_

#include <deque>

#define NODE Node<T>
#define MNGR TreeObjectManagerBase<T>

template <class T>
class TreeObjectManagerBase;

template<class T>
class Node
{
	friend class TreeObjectManagerBase<T>;
private:
	MNGR *oManager;
	void setManager(MNGR *manager);
public:
	Node();
	virtual ~Node();

	virtual T *self() final;
private:
	NODE *oParent;
	std::deque<NODE*> oChildren;
};

template<class T>
Node<T>::Node()
	:oManager(nullptr)
	, oParent(nullptr)
{
}

template<class T> 
Node<T>::~Node()
{
}

template <class T>
T *Node<T>::self()
{
	return dynamic_cast<T*>(this);
}

template <class T>
void Node<T>::setManager(MNGR *manager)
{
	oManager = manager;
}
#endif // !_MANAGERNODE_HPP_
