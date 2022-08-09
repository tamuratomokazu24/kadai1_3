#include "pch.h"
#include "../kadai1_2/DoublyLinkedList.h"

//=================================== データ数の取得 ===================================

//#define TT_TEST_GET_DATA_NUM_WHEN_CONST
/**
*	@brief		データ数の取得機能について、constのメソッドであるかのテスト
*	@details	ID:リスト-8(手動)\n
*				データ数の取得機能のテストです.\n
*				constのメソッドであるかを確認しています.\n
*				有効にしてコンパイルが通れば成功です.\n
*				TT_TEST_GET_DATA_NUM_WHEN_CONSTマクロを定義すると有効になります.\n
*/
TEST(GetDataNumManualTest, WhenListIsConst)
{
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
	const DoublyLinkedList list;
	EXPECT_EQ(0, list.size());
#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
	SUCCEED();
}

//=================================== データの挿入 ===================================

//#define TT_TEST_INSERT_WHEN_CONST
/**
*	@brief		リストへのデータ挿入について、非constが保障されているかのテスト
*	@details	ID:リスト-15(手動)\n
*				リスト先頭のダミー後方へのデータ追加テストです.\n
*				非constが保障されているかを確認しています.\n
*				有効にしてコンパイルエラーになれば成功です.\n
*				TT_TEST_INSERT_WHEN_CONSTマクロを定義すると有効になります.\n
*/
TEST(InsertDataManualTest, WhenInsertToConstList)
{
#if defined TT_TEST_INSERT_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.getFirstConstIterator();
	ScoreData scoredata("1", "test");
	list.insert(it, scoredata);//ここでエラー
#endif //TT_TEST_INSERT_WHEN_CONST
	SUCCEED();
}

//=================================== データの削除 ===================================

//#define TT_TEST_REMOVE_WHEN_CONST
/**
*	@brief		リストのデータ削除について、非constが保障されているかのテスト
*	@details	ID:リスト-22(手動)\n
*				リストのデータ削除テストです.\n
*				非constが保障されているかを確認しています.\n
*				有効にしてコンパイルエラーになれば成功です.\n
*				TT_TEST_REMOVE_WHEN_CONSTマクロを定義すると有効になります.\n
*/
TEST(RemoveDataManualTest, WhenRemoveFromConstList)
{
#if defined TT_TEST_REMOVE_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.getFirstConstIterator();
	list.remove(it);//ここでエラー

#endif //TT_TEST_REMOVE_WHEN_CONST
	SUCCEED();
}

//=================================== 先頭イテレータの取得 ===================================

//#define TT_TEST_GET_FIRST_ITERATOR_WHEN_CONST
/**
*	@brief		リスト先頭の非constイテレータの取得について、非constが保障されているかのテスト
*	@details	ID:リスト-28(手動)\n
*				リストの先頭イテレータ取得のテストです.\n
*				非constが保障されているかを確認しています.\n
*				有効にしてコンパイルエラーになれば成功です.\n
*				TT_TEST_GET_FIRST_ITERATOR_WHEN_CONSTマクロを定義すると有効になります.\n
*/
TEST(GetFistIteratorManualTest, WhenGetFirstIteratorFromConstList)
{
#if defined TT_TEST_GET_FIRST_ITERATOR_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.getFirstIterator();	//ここでエラー

#endif //TT_TEST_GET_FIRST_ITERATOR_WHEN_CONST
	SUCCEED();
}

//=================================== 先頭コンストイテレータの取得 ===================================

//#define TT_TEST_GET_FIRST_CONST_ITERATOR_WHEN_CONST
/**
*	@brief		リスト先頭のコンストイテレータの取得について、constのメソッドであるかのテスト
*	@details	ID:リスト-34(手動)\n
*				リストの先頭コンストイテレータ取得のテストです.\n
*				constのメソッドであるかを確認しています.\n
*				有効にしてコンパイルが通れば成功です.\n
*				TT_TEST_GET_FIRST_CONST_ITERATOR_WHEN_CONSTマクロを定義すると有効になります.\n
*/
TEST(GetFistConstIteratorManualTest, WhenGetFirstConstIteratorFromConstList)
{
#if defined TT_TEST_GET_FIRST_CONST_ITERATOR_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.getFirstConstIterator();

#endif //TT_TEST_GET_FIRST_CONST_ITERATOR_WHEN_CONST
	SUCCEED();
}

//=================================== 末尾イテレータの取得 ===================================

//#define TT_TEST_GET_LAST_ITERATOR_WHEN_CONST
/**
*	@brief		リスト末尾の非constイテレータの取得について、非constが保障されているかのテスト
*	@details	ID:リスト-40(手動)\n
*				リストの末尾イテレータ取得のテストです.\n
*				非constが保障されているかを確認しています.\n
*				有効にしてコンパイルエラーになれば成功です.\n
*				TT_TEST_GET_LAST_ITERATOR_WHEN_CONSTマクロを定義すると有効になります.\n
*/
TEST(GetLastIteratorManualTest, WhenGetLastIteratorFromConstList)
{
#if defined TT_TEST_GET_LAST_ITERATOR_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::Iterator it = list.getLastIterator();	//ここでエラー

#endif //TT_TEST_GET_LAST_ITERATOR_WHEN_CONST
	SUCCEED();
}

//=================================== 末尾コンストイテレータの取得 ===================================

//#define TT_TEST_GET_LAST_CONST_ITERATOR_WHEN_CONST
/**
*	@brief		リスト末尾のコンストイテレータの取得について、constのメソッドであるかのテスト
*	@details	ID:リスト-46(手動)\n
*				リストの末尾コンストイテレータ取得のテストです.\n
*				constのメソッドであるかを確認しています.\n
*				有効にしてコンパイルが通れば成功です.\n
*				TT_TEST_GET_LAST_CONST_ITERATOR_WHEN_CONSTマクロを定義すると有効になります.\n
*/
TEST(GetLastConstIteratorManualTest, WhenGetLastConstIteratorFromConstList)
{
#if defined TT_TEST_GET_LAST_CONST_ITERATOR_WHEN_CONST
	const DoublyLinkedList list;
	DoublyLinkedList::ConstIterator it = list.getLastConstIterator();

#endif //TT_TEST_GET_LAST_CONST_ITERATOR_WHEN_CONST
	SUCCEED();
}


//=================================== イテレータの指す要素の取得 ===================================

//#define TT_TEST_ASSIGN_TO_ELEMENT_OF_ITERATOR_WHEN_CONST
/**
*	@brief		コンストイテレータから取得した要素に対して，値の代入をした際のテスト
*	@details	ID:Iterator-2(手動)\n
*				イテレータの指す要素の取得機能のテストです.\n
*				コンストイテレータから取得した要素に対して，値の代入をした際の挙動を確認しています.\n
*				有効にしてコンパイルエラーになれば成功です.\n
*				TT_TEST_ASSIGN_TO_ELEMENT_OF_ITERATOR_WHEN_CONSTマクロを定義すると有効になります.\n
*/
TEST(GetElementOfIteratorManualTest, WhenAssignToElementOfConstIterator)
{
#if defined TT_TEST_ASSIGN_TO_ELEMENT_OF_ITERATOR_WHEN_CONST
	DoublyLinkedList list;
	ScoreData scoreData("1", "test1");

	DoublyLinkedList::ConstIterator it = list.getFirstConstIterator();

	ScoreData newScoreData("100", "newData");
	*it = newScoreData;	//ここでエラー

#endif //TT_TEST_ASSIGN_TO_ELEMENT_OF_ITERATOR_WHEN_CONST
	SUCCEED();
}

//=================================== イテレータのコピーを行う ===================================

//#define TT_TEST_COPY_TO_ITERATOR_FROM_CONST_ITERATOR
/**
*	@brief		コンストイテレータからイテレータへコピーを作成する際のテスト
*	@details	ID:Iterator-17(手動)\n
*				イテレータのコピー機能のテストです.\n
*				コンストイテレータからイテレータへコピーを作成する際の挙動を確認しています.\n
*				有効にしてコンパイルエラーになれば成功です.\n
*				TT_TEST_COPY_TO_ITERATOR_FROM_CONST_ITERATORマクロを定義すると有効になります.\n
*/
TEST(CopyIteratorTest, WhenCopyToIteratorFromConstIterator)
{
#if defined TT_TEST_COPY_TO_ITERATOR_FROM_CONST_ITERATOR
	DoublyLinkedList::ConstIterator cIt;
	DoublyLinkedList::Iterator it = cIt;	//ここでエラー

#endif //TT_TEST_COPY_TO_ITERATOR_FROM_CONST_ITERATOR
	SUCCEED();
}


//=================================== イテレータの代入を行う ===================================

//#define TT_TEST_ASSIGN_CONSTITERATOR_TO_ITERATOR
/**
*	@brief		イテレータへコンストイテレータを代入する際のテスト
*	@details	ID:Iterator-19(手動)\n
*				イテレータの代入機能のテストです.\n
*				イテレータへコンストイテレータを代入する際の挙動を確認しています.\n
*				有効にしてコンパイルエラーになれば成功です.\n
*				TT_TEST_ASSIGN_CONSTITERATOR_TO_ITERATORマクロを定義すると有効になります.\n
*/
TEST(AssignIteratorTest, WhenAssignConstIteratorToIterator)
{
#if defined TT_TEST_ASSIGN_CONSTITERATOR_TO_ITERATOR
	DoublyLinkedList::ConstIterator cIt;
	DoublyLinkedList::Iterator it;

	it = cIt;	//ここでエラー

#endif //TT_TEST_ASSIGN_CONSTITERATOR_TO_ITERATOR
	SUCCEED();
}

