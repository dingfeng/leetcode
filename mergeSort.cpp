#ifdef mergeSort
#include<iostream>
using namespace std;
void mergeSort(int list_backup[],int list[], int start, int end);
void merge(int list_backup[], int list[], int start, int mid ,int end);
void printArray(int list[], int len);


int main()
{
	int list[13] = {1,2,3,4,1,56,77,88,22,33,12,15,14};
	int list_backup[13];
	memset(list_backup, 0, 13);
	mergeSort(list_backup,list,0,12);
	printArray(list, 13);
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

void mergeSort(int list_backup[], int list[], int start, int end)
{
	if (end > start)
	{
		int mid = (start + end) / 2;
		mergeSort(list_backup, list, start, mid);
		mergeSort(list_backup, list, mid + 1, end);
		merge(list_backup,list,start,mid,end);
	}
}

void merge(int list_backup[], int list[], int start, int mid ,int end)
{
	if (end > start)
	{
		for (int i = start; i <= mid; ++i)
		{
			list_backup[i] = list[i];
		}
		for (int i = mid+1; i <= end; ++i)
		{
			list_backup[i] = list[end - (i - mid-1)];
		}
		int index = start;
		int i = start, j = end;
		while (i <= j)
		{
			if (list_backup[i] <= list_backup[j])
			{
				list[index++] = list_backup[i++];
			}
			else{
				list[index++] = list_backup[j--];
			}
		}
	}
}
#endif