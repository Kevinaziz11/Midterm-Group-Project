#include "Region.h"



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
	RegionSalary averageForGivenRegion(std::string region, std::vector<RegionSalary> theList)
	{
		int count = 0;
		double startSal = 0.00;
		double midSal = 0.00;
		
		RegionSalary obj1 = RegionSalary();
		//loop through the list 
		for (int i = theList.size() - 1; i >= 0; i--)
		{
			//if the elements region is equal to the input region 
			if (theList.at(i).getRegion() == region) {
				//add the salaries and increment the count
				startSal = startSal + theList.at(i).getStartSalary();
				midSal = midSal + theList.at(i).getMidSalary();
				
				count = count + 1;
			}

		}
		//divide the sum of salaries by the count to obtain average
		startSal = startSal / count;
		midSal = midSal / count;
		
		//set the objects elements to these averages
		obj1.setSchool("average of schools in the region");
		obj1.setRegion(region);
		obj1.setMidSalary(midSal);
		obj1.setStartSalary(startSal);
		obj1.setPercentSalaryChange(startSal,midSal);
		return obj1;
	}

	RegionSalary bestSchoolInRegion(std::string region, std::vector<RegionSalary> theList) {

		std::vector<RegionSalary> schoolList = theList;

		RegionSalary regSal = RegionSalary();

		for (int i = schoolList.size() - 1; i >=0; i--)
		{

			if (schoolList.at(i).getRegion() == region) {

				//if (regSal.getPercentSalaryChange() < schoolList.at(i).getPercentSalaryChange()) {

					regSal = schoolList.at(i);
					return regSal;
				//}

			}
		}
		return regSal;
	}



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

	const double RegionSalary::getPercentSalaryChange() {

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
	std::vector<RegionSalary> extractRegionData() {
		std::ifstream inputFile;

		inputFile.open("salaries-by-region.csv");

		std::string line = "";
		std::vector<RegionSalary> listOfRegSals = {};
		//skip first line
		std::getline(inputFile, line);
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
			//all cash values are in the thousands and seperated by a comma, we need to include both parts 
			//so we use two getlines in order to retrieve all of the information
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
		//TODO: close file DONE
		inputFile.close();
		//listOfRegSals = trimData(listOfRegSals);
		sortData(listOfRegSals,0,listOfRegSals.size()-1);
		return listOfRegSals;

	}

	//removes the entries in the vector that have a starting salary <40k
	std::vector<RegionSalary> trimData(std::vector<RegionSalary> theList, double setLimit)
	{
		std::vector<RegionSalary> objectList = theList;
		std::vector<RegionSalary> trimmedList = {};
		if (objectList.empty()) {

			std::cout << "it is empty" << std::endl;
			//return theList;
		}
		else {

			for (auto& i : theList) {

				if (i.getStartSalary() > setLimit) {

					trimmedList.push_back(i);

				}

			}


		}
		sortData(trimmedList, 0, trimmedList.size() - 1);
		return trimmedList;
	}




	//}
	//initial call sortData(list,0,list.size()-1);
	//quick sort is fastest sort algorithm O(n log n) in best case scenario
	//https://www.geeksforgeeks.org/quick-sort/
	void sortData(std::vector<RegionSalary> &theList, int low, int high) {

		std::vector<RegionSalary> listOne = theList;

		if (low < high)
			
		{
			
			int k = partition(theList, low, high);
			
			sortData(theList, low, k-1);
			
			sortData(theList, k + 1, high);
			
		}

		

	}  //sorts the vector from highest salary( index 0 ) to lowest

	void swap(RegionSalary* a, RegionSalary* b) {

		RegionSalary x = *a;
		*a = *b;
		*b = x;


	}
	//https://www.geeksforgeeks.org/quick-sort/
	int partition(std::vector<RegionSalary> &theList, int low, int high) {
		double pivot = theList.at(high).getPercentSalaryChange();
		
		int i = low - 1;
		
		for (int j = low; j <= high - 1; j++) {

			if (theList.at(j).getPercentSalaryChange() < pivot) {

				i++;
				swap(&theList.at(i), &theList.at(j));

			}



		}
		swap(&theList.at(i+1), &theList.at(high));
		


			return (i+1);

	}

}
