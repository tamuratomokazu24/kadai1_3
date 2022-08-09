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
		* 前後のノードとデータを指定してNodeを作成するコンストラクタ
		*
		* @param[in] preNode １つ前方のNodeを指すポインタ
		* @param[in] nextNode １つ後方のNodeを指すポインタ
		* @param[in] value ノードが持つ値
		*/
		Node(Node* preNode, Node* nextNode, const T& value);
	};

public:
	class ConstIterator {
	private:
		friend DoublyLinkedList;

		const DoublyLinkedList* referenceToList;	/** リストへの参照 */
		Node* _it; /** 内部的に保持するNode* */

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
		ConstIterator() {};

		/**
		* コピーコンストラクタ
		*/
		ConstIterator(const ConstIterator& constIterator) :referenceToList(constIterator.referenceToList), _it(constIterator._it) {}

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
	private:
		friend DoublyLinkedList;

	public:
		/**
		* Iteratorを１つ前方に戻す(前置デクリメント)
		*/
		Iterator& operator--();

		/**
		* Iteratorを１つ前方に戻す(後置デクリメント)
		*/
		Iterator operator--(int);

		/**
		* Iteratorを１つ後方に進める(前置インクリメント)
		*/
		Iterator& operator++();

		/**
		* Iteratorを１つ後方に進める(後置インクリメント)
		*/
		Iterator operator++(int);

		/**
		* Iteratorがもつ値を参照する
		*/
		T& operator*();

		/**
		* デフォルトコンストラクタ
		*/
		Iterator() {};

		/**
		* コピーコンストラクタ
		*/
		Iterator(const Iterator& iterator) :ConstIterator(iterator) {};

		/**
		* Iteratorの代入
		*/
		Iterator& operator=(Iterator& rhs);

		/**
		* ２つのIteratorが等しいか判定
		*
		* @return bool	true:lhsとrhsが等しい\n
						false:lhsとrhsが異なる\n
		*/
		bool operator==(const Iterator& rhs) const;

		/**
		* ２つのIteratorが異なるか判定
		*
		* @return bool	true:lhsとrhsが異なる\n
						false:lhsとrhsが等しい\n
		*/
		bool operator!=(const Iterator& rhs) const;
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
	* @return int ダミーノードを除くノードの個数
	*/
	int size() const;

	/**
	* 指定したイテレータの１つ前方にデータを挿入する
	*
	* @param[in] iterator 挿入する場所を指すイテレータ
	* @param[in] value 挿入する値
	*
	* @return bool	true:正常にデータを挿入することができた\n
	*				false:データの挿入に失敗した\n
	*/
	bool insert(Iterator iterator,const T& value);

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
	* データの削除し，削除したデータの１つ前方のデータにイテレータを戻す
	*
	* @param[in] iterator 削除するデータを指すイテレータ
	* @return bool	true:正常にデータを挿入することができた\n
	*				false:データの挿入に失敗した\n
	*/
	bool remove(Iterator iterator);

	/**
	* データの削除し，削除したデータの１つ前方のデータにコンストイテレータを戻す
	*
	* @param[in] cIterator 削除するデータを指すコンストイテレータ
	* @return bool	true:正常にデータを挿入することができた\n
	*				false:データの挿入に失敗した\n
	*/
	bool remove(ConstIterator cIterator);

	/**
	* リストの先頭を指すコンストイテレータを返す
	*
	* @return ConstIterator	リストが空の場合は先頭のダミーを指すコンストイテレータ\n
	*						リストに要素がある場合は先頭要素を指すコンストイテレータ\n
	*/
	ConstIterator getFirstConstIterator() const;

	/**
	* リストを逆順に見る際の先頭を指すコンストイテレータを返す
	*
	* @return ConstIterator	リストが空の場合はリスト逆順の先頭のダミーを指すコンストイテレータ\n
	*						リストに要素がある場合はリスト逆順の先頭要素を指すコンストイテレータ\n
	*/
	ConstIterator getReverseFirstConstIterator() const;

	/**
	* リストの末尾を指すコンストイテレータを返す
	*
	* @return ConstIterator	リストが空の場合は末尾のダミーを指すコンストイテレータ\n
	*						リストに要素がある場合は末尾要素を指すコンストイテレータ\n
	*/
	ConstIterator getLastConstIterator() const;

	/**
	* リストを逆順に見る際の末尾を指すコンストイテレータを返す
	*
	* @return ConstIterator	リストが空の場合はリスト逆順の末尾のダミーを指すコンストイテレータ\n
	*						リストに要素がある場合はリスト逆順の末尾要素を指すコンストイテレータ\n
	*/
	ConstIterator getReverseLastConstIterator() const;

	/**
	* リストの先頭を指すイテレータを返す
	*
	* @return Iterator	リストが空の場合は先頭のダミーを指すイテレータ\n
	*					リストに要素がある場合は先頭要素を指すイテレータ\n
	*/
	Iterator getFirstIterator();

	/**
	* リストを逆順に見る際の先頭を指すイテレータを返す
	*
	* @return ConstIterator	リストが空の場合はリスト逆順の先頭のダミーを指すイテレータ\n
	*						リストに要素がある場合はリスト逆順の先頭要素を指すイテレータ\n
	*/
	Iterator getReverseFirstIterator();

	/**
	* リストの末尾を指すイテレータを返す
	*
	* @return Iterator	リストが空の場合は末尾のダミーを指すイテレータ\n
	*					リストに要素がある場合は末尾要素を指すイテレータ\n
	*/
	Iterator getLastIterator();

	/**
	* リストを逆順に見る際の末尾を指すイテレータを返す
	*
	* @return ConstIterator	リストが空の場合はリスト逆順の末尾のダミーを指すイテレータ\n
	*						リストに要素がある場合はリスト逆順の末尾要素を指すイテレータ\n
	*/
	Iterator getReverseLastIterator();

};

#include "DoublyLinkedList.inl"

#endif