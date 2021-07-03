#include <iomanip>
#include "Car.h"
#include "Utilities.h"

namespace sdds {
    Car::Car(std::istream& is) : m_condition(""), m_maker(""), m_topSpeed(0.0)
    {
        //std::string temp, line;
        //std::getline(is, line);   // get a whole line

        //std::stringstream ss(line);
        std::string temp;

        std::getline(is, temp, ',');
        m_maker = temp;
        trimWS(m_maker);

        //Get the condition
        std::getline(is, temp, ',');
        trimWS(temp);

        //After trimming the string will never be only blanks
        if (temp == "n" || temp.empty())
            m_condition = "new";
        else if (temp == "u")
            m_condition = "used";
        else if (temp == "b")
            m_condition = "broken";
        else {
            std::string err = "Invalid record!";
            throw err;
        }
           /* throw("Invalid record!");*/

        //Get the speed
        try {        
            std::getline(is, temp, ',');
            trimWS(temp);
            m_topSpeed = std::stod(temp);
        }
        catch (std::exception& e) {
            std::string err = "Invalid record!";
            throw err;
        }
        is >> m_bufferLeft;
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
        
        out << "| " << std::setfill(' ') << std::setw(10) << 
            std::right << m_maker << " | " << std::setw(6) << std::left << 
            m_condition << " | " << std::setw(5) << std::setprecision(2) << 
            std::fixed << topSpeed() << " |";
    }
    std::string& Car::getBuffer()
    {
        return m_bufferLeft;
    }
}