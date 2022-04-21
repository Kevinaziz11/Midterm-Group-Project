#include "Degree.h"
#include <list>
#include <string>

namespace NS_Degree {

	//std::string Degree::type = "N/A";
	//double Degree::startingSalary = 0.0;
	//double Degree::midCareerSalary = 0.0;
	//double Degree::percentChange = 0.0;
	
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

	std::list<Degree> degreeFileReader() { //read from a csv file, create Degree objects for each line, stores them in a list and then returns the list 

	}

	std::list<Degree> degreeListTrim(std::list<Degree> untrimmedList) { //trim the list of Degree objects with any startingSalary < 40k

	}

	void degreeListSort(std::list<Degree> unsortedList) { //sort the list by percentChange

	}

}