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
    } // tests whether Region Salary objects are created properly

    bool RegionSalary_Object_Test_Failed() {
        NS_REGION::RegionSalary test = NS_REGION::RegionSalary();
        test.setRegion("California");
        test.setSchool("Stanford University");
        test.setStartSalary(50000);
        test.setMidSalary(100000);
        test.setPercentSalaryChange(50000, 100000);
        if (test.getRegion() == "California" && test.getSchool() == "Stanford" && test.getStartSalary() == 500 && test.getMidSalary() == 1000 && test.getPercentSalaryChange() == 50.67) {
            std::cout << "Passed Region Object Test" << std::endl;
            return true;
        }
        else {
            std::cout << "TEST ERROR" << std::endl;
            return false;
        }
    } // tests whether Region Salary objects are created properly


    bool RegionSalary_Average_Test() {
        std::vector<NS_REGION::RegionSalary> data = NS_REGION::extractRegionData();
        NS_REGION::RegionSalary test = averageForGivenRegion("California", data);
        if (test.getSchool() == "average of schools in the region" && test.getRegion() == "California" && test.getMidSalary() == 93132.142857142855064 && test.getStartSalary() == 51032.142857142855064 && test.getPercentSalaryChange() == 45.204586417149208444) {
            std::cout << "Passed Region Average Test" << std::endl;
            return true;
        }
        else {
            std::cout << "TEST ERROR" << std::endl;
            return false;
        }
    } // tests averageForGivenRegion function
    bool RegionSalary_Average_Test_Fail() {
        std::vector<NS_REGION::RegionSalary> data = NS_REGION::extractRegionData();
        NS_REGION::RegionSalary test = averageForGivenRegion("California", data);
        if (test.getSchool() != "average of schools in the region" && test.getRegion() != "Northeastern" && test.getMidSalary() != 90132.142857142855064 && test.getStartSalary() != 54032.142857142855064 && test.getPercentSalaryChange() != 49.204586417149208444) {
            std::cer << "TEST FAILED!" << std::endl;
            return true;
        }
        else {
            std::cout << "TEST PASSED!" << std::endl;
            return false;
        }
    } // tests averageForGivenRegion function

    bool RegionSalary_BestSchool_Test() {
        std::vector<NS_REGION::RegionSalary> data = NS_REGION::extractRegionData();
        NS_REGION::RegionSalary test = bestSchoolInRegion("California", data);
        if (test.getRegion() == "California" && test.getSchool() == "Pomona College" && test.getMidSalary() == 101000 && test.getStartSalary() == 48600 && test.getPercentSalaryChange() == 51.881188118811884635) {
            std::cout << "Passed Region BestSchool Test" << std::endl;
            return true;
        }
        else {
            std::cout << "TEST ERROR" << std::endl;
            return false;
        }
    } // tests bestSchoolInRegion function

    bool RegionSalary_BestSchool_Test_Fail() {
        std::vector<NS_REGION::RegionSalary> data = NS_REGION::extractRegionData();
        NS_REGION::RegionSalary test = bestSchoolInRegion("California", data);
        if (test.getRegion() == "California" && test.getSchool() == "SFSU" && test.getMidSalary() == 1012312 && test.getStartSalary() == 48234234 && test.getPercentSalaryChange() == 51.88213123) {
            std::cout << "best school fail test passed" << std::endl;
            return false;
        }
        else {
            std::cerr << "Passed Region BestSchool Test" << std::endl;
            return true;
        }
    } // tests bestSchoolInRegion function

    bool RegionSalary_FileRead_Test() {
        std::vector<NS_REGION::RegionSalary> test = NS_REGION::extractRegionData();
        if (test.empty()) {
            std::cerr << "TEST ERROR" << std::endl;
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
    } // tests setPercentChange function

    bool RegionSalary_PercentChange_Test_Fail() {
        NS_REGION::RegionSalary test = NS_REGION::RegionSalary();
        test.setPercentSalaryChange(50000, 100000);
        if (test.getPercentSalaryChange() == 51) {
            std::cerr << "TEST FAILED" << std::endl;
            return true;
        }
        else {
            std::cout << "TEST PASSED" << std::endl;
            return false;
        }
    } // tests setPercentChange function


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

    bool Degree_Object_Test_Fail() {
        NS_Degree::Degree test = NS_Degree::Degree();
        test.setType("Engineering");
        test.setStartingSalary(50000);
        test.setMidCareerSalary(100000);
        test.setPercentChange(50);
        if (test.getType() == "Engineering" && test.getStartingSalary() == 500 && test.getMidCareerSalary() == 100 && test.getPercentChange() == 50) {
            std::cerr << "TEST FAILED:" << std::endl;
            return false;
        }
        else {
            std::cout << "TEST PASSED!" << std::endl;
            return true;
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
        if (output == 66660) {
            std::cout << "Passed Degree Average Test" << std::endl;
            return true;
        }
        else {
            std::cout << "TEST ERROR" << std::endl;
            return false;
        }
    } // tests getDegreeAverage function

    bool Degree_Formatter_Test() {
        std::string test = NS_Degree::degreeNumFormatter(50000);
        if (test == "$50,000.000000") {
            std::cout << "Passed Degree Formatter Test" << std::endl;
            return true;
        }
        else {
            std::cout << test << std::endl;
            return false;
        }
    } // tests degreeNumFormatter function

    bool Degree_Exists_Test() {
        NS_Degree::Degree test = NS_Degree::Degree();
        test.setType("Ceramics");
        std::vector<NS_Degree::Degree> data = NS_Degree::degreeFileReader();
        std::string output = NS_Degree::degreeExists(data, test);
        if (output == "degree does not exist") {
            std::cout << "Passed Degree Exists Test" << std::endl;
            return true;
        }
        else {
            std::cout << "TEST ERROR" << std::endl;
            return false;
        }
    } //tests degreeExists function
 

}

#endif
