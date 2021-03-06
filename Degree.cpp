#include "Degree.h"
#include <list>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


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

	std::vector<Degree> degreeFileReader() { //reads a csv file, create Degree objects for each line, stores them in a list and then returns the list 
		std::vector<Degree> inputList;
		std::ifstream inFS;
		std::istringstream inSS;
		std::string lineRead;
		std::string lineParse;
		std::string temp;
		std::string fileName = "degrees-that-pay-back.csv";


		Degree currDegree;

		inFS.open(fileName);


		if (!(inFS.is_open())) {
			std::cerr << "cannot open file" << std::endl;
		}
		else {

			getline(inFS, lineRead);

			getline(inFS, lineRead); // getline is called twice to throwaway the first line (which is useless)

			while (!(inFS.fail())) {
				inSS.clear();
				inSS.str(lineRead);

				while (!(inSS.eof())) {
					getline(inSS, lineParse, ',');
					currDegree.setType(lineParse);

					getline(inSS, lineParse, ',');
					lineParse.erase(0, 2); // erases the first 2 characters which happen to be a / and $ 
					temp = lineParse; // since the delimiter is a comma, the first parse just gives 2 digits (ten thousands and thousands place)
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

					break; //stops the reader from reading the rest of the line
				}
				getline(inFS, lineRead);


				//	inputList = degreeListTrim(inputList);
				degreeListSort(inputList, 0, inputList.size() - 1);

			}
			inFS.close();
			return inputList;
		}
	}

	std::vector<Degree> degreeListTrim(std::vector<Degree> untrimmedList, double setLimit) { //trim the list of Degree objects with any startingSalary < 40k
		std::vector <Degree> trimmedList;
		for (auto& i : untrimmedList) {

			if (i.getStartingSalary() > setLimit)
			{
				trimmedList.push_back(i);
			}

		}
		degreeListSort(trimmedList, 0, trimmedList.size() - 1);
		return trimmedList;
	}


	void swapTwo(Degree* a, Degree* b) {

		Degree x = *a;
		*a = *b;
		*b = x;


	}


	void degreeListSort(std::vector<Degree> &theList, int low, int high) { //sort the list by percentChange
		std::vector<Degree> listOne = theList;

		if (low < high)

		{

			int k = partitionTwo(theList, low, high);

			degreeListSort(theList, low, k - 1);

			degreeListSort(theList, k + 1, high);

		}

		
	}

	int partitionTwo(std::vector<Degree>& theList, int low, int high)
	{
		double pivot = theList.at(high).getPercentChange();

		int i = low - 1;

		for (int j = low; j <= high - 1; j++) {

			if (theList.at(j).getPercentChange() < pivot) {

				i++;
				swapTwo(&theList.at(i), &theList.at(j));

			}



		}
		swapTwo(&theList.at(i + 1), &theList.at(high));



		return (i + 1);;
	}

	double getDegreeAverage(std::vector<Degree> degreeList, int numToAvg) {
		double average;
		double sum = 0;

		if (numToAvg > 25) {
			numToAvg = 25;
		}

		else if (numToAvg > degreeList.size()) {
			numToAvg = degreeList.size();
		}


		for (unsigned int i = 0; i < numToAvg; i++) {
			sum += degreeList.at(i).getMidCareerSalary();
		}

		average = sum / numToAvg;

		return average;
	}

	std::string degreeNumFormatter(double degreeVar) {
		std::string formattedNum;

		formattedNum = "$" + std::to_string(degreeVar);
		formattedNum.insert(3, ",");

		return formattedNum;
	}
	std::string degreeExists(std::vector<Degree> haystack, Degree needle) {

		for (int i = 0; i <= haystack.size(); i++) {

			if (haystack.at(i).getType() == needle.getType())
			{
				return "degree exists!";
			}
			else {
				return "degree does not exist";
			}

		}

	}
}
