//
//  WordFrequency.cpp
//  词频统计
//
//  Created by wenyiqian on 2018/9/10.
//  Copyright © 2018年 ding. All rights reserved.
//

#include "WordFrequency.h"
#include "CharCount.h"

vpsi WordsVec;


void WordsSort( int num)
{
	for (msi::iterator iter = WordsMap.begin(); iter != WordsMap.end(); iter++)
	{
		WordsVec.push_back(pair<string, int>(iter->first, iter->second));
	}
	vpsi::iterator vit;
	for (int i = 0; i < num; i++) {
		psi max = WordsVec[i];
		int pos, flag;
		for (vit = WordsVec.begin() + i, pos = i; vit != WordsVec.end(); vit++, pos++) {
			if (vit->second > max.second) { //改变max的值
				max.first = vit->first;
				max.second = vit->second;
				flag = pos;
			};
		}
		swap(WordsVec[i], WordsVec[flag]);
	}
}