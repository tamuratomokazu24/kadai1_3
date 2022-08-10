#pragma once

#ifndef ScoreData_h
#define ScoreData_h

#include <string>

/**
* @struct	ScoreData
* @brief	プレイヤーのスコアと名前を格納する構造体
*/
struct ScoreData {

	std::string score;
	std::string name;

	/**
	* score,nameを空文字列で初期化するコンストラクタ
	*/
	ScoreData();

	/**
	* score,nameを引数で初期化するコンストラクタ
	*
	* @param[in] score プレイヤーの得点
	* @param[in] name プレイヤーの名前
	*/
	ScoreData(std::string score, std::string name);

	/**
	* ２つのScoreDataが持つ(score,name)が等しいか判定
	*
	* @return bool	true:lhsとrhsのスコアと名前がそれぞれ等しい\n
	*				false:lhsとrhsのスコアと名前のいずれかが異なる\n
	*/
	bool operator==(const ScoreData& rhs) const;

	/**
	* ２つのScoreDataが持つ(score,name)が異なるか判定
	*
	* @return bool	true:lhsとrhsのスコアと名前のいずれかが異なる\n
	*				false:lhsとrhsのスコアと名前がそれぞれ等しい\n
	*/
	bool operator!=(const ScoreData& rhs) const;
};

#endif