#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include "Car.h"

namespace sdds {
	class Racecar : public Car
	{
	public:
		Racecar(std::istream& is);
		void display(std::ostream& out)const;
		double topSpeed()const;
	private:
		double m_booster;
	};
}
#endif