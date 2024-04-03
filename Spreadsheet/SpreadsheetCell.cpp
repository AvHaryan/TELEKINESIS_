#include "SpreadsheetCell.h"
#include <sstream>

SpreadsheetCell::SpreadsheetCell() : m_value("") {}

SpreadsheetCell::SpreadsheetCell(const std::string& value) : m_value(value) {}

SpreadsheetCell::~SpreadsheetCell() {}

void SpreadsheetCell::setStringValue(const std::string& value) {
    m_value = value;
}

std::string SpreadsheetCell::getStringValue() const {
    return m_value;
}

SpreadsheetCell::operator int() const {
    std::stringstream ss(m_value);
    int num = 0;
    ss >> num;
    return num;
}

SpreadsheetCell::operator double() const {
    std::stringstream ss(m_value);
    double num = 0.0;
    ss >> num;
    return num;
}

