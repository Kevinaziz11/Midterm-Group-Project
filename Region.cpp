#include "region1.h"



namespace NS_REGION {

	RegionSalary::RegionSalary() {

		region = "na";

		school = "na";

		startSalary = 0.00;
		midSalary = 0.00;
		percentSalaryChange = 0.00;


	} //constructor

	RegionSalary::RegionSalary(std::string theSchool, std::string theRegion, double theStartSalary, double theMidSalary, double thePercentSalaryChange) {

		region = theRegion;
		school = theSchool;
		startSalary = theStartSalary;
		midSalary = theMidSalary;
		percentSalaryChange = thePercentSalaryChange;


	} //constructor

	std::string RegionSalary::getRegion() {
		return region;
	} //returns the region for the specified RegionSalary Object

	std::string RegionSalary::getSchool() {
		return school;
	} //returns the school for the specified RegionSalary Object

	double RegionSalary::getStartSalary() {
		return startSalary;
	} //returns the starting salary for the specified RegionSalary Object

	double RegionSalary::getMidSalary() {
		return midSalary;
	} //returns the region for the specified RegionSalary Object

	double RegionSalary::getPercentSalaryChange() {

		return percentSalaryChange;

	}//returns the percentage change from start salary to mid salary

	void RegionSalary::setRegion(std::string theRegion) {
		region = theRegion;
	}

	void RegionSalary::setSchool(std::string theSchool) {
		school = theSchool;
	}

	void RegionSalary::setStartSalary(double theStartSal) {
		startSalary = theStartSal;
	}

	void RegionSalary::setMidSalary(double theMidSal) {
		midSalary = theMidSal;
	}

	void RegionSalary::setPercentSalaryChange(double theStartSal, double theMidSal) {

		double change = theMidSal - theStartSal;
		change = change / theMidSal;
		change = change * 100;

		NS_REGION::RegionSalary::percentSalaryChange = change;

	}

	//extracts the information from the csv file
	//source: https://www.youtube.com/watch?v=NFvxA-57LLA
	std::list<RegionSalary> RegionSalary::extractRegionData() {
		std::ifstream inputFile;

		inputFile.open("regionSalaries.csv");

		std::string line = "";
		std::list<RegionSalary> listOfRegSals = {};
		while (std::getline(inputFile, line))
		{
			std::string school = "";
			std::string region = "";
			double startSalary = 0.00;
			double midSalary = 0.00;
			std::string temp = "";
			std::string temp1 = "";
			std::string temp2 = "";
			

			std::stringstream inputString(line);
			//checking if the first character is a quotation mark
			if (line.at(0)=='\"') {
				//int firstComma = line.find_first_of(',');
				temp1 = "";
				temp2 = "";
				getline(inputString, temp1, ',');
				getline(inputString, temp2, ',');
				school = temp1 + "," + temp2;
				school.erase(remove(school.begin(), school.end(), '\"'), school.end());
				
			}else{
				getline(inputString, school, ','); 
			}
	
			

			getline(inputString, region, ',');
			temp1 = "";
			temp2 = "";
			getline(inputString, temp1, ',');
			getline(inputString, temp2, ',');
			temp = temp1 + "," + temp2;
			//remove first character from string '$'
			temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
			temp.erase(std::remove(temp.begin(), temp.end(), ','), temp.end());
			temp.erase(std::remove(temp.begin(), temp.end(), '$'), temp.end());
			


			//convert string to double
			startSalary = std::atof(temp.c_str());

			//same process as the lines above
			temp1 = "";
			temp2 = "";
			getline(inputString, temp1, ',');
			getline(inputString, temp2, ',');
			temp = temp1 + "," + temp2;
			temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
			temp.erase(std::remove(temp.begin(), temp.end(), ','), temp.end());
			temp.erase(std::remove(temp.begin(), temp.end(), '$'), temp.end());
			midSalary = std::atof(temp.c_str());

			//declare a new regionSalary object and push it to our list of objects
			RegionSalary regSal = RegionSalary();
			regSal.setSchool(school);
			regSal.setRegion(region);
			regSal.setStartSalary(startSalary);
			regSal.setMidSalary(midSalary);
			regSal.setPercentSalaryChange(startSalary, midSalary);

			listOfRegSals.push_back(regSal);
			line = "";
		}
		return listOfRegSals;

	}

	std::list<RegionSalary> trimData(std::list<RegionSalary> theList); //removes the entries in the vector that have a starting salary <40k

	std::list<RegionSalary> sortData(std::list<RegionSalary> theList) {



		return theList;

	}  //sorts the vector from highest salary( index 0 ) to lowest
}
