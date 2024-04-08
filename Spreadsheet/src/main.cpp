#include "spreadsheet.h"

int main() {
    Spreadsheet cells;
    cells.setCell(0, 0, "A");
    std::cout << cells[0][0];
}
