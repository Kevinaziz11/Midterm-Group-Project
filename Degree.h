
#ifndef Degree_h
#define Degree_h

#include<string>
#include<vector>

namespace NS_Degree {

	class Degree {

	public:
		Degree();

		Degree(std::string type, double startingSalary, double midCareerSalary, double percentChange);

		//accessors
		std::string getType() const;
		double getStartingSalary() const;
		double getMidCareerSalary() const;
		double getPercentChange() const;

		//mutators
		void setType(std::string incType);
		void setStartingSalary(double incStartingSalary);
		void setMidCareerSalary(double incMidCareerSalary);
		void setPercentChange(double incPercentChange);

	private:
		std::string degreeType = "N/A";
		double startingSalary = 0.0;
		double midCareerSalary = 0.0;
		double percentChange = 0.0;
	};

	std::vector<Degree> degreeFileReader(); //read from a csv file, create Degree objects for each line, stores them in a list and then returns the list 
	std::vector<Degree> degreeListTrim(std::vector<Degree> untrimmedList, double setLimit); //trim the list of Degree objects with any startingSalary < 40k
	std::vector<Degree> degreeListSort(std::vector<Degree> unsortedList); //sort the list by percentChange
	double getDegreeAverage(std::vector<Degree> degreeList, int numToAvg);
	std::string degreeNumFormatter(double degreeVar);

}


#endif
