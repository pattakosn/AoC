#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>

void line_search(std::string& line, std::string pattern, size_t& times)
{
    size_t pos = 0;
    //size_t local = 0;
    while ((pos = line.find(pattern, pos)) != std::string::npos) {
        pos += pattern.length();
        times++;
    //    local++;
    }
    //std::cout << "local matches: " << local << " ";
}

std::vector<std::string> transpose(std::vector<std::string>& data)
{
    size_t rows = data.size();
    assert (rows != 0);
    size_t cols = data[0].size();
    assert (cols != 0);

    std::vector<std::string> result(cols, std::string(rows, ' '));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[j][i] = data[i][j];
        }
    }
    return result;
}

size_t search_diagonal(const std::vector<std::string>& grid, const std::string& target)
{
    size_t rows = grid.size();
    assert (rows != 0);
    size_t cols = grid[0].size();
    assert (cols != 0);

    size_t hits = 0;

    auto check_diag_TLBR = [&](int row0, int col0) {
        std::string diag = "";
        for (int i = 0; (row0 + i) < rows && (col0 + i) < cols; ++i)
            diag += grid[row0 + i][col0 + i];
        size_t pos = diag.find(target);
        while (pos != std::string::npos) {
            hits++;
            pos = diag.find(target, pos + 1);
        }
    };

    auto check_diag_TRBL = [&](int row0, int col0) {
        std::string diag = "";
        for (int i = 0; (row0 + i) < rows && (col0 - i) >= 0; ++i)
            diag += grid[row0 + i][col0 - i];
        size_t pos = diag.find(target);
        while (pos != std::string::npos) {
            hits++;
            pos = diag.find(target, pos + 1);
        }
    };


    for (int row = 0; row < rows; ++row)
        check_diag_TLBR(row, 0);
    for (int col = 1; col < cols; ++col)
        check_diag_TLBR(0, col);

    for (int row = 0; row < rows; ++row)
        check_diag_TRBL(row, cols - 1);
    for (int col = cols - 2; col >= 0; --col) 
        check_diag_TRBL(0, col);

    return hits;
}

int main() {
    const std::string fileName = "../../04/04.txt";
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << "\n";
        return EXIT_FAILURE;
    }

    std::string xmas{"XMAS"};
    std::string samx{"SAMX"};
    std::string line;
    size_t hits = 0;
    std::vector<std::string> table;
    while (std::getline(file, line)) {
        line_search(line, xmas, hits);
        line_search(line, samx, hits);
        //std::cout << ", total: " << hits << "\n";
        table.push_back(line);
    }
    std::cout << "Read " << table.size() << " lines\n\n";
    std::cout << "Total hor hits: " << hits << "\n";
        
    auto transposed_data = transpose(table);
    for(auto& it : transposed_data) {
        line_search(it, xmas, hits);
        line_search(it, samx, hits);
        //std::cout << ", total: " << hits << "\n";
    }
    std::cout << "Total hor + transposed hits: " << hits << "\n";
    
    auto diagonals_xmas = search_diagonal(table, xmas);
    std::cout << "xmas diagonals: " << diagonals_xmas  << "\n";
    auto diagonals_smax = search_diagonal(table, samx);
    std::cout << "samx diagonals: " << diagonals_smax << "\n";
    std::cout << "Grand total: " << hits + diagonals_xmas + diagonals_smax << "\n";

    file.close();
    return EXIT_SUCCESS;
}
