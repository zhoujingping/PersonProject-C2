#include<stdio.h>
#include <iostream>
#include <fstream>
#include "CharNum.h"
#include "LineNum.h"
#include"WordNum.h"
#include "Word_Fre.h"
using namespace std;


int main(int argc, char *argv[])
{


	int Char_Number = CharNum(argv[1]);
	int Lines_Number = LineNum(argv[1]);
	int Words_Number = WordNum(argv[1]);

	printf("characters: %d\n", Char_Number);
	printf("words: %d\n", Words_Number);
	printf("lines: %d\n", Lines_Number);


	Word_Fre(argv[1]);			


	return 0;
}