#pragma once
#include "pch.h"
#include <iostream>
#include<map>
#include<string>
using namespace std;
class Zsn
{	
	private:
		string fname;
	public:

		Zsn(string name);
		~Zsn() {};
		int charact();
		int line();
		int word();
		void top10();
};