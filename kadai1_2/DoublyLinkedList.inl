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
	assert(this->_it->preNode);					//�擪�_�~�[���f�N�������g���悤�Ƃ����ꍇ
	assert(this->_it != this->_it->preNode);	//��̃��X�g�̖����_�~�[���f�N�������g���悤�Ƃ����ꍇ
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
	assert(this->_it != this->_it->nextNode);	//��̃��X�g�̐擪�_�~�[���C���N�������g���悤�Ƃ����ꍇ
	assert(this->_it->nextNode);				//�����_�~�[���C���N�������g���悤�Ƃ����ꍇ
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
	assert(this->_it);				//���X�g�ւ̎Q�Ƃ������Ȃ��R���X�g�C�e���[�^�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_it->preNode);		//�擪�_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_it->nextNode);	//�����_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
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
	assert(this->_it->preNode);					//�擪�_�~�[���f�N�������g���悤�Ƃ����ꍇ
	assert(this->_it != this->_it->preNode);	//��̃��X�g�̖����_�~�[���f�N�������g���悤�Ƃ����ꍇ
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
	assert(this->_it != this->_it->nextNode);	//��̃��X�g�̐擪�_�~�[���C���N�������g���悤�Ƃ����ꍇ
	assert(this->_it->nextNode);				//�����_�~�[���C���N�������g���悤�Ƃ����ꍇ
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
	assert(this->_it);				//���X�g�ւ̎Q�Ƃ������Ȃ��C�e���[�^�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_it->preNode);		//�擪�_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_it->nextNode);	//�����_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
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

	//�擪�Ɩ����̃_�~�[���쐬
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
	//**********	�f�[�^�̑}���Ɏ��s	**********//

	//���̃��X�g�̃C�e���[�^�����X�g�ւ̎Q�Ƃ��Ȃ��C�e���[�^���n���ꂽ�ꍇ
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
	//**********	�f�[�^�̑}���Ɏ��s	**********//

	//���̃��X�g�̃R���X�g�C�e���[�^�����X�g�ւ̎Q�Ƃ��Ȃ��R���X�g�C�e���[�^���n���ꂽ�ꍇ
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

	//**********	�f�[�^�̍폜�Ɏ��s	**********//
	//���̃��X�g�̃C�e���[�^�����X�g�ւ̎Q�Ƃ��Ȃ��C�e���[�^���n���ꂽ�ꍇ
	if (iterator.referenceToList != this) {
		return false;
	}
	if (iterator._it == this->_dummyFirstNode || iterator._it == this->_dummyLastNode) {
		return false;	//�擪�_�~�[�܂��͖����_�~�[���폜���悤�Ƃ����ꍇ
	}

	//*******************************************//

	iterator._it->preNode->nextNode = iterator._it->nextNode;
	iterator._it->nextNode->preNode = iterator._it->preNode;

	--_size;

	return true;
}

template<class T>
bool DoublyLinkedList<T>::remove(ConstIterator cIterator) {

	//**********	�f�[�^�̍폜�Ɏ��s	**********//
	//���̃��X�g�̃R���X�g�C�e���[�^�����X�g�ւ̎Q�Ƃ��Ȃ��R���X�g�C�e���[�^���n���ꂽ�ꍇ
	if (cIterator.referenceToList != this) {
		return false;
	}
	if (cIterator._it == this->_dummyFirstNode || cIterator._it == this->_dummyLastNode) {
		return false;	//�擪�_�~�[�܂��͖����_�~�[���폜���悤�Ƃ����ꍇ
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