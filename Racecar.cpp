#include <string>
#include "Racecar.h"
#include "Utilities.h"

namespace sdds {
	Racecar::Racecar(std::istream& in) : Car::Car(in), m_booster(0.0) {
	
		m_booster = std::stod(Car::getBuffer());
	}
	void Racecar::display(std::ostream& out)const {
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed()const { return Car::topSpeed() + (Car::topSpeed() * m_booster); }
}