#pragma once
#ifndef unitTests_h
#define unitTests_h

#include "Region.h"
#include "Degree.h"

namespace NS_UTESTS {

    bool RegionSalary_Object_Test() {
        NS_REGION::RegionSalary test = NS_REGION::RegionSalary();
        test.setRegion("California");
        test.setSchool("Stanford University");
        test.setStartSalary(50000);
        test.setMidSalary(100000);
        test.setPercentSalaryChange(50000, 100000);
        if (test.getRegion() == "California" && test.getSchool() == "Stanford University" && test.getStartSalary() == 50000 && test.getMidSalary() == 100000 && test.getPercentSalaryChange() == 50) {
            std::cout << "Passed Region Object Test" << std::endl;
            return true;
        }
        else {
            std::cout << "TEST ERROR" << std::endl;
            return false;
        }
    } //tests whether Region Salary objects are created properly

    bool RegionSalary_FileRead_Test() {
        NS_REGION::RegionSalary test = NS_REGION::RegionSalary();
        std::vector<NS_REGION::RegionSalary> data = test.extractRegionData();
        if (data.empty()) {
            std::cout << "TEST ERROR" << std::endl;
            return false;
        }
        else {
            std::cout << "Passes Region FileRead Test" << std::endl;
            return true;
        }
    } // tests extractRegionData function

    bool RegionSalary_PercentChange_Test() {
        NS_REGION::RegionSalary test = NS_REGION::RegionSalary();
        test.setPercentSalaryChange(50000, 100000);
        if (test.getPercentSalaryChange() == 50) {
            std::cout << "Passed Region PercentChange Test" << std::endl;
            return true;
        }
        else {
            std::cout << "TEST ERROR" << std::endl;
            return false;
        }
    } //tests setPercentChange function

    bool Degree_Object_Test() {
        NS_Degree::Degree test = NS_Degree::Degree();
        test.setType("Engineering");
        test.setStartingSalary(50000);
        test.setMidCareerSalary(100000);
        test.setPercentChange(50);
        if (test.getType() == "Engineering" && test.getStartingSalary() == 50000 && test.getMidCareerSalary() == 100000 && test.getPercentChange() == 50) {
            std::cout << "Passed Degree Object Test" << std::endl;
            return true;
        }
        else {
            std::cout << "TEST ERROR" << std::endl;
            return false;
        }

    } // tests whether Degree objects are created properly
    
    bool Degree_FileRead_Test() {
        std::vector<NS_Degree::Degree> test = NS_Degree::degreeFileReader();
        if (test.empty()) {
            std::cout << "TEST ERROR" << std::endl;
            return false;
        }
        else {
            std::cout << "Passes Degree FileRead Test" << std::endl;
            return true;
        }
    } // tests degreeFileReader function
    
    bool Degree_Average_Test() {
        std::vector<NS_Degree::Degree> test = NS_Degree::degreeFileReader();
        double output = NS_Degree::getDegreeAverage(test, 25);
        if (output == 86976) {
            std::cout << "Passed Degree Average Test" << std::endl;
            return true;
        }
        else {
            std::cout << "TEST ERROR" << std::endl;
            return false;
        }
    } //tests getDegreeAverage function

}

#endif
