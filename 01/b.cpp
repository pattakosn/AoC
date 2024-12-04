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
        std::cerr << "Error: Could not open file " << fileName << std::endl;
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
    unsigned similarity = 0;
    for ( auto const& one: col1) {
        std::multiset<int>::iterator found_in_col2 = col2.find(one);
        int multiplicity = 0;
        if(found_in_col2 != col2.end()) {
            do {
                multiplicity++;
                std::advance(found_in_col2, 1);
            } while(*found_in_col2 == one);
        }
        std::cout << "number: " << one << " found: " << multiplicity << "times\n";
        similarity += one * multiplicity;
        
    }
    
    std::cout << "Similarity = " << similarity << "\n";
    return EXIT_SUCCESS;
}