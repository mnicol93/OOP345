#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <string>
#include "Vehicle.h"
namespace sdds{
	class Car : public Vehicle
	{
	public:
		Car(): m_maker(""), m_condition(""), m_topSpeed(0){}
		//Read single record from the stream, extracts info
		// and store it in attributes.
		Car(std::istream&);
		//returns new, used or broken.
		std::string condition() const;
		double topSpeed() const;
		// "| MAKER(w10) | CONDITION(w6) | TOP_SPEED(w6p2) | "
		void display(std::ostream&)const;
		std::string& getBuffer();
	private:
		std::string m_maker;
		std::string m_condition;
		double m_topSpeed;
		std::string m_bufferLeft;
	};
}
#endif