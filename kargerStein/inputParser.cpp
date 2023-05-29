#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

std::ifstream getFile(std::string file) {
    return std::ifstream{ file };
}

template< typename T >
std::map<T, std::vector<T>> parse(std::ifstream file) {
    std::map<T, std::vector<T>> result;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        T key, number;
        iss >> key;
        while (iss >> number) {
            result[key].push_back(number);
        }
    }
    return result;
}
