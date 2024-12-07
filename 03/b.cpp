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

    std::regex main_pattern(R"(mul\((\d{1,3}),(\d{1,3})\)|don't\(\))");
    std::regex pause_pattern(R"(do\(\))");
    std::regex* pattern = &main_pattern;
    std::string line;
    unsigned long result = 0;
    while (std::getline(file, line)) {
        //std::cout << "Read line of size: " << line.size() << "\n";
        std::smatch match;
        auto searchStart = line.cbegin();
        while (std::regex_search(searchStart, line.cend(), match, *pattern)) {
            //size_t position = match.position() + std::distance(line.cbegin(), searchStart);
            if (match.str() == "don't()") {
                //std::cout << "Found " << match.str() << " at position " << position << "\n";
                pattern = &pause_pattern;
            } else if (match.str() == "do()") {
                //std::cout << "Found " << match.str() << " at position " << position << "\n";
                pattern = &main_pattern;
            } else {
                int x = std::stoi(match[1].str());
                int y = std::stoi(match[2].str());
                //std::cout<< "Found: " << x << " " << y << " at position " << position << "\n";
                result += x * y;
            }

            searchStart = match.suffix().first;
        }
    }
    std::cout << "message = " << result << "\n";
    file.close();
    return EXIT_SUCCESS;
}
