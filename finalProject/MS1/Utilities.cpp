// Name: Marc Nicolas Oliva
// Seneca Student ID: 130943202
// Seneca email: mnicolas-oliva@myseneca.ca
// Date of completion: 2021-07-11
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

void sdds::Utilities::setFieldWidth(size_t newWidth)
{
    m_widthField = newWidth;
}

size_t sdds::Utilities::getFieldWidth() const
{
    return m_widthField;
}

std::string sdds::Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
    return std::string();
}

void sdds::Utilities::setDelimiter(char newDelimiter)
{
}

char sdds::Utilities::getDelimiter()
{
    return 0;
}
