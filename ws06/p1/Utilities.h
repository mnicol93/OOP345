#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <sstream>
#include "Vehicle.h"
#include "Car.h"

namespace sdds {
	inline void trimWS(std::string& src) {
		src.erase(0, src.find_first_not_of(' '));
		src.erase(src.find_last_not_of(' ') + 1, src.size());
	}

	inline Vehicle* createInstance(std::istream& in) {
		//char vType;
		//std::stringstream ss;
		//while (in) {
		//	ss.put(in.get());
		//}
		//do {
		//	ss >> vType;
		//	if (vType == 'c' || vType == 'C') {
		//		return new Car(ss);
		//	}
		//	else {
		//		return nullptr;
		//	}
		//} while (ss);
		std::string vType;
		std::getline(in, vType, ',');
		trimWS(vType);

		if (vType == "c" || vType == "C") {
			return new Car(in);
		}
		else {
			return nullptr;
		}
		/*std::stringstream buf;
		in >> buff;*/
	}
}
#endif
