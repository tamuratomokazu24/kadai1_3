#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

#include "DoublyLinkedList.h"
#include "ScoreData.h"

int main() {
	std::string fileName = "Scores.txt";
	std::ifstream fileInput(fileName);

	DoublyLinkedList<ScoreData> list;
	DoublyLinkedList<ScoreData>::Iterator itInsert = list.begin();

	while (!fileInput.eof()) {

		ScoreData scoreData;
		fileInput >> scoreData.score >> scoreData.name;
		list.insert(itInsert, scoreData);
	}

	for (auto i = list.begin(); i != list.end(); i++) {
		std::cout << (*i).score << "," << (*i).name << std::endl;
	}

	return 0;
}