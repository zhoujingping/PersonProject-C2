//
//  main.cpp
//  词频统计
//
//  Created by wenyiqian on 2018/9/8.
//  Copyright © 2018年 ding. All rights reserved.
//


#include <iostream>
#include <cstring>
#include <map>
#include <fstream>
#include <time.h>
#include <cstdio>
#include "CharCount.h"
#include "WordsCount.h"
#include "LinesCount.h"
#include "WordFrequency.h"

using namespace std;

int main(int argc, const char * argv[]) {

	//double begintime, endtime;
	//begintime = clock();	//计时开始
	
	const char *FileName = argv[1];
	const char *OutName = "result.txt";
	ifstream file;
	try
	{
		file.open(argv[1], ios::in);
		if (!file) throw string("输入文件错误\n");
		if (argc > 2) throw string("输入参数过多\n");
		file.close();

		int CharNum = CharCount(FileName);
		long WordsNum = WordsCount( );
		long LinesNum = LinesCount(FileName);
		int Num = (WordsNum < 10) ? WordsNum : 10;
		WordsSort(Num);
		ofstream out(OutName);
		if (!out) throw string("输出文件无法打开\n");
		out << "characters: " << CharNum << endl;
		out << "words: " << WordsNum << endl;
		out << "lines: " << LinesNum << endl;
		for (vpsi::iterator iter = WordsVec.begin(); iter != (WordsVec.begin() + Num); ++iter)
		{
			out << "<" << iter->first << ">: " << iter->second << endl;
		}
		out.close();
	}
	catch(string R)
	{
		cout << R << endl;
	}
		//endtime = clock();	//计时结束
		//out << "RUNNING TIME:" << (endtime) << "-" << (begintime) << "=" << endtime - begintime << "ms" << endl;
		//printf("\n\nRunning Time：%fms\n", endtime - begintime);

	return 0;
}