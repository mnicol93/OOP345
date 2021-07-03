#include <iomanip>
#include "Autoshop.h"

namespace sdds {
    Autoshop::~Autoshop()
    {
        for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++) {
            delete (*it);
        }
    }
    Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
    {
        m_vehicles.push_back(theVehicle);
        return *this;
    }
    void Autoshop::display(std::ostream& out)const 
    {
        out << std::setfill('-') << std::setw(32) << "-" <<
            "\n" << "|" << std::setfill(' ') << std::setw(30) << 
            std::left << " Cars in the autoshop!" << "|\n"
            << std::setfill('-') << std::setw(32) << "-" 
            << std::setfill(' ')<< "\n";

        for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++) {
            (*it)->display(out);
            out << std::endl;
        }

        out << std::setw(32) << std::setfill('-') << "-" << std::endl;
        
        
    }
}