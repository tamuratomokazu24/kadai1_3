#pragma once

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

template<class T>
class DoublyLinkedList {

private:

	struct Node {

		Node* preNode; /** �P�O����Node���w���|�C���^ */
		Node* nextNode; /** �P�����Node���w���|�C���^ */
		T value; /** ���X�g�Ɋi�[����l */

		/**
		* �O��̃m�[�h���w�肵��Node���쐬����R���X�g���N�^
		*
		* @param[in] preNode �P�O����Node���w���|�C���^
		* @param[in] nextNode �P�����Node���w���|�C���^
		*/
		Node(Node* preNode, Node* nextNode);

		/**
		* �O��̃m�[�h�Ɗi�[����l���w�肵��Node���쐬����R���X�g���N�^
		*
		* @param[in] preNode �P�O����Node���w���|�C���^
		* @param[in] nextNode �P�����Node���w���|�C���^
		* @param[in] value �m�[�h�����l
		*/
		Node(Node* preNode, Node* nextNode, const T& value);
	};

public:
	class ConstIterator {
	protected:

		const DoublyLinkedList<T>* _referenceToList;	/** ���X�g�ւ̎Q�� */
		Node* _ptr;	/** �C�e���[�^�������I�ɕێ�����Node* */

	public:

		/**
		* ���X�g�ւ̎Q�Ƃ�Ԃ��֐�
		*/
		const DoublyLinkedList<T>* getReferenceToList() {
			return _referenceToList;
		}

		/**
		* �m�[�h�ւ̎Q�Ƃ�Ԃ��֐�
		*/
		Node* getPtr() {
			return _ptr;
		}

		/**
		* ConstIterator���P�O���ɖ߂�(�O�u�f�N�������g)
		*/
		ConstIterator& operator--();

		/**
		* ConstIterator���P�O���ɖ߂�(��u�f�N�������g)
		*/
		ConstIterator operator--(int);

		/**
		* ConstIterator���P����ɐi�߂�(�O�u�C���N�������g)
		*/
		ConstIterator& operator++();

		/**
		* ConstIterator���P����ɐi�߂�(��u�C���N�������g)
		*/
		ConstIterator operator++(int);

		/**
		* ConstIterator�����l���Q�Ƃ���
		*/
		const T& operator*() const;

		/**
		* �f�t�H���g�R���X�g���N�^
		*/
		ConstIterator() {}
		
		/**
		* �R�s�[�R���X�g���N�^
		*/
		ConstIterator(const ConstIterator& constIterator) :_referenceToList(constIterator._referenceToList), _ptr(constIterator._ptr) {}

		/**
		* �Q�Ƃ��郊�X�g��Node*����R���X�g�C�e���[�^���쐬����R���X�g���N�^
		*/
		ConstIterator(const DoublyLinkedList<T>* list, Node* node) :_referenceToList(list), _ptr(node) {}

		/**
		* ConstIterator�̑��
		*/
		ConstIterator& operator=(const ConstIterator& rhs);

		/**
		* �Q��ConstIterator��������������
		*
		* @return bool	true:lhs��rhs��������\n
						false:lhs��rhs���قȂ�\n
		*/
		bool operator==(const ConstIterator& rhs) const;

		/**
		* �Q��ConstIterator���قȂ邩����
		*
		* @return bool	true:lhs��rhs���قȂ�\n
						false:lhs��rhs��������\n
		*/
		bool operator!=(const ConstIterator& rhs) const;

	};

	class Iterator :public ConstIterator {
	public:

		/**
		* Iterator�����l���Q�Ƃ���
		*/
		T& operator*();

		/**
		* �f�t�H���g�R���X�g���N�^
		*/
		Iterator() :ConstIterator() {}

		/**
		* �R�s�[�R���X�g���N�^
		*/
		Iterator(const Iterator& iterator) :ConstIterator(iterator) {}

		/**
		* �Q�Ƃ��郊�X�g��Node*����C�e���[�^���쐬����R���X�g���N�^
		*/
		Iterator(DoublyLinkedList<T>* list, Node* node) :ConstIterator(list, node) {}
	};

private:

	Node* _dummyFirstNode;	/** �擪�̃_�~�[�m�[�h���w���|�C���^ */
	Node* _dummyLastNode;	/** �����̃_�~�[�m�[�h���w���|�C���^ */

	int _size; /** �_�~�[�m�[�h�������m�[�h�̌� */

public:

	/**
	* �擪�Ɩ����̃_�~�[�m�[�h���쐬����R���X�g���N�^
	*/
	DoublyLinkedList();

	/**
	* �f�X�g���N�^
	*/
	~DoublyLinkedList();

	/**
	* @return int �_�~�[�m�[�h�������m�[�h�̌�
	*/
	int size() const;

	/**
	* �w�肵���R���X�g�C�e���[�^�̂P�O���Ƀf�[�^��}������
	*
	* @param[in] cIterator �}������ꏊ���w���R���X�g�C�e���[�^
	* @param[in] value �}������l
	*
	* @return bool	true:����Ƀf�[�^��}�����邱�Ƃ��ł���\n
	*				false:�f�[�^�̑}���Ɏ��s����\n
	*/
	bool insert(ConstIterator cIterator, const T& value);

	/**
	* �w�肵���R���X�g�C�e���[�^���w���f�[�^���폜����
	*
	* @param[in] cIterator �폜����f�[�^���w���R���X�g�C�e���[�^
	* @return bool	true:����Ƀf�[�^���폜���邱�Ƃ��ł���\n
	*				false:�f�[�^�̍폜�Ɏ��s����\n
	*/
	bool remove(ConstIterator cIterator);

	/**
	* ���X�g�̐擪���w���R���X�g�C�e���[�^��Ԃ�
	*
	* @return ConstIterator	���X�g����̏ꍇ�͐擪�̃_�~�[���w���R���X�g�C�e���[�^\n
	*						���X�g�ɗv�f������ꍇ�͐擪�v�f���w���R���X�g�C�e���[�^\n
	*/
	ConstIterator cbegin() const;

	/**
	* ���X�g�̖������w���R���X�g�C�e���[�^��Ԃ�
	*
	* @return ConstIterator	���X�g����̏ꍇ�͖����̃_�~�[���w���R���X�g�C�e���[�^\n
	*						���X�g�ɗv�f������ꍇ�͖����v�f���w���R���X�g�C�e���[�^\n
	*/
	ConstIterator cend() const;

	/**
	* ���X�g���t���Ɍ���ۂ̐擪���w���R���X�g�C�e���[�^��Ԃ�
	*
	* @return ConstIterator	���X�g����̏ꍇ�̓��X�g�t���̐擪�̃_�~�[���w���R���X�g�C�e���[�^\n
	*						���X�g�ɗv�f������ꍇ�̓��X�g�t���̐擪�v�f���w���R���X�g�C�e���[�^\n
	*/
	ConstIterator rcbegin() const;

	/**
	* ���X�g���t���Ɍ���ۂ̖������w���R���X�g�C�e���[�^��Ԃ�
	*
	* @return ConstIterator	���X�g����̏ꍇ�̓��X�g�t���̖����̃_�~�[���w���R���X�g�C�e���[�^\n
	*						���X�g�ɗv�f������ꍇ�̓��X�g�t���̖����v�f���w���R���X�g�C�e���[�^\n
	*/
	ConstIterator rcend() const;

	/**
	* ���X�g�̐擪���w���C�e���[�^��Ԃ�
	*
	* @return Iterator	���X�g����̏ꍇ�͐擪�̃_�~�[���w���C�e���[�^\n
	*					���X�g�ɗv�f������ꍇ�͐擪�v�f���w���C�e���[�^\n
	*/
	Iterator begin();

	/**
	* ���X�g�̖������w���C�e���[�^��Ԃ�
	*
	* @return Iterator	���X�g����̏ꍇ�͖����̃_�~�[���w���C�e���[�^\n
	*					���X�g�ɗv�f������ꍇ�͖����v�f���w���C�e���[�^\n
	*/
	Iterator end();

	/**
	* ���X�g���t���Ɍ���ۂ̐擪���w���C�e���[�^��Ԃ�
	*
	* @return Iterator	���X�g����̏ꍇ�̓��X�g�t���̐擪�̃_�~�[���w���C�e���[�^\n
	*					���X�g�ɗv�f������ꍇ�̓��X�g�t���̐擪�v�f���w���C�e���[�^\n
	*/
	Iterator rbegin();

	/**
	* ���X�g���t���Ɍ���ۂ̖������w���C�e���[�^��Ԃ�
	*
	* @return Iterator	���X�g����̏ꍇ�̓��X�g�t���̖����̃_�~�[���w���C�e���[�^\n
	*					���X�g�ɗv�f������ꍇ�̓��X�g�t���̖����v�f���w���C�e���[�^\n
	*/
	Iterator rend();

};

#include "DoublyLinkedList.inl"

#endif