#pragma once

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

/** 
* @class	DoubLuLinkedList
* @brief	テンプレートクラスTを値に持つ双方向リスト
* @tparam	T 双方向リストに格納する値の型
*/
template<class T>
class DoublyLinkedList {

private:

	/**
	* @struct	Node
	* @brief	双方向リストの値を保持する内部構造体
	*/
	struct Node {

		Node* preNode;	/** １つ前方のNodeを指すポインタ */
		Node* nextNode; /** １つ後方のNodeを指すポインタ */
		T value;		/** リストに格納する値 */

		/**
		* 前後のノードを指定してNodeを作成するコンストラクタ
		*
		* @param[in] preNode	１つ前方のNodeを指すポインタ
		* @param[in] nextNode	１つ後方のNodeを指すポインタ
		*/
		Node(Node* preNode, Node* nextNode);

		/**
		* 前後のノードと格納する値を指定してNodeを作成するコンストラクタ
		*
		* @param[in] preNode	１つ前方のNodeを指すポインタ
		* @param[in] nextNode	１つ後方のNodeを指すポインタ
		* @param[in] value		ノードが持つ値
		*/
		Node(Node* preNode, Node* nextNode, const T& value);
	};

public:

	/**
	* @class	ConstIterator
	* @brief	双方向リストのノードを指すインナークラス\n
	*			ノードが持つ値を変更することはできない\n
	*/
	class ConstIterator {
	protected:

		friend bool DoublyLinkedList<T>::insert(ConstIterator cIterator, const T& value);	//insert()でノードを追加する際，_ptrへのアクセスが必要なため
		friend bool DoublyLinkedList<T>::remove(ConstIterator cIterator);					//remove()でノードを削除する際，_ptrへのアクセスが必要なため

		const DoublyLinkedList<T>* _referenceToList;	/** リストへの参照 */
		Node* _ptr;										/** イテレータが内部的に保持するNode* */

	public:

		/**
		* ConstIteratorを１つ前方に戻す(前置デクリメント)
		*/
		ConstIterator& operator--();

		/**
		* ConstIteratorを１つ前方に戻す(後置デクリメント)
		*/
		ConstIterator operator--(int);

		/**
		* ConstIteratorを１つ後方に進める(前置インクリメント)
		*/
		ConstIterator& operator++();

		/**
		* ConstIteratorを１つ後方に進める(後置インクリメント)
		*/
		ConstIterator operator++(int);

		/**
		* ConstIteratorがもつ値を参照する
		*/
		const T& operator*() const;

		/**
		* デフォルトコンストラクタ
		*/
		ConstIterator() :_referenceToList(nullptr), _ptr(nullptr) {}
		
		/**
		* コピーコンストラクタ
		*/
		ConstIterator(const ConstIterator& constIterator) :_referenceToList(constIterator._referenceToList), _ptr(constIterator._ptr) {}

		/**
		* 参照するリストとNode*からコンストイテレータを作成するコンストラクタ
		*/
		ConstIterator(const DoublyLinkedList<T>* list, Node* node) :_referenceToList(list), _ptr(node) {}

		/**
		* ConstIteratorの代入
		*/
		ConstIterator& operator=(const ConstIterator& rhs);

		/**
		* ２つのConstIteratorが等しいか判定
		*
		* @return bool	true:lhsとrhsが等しい\n
		*				false:lhsとrhsが異なる\n
		*/
		bool operator==(const ConstIterator& rhs) const;

		/**
		* ２つのConstIteratorが異なるか判定
		*
		* @return bool	true:lhsとrhsが異なる\n
		*				false:lhsとrhsが等しい\n
		*/
		bool operator!=(const ConstIterator& rhs) const;

	};

	/**
	* @class	ConstIterator
	* @brief	双方向リストのノードを指すインナークラス\n
	*			ノードが持つ値を変更することができる\n
	*			親クラス：ConstIterator
	*/
	class Iterator :public ConstIterator {
	public:

		/**
		* Iteratorがもつ値を参照する
		*/
		T& operator*();

		/**
		* デフォルトコンストラクタ
		*/
		Iterator() :ConstIterator() {}

		/**
		* コピーコンストラクタ
		*/
		Iterator(const Iterator& iterator) :ConstIterator(iterator) {}

		/**
		* 参照するリストとNode*からイテレータを作成するコンストラクタ
		*/
		Iterator(DoublyLinkedList<T>* list, Node* node) :ConstIterator(list, node) {}
	};

private:

	Node* _dummyFirstNode;	/** 先頭のダミーノードを指すポインタ */
	Node* _dummyLastNode;	/** 末尾のダミーノードを指すポインタ */

	int _size;				/** ダミーノードを除くノードの個数 */

public:

	/**
	* 先頭と末尾のダミーノードを作成するコンストラクタ
	*/
	DoublyLinkedList();

	/**
	* デストラクタ
	*/
	~DoublyLinkedList();

	/**
	* @fn		size()	const
	* @return	int		ダミーノードを除くノードの個数
	*/
	int size() const;

	/**
	* @fn			insert(ConstIterator,const T&)
	* @brief		指定したコンストイテレータの１つ前方にデータを挿入する
	* @param[in]	cIterator	挿入する場所を指すコンストイテレータ
	* @param[in]	value		挿入する値
	* @return bool	true:正常にデータを挿入することができた\n
	*				false:データの挿入に失敗した\n
	*/
	bool insert(ConstIterator cIterator, const T& value);

	/**
	* @fn			insert(ConstIterator,const T&)
	* @brief		指定したコンストイテレータが指すデータを削除する
	* @param[in]	cIterator	削除するデータを指すコンストイテレータ
	* @return bool	true:正常にデータを削除することができた\n
	*				false:データの削除に失敗した\n
	*/
	bool remove(ConstIterator cIterator);

	/**
	* @fn		cbegin() const
	* @brief	リストの先頭を指すコンストイテレータを返す
	* @return	ConstIterator	リストが空の場合は末尾ダミーを指すコンストイテレータ\n
	*							リストに要素がある場合は先頭要素を指すコンストイテレータ\n
	*/
	ConstIterator cbegin() const;

	/**
	* @fn		cbegin() const
	* @brief	リストの末尾ダミーを指すコンストイテレータを返す
	* @return	ConstIterator	リストの末尾ダミーを指すコンストイテレータ\n
	*/
	ConstIterator cend() const;
	/**
	* @fn		begin()
	* @brief	リストの先頭を指すイテレータを返す
	* @return	Iterator	リストが空の場合は末尾ダミーを指すイテレータ\n
	*						リストに要素がある場合は先頭要素を指すイテレータ\n
	*/

	Iterator begin();

	/**
	* @fn		cend()
	* @brief	リストの末尾ダミーを指すイテレータを返す
	* @return	Iterator	リストの末尾ダミーを指すイテレータ\n
	*/
	Iterator end();

};

#include "DoublyLinkedList.inl"

#endif