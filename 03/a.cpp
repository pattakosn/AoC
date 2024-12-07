#include <fstream>
#include <iostream>
#include <regex>

int main() {
    const std::string fileName = "../../03/03.txt";
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << "\n";
        return EXIT_FAILURE;
    }

    std::string line;
    unsigned long result = 0;
    while (std::getline(file, line)) {
        std::cout << "Read line of size: " << line.size() << "\n";
        std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
        std::match_results<std::string::const_iterator> match;
        auto start = line.cbegin();
        auto end = line.cend();
        while (std::regex_search(start, end, match, pattern)) {
            int x = std::stoi(match[1].str());
            int y = std::stoi(match[2].str());
            std::cout<< "Found: " << x << " " << y << "\n";
            result += x * y;
            start = match.suffix().first;
        }
    }
    std::cout << "message= " << result << "\n";
    file.close();
    return EXIT_SUCCESS;
}
