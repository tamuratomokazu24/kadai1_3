#pragma once

#ifndef ScoreData_h
#define ScoreData_h

#include <string>

struct ScoreData {

	std::string score;
	std::string name;

	/**
	* score,name���󕶎���ŏ���������R���X�g���N�^
	*/
	ScoreData();

	/**
	* score,name�������ŏ���������R���X�g���N�^
	*
	* @param[in] score �v���C���[�̓��_
	* @param[in] name �v���C���[�̖��O
	*/
	ScoreData(std::string score, std::string name);

	/**
	* �Q��ScoreData������(score,name)��������������
	*
	* @return bool (this->score == rhs.score && this->name == rhs.name)
	*/
	bool operator==(const ScoreData& rhs) const;

	/**
	* �Q��ScoreData������(score,name)���قȂ邩����
	*
	* @return bool (this->score != rhs.score || this->name != rhs.name)
	*/
	bool operator!=(const ScoreData& rhs) const;
};

#endif