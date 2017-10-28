#ifndef _TREEOBJECTMANAGERBASE_HPP_
#define _TREEOBJECTMANAGERBASE_HPP_

#include "managernode.hpp"
#include "objectmanagerbase.hpp"

template <class T>
class TreeObjectManagerBase : public ObjectManagerBase<Node<T>>
{
public:
	TreeObjectManagerBase();
	virtual ~TreeObjectManagerBase();

	virtual T *New() override final;
	virtual void Delete(T *&obj) override final;
};

#endif // !_TREEOBJECTMANAGERBASE_HPP_

template<class T>
inline TreeObjectManagerBase<T>::TreeObjectManagerBase()
{
}

template<class T>
inline TreeObjectManagerBase<T>::~TreeObjectManagerBase()
{
}

template<class T>
inline T * TreeObjectManagerBase<T>::New()
{
	NODE *temp = ObjectManagerBase::New();
	return temp->self();
}

template<class T>
inline void TreeObjectManagerBase<T>::Delete(T *& obj)
{
	ObjectManagerBase::Delete(dynamic_cats<Node<T>*>(obj));
}
