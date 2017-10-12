#include "main.h"

int main(int argc, char* argv[]) {
	//get_words() возвращает вектор слов
	//get_phrases(vector<string> words) возвращает вектор фраз
	//get_sphr(vector<string> phrases возвращает отсортированный map


	// -m <number> -m <number> 
	// file.txt -m <number> -m <number> 
	string filename = "";
	int n = 2;
	int m = 2;

	if (argc > 6) {
		cout << "Too much arguments" << endl;
		cin.get();
		return -1;
	}

	for (int i = 1; i < argc; i++) {
		string str = argv[i];
		if (str == "-n") {
			if (i + 1 != argc)i++; else {
				cout << "Wrong arguments" << endl;
				cin.get();
				return -1;
			}
			n = atoi(argv[i]);
			if (n < 1) {
				cout << "Wrong arguments" << endl;
				cin.get();
				return -1;
			}
		} else
		if (str == "-m") {
			if (i + 1 != argc)i++; else {
				cout << "Wrong arguments" << endl;
				cin.get();
				return -1;
			}
			m = atoi(argv[i]);
			if (m < 1) {
				cout << "Wrong arguments" << endl;
				cin.get();
				return -1;
			}
		} else 
		if (str.find(".txt") != string::npos) {
			filename = str;
		}
		else {
			cout << "Wrong arguments" << endl;
			cin.get();
			return -1;
		}
	}

	cout << "filename: " << filename << endl;
	cout << "-n: " << n << endl;
	cout << "-m " << m << endl;

	/*if (filename != "") {
		ifstream file(filename);
		string phrase;
		string str;
		while (getline(file, str)) {
			phrase = phrase + " " + str;
		}
		cout << phrase << endl;
	}*/


	vector<string> words = get_words(filename);
	vector<string> phrases = get_phrases(words, n);
	vector<pair<string, int>> sort_phrases = get_sphr(phrases);
	for (int i = 0; i < sort_phrases.size(); i++) {
		if (sort_phrases[i].second>=m)
			cout << sort_phrases[i].first << "    " << sort_phrases[i].second << endl;
	}
	cin.get();
	return 0;
}





vector<string> get_words(string filename) {
	string phrase;

	if (filename != "") {
		ifstream file(filename);
		string str;
		while (getline(file, str)) {
			phrase = phrase + " " + str;
		}
		//cout << phrase << endl;
	}
	else {
		cout << "Enter your phrase:" << endl;
		getline(cin, phrase);
	}

	char* c_phrase = (char*)malloc(sizeof(char)*phrase.size());
	for (int i = 0; i < phrase.size(); i++) {
		c_phrase[i] = phrase[i];
	}
	c_phrase[phrase.size()] = '\0';
	std::vector<string> words;
	int i = 0;
	string word;
	const char separator[] = " ";
	char *ptr = NULL;
	ptr = strtok(c_phrase, separator);
	while (ptr) {
		words.push_back(ptr);
		ptr = strtok(0, separator);
	}

	return words;
}

vector<string> get_phrases(vector<string> words, int n) {
	vector<string> phrases;
	for (int i = 0; i < words.size() - (n-1); i++) {
		string phrase;
		for (int j = 0; j < n; j++)
			phrase = phrase + words[i + j] + " ";
		phrases.push_back(phrase);
	}
	return phrases;

}

vector<pair<string, int>> get_sphr(vector<string> phrases) {
	map<string, int> phrases_map;
	for (int i = 0; i < phrases.size(); i++) {
		auto f_map = phrases_map.find(phrases[i]);
		if (f_map != phrases_map.end()) {
			f_map->second++;
		}
		phrases_map.insert(pair<string, int>(phrases[i], 1));
	}
	vector<pair<string, int>> fr_phrases;
	for (auto itr = phrases_map.begin(); itr != phrases_map.end(); itr++) {
		fr_phrases.push_back(*itr);
	}
	sort(fr_phrases.begin(), fr_phrases.end(), mySort);
	return fr_phrases;
}