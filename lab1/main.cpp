#include "main.h"
using namespace std;
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
		}
		else		
		if (str.find(".") != string::npos) {
			int counter = 0;
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == '.')counter++;
			}
			if (counter > 1) {
				cout << "Wrong filename" << endl;
				cin.get();
				return -1;
			}
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


	string phrase;

	if (filename != "") {
		ifstream file(filename);
		if (file.is_open()==0) {
			cout << "Can't open this file: " << filename << endl;
			cin.get();
			return -1;
		}
		string str;
		while (getline(file, str)) {
			phrase = phrase + " " + str;
		}
		//cout << phrase << endl;
	}
	else {
		cout << "Enter your phrase:" << endl;
		string str;
		do {
			getline(cin, str);
			phrase = phrase + " " + str;
		} while (cin.get() != '\n');
	}


	vector<string> words = get_words(phrase);
	vector<string> phrases = get_phrases(words, n);
	vector<pair<string, int>> sort_phrases = get_sphr(phrases);
	for (int i = 0; i < sort_phrases.size(); i++) {
		if (sort_phrases[i].second>=m)
			cout << sort_phrases[i].first << "    " << sort_phrases[i].second << endl;
	}
	cin.get();
	return 0;
}



