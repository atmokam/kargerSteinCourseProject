#pragma once
#include "kargerStein.cpp"


template< typename T>
std::pair<T, T> pickHeadAndTail(std::map<T, std::vector<T>>& graph);

template< typename T>
std::map<T, std::vector<T>> modifiedKarger(std::map<T, std::vector<T>> graph, T lim, std::vector<T>& cuts);

template< typename T>
std::map<T, std::vector<T>> kargerStein(std::map<T, std::vector<T>> graph, std::vector<T>& cuts);
