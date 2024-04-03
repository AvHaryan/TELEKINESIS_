#include "SpreadsheetCell.h"
#include <sstream>
#include <stdexcept>



SpreadsheetCell::SpreadsheetCell() : m_value("") {}

SpreadsheetCell::SpreadsheetCell(const std::string& value) : m_value(value) {}

SpreadsheetCell::~SpreadsheetCell() {}

void SpreadsheetCell::setStringValue(const std::string& value) {
	 m_value = value;
}

std::string SpreadsheetCell::getStringValue() const {
	 return m_value;
}

int SpreadsheetCell::getIntValue() const {
	 try {
		 std::stringstream ss(m_value);
		 int num{};
		 if (!(ss >> num)) {
			  throw std::invalid_argument("ERROR: Invalid integer value!");
		 }
		 return num;
     } catch (const std::invalid_argument& e) {
			  std::cerr << e.what() << std::endl;
			  return 0;
		 }
}

double SpreadsheetCell::getDoubleValue() const {
	 try {
		  std::stringstream ss(m_value);
		  double num;
		  if (!(ss >> num)) {
		 	  throw std::invalid_argument("ERROR: Invalid double value!");
		  }
		  return num;
	 } catch (const std::invalid_argument& e) {
		  std::cerr << e.what() << std::endl;
		  return 0;
	 }
}


