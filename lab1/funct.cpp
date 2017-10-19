#include "main.h"
using namespace std;

bool mySort(pair<string, int>a, pair<string, int>b) {
	return a.second >  b.second;
}

vector<string> get_words(const string &phrase) {
	std::vector<string> words;
	if (phrase == "") {
		cout << "Empty phrase" << endl;
		return words;
	}

	string word;
	istringstream iss(phrase, istringstream::in);
	while (iss >> word) {
		words.push_back(word);
	}

	return words;
}

vector<string> get_phrases(const vector<string> &words, int n) {
	vector<string> phrases;
	if (n > words.size() || n < 1) {
		cout << "Wrong n number" << endl;
		return phrases;
	}
	for (int i = 0; i < words.size() - (n - 1); i++) {
		string phrase;
		for (int j = 0; j < n; j++)
			phrase = phrase + words[i + j] + " ";
		phrases.push_back(phrase);
	}
	return phrases;

}

vector<pair<string, int>> get_sphr(const vector<string> &phrases) {
	vector<pair<string, int>> fr_phrases;
	if (phrases.size() == 0) {
		cout << "Empty input" << endl;
		return fr_phrases;
	}
	map<string, int> phrases_map;
	for (int i = 0; i < phrases.size(); i++) {
		auto f_map = phrases_map.find(phrases[i]);
		if (f_map != phrases_map.end()) {
			f_map->second++;
		}
		phrases_map.insert(pair<string, int>(phrases[i], 1));
	}
	for (auto itr = phrases_map.begin(); itr != phrases_map.end(); itr++) {
		fr_phrases.push_back(*itr);
	}
	sort(fr_phrases.begin(), fr_phrases.end(), mySort);
	return fr_phrases;
}