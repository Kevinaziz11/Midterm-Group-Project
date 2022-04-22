#ifndef unitTests_h
#define unitTests_h

#include "Region.h"
#include "Degree.h"

namespace NS_UTESTS {

	bool RegionSalary_Object_Test(); //tests whether Region Salary objects are created properly

	bool RegionSalary_FileRead_Test(); // tests extractRegionData function

	bool RegionSalary_PercentChange_Test(); //tests setPercentChange function

	bool Degree_Object_Test(); // tests whether Degree objects are created properly

	bool Degree_FileRead_Test(); // tests degreeFileRead function

	bool Degree_Average_Test(); //tests getDegreeAverage function

}

#endif
