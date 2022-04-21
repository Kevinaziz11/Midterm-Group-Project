#include "Degree.h"
#include <list>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>

namespace NS_Degree {

	//std::string Degree::type = "N/A";
	//double Degree::startingSalary = 0.0;
	//double Degree::midCareerSalary = 0.0;
	//double Degree::percentChange = 0.0;

	Degree::Degree() : degreeType("N/A"), startingSalary(0.0), midCareerSalary(0.0), percentChange(0.0) {}

	Degree::Degree(std::string newType, double newStartingSalary, double newMidCareerSalary, double newPercentChange) {
		degreeType = newType;
		startingSalary = newStartingSalary;
		midCareerSalary = newMidCareerSalary;
		percentChange = newPercentChange;
	};

	std::string Degree::getType() const {
		return degreeType;
	}
	double Degree::getStartingSalary() const {
		return startingSalary;
	}
	double Degree::getMidCareerSalary() const {
		return midCareerSalary;
	}
	double Degree::getPercentChange() const {
		return percentChange;
	}
	void Degree::setType(std::string incType) {
		degreeType = incType;
	}
	void Degree::setStartingSalary(double incStartingSalary) {
		startingSalary = incStartingSalary;
	}
	void Degree::setMidCareerSalary(double incMidCareerSalary) {
		midCareerSalary = incMidCareerSalary;
	}
	void Degree::setPercentChange(double incPercentChange) {
		percentChange = incPercentChange;
	}

	std::list<Degree> degreeFileReader() { //reads a csv file, create Degree objects for each line, stores them in a list and then returns the list 
		std::list<Degree> inputList;
		std::ifstream inFS;
		std::istringstream inSS;
		std::string lineRead;
		std::string lineParse;
		std::string temp;
		std::string fileName = "degrees-that-pay-back.csv";

		Degree currDegree;

		inFS.open(fileName);

		/**
		if (!inFS.is_open()) {
			std::cout << "Could not open file " << fileName << std::endl;
			return 1; // 1 indicates error
		}
		**/
		getline(inFS, lineRead);

		getline(inFS, lineRead); // getline is called twice to throwaway the first line (which is useless)

		while (!inFS.fail()) {
			inSS.clear();
			inSS.str(lineRead);

			while (!inSS.eof()) {
				getline(inSS, lineParse, ',');
				currDegree.setType(lineParse);

				getline(inSS, lineParse, ',');
				lineParse.erase(0, 2); // erases the first 2 characters which happen to be a / and $ 
				temp = lineParse; // since the delimiter is a comma, the first parse just gives 2 digits (ten thousands and thaousands place)
				getline(inSS, lineParse, ','); // get the rest of the number
				lineParse = temp + lineParse; // add them back together (e.g "42" + "000.00" = "42000")
				currDegree.setStartingSalary(std::stod(lineParse));

				getline(inSS, lineParse, ',');
				lineParse.erase(0, 2);
				temp = lineParse;
				getline(inSS, lineParse, ',');
				lineParse = temp + lineParse;
				currDegree.setMidCareerSalary(std::stod(lineParse));

				getline(inSS, lineParse, ',');
				currDegree.setPercentChange(std::stod(lineParse));

				inputList.push_back(currDegree);

				break;
			}
			getline(inFS, lineRead);
		}
		return inputList;
	}

	std::list<Degree> degreeListTrim(std::list<Degree> untrimmedList) { //trim the list of Degree objects with any startingSalary < 40k
		std::list<Degree> inputList;

		return inputList;


	}

	void degreeListSort(std::list<Degree> unsortedList) { //sort the list by percentChange

	}

}