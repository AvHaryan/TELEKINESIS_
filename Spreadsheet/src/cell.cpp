#include "cell.h"

Cell::Cell() : storage("") {}

Cell::Cell(int n) : storage(std::to_string(n)) {}

Cell::Cell(double n) : storage(std::to_string(n)) {}

Cell::Cell(const std::string& str) : storage(str) {}

Cell::Cell(const Cell& rhv) : storage(rhv.storage) {}

Cell& Cell::operator=(const Cell& rhv) {
    if (this != &rhv) {
        this->storage = rhv.storage;
    }
    return *this;
}

Cell& Cell::operator=(int val) {
    this->storage = std::to_string(val);
    return *this;
}

Cell& Cell::operator=(double val) {
    this->storage = std::to_string(val);
    return *this;
}

Cell& Cell::operator=(const std::string& val) {
    this->storage = val;
    return *this;
}


Cell::Cell(Cell&& rhv) noexcept : storage(std::move(rhv.storage)) {
   rhv.storage = "";
}

Cell& Cell::operator=(Cell&& rhv) noexcept {
   if (this != &rhv) {
     this->storage = std::move(rhv.storage);
     rhv.storage = "";
   }
   return *this;
}


//void Cell::display() const{
//    std::cout << this->storage << std::endl;
//}

Cell::~Cell() = default;

std::ostream& operator<<(std::ostream& ostr, const Cell& cell) {
    ostr<<cell.storage;
    return ostr;
}
