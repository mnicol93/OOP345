#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <sstream>
#include <string>
#include "Car.h"
#include "Racecar.h"
#include "Vehicle.h"

namespace sdds {
	inline void trimWS(std::string& src) {
		src.erase(0, src.find_first_not_of(' '));
		src.erase(src.find_last_not_of(' ') + 1, src.size());
	}

	inline Vehicle* createInstance(std::istream& in) {

		std::string temp, line;
		std::getline(in, line);   // get a whole line

		std::stringstream ss(line);
		std::getline(ss, temp, ',');
		trimWS(temp);
		
			if (temp == "c" || temp == "C") {
				return new Car(ss);
			}
			else if (temp == "R" || temp == "r") {
				return new Racecar(ss);
			}
			else if (temp.empty()) {
				return nullptr;
			}
		
			else {
				throw "Unrecognized record type: [" + temp + ']';
		}

	}
}
#endif