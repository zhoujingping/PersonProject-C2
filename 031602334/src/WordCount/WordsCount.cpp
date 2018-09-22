//
//  WordsCount.cpp
//  词频统计
//
//  Created by wenyiqian on 2018/9/9.
//  Copyright 2018年 ding. All rights reserved.
//

#include "WordsCount.h"
#include "CharCount.h"

long WordsCount()
{
	int WordsNum = 0;
	for (msi::iterator iter = WordsMap.begin(); iter != WordsMap.end(); iter++) {
		WordsNum += iter->second;
	}
	return WordsNum;
}