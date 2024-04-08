#include "cell.h"
#include "spreadsheet.h"

#include <string>

void Spreadsheet::initializeCells() {
    m_cells = new Cell*[m_row];
    for (size_t i = 0; i < m_row; ++i) {
        m_cells[i] = new Cell[m_col];
    }
}

void Spreadsheet::deallocateCells() {
      if (m_cells) {
          for (size_t i = 0; i < m_row; ++i) {
              delete[] m_cells[i];
          }
          delete[] m_cells;
          m_cells = nullptr;
      }
}

Spreadsheet::Spreadsheet() 
    : m_row(2)
    , m_col(2)
    , m_cells(nullptr)
{
    initializeCells();
}

Spreadsheet::Spreadsheet(size_t n)
    : m_row(n)
    , m_col(n)
    , m_cells(nullptr)
{
    initializeCells();
}

Spreadsheet::Spreadsheet(size_t row, size_t col)
    : m_row(row)
    , m_col(col)
    , m_cells(nullptr)
{
    initializeCells();
}

Spreadsheet::Spreadsheet(const Spreadsheet& other)
    :m_row(other.m_row)
    ,m_col(other.m_col)
    ,m_cells(nullptr)
{
    initializeCells();

    for(size_t i = 0; i < other.m_row; ++i) {
        for(size_t j = 0; j < other.m_col; ++j) {
            m_cells[i][j] = other.m_cells[i][j];
        }
    }
}

Spreadsheet::Spreadsheet(Spreadsheet&& other) noexcept 
    :m_row(other.m_row)
    ,m_col(other.m_col)
    ,m_cells(other.m_cells)
{
    other.m_row = 0;
    other.m_col = 0;
    other.m_cells = nullptr;
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhv) {
    if (this != &rhv) {
        this->deallocateCells();

        this->m_row = rhv.m_row;
        this->m_col = rhv.m_col;
        initializeCells();

        for (size_t i = 0; i < m_row; ++i) {
            this->m_cells[i] = new Cell[m_col];
            for (size_t j = 0; j < m_col; ++j) {
                this->m_cells[i][j] = rhv.m_cells[i][j];
            }
        }
    }
    return *this;
}

Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhv) noexcept {
    if (this != &rhv) {
        this->deallocateCells();

        this->m_row = rhv.m_row;
        this->m_col = rhv.m_col;
        this->m_cells = rhv.m_cells;

        rhv.m_row = 0;
        rhv.m_col = 0;
        rhv.m_cells = nullptr;
    }
    return *this;
}



void Spreadsheet::setCell(int row, int col, const std::string& str) {
    if (row >= 0 && row < m_row && col >= 0 && col < m_col) {
        m_cells[row][col] = str;
    } else {
        throw std::out_of_range("Row or column index out of range");
    }
}



const Cell* Spreadsheet::operator[](size_t rowIndex) const {
       if(rowIndex >= m_row) {
           throw std::out_of_range("Index out of range");
       }
       return m_cells[rowIndex];
   }

void Spreadsheet::addRow() {
    Cell** newCells = new Cell*[m_row + 1]; 
    for (size_t i = 0; i < m_row; ++ i) {
        newCells[i] = m_cells[i];
    }
    newCells[m_row] = new Cell[m_col];
    delete[] m_cells;
    ++m_row;
    m_cells = newCells;
    newCells = nullptr;
}

Spreadsheet::~Spreadsheet()  
{
    deallocateCells();
}


