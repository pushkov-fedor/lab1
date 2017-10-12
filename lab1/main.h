#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>
#include <algorithm> 
#include <functional>
using namespace std;
vector<string> get_words(string filename);
vector<string> get_phrases(vector<string> words, int n);
vector<pair<string, int>> get_sphr(vector<string> phrases);
bool mySort(pair<string, int>a, pair<string, int>b) {
	return a.second >  b.second;
}

