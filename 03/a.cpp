//#include <cstdlib>
#include <iostream>
#include <fstream>
//#include <sstream>
#include <string>
#include <vector>
//#include <vector>

int main() 
{
    const std::string fileName = "../../03/03.txt";
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << "Read line of size: " << line.size() << std::endl;
        size_t position = line.find("mul(");
        
        while (position != std::string::npos) {
            positions.push_back(position); // Store the position
            position = line.find("mul(", position + 1); // Search from the next character
        }
    }

    file.close();
    return EXIT_SUCCESS;
}
