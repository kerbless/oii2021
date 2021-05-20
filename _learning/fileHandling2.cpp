// 
#include <iostream>
#include <fstream>

int main() {
    /* Input */
    std::fstream f;
    f.open("input.txt", ios::in);
    if (!f.is_open()) {std::cout << "error opening input file"; return 100;}
    // GET INPUT
    f.close();

    /* Elaboration */

    /* Output */
    std::fstream f;
    f.open("output.txt", ios::out);
    if (!f.is_open()) {std::cout << "error opening output file"; return 100;}
    // PRINT OUTPUT
    f.close();

    /* End */
    return 0;
}