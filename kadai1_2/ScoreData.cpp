#include "ScoreData.h"

ScoreData::ScoreData() {
	this->score = "";
	this->name = "";
}

ScoreData::ScoreData(std::string score, std::string name) {
	this->score = score;
	this->name = name;
}

bool ScoreData::operator==(const ScoreData& rhs) const {
	return (this->score == rhs.score && this->name == rhs.name);
}

bool ScoreData::operator!=(const ScoreData& rhs) const {
	return (this->score != rhs.score || this->name != rhs.name);
}