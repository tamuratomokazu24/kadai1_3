#pragma once

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

class ConstIterator;
class Iterator;

template<class T>
class DoublyLinkedList {

	friend ConstIterator;
	friend Iterator;

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
		* �O��̃m�[�h�ƃf�[�^���w�肵��Node���쐬����R���X�g���N�^
		*
		* @param[in] preNode �P�O����Node���w���|�C���^
		* @param[in] nextNode �P�����Node���w���|�C���^
		* @param[in] value �m�[�h�����l
		*/
		Node(Node* preNode, Node* nextNode, const T& value);
	};

public:
	class ConstIterator {
	private:
		friend DoublyLinkedList;

		const DoublyLinkedList* referenceToList;	/** ���X�g�ւ̎Q�� */
		Node* _it; /** �����I�ɕێ�����Node* */

	public:
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
		ConstIterator() {};

		/**
		* �R�s�[�R���X�g���N�^
		*/
		ConstIterator(const ConstIterator& constIterator) :referenceToList(constIterator.referenceToList), _it(constIterator._it) {}

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
	private:
		friend DoublyLinkedList;

	public:
		/**
		* Iterator���P�O���ɖ߂�(�O�u�f�N�������g)
		*/
		Iterator& operator--();

		/**
		* Iterator���P�O���ɖ߂�(��u�f�N�������g)
		*/
		Iterator operator--(int);

		/**
		* Iterator���P����ɐi�߂�(�O�u�C���N�������g)
		*/
		Iterator& operator++();

		/**
		* Iterator���P����ɐi�߂�(��u�C���N�������g)
		*/
		Iterator operator++(int);

		/**
		* Iterator�����l���Q�Ƃ���
		*/
		T& operator*();

		/**
		* �f�t�H���g�R���X�g���N�^
		*/
		Iterator() {};

		/**
		* �R�s�[�R���X�g���N�^
		*/
		Iterator(const Iterator& iterator) :ConstIterator(iterator) {};

		/**
		* Iterator�̑��
		*/
		Iterator& operator=(Iterator& rhs);

		/**
		* �Q��Iterator��������������
		*
		* @return bool	true:lhs��rhs��������\n
						false:lhs��rhs���قȂ�\n
		*/
		bool operator==(const Iterator& rhs) const;

		/**
		* �Q��Iterator���قȂ邩����
		*
		* @return bool	true:lhs��rhs���قȂ�\n
						false:lhs��rhs��������\n
		*/
		bool operator!=(const Iterator& rhs) const;
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
	* @return int �_�~�[�m�[�h�������m�[�h�̌�
	*/
	int size() const;

	/**
	* �w�肵���C�e���[�^�̂P�O���Ƀf�[�^��}������
	*
	* @param[in] iterator �}������ꏊ���w���C�e���[�^
	* @param[in] value �}������l
	*
	* @return bool	true:����Ƀf�[�^��}�����邱�Ƃ��ł���\n
	*				false:�f�[�^�̑}���Ɏ��s����\n
	*/
	bool insert(Iterator iterator,const T& value);

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
	* �f�[�^�̍폜���C�폜�����f�[�^�̂P�O���̃f�[�^�ɃC�e���[�^��߂�
	*
	* @param[in] iterator �폜����f�[�^���w���C�e���[�^
	* @return bool	true:����Ƀf�[�^��}�����邱�Ƃ��ł���\n
	*				false:�f�[�^�̑}���Ɏ��s����\n
	*/
	bool remove(Iterator iterator);

	/**
	* �f�[�^�̍폜���C�폜�����f�[�^�̂P�O���̃f�[�^�ɃR���X�g�C�e���[�^��߂�
	*
	* @param[in] cIterator �폜����f�[�^���w���R���X�g�C�e���[�^
	* @return bool	true:����Ƀf�[�^��}�����邱�Ƃ��ł���\n
	*				false:�f�[�^�̑}���Ɏ��s����\n
	*/
	bool remove(ConstIterator cIterator);

	/**
	* ���X�g�̐擪���w���R���X�g�C�e���[�^��Ԃ�
	*
	* @return ConstIterator	���X�g����̏ꍇ�͐擪�̃_�~�[���w���R���X�g�C�e���[�^\n
	*						���X�g�ɗv�f������ꍇ�͐擪�v�f���w���R���X�g�C�e���[�^\n
	*/
	ConstIterator getFirstConstIterator() const;

	/**
	* ���X�g���t���Ɍ���ۂ̐擪���w���R���X�g�C�e���[�^��Ԃ�
	*
	* @return ConstIterator	���X�g����̏ꍇ�̓��X�g�t���̐擪�̃_�~�[���w���R���X�g�C�e���[�^\n
	*						���X�g�ɗv�f������ꍇ�̓��X�g�t���̐擪�v�f���w���R���X�g�C�e���[�^\n
	*/
	ConstIterator getReverseFirstConstIterator() const;

	/**
	* ���X�g�̖������w���R���X�g�C�e���[�^��Ԃ�
	*
	* @return ConstIterator	���X�g����̏ꍇ�͖����̃_�~�[���w���R���X�g�C�e���[�^\n
	*						���X�g�ɗv�f������ꍇ�͖����v�f���w���R���X�g�C�e���[�^\n
	*/
	ConstIterator getLastConstIterator() const;

	/**
	* ���X�g���t���Ɍ���ۂ̖������w���R���X�g�C�e���[�^��Ԃ�
	*
	* @return ConstIterator	���X�g����̏ꍇ�̓��X�g�t���̖����̃_�~�[���w���R���X�g�C�e���[�^\n
	*						���X�g�ɗv�f������ꍇ�̓��X�g�t���̖����v�f���w���R���X�g�C�e���[�^\n
	*/
	ConstIterator getReverseLastConstIterator() const;

	/**
	* ���X�g�̐擪���w���C�e���[�^��Ԃ�
	*
	* @return Iterator	���X�g����̏ꍇ�͐擪�̃_�~�[���w���C�e���[�^\n
	*					���X�g�ɗv�f������ꍇ�͐擪�v�f���w���C�e���[�^\n
	*/
	Iterator getFirstIterator();

	/**
	* ���X�g���t���Ɍ���ۂ̐擪���w���C�e���[�^��Ԃ�
	*
	* @return ConstIterator	���X�g����̏ꍇ�̓��X�g�t���̐擪�̃_�~�[���w���C�e���[�^\n
	*						���X�g�ɗv�f������ꍇ�̓��X�g�t���̐擪�v�f���w���C�e���[�^\n
	*/
	Iterator getReverseFirstIterator();

	/**
	* ���X�g�̖������w���C�e���[�^��Ԃ�
	*
	* @return Iterator	���X�g����̏ꍇ�͖����̃_�~�[���w���C�e���[�^\n
	*					���X�g�ɗv�f������ꍇ�͖����v�f���w���C�e���[�^\n
	*/
	Iterator getLastIterator();

	/**
	* ���X�g���t���Ɍ���ۂ̖������w���C�e���[�^��Ԃ�
	*
	* @return ConstIterator	���X�g����̏ꍇ�̓��X�g�t���̖����̃_�~�[���w���C�e���[�^\n
	*						���X�g�ɗv�f������ꍇ�̓��X�g�t���̖����v�f���w���C�e���[�^\n
	*/
	Iterator getReverseLastIterator();

};

#include "DoublyLinkedList.inl"

#endif