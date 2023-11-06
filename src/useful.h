#pragma once
#include <string>
#include <vector>

using namespace std;

vector<string> splitStr(string input, char split_char='\n');

string formatVec(vector<string>* vec, string join_str=", ");

