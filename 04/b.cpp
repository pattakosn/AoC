#include <fstream>
#include <iostream>
#include <vector>

int main() {
    const std::string fileName = "../../04/04.txt";
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << "\n";
        return EXIT_FAILURE;
    }

    std::string line;
    std::vector<std::string> table;
    while (std::getline(file, line))
        table.push_back(line);

    auto rows = table.size();
    auto cols = table[0].size();
    std::cout << "Read " << rows << " lines of size: " << cols << "\n";

    // .{M,S}.{M,S}.
    // .  .  A  .  .
    // .{S,M}.{S,M}.
    size_t hits = 0;
    for( size_t row = 0; row < rows-2; ++row)
        for( size_t col = 0; col < cols-2; ++col) {
            if (table[row][col] == 'M' && table[row][col+2] == 'M')
                if (table[row+1][col+1] == 'A')
                    if (table[row+2][col] == 'S' && table[row+2][col+2] == 'S')
                        ++hits;
            if (table[row][col] == 'M' && table[row][col+2] == 'S')
                if (table[row+1][col+1] == 'A')
                    if (table[row+2][col] == 'M' && table[row+2][col+2] == 'S')
                        ++hits;
            if (table[row][col] == 'S' && table[row][col+2] == 'M')
                if (table[row+1][col+1] == 'A')
                    if (table[row+2][col] == 'S' && table[row+2][col+2] == 'M')
                        ++hits;
            if (table[row][col] == 'S' && table[row][col+2] == 'S')
                if (table[row+1][col+1] == 'A')
                    if (table[row+2][col] == 'M' && table[row+2][col+2] == 'M')
                        ++hits;
            }
    std::cout << "xmas found: " << hits << "\n";
    file.close();
    return EXIT_SUCCESS;
}
