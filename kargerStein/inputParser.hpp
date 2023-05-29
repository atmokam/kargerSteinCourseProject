#pragma once
#include "inputParser.cpp"

std::ifstream getFile(std::string file);

template< typename T >
std::map<T, std::vector<T>> parse(std::ifstream file);