#ifdef quickSort
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
void quickSort(int list[], int start,int end);
void printArray(int list[], int len);
int main()
{
	int M[] = {1,2,5,677,3,4,12,3,2,5,61,23,4};
	printArray(M, 13);
	cout << "array size: " << sizeof(M) / sizeof(M[0]) << endl;
	quickSort(M, 0, sizeof(M)/sizeof(M[0])-1);
	printArray(M, sizeof(M) / sizeof(M[0]));
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


void quickSort(int list[], int start, int end)
{
	if (start < end)
	{
		int pivot = list[start];
		int index = start;
		for (int i = start + 1; i <= end; ++i)
		{
			if (list[i] < pivot)
			{
				swap(list[++index], list[i]);
			}
		}
		swap(list[start], list[index]);
		quickSort(list, start, index - 1);
		quickSort(list, index + 1, end);
	}
}

void swap(int & a, int &b)
{
	if (a == b) return;
	int temp = a;
	a = b;
	b = temp;
}

#endif quickSort