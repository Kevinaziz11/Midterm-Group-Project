#ifndef region_h
#define region_h

#include <iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<list>
#include<vector>
#include<algorithm>
//TODO: create a function that can average the (total of all schools in the region) start and mid salaries for a specified region
//TODO: create a function that can give the best school to go to in a specified region based on start and mid salaries as well as percentage change

namespace NS_REGION {

	class RegionSalary {


	public:


		RegionSalary();              //constructor

		RegionSalary(std::string theSchool, std::string theRegion, double theStartSalary, double theMidSalary, double thePercentSalaryChange);

		//RegionSalary(string school, string region, double startSalary, double midSalary, double percentSalaryChange, ); //constructor

		std::string getRegion();         //returns the region for the specified RegionSalary Object

		std::string getSchool();        //returns the school for the specified RegionSalary Object

		double getStartSalary();  //returns the starting salary for the specified RegionSalary Object

		double getMidSalary();   //returns the region for the specified RegionSalary Object

		const double getPercentSalaryChange();  //returns the percentage change from start salary to mid salary

		void setRegion(std::string theRegion);

		void setSchool(std::string theSchool);

		void setStartSalary(double theStartSal);

		void setMidSalary(double theMidSal);

		void setPercentSalaryChange(double theStartSal, double theMidSal);

		std::vector<RegionSalary> extractRegionData(); //extracts the information from the csv file

		std::vector<RegionSalary> trimData(std::vector<RegionSalary> theList); //removes the entries in the vector that have a starting salary <40k

		void sortData(std::vector<RegionSalary>& theList, int low, int high);  //sorts the vector from highest slary( index 0 ) to lowest

		int partition(std::vector<RegionSalary>& theList, int left, int right);//quick sort helper function

	private:
		std::string region;

		std::string school;

		double startSalary;

		double midSalary;

		double percentSalaryChange;




	};










}
#endif // region_h
