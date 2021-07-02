#include <iomanip>
#include "Car.h"
#include "Utilities.h"

namespace sdds {
    Car::Car(std::istream& is)
    {
        std::string temp;
        
        std::getline(is, temp, ',');
        trimWS(temp);
        /*if (temp == "c" || temp == "C") {
            std::getline(is, temp, ',');*/
            m_maker = temp;
            trimWS(m_maker);

            std::getline(is, temp, ',');
            trimWS(temp);
            if (temp == "n") m_condition = "new";
            else if (temp == "u") m_condition = "used";
            else if (temp == "b") m_condition = "broken";
            else m_condition = "unknown";

            std::getline(is, temp, '\n');
            trimWS(temp);

            if (std::stod(temp))
                m_topSpeed = std::stod(temp);
        /*}
        else {
            m_maker = "INVALID";
            m_condition = "INVALID";
            m_topSpeed = 0.0;
        }*/
    }

    std::string Car::condition() const
    {
        return m_condition;
    }

    double Car::topSpeed() const
    {
        return m_topSpeed;
    }

    void Car::display(std::ostream& out) const
    {
        out << "| " << std::setw(8) << m_maker << " | " << 
            std::setw(6) << m_condition << " | " << 
            std::setw(5) << std::setprecision(2) << std::fixed << m_topSpeed 
            << " |\n";
    }
}