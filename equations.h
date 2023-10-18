#pragma once    //  Guard: Ensures this file is not inserted multiple times into a single cpp file.
#include <vector>

void displayMatrix(std::vector<std::vector<float>> m);
float det2x2(std::vector<std::vector<float>> n);
std::vector<std::vector<float>> calcSmallerMatrix(std::vector<std::vector<float>> &m, short pos);
float detnxn(std::vector<std::vector<float>> o);