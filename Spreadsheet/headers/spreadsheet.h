#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include "cell.h"
#include <string>

class Spreadsheet {
private:
   size_t m_row;
   size_t m_col;
   Cell** m_cells;

private:
   void initializeCells();
   void deallocateCells();

public:
   Spreadsheet();
   Spreadsheet(size_t n);
   Spreadsheet(size_t row, size_t col);
   Spreadsheet(const Spreadsheet& other);
   Spreadsheet(Spreadsheet&& other) noexcept;  
   ~Spreadsheet();

public:
   Spreadsheet& operator=(const Spreadsheet& other);
   Spreadsheet& operator=(Spreadsheet&& other) noexcept;
    const Cell* operator[](size_t rowIndex) const;
    void setCell(int row, int col, const std::string& value);
    void addRow(); 
    void addColumn(); 

};

#endif // SPREADSHEET_H
