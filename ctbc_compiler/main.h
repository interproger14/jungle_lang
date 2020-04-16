#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Lexems {
	string type;
	string token;

	void print_lexems() {
		cout << type << ": " << token << endl;
	}

	void set_lexems(string ty, string tok) {
		type = ty;
		token = tok;
	}
};

struct method_dict {
	string mt;
	vector<vector<Lexems>> coms;

	 
};

struct class_dict {
	string cl;
	vector<method_dict> mth;

	void set(string c, vector<method_dict> mt) {
		cl = c;
		mth = mt;
	}
};

#endif
