#include<iostream>
using namespace std;

void heapSort(int list[], int len);
void siftDown(int list[], int start,int end);
void swap(int &a, int &b);
void printArray(int list[], int len);
class A
{
	virtual void func()
	{

	}
};
int main()
{ 
	cout << sizeof(A) << endl;
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

void heapSort(int list[], int len)
{
	int end = (len - 1 - 1) / 2;
	for (int i = end; i >= 0; --i)
	{
		siftDown(list,i,len-1);
	}
	for (int i = 1; i < len; ++i)
	{
		swap(list[0],list[len-i]);
		siftDown(list,0,len-i-1);
	}
}

void swap(int &a, int &b)
{
	if (a == b)
	{
		return;
	}
	int temp = a;
	a = b;
	b = temp;
}

void siftDown(int list[], int start, int end)
{
	int temp = list[start];
	int i = start;
	int j = i * 2 + 1;
	while (j <= end)
	{
		if (j!=end && list[j+1]>list[j])
		{
			++j;
		}
		if (list[j] > temp)
		{
			list[i] = list[j];
			i = j;
			j = i * 2 + 1;
		}
		else
		{
			break;
		}
	}
	list[i] = temp;
}
