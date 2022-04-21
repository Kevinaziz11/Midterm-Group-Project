#pragma once

#ifndef Degree_h
#define Degree_h

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

	std::list<Degree> degreeFileReader(); //read from a csv file, create Degree objects for each line, stores them in a list and then returns the list 
	std::list<Degree> degreeListTrim(std::list<Degree> untrimmedList); //trim the list of Degree objects with any startingSalary < 40k
	void degreeListSort(std::list<Degree> unsortedList); //sort the list by percentChange

}


#endif