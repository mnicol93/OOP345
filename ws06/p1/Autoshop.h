#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include "Vehicle.h"

namespace sdds {
	class Autoshop
	{
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out)const;
	private:
		std::vector<Vehicle*> m_vehicles;
	};
}
#endif
