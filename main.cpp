
#include "region1.h"
#include<ostream>

int main() {

	NS_REGION::RegionSalary test = NS_REGION::RegionSalary();
	std::list < NS_REGION::RegionSalary > x =  test.extractRegionData();
	std::cout << "testing123123" << std::endl;
	if (x.empty()) {

		std::cout << "it is empty" << std::endl;

	}
	std::list<NS_REGION::RegionSalary>::iterator it;
	for (it = x.begin(); it != x.end(); ++it) {
		std::cout << it->getStartSalary()<<std::endl;
	}



	//std::cout << x.size() << std::endl;
	return 0;
}
