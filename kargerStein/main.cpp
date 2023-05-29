#include "kargerStein.hpp"
#include "inputParser.hpp"
#include <chrono>
#include <limits>

size_t runAlgorithm(std::string filePath) {
    std::vector<size_t> cuts = {};
    std::map<size_t, std::vector<size_t>> graph = parse<size_t>(getFile(filePath));

    size_t timesToBeRun = std::pow(std::log2(graph.size()), 2);
    size_t minimum = std::numeric_limits<size_t>::max();

    while (timesToBeRun > 0) {
        kargerStein(graph, cuts);
        if (cuts[cuts.size() - 1] < minimum) 
            minimum = cuts[cuts.size() - 1];
        --timesToBeRun;
    }
    return minimum;
}

int main() {
    std::srand((unsigned int)std::time(nullptr));

    std::cout << "Please input file path: ";
    std::string filePath;
    std::cin >> filePath;

    size_t result = runAlgorithm(filePath);
    if(result < std::numeric_limits<size_t>::max())
        std::cout << "result: " << result << std::endl;

}

    