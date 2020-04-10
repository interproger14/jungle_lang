#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "main.h"

using namespace std;

vector<vector<Lexems>> lexems_list;
vector<vector<string>> dictionary_classes = {{"Console", "out", "in"}};
vector<string> w_s;
ifstream source_file("test.jngl");
string hv1;
int hv2 = 0;
int hv3 = 0;
char hv4;
int hv5;
Lexems hv6;
int hv7 = 0;
string hv8 = "";
int hv9 = 0;
bool hv10 = false;
int hv11 = 0;
vector<Lexems> hv12;
int hv13 = 0;
char hv14;
string hv15;
int hv16 = 0;

void get_object(int mode) {
	if(mode == 0) {
		hv7 = 0;
		while(hv7 != hv5) {
			hv8 += hv1[hv7];
			hv7++;
		}
	} else if(mode == 1) {
		hv7 = hv5 + 1;
		while(true) {
			hv14 = hv1[hv7];
			if(hv14 == '(') {
				break;
			}
			hv8 += hv14;
			cout << hv8 << endl;
			hv7++;
		}
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
				get_object(0);
				while(hv9 < dictionary_classes.size()) {
					if(dictionary_classes[hv9][0] == hv8) {
						hv6.set_lexems("class", hv8);
						hv12.push_back(hv6);
						lexems_list.push_back(hv12);
						hv10 = true;
						break;
					}
					hv9++;
				}
				if(!hv10) {
					cerr << "Wrong class name at line " << hv2 + 1 << endl;
					return 1;
				}
				hv8 = "";
				hv9 = 1;
				hv10 = false;
				get_object(1);
				while(hv16 < dictionary_classes.size()) {
					while(hv9 < dictionary_classes[hv16].size()) {
						if(dictionary_classes[hv16][hv9] == hv8) {
							hv6.set_lexems("method", hv8);
							hv12.push_back(hv6);
							lexems_list.push_back(hv12);
							hv10 = true;
							break;
						}
						hv9++;
					}
					hv16++;
				}
				if(!hv10) {
					cerr << "Wrong method name at line " << hv2 + 1 << endl;
					return 1;
				}
				cout << hv8 << endl;
				cout << hv4 << endl;
				hv16 = 0;
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
		while(hv13 < lexems_list[hv11].size()) {
			lexems_list[hv11][hv13].print_lexems();
			hv13++;
		}
		hv11++;
		cout << endl;
	}

	return 0;
}
