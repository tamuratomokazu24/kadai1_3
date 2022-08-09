#include<cassert>

template<class T>
DoublyLinkedList<T>::Node::Node(Node* preNode, Node* nextNode) {
	this->preNode = preNode;
	this->nextNode = nextNode;
}

template<class T>
DoublyLinkedList<T>::Node::Node(Node* preNode, Node* nextNode, const T& value) {
	this->preNode = preNode;
	this->nextNode = nextNode;
	this->value = value;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator& DoublyLinkedList<T>::ConstIterator::operator--() {
	assert(this->_it->preNode);					//先頭ダミーをデクリメントしようとした場合
	assert(this->_it != this->_it->preNode);	//空のリストの末尾ダミーをデクリメントしようとした場合
	this->_it = this->_it->preNode;
	return *this;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::ConstIterator::operator--(int) {
	ConstIterator tmp = *this;
	--* this;
	return tmp;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator& DoublyLinkedList<T>::ConstIterator::operator++() {
	assert(this->_it != this->_it->nextNode);	//空のリストの先頭ダミーをインクリメントしようとした場合
	assert(this->_it->nextNode);				//末尾ダミーをインクリメントしようとした場合
	this->_it = this->_it->nextNode;
	return *this;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::ConstIterator::operator++(int) {
	ConstIterator tmp = *this;
	++* this;
	return tmp;
}

template<class T>
const T& DoublyLinkedList<T>::ConstIterator::operator*() const {
	assert(this->_it);				//リストへの参照を持たないコンストイテレータの要素を参照しようとした場合
	assert(this->_it->preNode);		//先頭ダミーの要素を参照しようとした場合
	assert(this->_it->nextNode);	//末尾ダミーの要素を参照しようとした場合
	return this->_it->value;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator& DoublyLinkedList<T>::ConstIterator::operator=(const ConstIterator& rhs) {
	this->referenceToList = rhs.referenceToList;
	this->_it = rhs._it;
	return *this;
}

template<class T>
bool DoublyLinkedList<T>::ConstIterator::operator==(const ConstIterator& rhs) const {
	return this->_it == rhs._it;
}

template<class T>
bool DoublyLinkedList<T>::ConstIterator::operator!=(const ConstIterator& rhs) const {
	return this->_it != rhs._it;
}

template<class T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator--() {
	assert(this->_it->preNode);					//先頭ダミーをデクリメントしようとした場合
	assert(this->_it != this->_it->preNode);	//空のリストの末尾ダミーをデクリメントしようとした場合
	this->_it = this->_it->preNode;
	return *this;
}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator--(int) {
	Iterator tmp = *this;
	--* this;
	return tmp;
}

template<class T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator++() {
	assert(this->_it != this->_it->nextNode);	//空のリストの先頭ダミーをインクリメントしようとした場合
	assert(this->_it->nextNode);				//末尾ダミーをインクリメントしようとした場合
	this->_it = this->_it->nextNode;
	return *this;
}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator++(int) {
	Iterator tmp = *this;
	++* this;
	return tmp;
}

template<class T>
T& DoublyLinkedList<T>::Iterator::operator*() {
	assert(this->_it);				//リストへの参照を持たないイテレータの要素を参照しようとした場合
	assert(this->_it->preNode);		//先頭ダミーの要素を参照しようとした場合
	assert(this->_it->nextNode);	//末尾ダミーの要素を参照しようとした場合
	return this->_it->value;
}

template<class T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator=(Iterator& rhs) {
	this->referenceToList = rhs.referenceToList;
	this->_it = rhs._it;
	return *this;
}

template<class T>
bool DoublyLinkedList<T>::Iterator::operator==(const Iterator& rhs) const {
	return this->_it == rhs._it;
}

template<class T>
bool DoublyLinkedList<T>::Iterator::operator!=(const Iterator& rhs) const {
	return this->_it != rhs._it;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {

	//先頭と末尾のダミーを作成
	this->_dummyFirstNode = new Node(nullptr, nullptr);
	this->_dummyLastNode = new Node(nullptr, nullptr);
	this->_dummyFirstNode->nextNode = this->_dummyLastNode;
	this->_dummyLastNode->preNode = this->_dummyFirstNode;

	this->_size = 0;
}

template<class T>
int DoublyLinkedList<T>::size() const {
	return this->_size;
}

template<class T>
bool DoublyLinkedList<T>::insert(Iterator iterator, const T& val) {
	//**********	データの挿入に失敗	**********//

	//他のリストのイテレータかリストへの参照がないイテレータが渡された場合
	if (iterator.referenceToList != this) {
		return false;
	}

	//********************************************//

	Node* newNode = new Node(iterator._it->preNode, iterator._it, val);
	iterator._it->preNode->nextNode = newNode;
	iterator._it->preNode = newNode;

	_size++;

	return true;
}

template<class T>
bool DoublyLinkedList<T>::insert(ConstIterator cIterator, const T& val) {
	//**********	データの挿入に失敗	**********//

	//他のリストのコンストイテレータかリストへの参照がないコンストイテレータが渡された場合
	if (cIterator.referenceToList != this) {
		return false;
	}

	//********************************************//

	Node* newNode = new Node(cIterator._it->preNode, cIterator._it, val);
	cIterator._it->preNode->nextNode = newNode;
	cIterator._it->preNode = newNode;

	_size++;

	return true;
}

template<class T>
bool DoublyLinkedList<T>::remove(Iterator iterator) {

	//**********	データの削除に失敗	**********//
	//他のリストのイテレータかリストへの参照がないイテレータが渡された場合
	if (iterator.referenceToList != this) {
		return false;
	}
	if (iterator._it == this->_dummyFirstNode || iterator._it == this->_dummyLastNode) {
		return false;	//先頭ダミーまたは末尾ダミーを削除しようとした場合
	}

	//*******************************************//

	iterator._it->preNode->nextNode = iterator._it->nextNode;
	iterator._it->nextNode->preNode = iterator._it->preNode;

	--_size;

	return true;
}

template<class T>
bool DoublyLinkedList<T>::remove(ConstIterator cIterator) {

	//**********	データの削除に失敗	**********//
	//他のリストのコンストイテレータかリストへの参照がないコンストイテレータが渡された場合
	if (cIterator.referenceToList != this) {
		return false;
	}
	if (cIterator._it == this->_dummyFirstNode || cIterator._it == this->_dummyLastNode) {
		return false;	//先頭ダミーまたは末尾ダミーを削除しようとした場合
	}

	//*******************************************//

	cIterator._it->preNode->nextNode = cIterator._it->nextNode;
	cIterator._it->nextNode->preNode = cIterator._it->preNode;

	--_size;

	return true;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::getFirstConstIterator() const {
	ConstIterator ret;
	if (_size == 0) {
		ret._it = _dummyLastNode;
	}
	else {
		ret._it = _dummyFirstNode->nextNode;
	}
	ret.referenceToList = this;
	return ret;

}

template<class T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::getReverseFirstConstIterator() const {
	ConstIterator ret;
	if (_size == 0) {
		ret._it = _dummyFirstNode;
	}
	else {
		ret._it = _dummyLastNode->preNode;
	}
	ret.referenceToList = this;
	return ret;

}

template<class T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::getLastConstIterator() const {
	ConstIterator ret;
	ret._it = _dummyLastNode;
	ret.referenceToList = this;
	return ret;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::getReverseLastConstIterator() const {
	ConstIterator ret;
	ret._it = _dummyFirstNode;
	ret.referenceToList = this;
	return ret;

}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::getFirstIterator() {
	Iterator ret;
	if (_size == 0) {
		ret._it = _dummyLastNode;
	}
	else {
		ret._it = _dummyFirstNode->nextNode;
	}
	ret.referenceToList = this;
	return ret;

}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::getReverseFirstIterator() {
	Iterator ret;
	if (_size == 0) {
		ret._it = _dummyFirstNode;
	}
	else {
		ret._it = _dummyLastNode->preNode;
	}
	ret.referenceToList = this;
	return ret;

}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::getLastIterator() {
	Iterator ret;
	ret._it = _dummyLastNode;
	ret.referenceToList = this;
	return ret;
}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::getReverseLastIterator() {
	Iterator ret;
	ret._it = _dummyFirstNode;
	ret.referenceToList = this;
	return ret;

}