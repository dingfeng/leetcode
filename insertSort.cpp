#ifdef insertSort
#include<iostream>
using namespace std;
void insertSort(int list[], int len);
void printArray(int list[], int len);
int main()
{
	int list[13] = { 1, 2, 3, 4, 1, 56, 77, 88, 22, 33, 12, 15, 14 };
	insertSort(list, 13);
	printArray(list,13);
	cin.get();
}


void printArray(int list[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << list[i] << ",";
	}
	cout << endl;
}

void insertSort(int list[], int len)
{
	for (int i = 1; i < len; ++i)
	{
		int tmp = list[i];
		int j = i;
		while (j > 0 && list[j-1]>tmp)
		{
			list[j] = list[j - 1];
			--j;
		}
		list[j] = tmp;
	}
}
#endif