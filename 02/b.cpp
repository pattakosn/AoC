#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

static constexpr int DIFF = 3;

bool is_safe(const std::vector<int>& report)
{
    if (report[0] == report[1] || abs(report[1] - report[0]) > DIFF)
        return false;

    bool increasing = report[0] < report[1];
    for(auto i = 1u; i < report.size()-1; ++i) {
        if(increasing) {
            if(report[i] >= report[i+1] || (report[i+1] - report[i]) > DIFF )
                return false;
        } else {
            if(report[i] <= report[i+1] || (report[i] - report[i+1]) > DIFF )
                return false;
        }
    }
    return true;
}

bool extended_is_safe(const std::vector<int>& report)
{
    for(auto i = 0u; i < report.size(); ++i) {
        std::vector<int> sub_report(report);
        sub_report.erase(sub_report.begin() + i);
        if(is_safe(sub_report))
            return true;
    }
    return false;
}

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
        //std::cout << "Report of size: " << report.size() <<"\n";
        reports.push_back(report);
    }
    std::cout << "Total reports: = " << reports.size() << "\n";
    
    unsigned safe = 0;
    for( const auto& report : reports) {
        for( const auto&i : report)
            std::cout << i << " ";
        std::cout <<", size: " << report.size();
        if( !is_safe(report) && !extended_is_safe(report) ) {
            std::cout <<" is not safe\n";
        } else {
            std::cout <<" is not safe\n";
            safe++;
        }
    }
    std::cout << "Safe ones = " << safe << "\n";
    return EXIT_SUCCESS;
}
