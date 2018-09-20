#pragma once

#pragma once

#include <stdio.h>
#include <fstream>
#include <cstring>
#include <regex>
#include <map>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define pii pair<int, int>
#define msi unordered_map<string, int>
#define psi pair<string, int>
#define vpsi vector<psi>

extern msi WordsMap;
extern vpsi WordsVec;

int CharCount(const char *filename);