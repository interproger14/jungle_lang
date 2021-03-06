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
string hv17;
string hv18;
string hv19;
string hv20;
Lexems hv21;
Lexems hv22;

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
			//cout << hv8 << endl;
			hv7++;
		}
	} else if(mode == 2) {
		hv7 = hv5 + 1;
		while(true) {
			hv14 = hv1[hv7];
			if(hv14 == ')') {
				break;
			}
			hv8 += hv14;
			//cout << hv8 << endl;
			hv7++;
		}
		hv7 = 0;
		if(hv8[hv7] == '"') {
			while(true) {
				if(hv8[hv7] == '"') {
					break;
				}
				hv18 += hv8[hv7];
				hv7++;
			}
			hv8 = hv18;
			hv18 = "";
			hv19 = "string";
		} else {
			hv19 = "number";
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
					cerr << "Wrong method name" << endl;
					return 1;
				}
				//cout << hv8 << endl;
				//cout << hv4 << endl;
				hv16 = 0;
				hv8 = "";
				hv9 = 0;
				hv10 = false;
			} else if(hv4 == '(') {
				hv5 = hv3;
				get_object(2);
				hv6.set_lexems(hv19, hv8);
				hv12.push_back(hv6);
				lexems_list.push_back(hv12);
				hv8 = "";
			} else {
				//cout << hv4 << endl;
			}
			hv3++;
		}

		hv3 = 0;
		hv2++;
	}

	while(hv11 < lexems_list.size()) {
		while(hv13 < lexems_list[hv11].size()) {
			if(lexems_list[hv11][hv13].type == "class" && lexems_list[hv11][hv13].token == "Console") {
				hv20 = lexems_list[hv11][hv13].token;
				// hv21.set_lexems(lexems_list[hv11][hv20].type, lexems_list[hv11][hv20].token);
				// hv22 = lexems_list[hv11][hv20];
				// cout << hv21.token << endl;
				// cout << hv22.type << endl;
				// cout << hv20;
				// cout << hv20 << endl;
				// cout << hv20 << endl;
				// cout << hv20 << endl;
				// if(1 > 0 && 1 > 0 && 1 > 0 && 1 > 0 && 1 > 0 && 1 > 0 && 1 > 0 && 1 > 0 && 1 > 0 && 1 > 0) {
				// 	cout << hv20 << "eee" << endl;
				// }

				// if(hv21 == "method" && hv22 == "out") {
			 	// 	cout << lexems_list[hv11][hv13 + 2].token;
				// }
			} else if(lexems_list[hv11][hv13].type == "method" && lexems_list[hv11][hv13].token == "out" && hv20 == "Console") {
				cout << "work!" << endl;
			}
			lexems_list[hv11][hv13].print_lexems();
			hv13++;
		}
		hv11++;
		cout << endl;
	}

	return 0;
}
