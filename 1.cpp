#ifdef n2
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> numMap;
void initNumMap();
#define forItr(i,size) for(int j=i;j<size;++j)
void getPossibleNum(vector<int> & inNums, vector<int> & possi);
bool sub(vector<int> & small,vector<int> & big);
bool has(vector<int> vec, int num);
void  getLessCount(vector<vector<int>> &  vv, int index,int num, int total,int & lessCount);
int tenMap[7] = {1,10,100,1000,10000,100000,100000};
void printVector(vector<int> & vec);
int chToInt(char ch);
bool isNum(char ch);
int main() 
{
	initNumMap();
	int count;
	int k,n;
	cin >> count;
	char ch;


	forItr(0, count)
	{
		vector<vector<int>> vv;
		cin >> k >> n;
		cin.get();
		forItr(0, k)
		{
			vector<int> vec;
			vv.push_back(vec);
			do
			{
				ch = cin.get();
				if (isNum(ch))
				{
					vv[j].push_back(chToInt(ch));
				}
			} while (ch != '\n');
			//printVector(vv[j]);
		}

		vector<vector<int>> vv1;
		forItr(0, vv.size())
		{
			vector<int> vec;
			vv1.push_back(vec);
			getPossibleNum(vv[j], vv1[j]);
		}

		int lessCount = 0;
		getLessCount(vv1, 0, n, 0, lessCount);
		cout << lessCount << endl;

	}
	 /* vector<vector<int>> vv;
	  forItr(0, 3)
	  {
		  vector<int> vec;
		  vv.push_back(vec);
	  }
	  vv[0].push_back(3);
	  vv[0].push_back(1);

	  vv[1].push_back(4);
	  vv[1].push_back(1);
	  vv[1].push_back(5);

	  vv[2].push_back(6);
	  vv[2].push_back(1);
	  vv[2].push_back(7);
	  vv[2].push_back(5);
	  */
	//}
		

}

int chToInt(char ch)
{
	return ch + (0 - '0');
}

bool isNum(char ch)
{
	if (ch <= '9' && ch >= '0')
	{
		return true;
	}
	return false;
}

void getLessCount(vector<vector<int>>  & vv, int index, int num, int total, int & lessCount)
{
	if (index == vv.size())
	{
		//cout << total << endl;
		if (total < num)
		{
			++lessCount;
		}
		return;
	}
	vector<int> & vec = vv[vv.size()-1-index];
	int size = vec.size();
	forItr(0, size)
	{
		int totalTmp = total;
		totalTmp += vec[j] * tenMap[index];
		getLessCount(vv, index + 1, num, totalTmp, lessCount);
	}
}

void printVector(vector<int> & vec)
{
	auto end = vec.end();
	for (auto tmp = vec.begin(); tmp != end; ++tmp)
	{
		cout << *tmp << " ";
	}
	cout << endl;
}


void getPossibleNum(vector<int> & inNums, vector<int> & possi)
{
	forItr(0, 10)
	{
		if (sub(inNums, numMap[j]))
		{
			possi.push_back(j);
		}
	}
}

bool sub(vector<int> & small, vector<int> & big)
{
	if (small.size() > big.size() )
	{
		return false;
	}
	auto end = small;
	for (auto tmp = small.begin(); tmp !=small.end(); ++tmp)
	{
		if (!has(big, *tmp))
		{
			return false;
		}
	}
	return true;
}

bool has(vector<int> vec, int num)
{
	auto end = vec;
	for (auto tmp = vec.begin(); tmp != vec.end(); ++tmp)
	{
		if (*tmp == num)
		{
			return true;
		}
	}
	return false;
}

void initNumMap()
{
	forItr(0, 10)
	{
		vector<int> vec;
		numMap.push_back(vec);
	}
	numMap[0].push_back(1);
	numMap[0].push_back(2);
	numMap[0].push_back(3);
	numMap[0].push_back(5);
	numMap[0].push_back(6);
	numMap[0].push_back(7);

	numMap[2].push_back(1);
	numMap[2].push_back(3);
	numMap[2].push_back(4);
	numMap[2].push_back(5);
	numMap[2].push_back(7);

	numMap[1].push_back(3);
	numMap[1].push_back(6);

	numMap[3].push_back(1);
	numMap[3].push_back(3);
	numMap[3].push_back(4);
	numMap[3].push_back(6);
	numMap[3].push_back(7);

	numMap[4].push_back(2);
	numMap[4].push_back(4);
	numMap[4].push_back(3);
	numMap[4].push_back(6);

	numMap[5].push_back(1);
	numMap[5].push_back(2);
	numMap[5].push_back(4);
	numMap[5].push_back(6);
	numMap[5].push_back(7);

	numMap[6].push_back(1);
	numMap[6].push_back(2);
	numMap[6].push_back(4);
	numMap[6].push_back(5);
	numMap[6].push_back(6);
	numMap[6].push_back(7);

	numMap[7].push_back(1);
	numMap[7].push_back(3);
	numMap[7].push_back(6);

	numMap[8].push_back(1);
	numMap[8].push_back(2);
	numMap[8].push_back(3);
	numMap[8].push_back(4);
	numMap[8].push_back(5);
	numMap[8].push_back(6);
	numMap[8].push_back(7);

	numMap[9].push_back(1);
	numMap[9].push_back(2);
	numMap[9].push_back(3);
	numMap[9].push_back(4);
	numMap[9].push_back(6);
	numMap[9].push_back(7);
}

#endif