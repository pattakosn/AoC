#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>

int main() 
{
    const std::string fileName = "../../01/01.txt";
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << "\n";
        return EXIT_FAILURE;
    }

    std::string line;
    std::multiset<int> col1, col2;
    unsigned lines_read = 0;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int num1, num2;

        if (iss >> num1 >> num2) {
            col1.insert(num1);
            col2.insert(num2);
        } else
            exit(EXIT_FAILURE);
        lines_read++;
    }
    std::cout << "lines_read = " << lines_read << ". col1.size = " << col1.size() << ". col2.size = " << col2.size() << "\n";
    unsigned distance = 0;
    for ( auto i = 0u; i < lines_read; ++i) {
        auto col1_it = col1.begin();
        std::advance(col1_it, i);
        auto col2_it = col2.begin();
        std::advance(col2_it, i);
        distance += abs(*col2_it - *col1_it);
    }
    
    std::cout << "Distance= " << distance << "\n";
    return EXIT_SUCCESS;
}