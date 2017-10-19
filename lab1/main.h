#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>
#include <algorithm> 
#include <sstream>
#include <functional>
std::vector<std::string> get_words(const std::string &phrase);
std::vector<std::string> get_phrases(const std::vector<std::string> &words, int n);
std::vector<std::pair<std::string, int>> get_sphr(const std::vector<std::string> &phrases);
bool mySort(std::pair<std::string, int>a, std::pair<std::string, int>b);

