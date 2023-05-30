#include <algorithm>
#include <cmath>
#include <map>
#include <random>
#include <vector>
#include <string>
#include <tuple>

template< typename T>
std::pair<T, T> pickHeadAndTail(std::map<T, std::vector<T>>& graph) {
    auto it = graph.begin();
    std::advance(it, rand() % graph.size());
    T head = it->first;
    T index = rand() % graph[head].size();
    T tail = graph[head][index];
    return { head, tail };
}

template< typename T>
std::map<T, std::vector<T>> modifiedKarger(std::map<T, std::vector<T>> graph, T limit, std::vector<T>& cuts) {
    while (graph.size() > limit) {

        auto [head, tail] = pickHeadAndTail(graph);
        // pick random key (head) and random vector element (tail)

        for (auto edge : graph[tail]) {
            if (edge != head) {
                graph[head].push_back(edge);
            }
        } // if no loops, add the edge to head

        for (auto edge : graph[tail]) {
            graph[edge].erase(std::remove(graph[edge].begin(), graph[edge].end(), tail), graph[edge].end());
            if (edge != head) {
                graph[edge].push_back(head);
            }
        }
        graph.erase(tail);
    }


    size_t minCut = graph.begin()->second.size();
    cuts.push_back(minCut);

    return graph;
}

template< typename T>
std::map<T, std::vector<T>> kargerStein(std::map<T, std::vector<T>>& graph, std::vector<T>& cuts) {
    if (graph.size() < 6) {
        return modifiedKarger(graph, static_cast<T>(2), cuts);
    }
    else {
        T times = static_cast<T>((double)graph.size() / sqrt(2.0));
        std::map<T, std::vector<T>> graph1 = modifiedKarger(graph, times, cuts);
        std::map<T, std::vector<T>> graph2 = modifiedKarger(graph, times, cuts);

        return std::min(kargerStein(graph1, cuts), kargerStein(graph2, cuts));
    }
}
