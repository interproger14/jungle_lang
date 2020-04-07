#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "main.h"

using namespace std;

vector<Lexems> lexems_list;
vector<vector<string>> dictionary_classes = {{"Console", "out", "in"}};
vector<string> w_s;
ifstream source_file("test.jngl");
string hv1;
int hv2 = 0;
int hv3 = 0;
char hv4;
int hv5;
Lexems hv6;
string hv8 = "";
int hv9 = 0;
bool hv10 = false;
int hv11 = 0;


void get_command() {
	int hv7 = 0;
	while(hv7 != hv5) {
		hv8 += hv1[hv7];
		hv7++;
	}
}

int main() {
	while(getline(source_file, hv1)) {
		w_s.push_back(hv1);
	}

	while(hv2 < w_s.size()) {
		hv1 = w_s[hv2];
		while(hv3 < hv1.size()) {
			hv4 = hv1[hv3];
			if(hv4 == '.') {
				hv5 = hv3;
				get_command();
				while(hv9 < dictionary_classes.size()) {
					if(dictionary_classes[hv9][0] == hv8) {
						hv6.set_lexems("class", hv8);
						lexems_list.push_back(hv6);
						hv10 = true;
						break;
					}
					hv9++;
				}
				if(!hv10) {
					cerr << "Wrong class name at line " << hv2 + 1 << endl;
					return 1;
				}
				cout << hv8 << endl;
				cout << hv4 << endl;
				hv8 = "";
				hv9 = 0;
				hv10 = false;
			} else {
				cout << hv4 << endl;
			}
			hv3++;
		}

		hv3 = 0;
		hv2++;
	}

	while(hv11 < lexems_list.size()) {
		lexems_list[hv11].print_lexems();
		hv11++;
	}
	return 0;
}
