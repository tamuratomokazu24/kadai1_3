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
	assert(this->_ptr->preNode);					//�擪�_�~�[���f�N�������g���悤�Ƃ����ꍇ
	assert(this->_ptr != this->_ptr->preNode);	//��̃��X�g�̖����_�~�[���f�N�������g���悤�Ƃ����ꍇ
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
	assert(this->_ptr != this->_ptr->nextNode);	//��̃��X�g�̐擪�_�~�[���C���N�������g���悤�Ƃ����ꍇ
	assert(this->_ptr->nextNode);				//�����_�~�[���C���N�������g���悤�Ƃ����ꍇ
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
	assert(this->_ptr);				//�m�[�h���w���Ă��Ȃ��R���X�g�C�e���[�^�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_ptr->preNode);	//�擪�_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_ptr->nextNode);	//�����_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
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
	assert(this->_ptr);				//�m�[�h���w���Ă��Ȃ��C�e���[�^�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_ptr->preNode);	//�擪�_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_ptr->nextNode);	//�����_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	return this->_ptr->value;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {

	//�擪�Ɩ����̃_�~�[���쐬
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
	//**********	�f�[�^�̑}���Ɏ��s	**********//

	//���̃��X�g�̃R���X�g�C�e���[�^�����X�g�ւ̎Q�Ƃ��Ȃ��R���X�g�C�e���[�^���n���ꂽ�ꍇ
	if (cIterator.getReferenceToList() != this) {
		return false;
	}

	//********************************************//

	Node* newNode = new Node(cIterator.getPtr()->preNode, cIterator.getPtr(), val);
	cIterator.getPtr()->preNode->nextNode = newNode;
	cIterator.getPtr()->preNode = newNode;

	_size++;

	return true;
}

template<class T>
bool DoublyLinkedList<T>::remove(ConstIterator cIterator) {

	//**********	�f�[�^�̍폜�Ɏ��s	**********//
	//���̃��X�g�̃R���X�g�C�e���[�^�����X�g�ւ̎Q�Ƃ��Ȃ��R���X�g�C�e���[�^���n���ꂽ�ꍇ

	if (cIterator.getReferenceToList() != this) {
		return false;
	}
	if (cIterator.getPtr() == this->_dummyFirstNode || cIterator.getPtr() == this->_dummyLastNode) {
		return false;
	}

	//*******************************************//

	cIterator.getPtr()->preNode->nextNode = cIterator.getPtr()->nextNode;
	cIterator.getPtr()->nextNode->preNode = cIterator.getPtr()->preNode;

	delete cIterator.getPtr();
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
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::rcbegin() const {
	ConstIterator ret(this, _dummyLastNode->preNode);
	return ret;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::rcend() const {
	ConstIterator ret(this, _dummyFirstNode);
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

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::rbegin() {
	Iterator ret(this, _dummyLastNode->preNode);
	return ret;
}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::rend() {
	Iterator ret(this, _dummyFirstNode);
	return ret;
}