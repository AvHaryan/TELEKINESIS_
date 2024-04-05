#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>

class Cell {
private:
    std::string storage;

public:
    Cell();
    Cell(int);
    Cell(double);
    Cell(const std::string& str);

    Cell(const Cell& rhv);
    Cell& operator=(const Cell& rhv);
    Cell& operator=(int val);
    Cell& operator=(double val);
    Cell& operator=(const std::string& val);

    Cell(Cell&& rhv) noexcept;
    Cell& operator=(Cell&& rhv) noexcept;

    ~Cell();
    //void display() const;
    friend std::ostream& operator<<(std::ostream& ostr, const Cell& cell);

};

std::ostream& operator<<(std::ostream& ostr, const Cell& cell);
#endif //CELL_H
