
#include"CharCount.h"
int CharNum;
msi WordsMap;

int CharCount(const char *filename)
{
	ifstream ifs(filename);
	char charTemp;
	string wordtemp;
	int sum = 0;
	int state = 0;
	while ((charTemp = ifs.get()) != EOF)
	{
		CharNum++;
		if (charTemp >= 65 && charTemp <= 90)//大写转化为小写
			charTemp = charTemp + 32;
		switch (state)
		{
		case 0:
			if (charTemp >= 97 && charTemp <= 122) {
				wordtemp = wordtemp + charTemp;
				state = 1;
			}
			break;
		case 1:
			if (charTemp >= 97 && charTemp <= 122) {
				wordtemp = wordtemp + charTemp;
				state = 2;
			}
			else
			{
				state = 0;
				wordtemp = "";
			}
			break;
		case 2:
			if (charTemp >= 97 && charTemp <= 122) {
				wordtemp = wordtemp + charTemp;
				state = 3;
			}
			else
			{
				state = 0;
				wordtemp = "";
			}
			break;
		case 3:
			if (charTemp >= 97 && charTemp <= 122) {
				wordtemp = wordtemp + charTemp;
				state = 4;
			}
			else
			{
				state = 0;
				wordtemp = "";
			}
			break;
		case 4:
			if (charTemp >= 97 && charTemp <= 122 || (charTemp >= '0'&&charTemp <= '9')) {
				wordtemp = wordtemp + charTemp;
			}
			else
			{
				WordsMap[wordtemp] ++;
				state = 0;
				wordtemp = "";
			}
			break;
		}
	}
	if (state == 4) {
		WordsMap[wordtemp] ++;
	}
	ifs.close();
	ifs.clear();
	return CharNum;
}
