#include <gtest/gtest.h>
#include "../lab1/funct.cpp"


	int main(int argc, char* argv[]) {
		::testing::InitGoogleTest(&argc, argv);
		auto ret = RUN_ALL_TESTS();
		cin.get();
		return ret;
	}

	TEST(lab1, get_words) {
		vector<string> words_exp = { "i","hate","this" };
		vector <string> words_real = get_words("i hate this");
		for (int i = 0; i < words_real.size(); i++)
			EXPECT_EQ(words_exp[i], words_real[i]);
	}

	TEST(lab1, get_words_empty_input) {
		vector <string> words_real = get_words("");
		EXPECT_EQ(0, words_real.size());
	}


	TEST(lab1, get_phrases) {
		vector <string> phrase_exp = { "i hate", "hate this" };
		vector <string> words_real = { "i hate this" };
		int n = 2;
		vector<string> phrase_real = get_phrases(words_real, n);
		for (int i = 0; i < phrase_real.size(); i++) {
			EXPECT_EQ(phrase_exp[i], phrase_real[i]);
		} 
	}

	TEST(lab1, get_phrases_negative_n) {
		int n = -100;
		vector <string> words_real = { "i hate this" };
		vector<string> phrases = get_phrases(words_real,n);
		EXPECT_EQ(0, phrases.size());
	}

	TEST(lab1, get_phrases_zero_n) {
		int n = 0;
		vector <string> words_real = { "i hate this" };
		vector<string> phrases = get_phrases(words_real, n);
		EXPECT_EQ(0, phrases.size());
	}

	TEST(lab1, get_phrases_too_big_n) {
		int n = 100;
		vector <string> words_real = { "i hate this" };
		vector<string> phrases = get_phrases(words_real, n);
		EXPECT_EQ(0, phrases.size());
	}

	TEST(lab1, get_sphr) {
		vector <string> phrases_real = { "wanna gonna", "gonna wanna", "wanna gonna"};
		vector<pair<string, int>> exp_vector = { {"wanna gonna",2},{"gonna wanna",1}};
		vector<pair<string, int>> real_vector = get_sphr(phrases_real);
		for (int i = 0; i < real_vector.size(); i++) {
			EXPECT_EQ(exp_vector[i].first,real_vector[i].first);
			EXPECT_EQ(exp_vector[i].second, real_vector[i].second);
		}
		
	}

	TEST(lab1, get_sphr_empty) {
		vector <string> phrases_real;
		vector<pair<string, int>> real_vector = get_sphr(phrases_real);
		EXPECT_EQ(0, real_vector.size());

	}
