#include "Degree.h"

namespace NS_Degree {

	std::string Degree::type = "N/A";
	double Degree::startingSalary = 0.0;
	double Degree::midCareerSalary = 0.0;
	double Degree::percentChange = 0.0;


	Degree::Degree(std::string newType, double newStartingSalary, double newMidCareerSalary, double newPercentChange) {

		newType = type;
		newStartingSalary = startingSalary;
		newMidCareerSalary midCareerSalary;
		newPercentChange = percentChange;
	}

	std::string Degree::getType() const {
		return type;
	}
	double Degree::getStartingSalary() const {
		return startingSalary;
	}
	double getMidCareerSalary() const {
		return midCareerSalary;
	}
	double getPercentChange() const {
		return percentChange;
	}

	void Degree::setType(std::string incType) {
		type = incType;
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

	std::list NS_Degree::degreeFileReader() { //read from a csv file, create Degree objects for each line, stores them in a list and then returns the list 

	}

	std::list NS_Degree::degreeListTrim(std::list untrimmedList) { //trim the list of Degree objects with any startingSalary < 40k

	}

	void NS_Degree::degreeListSort(std::list unsortedList) { //sort the list by percentChange

	}

}