#include "Spreadsheet.h"

Spreadsheet::Spreadsheet() : m_numRows(1),  m_numCols(1), m_cells(new SpreadsheetCell*[1]) {
	 m_cells[0] = new SpreadsheetCell[1];
}

Spreadsheet::Spreadsheet(size_t numRows, size_t numCols) : m_numRows(numRows), m_numCols(numCols), 
	 m_cells(new SpreadsheetCell*[numRows]) {
		  for (size_t i = 0; i < numRows; ++i) {
				m_cells[i] = new SpreadsheetCell[numCols];
		  }
	 }

Spreadsheet::~Spreadsheet() {
	 for (size_t i = 0; i < m_numRows; ++i) {
		  delete[] m_cells[i];
	 }
	 delete[] m_cells;
}

void Spreadsheet::addRow(int row) {

	 SpreadsheetCell** newCells = new SpreadsheetCell*[m_numRows + row];

	 for (size_t i = 0; i < m_numRows; ++i) {
		  newCells[i] = m_cells[i];
	 }

	 for (size_t i = m_numRows; i < m_numRows + row; ++i) {
	 	newCells[i] = new SpreadsheetCell[m_numCols];
	 }

	 delete[] m_cells;
	 m_cells = newCells;
	 m_numRows += row;
}

void Spreadsheet::addColumn(int col) {
    // Allocate memory for the new column
    SpreadsheetCell** newCells = new SpreadsheetCell*[m_numRows];
    for (size_t i = 0; i < m_numRows; ++i) {
        newCells[i] = new SpreadsheetCell[m_numCols + col];
        for (size_t j = 0; j < m_numCols; ++j) {
            newCells[i][j] = m_cells[i][j];
        }
        for (size_t j = m_numCols; j < m_numCols + col; ++j) {
            newCells[i][j].setStringValue(""); 
        }
        delete[] m_cells[i];
    }
    delete[] m_cells;
    m_cells = newCells;
    m_numCols += col;
}


void Spreadsheet::removeRow(size_t rowIndex) {
	 if (rowIndex >= 0 &&  rowIndex < m_numRows) {
		  delete[] m_cells[rowIndex];
		  for (size_t i = rowIndex; i < m_numRows - 1; ++i) {
				m_cells[i] = m_cells[i + 1];
		  }
		  --m_numRows;
	 }
}

void Spreadsheet::removeColumn(size_t colIndex) {
	 for (size_t i = 0; i < m_numRows; ++i) {
		  size_t newColIndex = 0;
		  SpreadsheetCell* newColumn = new SpreadsheetCell[m_numCols - 1];
		  for (size_t j = 0; j < m_numCols; ++j) {
				if (j != colIndex) {
					 newColumn[newColIndex++] = m_cells[i][j];
				}
		  }
		  delete[] m_cells[i];
		  m_cells[i] = newColumn;
		  newColumn = nullptr;
	 }
}

SpreadsheetCell& Spreadsheet::getCell(size_t row, size_t col)  {
	 return m_cells[row][col];
}

void Spreadsheet::setCell(size_t row, size_t col, const std::string& value) { 
	 m_cells[row][col].setStringValue(value);
}

void Spreadsheet::print() const {
	 for (size_t i = 0; i < m_numRows; ++i) {
		  for (size_t j = 0; j < m_numCols; ++j) {
				std::cout << m_cells[i][j].getStringValue() << '\t';
		  }
		  std::cout << std::endl;
	 }
}



