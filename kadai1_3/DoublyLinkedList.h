#pragma once

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

template<class T>
class DoublyLinkedList {

private:

	struct Node {

		Node* preNode; /** １つ前方のNodeを指すポインタ */
		Node* nextNode; /** １つ後方のNodeを指すポインタ */
		T value; /** リストに格納する値 */

		/**
		* 前後のノードを指定してNodeを作成するコンストラクタ
		*
		* @param[in] preNode １つ前方のNodeを指すポインタ
		* @param[in] nextNode １つ後方のNodeを指すポインタ
		*/
		Node(Node* preNode, Node* nextNode);

		/**
		* 前後のノードと格納する値を指定してNodeを作成するコンストラクタ
		*
		* @param[in] preNode １つ前方のNodeを指すポインタ
		* @param[in] nextNode １つ後方のNodeを指すポインタ
		* @param[in] value ノードが持つ値
		*/
		Node(Node* preNode, Node* nextNode, const T& value);
	};

public:
	class ConstIterator {
	protected:

		const DoublyLinkedList<T>* _referenceToList;	/** リストへの参照 */
		Node* _ptr;	/** イテレータが内部的に保持するNode* */

	public:

		/**
		* リストへの参照を返す関数
		*/
		const DoublyLinkedList<T>* getReferenceToList() {
			return _referenceToList;
		}

		/**
		* ノードへの参照を返す関数
		*/
		Node* getPtr() {
			return _ptr;
		}

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
		ConstIterator() {}
		
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
						false:lhsとrhsが異なる\n
		*/
		bool operator==(const ConstIterator& rhs) const;

		/**
		* ２つのConstIteratorが異なるか判定
		*
		* @return bool	true:lhsとrhsが異なる\n
						false:lhsとrhsが等しい\n
		*/
		bool operator!=(const ConstIterator& rhs) const;

	};

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

	int _size; /** ダミーノードを除くノードの個数 */

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
	* @return int ダミーノードを除くノードの個数
	*/
	int size() const;

	/**
	* 指定したコンストイテレータの１つ前方にデータを挿入する
	*
	* @param[in] cIterator 挿入する場所を指すコンストイテレータ
	* @param[in] value 挿入する値
	*
	* @return bool	true:正常にデータを挿入することができた\n
	*				false:データの挿入に失敗した\n
	*/
	bool insert(ConstIterator cIterator, const T& value);

	/**
	* 指定したコンストイテレータが指すデータを削除する
	*
	* @param[in] cIterator 削除するデータを指すコンストイテレータ
	* @return bool	true:正常にデータを削除することができた\n
	*				false:データの削除に失敗した\n
	*/
	bool remove(ConstIterator cIterator);

	/**
	* リストの先頭を指すコンストイテレータを返す
	*
	* @return ConstIterator	リストが空の場合は先頭のダミーを指すコンストイテレータ\n
	*						リストに要素がある場合は先頭要素を指すコンストイテレータ\n
	*/
	ConstIterator cbegin() const;

	/**
	* リストの末尾を指すコンストイテレータを返す
	*
	* @return ConstIterator	リストが空の場合は末尾のダミーを指すコンストイテレータ\n
	*						リストに要素がある場合は末尾要素を指すコンストイテレータ\n
	*/
	ConstIterator cend() const;

	/**
	* リストを逆順に見る際の先頭を指すコンストイテレータを返す
	*
	* @return ConstIterator	リストが空の場合はリスト逆順の先頭のダミーを指すコンストイテレータ\n
	*						リストに要素がある場合はリスト逆順の先頭要素を指すコンストイテレータ\n
	*/
	ConstIterator rcbegin() const;

	/**
	* リストを逆順に見る際の末尾を指すコンストイテレータを返す
	*
	* @return ConstIterator	リストが空の場合はリスト逆順の末尾のダミーを指すコンストイテレータ\n
	*						リストに要素がある場合はリスト逆順の末尾要素を指すコンストイテレータ\n
	*/
	ConstIterator rcend() const;

	/**
	* リストの先頭を指すイテレータを返す
	*
	* @return Iterator	リストが空の場合は先頭のダミーを指すイテレータ\n
	*					リストに要素がある場合は先頭要素を指すイテレータ\n
	*/
	Iterator begin();

	/**
	* リストの末尾を指すイテレータを返す
	*
	* @return Iterator	リストが空の場合は末尾のダミーを指すイテレータ\n
	*					リストに要素がある場合は末尾要素を指すイテレータ\n
	*/
	Iterator end();

	/**
	* リストを逆順に見る際の先頭を指すイテレータを返す
	*
	* @return Iterator	リストが空の場合はリスト逆順の先頭のダミーを指すイテレータ\n
	*					リストに要素がある場合はリスト逆順の先頭要素を指すイテレータ\n
	*/
	Iterator rbegin();

	/**
	* リストを逆順に見る際の末尾を指すイテレータを返す
	*
	* @return Iterator	リストが空の場合はリスト逆順の末尾のダミーを指すイテレータ\n
	*					リストに要素がある場合はリスト逆順の末尾要素を指すイテレータ\n
	*/
	Iterator rend();

};

#include "DoublyLinkedList.inl"

#endif