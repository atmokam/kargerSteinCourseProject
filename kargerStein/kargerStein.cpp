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
    T idx = rand() % graph[head].size();
    T tail = graph[head][idx];
    return { head, tail };
}

template< typename T>
std::map<T, std::vector<T>> modifiedKarger(std::map<T, std::vector<T>> graph, T lim, std::vector<T>& cuts) {
    while (graph.size() > lim) {

        auto [head, tail] = pickHeadAndTail(graph);
        // pick random key (head) and random vector element (tail)

        for (auto edge : graph[tail]) {
            if (edge != head) {
                graph[head].push_back(edge);
            }
        } // if no self-loops, add the edge 

        for (auto edge : graph[tail]) {
            graph[edge].erase(std::remove(graph[edge].begin(), graph[edge].end(), tail), graph[edge].end());
            if (edge != head) {
                graph[edge].push_back(head);
            }
        }
        graph.erase(tail);
    }


    size_t mincut = graph.begin()->second.size();
    cuts.push_back(mincut);

    return graph;
}

template< typename T>
std::map<T, std::vector<T>> kargerStein(std::map<T, std::vector<T>> graph, std::vector<T>& cuts) {
    if (graph.size() < 6) {
        return modifiedKarger(graph, (T)2, cuts);
    }
    else {
        T times = static_cast<T>((double)graph.size() / sqrt(2.0));
        std::map<T, std::vector<T>> graph_1 = modifiedKarger(graph, times, cuts);
        std::map<T, std::vector<T>> graph_2 = modifiedKarger(graph, times, cuts);

        return std::min(kargerStein(graph_1, cuts), kargerStein(graph_2, cuts));
    }
}

