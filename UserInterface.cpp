#include "UserInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//the function that will be called by main in order to take in user input and perform the specified tasks.

void NS_USERINTERFACE::userInterface()
{
	NS_REGION::RegionSalary regionObject = NS_REGION::RegionSalary();
	NS_Degree::Degree degreeObject = NS_Degree::Degree();
	std::vector < NS_REGION::RegionSalary > x = NS_REGION::extractRegionData();
	std::vector < NS_Degree::Degree > y = NS_Degree::degreeFileReader();
	if (x.empty()||y.empty()) {

		std::cerr << "there was an error processing the data set(s)" << std::endl;
		std::cout << "---------------------------------------------------------" << std::endl;
	}
	else {

		//RegionSalary bestSchoolInRegion(std::string region, std::vector<RegionSalary> theList);
		//listOfRegSals = trimData(listOfRegSals, double setLimit);
		//std::vector<Degree> degreeListTrim(std::vector<Degree> untrimmedList, double setLimit)
		std::cout << "The data sets have been parsed and sorted." << std::endl;



		std::cout << std::endl;

		std::cout << "would you like to set a limit to the starting salary? Please type yes or no. " << std::endl;

		std::string limitDecision = "";
		//std::cin >> limitDecision;
		while (std::cin >> limitDecision) {
			std::for_each(limitDecision.begin(), limitDecision.end(), [](char& c) {
				c = ::tolower(c);
				});
			if (limitDecision == "yes" || limitDecision == "Yes" || limitDecision == "no" || limitDecision == "No") {
				break;

			}
			else {
				std::cerr << "Please enter a valid input option: " << std::endl;
				std::cout << std::setfill('-') << std::setw(85) << "" << std::endl;
				continue;
			}

		}

		if (limitDecision == "yes" || limitDecision == "Yes") {
			std::cout << "enter a cash value to limit the starting yearly salary: " << std::endl;
			double cashLimit = 0.00;
			

			/*if (cashLimit == 0.00) {
				std::cout << "Limit not set" << std::endl;
				std::cout << std::setfill('-') << std::setw(50) << "" << std::endl;

			}*/


			

			while(1){

			if(std::cin>>cashLimit){

				break;

			}else{

				std::cerr << "Please enter a valid input option: " << std::endl;
				std::cin.clear();
				while (std::cin.get() != '\n') ; // empty loop
			}

			}
	

		
			y = NS_Degree::degreeListTrim(y, cashLimit);
			x = NS_REGION::trimData(x, cashLimit);


		}
		else {

			NS_Degree::degreeListTrim(y, 0.00);
			NS_REGION::trimData(x, 0.00);



		}

		std::cout <<  std::endl << std::endl;
		std::cout << "Best school based on percentage salary increase: " << x.at(x.size() - 1).getSchool() << std::endl;
		std::cout << "the average starting salary is: " << x.at(x.size() - 1).getStartSalary() << std::endl;
		std::cout << "the average mid salary is: " << x.at(x.size() - 1).getMidSalary() << std::endl;
		std::cout << "the percentage change from start to mid salary is: " << x.at(x.size() - 1).getPercentSalaryChange() << std::endl;
		std::cout << std::setfill('-') << std::setw(85) << "" << std::endl;

		std::cout << std::endl;


		std::cout << "Best degree based on percentage salary:" << " " << y.at(y.size()-1).getType() << std::endl;
		std::cout << "Starting salary for this degree is: " << y.at(y.size()-1).getStartingSalary() << std::endl;
		std::cout << "Mid salary for this degre is: " << y.at(y.size()-1).getMidCareerSalary() << std::endl;
		std::cout << "the percentage change from start to mid salary is: " << y.at(y.size()-1).getPercentChange() << std::endl;
		std::cout << std::setfill('-') << std::setw(85) << "" << std::endl;
		std::cout << std::endl;
		//RegionSalary bestSchoolInRegion(std::string region, std::vector<RegionSalary> theList);
		std::cout << "If you would like to exit, type exit otherwise you can enter a region and find out what the most lucrative school is in that regions" << std::endl<<std::endl;
		std::cout << "List of regions to select from: California, Western, Midwestern, Southern, Northeastern" << std::endl<<std::endl;
		std::cout << std::endl;
		std::string input = "";
		//std::cin>>input;
		////California,Western,Midwestern,Southern,Northeastern, Exit
		while (std::cin >> input) {
			std::for_each(input.begin(), input.end(), [](char& c) {
				c = ::tolower(c);
				});
			input[0] = toupper(input[0]);
			
			if (input == "Exit" || input == "California" || input == "Western" || input=="Midwestern" || input == "Southern" || input == "Northeastern") {
				break;
			}
			else{

			std::cerr << "Please enter a valid input option: " << std::endl;
				std::cout << std::setfill('-') << std::setw(85) << "" << std::endl<<std::endl;
				continue;

			}
		}

		//https://www.cplusplus.com/reference/cctype/toupper/
		std::for_each(input.begin(), input.end(), [](char& c) {
			c = ::tolower(c);
			});
		input[0] = toupper(input[0]);
		//California,Western,Midwestern,Southern,Northeastern
			if(input == "exit"||input == "Exit"){

				exit(EXIT_FAILURE);
			}else{
			//x is name of region  list
			//y is name of degree list 
			//RegionSalary bestSchoolInRegion(std::string region, std::vector<RegionSalary> theList);

				if(input == "california" || input == "California" ){
					regionObject = NS_REGION::bestSchoolInRegion(input, x);
				


				}
				else if(input == "western" || input == "Western"){
					regionObject = NS_REGION::bestSchoolInRegion(input, x);

				}
				else if(input == "southern" || input == "Southern"){
					regionObject = NS_REGION::bestSchoolInRegion(input, x);

				}
				else if (input == "Midwestern" || input == "midwestern") {
					regionObject = NS_REGION::bestSchoolInRegion(input, x);

				}
				else if(input == "Northeastern" || input == "northeastern"){
					regionObject = NS_REGION::bestSchoolInRegion(input, x);

				} 
				std::cout<<std::endl;
				std::cout <<"the best school in the region is: " << regionObject.getSchool() << std::endl;
				std::cout <<"best school's average starting salary is: " <<regionObject.getStartSalary()<<std::endl;
			
			
				std::cout <<"best school's average mid salary is: "<< regionObject.getMidSalary() << std::endl;
				std::cout << "best school's percentage salary change is: " << regionObject.getPercentSalaryChange() << std::endl;
				std::cout << std::setfill('-') << std::setw(85) << "" << std::endl<<std::endl;
				

			}
			std::cout << "If you would like to exit, type exit otherwise you can enter a region and find out the average salaries and percentage salary change for all schools in the region" << std::endl<<std::endl;
			std::cout << "list of regions: California, Western, Midwestern, Southern, Northeastern" << std::endl<<std::endl;
			std::cout << std::endl;
			input = "";
			//std::cin >> input;
			while(std::cin>>input){
				std::for_each(input.begin(), input.end(), [](char& c) {
					c = ::tolower(c);
					});
				input[0] = toupper(input[0]);
				if(input == "Exit" || input == "California" || input == "Western" || input == "Midwestern" || input == "Southern" || input == "Northeastern") {

					break;

				}else{

					std::cerr << "Please enter a valid input option: " << std::endl;
					std::cout << std::setfill('-') << std::setw(85) << "" << std::endl;
					continue;

				}

			}

			//https://www.cplusplus.com/reference/cctype/toupper/
			std::for_each(input.begin(), input.end(), [](char& c) {
				c = ::tolower(c);
				});
			input[0] = toupper(input[0]);
			//California,Western,Midwestern,Southern,Northeastern
			if (input == "exit" || input == "Exit") {
				exit(EXIT_FAILURE);

			}
			else {
				//x is name of region  list
				//y is name of degree list 
				//RegionSalary bestSchoolInRegion(std::string region, std::vector<RegionSalary> theList);

				if (input == "california" || input == "California") {
					regionObject = NS_REGION::averageForGivenRegion(input, x);



				}
				else if (input == "western" || input == "Western") {
					regionObject = NS_REGION::averageForGivenRegion(input, x);

				}
				else if (input == "Midwestern" || input == "midwestern") {
					regionObject = NS_REGION::averageForGivenRegion(input, x);

				}
				else if (input == "southern" || input == "Southern") {
					regionObject = NS_REGION::averageForGivenRegion(input, x);

				}
				else if (input == "Northeastern" || input == "northeastern") {
					regionObject = NS_REGION::averageForGivenRegion(input, x);

				}

			}
			std::cout << std::endl;
					std::cout << std::setfill('-') << std::setw(85) << "" << std::endl;
					std::cout << std::endl;

			std::cout << "the average starting salary for all schools the region is: " << regionObject.getStartSalary() << std::endl;
			std::cout << "the average mid salary for all schools in the given region is: " << regionObject.getMidSalary() << std::endl;
			std::cout << "the average percentage salary increase for all schools in the given region is: " << regionObject.getPercentSalaryChange() << std::endl;
	}
}


