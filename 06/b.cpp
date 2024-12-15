#include <fstream>
#include <iostream>
#include <vector>
#include <set>

int main() {
    const std::string fileName = "../../06/06.txt";
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << "\n";
        return EXIT_FAILURE;
    }

    char up = '^';
    char ob = '#';
    std::string line;
    std::vector<std::string> map;
    int x_cur{0};
    int y_cur{0};
    int x_temp = 0;
    while (std::getline(file, line)) {
        map.push_back(line);
        size_t pos = line.find(up);
        if (pos != std::string::npos) {
            x_cur = x_temp;
            y_cur = pos;
            std::cout << "starting position found at: " << x_cur << " , " << y_cur << "\n";
        }
        x_temp++;
    }
    std::cout << "lines: " << map.size() <<" of length: " << map[0].size() << "\n";

    enum class direction { up, right, down, left};
    direction cur_direction = direction::up;
    std::set<std::pair<int,int>> visited;
    while( x_cur >= 0 && x_cur < static_cast<int>(map.size()) && y_cur >= 0 && y_cur < static_cast<int>(map[0].size()) ) {
        int x_new;
        int y_new;
        std::cout << "current position: " << x_cur << " , " << y_cur << "\n";
        visited.insert({x_cur,y_cur});
        
        switch (cur_direction) {
            case direction::up :
                x_new = x_cur - 1;
                y_new = y_cur;
                if(x_new >= 0 && map.at(x_new).at(y_new) == ob) {
                    std::cout << "\nturn right. no step :) \n";
                    cur_direction = direction::right;
                    continue;
                } else {
                    x_cur = x_new;
                    continue;
                }
            break;
            case direction::right :
                x_new = x_cur;
                y_new = y_cur + 1;
                if(y_new < static_cast<int>(map[0].size()) && map.at(x_new).at(y_new) == ob) {
                    cur_direction = direction::down;
                    std::cout << "\nturn down. no step :) \n";
                    continue;
                } else {
                    y_cur = y_new;
                    continue;
                }
            break;
            case direction::down :
                x_new = x_cur + 1;
                y_new = y_cur;
                if(x_new < static_cast<int>(map.size()) && map.at(x_new).at(y_new) == ob) {
                    cur_direction = direction::left;
                    std::cout << "turn left. no step :) \n";
                    continue;
                } else {
                    x_cur = x_new;
                    continue;
                }
            break;
            case direction::left :
                x_new = x_cur;
                y_new = y_cur - 1;
                if(y_new >= 0 && map.at(x_new).at(y_new) == ob) {
                    cur_direction = direction::up;
                    std::cout << "turn up. no step :) \n";
                    continue;
                } else {
                    y_cur = y_new;
                    continue;
                }
            break;
        }
    }
    std::cout << "Final position: " << x_cur << " , " << y_cur << " distinct visited: " << visited.size() << "\n";
    file.close();
    return EXIT_SUCCESS;
}
