#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <vector>
#include "useful.h"

using namespace std;

int main(int argc, char* argv[]) {
  // handle wrong amount of arguments
  if (argc != 3) {
    cout << "Need two arguments (pattern then file to search in)" << endl;
    return 1;
  }
  // open the file
  ifstream search_file(argv[2]);
  if (!search_file) {
    cout << "File does not exist!" << endl;
    return 1;
  }
  // read file in
  string lines;
  // split to lines
  // create regex pattern
  // search all lines for pattern and add lines to found vector
  // print found vector
  return 0;
}

