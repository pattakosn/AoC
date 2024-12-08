#include <fstream>
#include <iostream>
#include <vector>
#include <regex>
#include <cassert>

int main() {
    const std::string fileName = "../../05/05.txt";
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << "\n";
        return EXIT_FAILURE;
    }

    std::string line;
    
    std::vector<std::pair<int, int>> rules;
    std::regex pattern(R"((\d+)\|(\d+))");
    std::smatch match;
    while (std::getline(file, line) && std::regex_match(line, match, pattern)) {
        int X = std::stoi(match[1].str());
        int Y = std::stoi(match[2].str());
        //std::cout << "X: " << X << " Y: " << Y << "\n";
        rules.push_back({X,Y});
    }
    std::cout << "number of rules: " << rules.size() <<"\n";
    std::cout << line << "\n";
    
    std::vector<std::vector<int>> updates;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<int> update;
        while (std::getline(ss, token, ',')) {
            update.push_back(std::stoi(token));
            //std::cout << " " << update.back();
        }
        //std::cout << "\n";
        updates.push_back(update);
    }
    std::cout << "number of updates: " << updates.size() << "\n";

    // check rules
    for( const auto& r : rules ) {
        for(auto u = updates.begin(); u < updates.end(); ++u ) {
            auto it1 = std::find(u->begin(), u->end(), r.first);
            auto d1 = std::distance(u->begin(), it1); 
            if (it1 == u->end())
                continue;
            else {
                auto it2 = std::find(u->begin(), u->end(), r.second);
                auto d2 = std::distance(u->begin(), it2); 
                if (it2 == u->end() || d1<d2)
                    continue;
                else {
                    updates.erase(u);
                    continue;
                }
            }
        }
    }
    std::cout << "number of updates: " << updates.size() << "\n";

    auto result = 0;
    for (const auto& u:updates) {
        //std::cout << "size: " << u.size() << " mid number: " << u.at(u.size()/2) << "\n";
        assert(u.size()%2);
        result += u.at(u.size()/2);
    }
    std::cout << "result= " << result << "\n";

    file.close();
    return EXIT_SUCCESS;
}
