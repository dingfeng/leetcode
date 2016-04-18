#ifdef testcpp
#include <iostream>
#include<string>
#include<fstream>
using namespace std;
void main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	
	string word;
	int newLineCount = 1;
	int wordCount = 0;
	int byteCount = 0;
	while (in >> word)
	{
		++wordCount;
	}
	in.clear();
	in.seekg(0);
	while (in)
	{
		if (in.get() == '\n')
		{
			++newLineCount;
		}
		++byteCount;
	}
	cout << newLineCount << " " << wordCount << " " << byteCount << " " << argv[1] << endl;
	int i = 0;
	cout << sizeof(int) << typeid(i).name << endl;
	cin.get();
	cin.get();
}
#endif