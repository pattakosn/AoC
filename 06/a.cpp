#include <fstream>
#include <iostream>
#include <vector>

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
    size_t steps = 0;
    direction cur_direction = direction::up;
    while( x_cur > 0 || x_cur < map[0].size() || y_cur > 0 || y_cur < map.size() ) {
        int x_new;
        int y_new;
            std::cout << "Total steps to exit: " << steps << "\n";

        switch (cur_direction) {
            case direction::up :
                x_new = x_cur - 1;
                y_new = y_cur;
                if(x_new >= 0 && map[x_new][y_new] == ob) {
                    cur_direction = direction::right;
                    continue;
                } else {
                    steps++;
                    x_cur = x_new;
                    continue;
                }
            break;
            case direction::right :
                x_new = x_cur;
                y_new = y_cur + 1;
                if(y_new <map.size() && map[x_new][y_new] == ob) {
                    cur_direction = direction::down;
                    continue;
                } else {
                    steps++;
                    y_cur = y_new;
                    continue;
                }
            break;
            case direction::down :
                x_new = x_cur + 1;
                y_new = y_cur;
                if(x_new < map[0].size() && map[x_new][y_new] == ob) {
                    cur_direction = direction::left;
                    continue;
                } else {
                    steps++;
                    x_cur = x_new;
                    continue;
                }
            break;
            case direction::left :
                x_new = x_cur;
                y_new = y_cur - 1;
                if(y_new >= 0 && map[x_new][y_new] == ob) {
                    cur_direction = direction::up;
                    continue;
                } else {
                    steps++;
                    y_cur = y_new;
                    continue;
                }
            break;
        }
    }
    std::cout << "Total steps to exit: " << steps << "\n";
    file.close();
    return EXIT_SUCCESS;
}
