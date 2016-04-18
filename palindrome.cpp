#ifdef PALINDROME
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int getMaxSubPalindrome(string & str);
int getMaxLenMid(const int record[],const char * str, int mid, int maxRight, int len);
#define forItr(i,size) for(int i=0;i<size;++i)
void print(int list[], int size);
int main()
{
    int n;
	cin >> n;
	string str;
	forItr(i, n)
	{
		cin >> str;
		int len = getMaxSubPalindrome(str);
		cout <<len<< endl;
	}
	/*string strs[3] = {"abababa", "aaaabaa" ,"acacdas"};
	forItr(i, 3)
	{
		cout << getMaxSubPalindrome(strs[i])<<endl;
	}
	cin.get();
	cin.get();*/
	/*LARGE_INTEGER m_nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceCounter(&m_nBeginTime); // 获取时钟计数  */
	
	/*QueryPerformanceCounter(&nEndTime);
	cout << nEndTime.QuadPart - m_nBeginTime.QuadPart<< endl; 
	cin.get();*/
	/*string str = "aaaabbbbbb";
	cout << getMaxSubPalindrome(str)<<endl;
	cin.get();*/
}

int getMaxSubPalindrome(string & str)
{
	int max = 1;
	const char* c_str=str.c_str();
	int str_len = str.length();
	int * palind_len_record = NULL;
	char fill_char = 0;  //填充字符
	int maxRight = 0;
	int maxRightValue = 0;
		int new_len = str_len * 2 - 1;
		palind_len_record = new int[new_len];
		memset(palind_len_record, 0, sizeof(int) * new_len);
		char * new_str = new char[new_len];
		forItr(i, str_len)
		{
			new_str[i * 2] = c_str[i];
			if (i != str_len - 1)
			{
				new_str[i * 2 + 1] = fill_char;
			}
		}

		forItr(i, new_len)
		{
			int maxLenMid = getMaxLenMid(palind_len_record, new_str, i, maxRight,new_len);
			palind_len_record[i] = maxLenMid;
			int true_len = maxLenMid / 2;
			if ((i + maxLenMid / 2) % 2 == 0)
			{
				++true_len;
			}
			if (true_len > max)
			{
				max = true_len;
			}
			if ((i + maxLenMid / 2) > maxRightValue)
			{
				maxRight = i;
			}

		}
		delete[] new_str;
	if (palind_len_record != NULL)
	{
		delete[] palind_len_record;
	}
	return max;
}

void print(int list[],int size)
{
	cout << "list: ";
	forItr(i, size)
	{
		cout << list[i];
		if (i != size - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
}

int getMaxLenMid(const int record[], const char * str, int mid, int maxRight, int len)
{

	int j = maxRight;
	int min = 1;
	if (j != 0){
		int min0 = record[2 * j - mid];
	    int min1 = record[j] - 2 * (mid - j);
	    min = min0 < min1 ? min0 : min1;
		if (min <= 0)
		{
			min = 1;
		}
    }
	
	int right = mid + min / 2 + 1;
	int left = mid - min / 2 - 1;
	int count = min;
	while (true)
	{
		if (right == len || left == -1||str[left] != str[right])
		{
			break;
		}
		count += 2;
		--left;
		++right;
	}
	return count;
}
#endif