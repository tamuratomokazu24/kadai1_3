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
	assert(this->_ptr);						//リストへの参照がないイテレータをデクリメントしようとした場合	
	assert(this->_ptr->preNode);			//先頭ダミーをデクリメントしようとした場合
	assert(this->_referenceToList->size());	//参照しているリストが空の場合
	this->_ptr = this->_ptr->preNode;
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
	assert(this->_ptr);							//リストへの参照がないイテレータをインクリメントしようとした場合
	assert(this->_ptr->nextNode);				//末尾ダミーをインクリメントしようとした場合
	assert(this->_referenceToList->size());		//参照しているリストが空の場合
	this->_ptr = this->_ptr->nextNode;
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
	assert(this->_ptr);				//ノードを指していないコンストイテレータの要素を参照しようとした場合
	assert(this->_ptr->preNode);	//先頭ダミーの要素を参照しようとした場合
	assert(this->_ptr->nextNode);	//末尾ダミーの要素を参照しようとした場合
	return this->_ptr->value;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator& DoublyLinkedList<T>::ConstIterator::operator=(const ConstIterator& rhs) {
	this->_referenceToList = rhs._referenceToList;
	this->_ptr = rhs._ptr;
	return *this;
}

template<class T>
bool DoublyLinkedList<T>::ConstIterator::operator==(const ConstIterator& rhs) const {
	return this->_ptr == rhs._ptr;
}

template<class T>
bool DoublyLinkedList<T>::ConstIterator::operator!=(const ConstIterator& rhs) const {
	return this->_ptr != rhs._ptr;
}

template<class T>
T& DoublyLinkedList<T>::Iterator::operator*() {
	assert(this->_ptr);				//ノードを指していないイテレータの要素を参照しようとした場合
	assert(this->_ptr->preNode);	//先頭ダミーの要素を参照しようとした場合
	assert(this->_ptr->nextNode);	//末尾ダミーの要素を参照しようとした場合
	return this->_ptr->value;
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
DoublyLinkedList<T>::~DoublyLinkedList() {
	while (cbegin() != cend()) {
		remove(cbegin());
	}
}

template<class T>
int DoublyLinkedList<T>::size() const {
	return this->_size;
}

template<class T>
bool DoublyLinkedList<T>::insert(ConstIterator cIterator, const T& val) {
	//**********	データの挿入に失敗	**********//

	//他のリストのコンストイテレータかリストへの参照がないコンストイテレータが渡された場合
	if (cIterator._referenceToList != this) {
		return false;
	}

	//********************************************//

	Node* newNode = new Node(cIterator._ptr->preNode, cIterator._ptr, val);
	cIterator._ptr->preNode->nextNode = newNode;
	cIterator._ptr->preNode = newNode;

	_size++;

	return true;
}

template<class T>
bool DoublyLinkedList<T>::remove(ConstIterator cIterator) {

	//**********	データの削除に失敗	**********//
	//他のリストのコンストイテレータかリストへの参照がないコンストイテレータが渡された場合

	if (cIterator._referenceToList != this) {
		return false;
	}
	if (cIterator._ptr == this->_dummyFirstNode || cIterator._ptr == this->_dummyLastNode) {
		return false;
	}

	//*******************************************//

	cIterator._ptr->preNode->nextNode = cIterator._ptr->nextNode;
	cIterator._ptr->nextNode->preNode = cIterator._ptr->preNode;

	delete cIterator._ptr;
	--_size;

	return true;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::cbegin() const {
	ConstIterator ret(this, _dummyFirstNode->nextNode);
	return ret;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::cend() const {
	ConstIterator ret(this,_dummyLastNode);
	return ret;
}
template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin() {
	Iterator ret(this, _dummyFirstNode->nextNode);
	return ret;
}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::end() {
	Iterator ret(this,_dummyLastNode);
	return ret;
}
