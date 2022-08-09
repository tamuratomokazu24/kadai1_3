#pragma once

#ifndef ScoreData_h
#define ScoreData_h

#include <string>

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
	* @return bool (this->score == rhs.score && this->name == rhs.name)
	*/
	bool operator==(const ScoreData& rhs) const;

	/**
	* ２つのScoreDataが持つ(score,name)が異なるか判定
	*
	* @return bool (this->score != rhs.score || this->name != rhs.name)
	*/
	bool operator!=(const ScoreData& rhs) const;
};

#endif