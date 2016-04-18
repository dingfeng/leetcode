#ifdef classTes1
#include<iostream>
#include<cstring>
using namespace std;
int atoi(char * str);
void printNineNineTable();
int main(int argc, char* argv[])
{
	

}

void printNineNineTable()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << j << "x" << i << "=" << i*j << "\t";
		}
		cout << endl;
	}
	cin.get();
}


int atoi(char * str)
{
	int index = 0;
	int total=0;
	while (str[index])
	{
		total += str[index]-'0';
		if (str[index + 1])
		{
			total *= 10;
		}
		index++;
	}
	return total;
}
#endif