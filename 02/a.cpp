#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() 
{
    const std::string fileName = "../../02/02.txt";
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;
    std::vector<std::vector<int>> reports;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int number;
        std::vector<int> report;
        while (iss >> number) {
            report.push_back(number);
        }
        std::cout << "Report of size: " << report.size() <<"\n";
        reports.push_back(report);
    }
    std::cout << "Total reports: = " << reports.size() << "\n";
    
    unsigned safe = 0;
    for( const auto& report : reports) {
        if(report[0] < report[1])
            check

    }
    std::cout << "Safe ones = " << safe << "\n";
    return EXIT_SUCCESS;
}