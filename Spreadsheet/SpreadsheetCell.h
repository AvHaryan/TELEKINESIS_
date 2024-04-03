#ifndef SPREADSHEET_CELL_H
#define SPREADSHEET_CELL_H

#include <string>
#include <iostream>
#include <cstddef>

class SpreadsheetCell {
private:
    std::string m_value;

public:
    SpreadsheetCell();
    SpreadsheetCell(const std::string& value);
    ~SpreadsheetCell();

    void setStringValue(const std::string& value);
    std::string getStringValue() const;

    operator int() const;
    operator double() const;
};

#endif // SPREADSHEET_CELL_H

