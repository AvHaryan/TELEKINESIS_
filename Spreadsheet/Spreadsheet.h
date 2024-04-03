#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include "SpreadsheetCell.h"

#include <string>
#include <cstddef>


class Spreadsheet {
private:
	 size_t m_numRows;
	 size_t m_numCols;
	 SpreadsheetCell** m_cells;
public:
	 Spreadsheet();
	 Spreadsheet(size_t numRows, size_t numCols); 

	 ~Spreadsheet();

	 void addRow(int row);

	 void addColumn(int col);

	 void removeRow(size_t rowIndex);

	 void removeColumn(size_t colIndex);

	 SpreadsheetCell& getCell(size_t row, size_t col);

	 void setCell(size_t row, size_t col, const std::string& value);

	 void print() const;

};


#endif //SPREADSHEET_H

