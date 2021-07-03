#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
	class Autoshop
	{
	public:
		~Autoshop();
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out)const;
		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++) {
				if (test((*it))) vehicles.push_back((*it));
			}
		}
	private:
		std::vector<Vehicle*> m_vehicles;
	};
}
#endif