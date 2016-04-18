#ifdef KMP
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int * getNextArray(string & str);
int nextValue(string &str, int nextArray[], int p,bool visited[]);
void printArray(int * list,int len);
int matchCount(string &match, string & matched);
#define forItr(i,size) for(int i=0;i<size;++i)

int main()
{
	string str0,str1;
	int num = 0;
	cin >> num;
	forItr(i, num)
	{
		cin >> str0 >> str1;
		cout << matchCount(str0, str1) << endl;
	}
}

int matchCount(string &match, string & matched)
{
	int * nextArray = getNextArray(match);
	int start = 0;
	int end = 0;
	int count = 0;
	while (matched.length() - start >= match.length())
	{
		bool matchOne = true;
		if (match[end - start] == matched[end])
		{
			++end;
		}
		else
		{
			start = end - nextArray[end - start];
			if (start>end)
			{
				end = start;
			}
		}
		if (end - start == match.length())
		{
			++count;
			start = end - nextArray[match.length()];
		}
	}
	delete[] nextArray;
	return count;
}


void printArray(int * list, int len)
{
	forItr(i, len)
	{
		cout << list[i];
		if (i != len - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
}

int * getNextArray(string & str)
{
	int * nextArray = new int[str.length() + 1];
	bool * visited = new bool[str.length() + 1];
	memset(visited, 0, sizeof(visited[0])*str.length() + 1);
	visited[0] = visited[1] = true;
	nextArray[0] = -1;
	nextArray[1] = 0; 
	nextValue(str,nextArray,str.length(),visited);
	delete[] visited;
	return nextArray;
}

int nextValue(string &str, int nextArray[], int p, bool visited[])
{
	if (!visited[p])
	{
		if (str[p - 1] == str[nextValue(str, nextArray, p - 1, visited)])
		{
			nextArray[p] = nextArray[p - 1] + 1;
			return nextArray[p];
		}
		else
		{
			int next_value_temp = nextValue(str, nextArray, nextArray[p - 1], visited);
			while (next_value_temp != -1)
			{
				if (str[p - 1] == str[next_value_temp])
				{
					nextArray[p] = next_value_temp + 1;
					break;
				}
				next_value_temp = nextValue(str, nextArray, next_value_temp, visited);
			}
			if (next_value_temp == -1)
			{
				nextArray[p] = 0;
			}
		}
	}
	visited[p] = true;
	return nextArray[p];
}
#endif

