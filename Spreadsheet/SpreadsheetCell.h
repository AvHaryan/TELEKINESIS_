#ifndef SPREADSHEET_CELL_H
#define SPREADSHEET_CELL_H

#include <string>
#include <iostream>
#include <cstddef>

class SpreadsheetCell {
private:

	 std::string m_value;

public:
	 //Default constructor
	 SpreadsheetCell();

	 //Parametrized constructor
	 SpreadsheetCell(const std::string& value);

	 //Destructor
	 ~SpreadsheetCell();

	 //Method to set the content of the cell
	 void setStringValue(const std::string& value);
	 
	 //Method to get the string value of the cell
	 std::string getStringValue() const;

	 //Method to get integer representation of the content
	 int getIntValue() const;

	 //Methot to get double representation of the content
	 double getDoubleValue() const;
};

#endif // SPREADSHEET_H
