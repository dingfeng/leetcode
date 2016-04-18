#ifdef NINEGONG
#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 3;
int** rotateRight(int ** matrix);
int** rotateLeft(int ** matrix);
int** mirror1(int ** matrix);
int** mirror2(int ** matrix);
int** mirror3(int ** matrix);
int** mirror4(int ** matrix);
int** newMatrix();
bool isSame(int ** matrix0, int ** matrix1);
vector<int**> vec;
void addMatrix(int ** matrix);
bool hasMatrix(int ** matrix);
void tryAdd(int ** matrix);
void printMatrix(int ** matrix);
int** findMatrix(int(*matrix)[SIZE]);
bool match(int(*matrix0)[SIZE], int ** standard);
#define forItr(i,size) for(int i=0;i<size;++i)
int main_nine()
{
	int oneMatrixArray[SIZE][SIZE] = {
			{4,9,2},
			{3,5,7},
			{8,1,6}
	};
	int ** firstMatrix = new int * [SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		firstMatrix[i] = new int[SIZE];
	}
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			firstMatrix[i][j] = oneMatrixArray[i][j];
		}
	}
	/*printMatrix(rotateRight(firstMatrix));
	printMatrix(rotateLeft(firstMatrix));
	printMatrix(mirror1(firstMatrix));
	printMatrix(mirror2(firstMatrix));
	printMatrix(mirror3(firstMatrix));
	printMatrix(mirror4(firstMatrix));*/
	addMatrix(firstMatrix);
	int inputMatrix[SIZE][SIZE];
	forItr(i,3)
	{
		forItr (j, 3)
		{
			cin >> inputMatrix[i][j];
		}
	}
	int ** matchedMatrix = findMatrix(inputMatrix);
	if (matchedMatrix == NULL)
	{
		cout << "Too Many" << endl;
	}
	else
	{
		forItr(i, SIZE)
		{
			forItr(j, SIZE)
			{
				cout << matchedMatrix[i][j];
				if (j != 2)
				{
					cout << " ";
				}
			}
			cout << endl;
		}
	}
}

bool match(int (*matrix0)[SIZE], int ** standard)
{
	bool isMatch = true;
	forItr(i, SIZE)
	{
		forItr(j, SIZE)
		{
			if (matrix0[i][j] != 0 && matrix0[i][j] != standard[i][j])
			{
				isMatch = false;
				break;
			}
		}
	}
	return isMatch;
}

int** findMatrix(int(*matrix)[SIZE])
{
	int ** matched = NULL;
	auto end = vec.end();
	for (auto itr = vec.begin(); itr != end; ++itr)
	{
		int ** vecMatrix = *itr;
		if (match(matrix, vecMatrix))
		{
			if (matched == NULL)
			{
				matched = vecMatrix;
			}
			else
			{
				return NULL;
			}
		}
	}
	return matched;
}



void printMatrix(int ** matrix)
{
	cout << endl;
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}
void addMatrix(int ** matrix)
{
	vec.push_back(matrix);
	int** rotateRightMatrix = rotateRight(matrix);
	tryAdd(rotateRightMatrix);
	int** rotateLeftMatrix = rotateLeft(matrix);
	tryAdd(rotateLeftMatrix);
	int** mirror1Matrix = mirror1(matrix);
	tryAdd(mirror1Matrix);
	int** mirror2Matrix = mirror2(matrix);
	tryAdd(mirror2Matrix);
	int** mirror3Matrix = mirror3(matrix);
	tryAdd(mirror3Matrix);
	int** mirror4Matrix = mirror4(matrix);
	tryAdd(mirror4Matrix);

}
void tryAdd(int ** matrix)
{
	if (!hasMatrix(matrix))
	{
		addMatrix(matrix);
	}
	else
	{
		for (int i = 0; i < SIZE; ++i)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}


int** rotateRight(int ** matrix)
{
	int** resultMatrix = newMatrix();
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			resultMatrix[i][j] = matrix[j][2-i];
		}
	}
	return resultMatrix;
}
int** rotateLeft(int ** matrix)
{
	int** resultMatrix = newMatrix();
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			resultMatrix[i][j] = matrix[2-j][i];
		}
	}
	return resultMatrix;
}
int** mirror1(int ** matrix)
{
	int** resultMatrix = newMatrix();
	for (int i = 0; i < SIZE; ++i)
	{
		resultMatrix[0][i] = matrix[2][i];
		resultMatrix[2][i] = matrix[0][i];
		resultMatrix[1][i] = matrix[1][i];
	}
	return resultMatrix;
}
int** mirror2(int ** matrix)
{
	int** resultMatrix = newMatrix();
	for (int i = 0; i < SIZE; ++i)
	{
		resultMatrix[i][0] = matrix[i][2];
		resultMatrix[i][2] = matrix[i][0];
		resultMatrix[i][1] = matrix[i][1];
	}
	return resultMatrix;
}
int** mirror3(int ** matrix)
{
	int** resultMatrix = newMatrix();
	for (int i = 0; i <SIZE;++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if ((i - 1) != ( (j - 1) * (-1)))
			{
				resultMatrix[i][j] = matrix[2-j][2-i];
			}
			else
			{
				resultMatrix[i][j] = matrix[i][j];
			}
		}
	}
	return resultMatrix;
}

int** mirror4(int ** matrix)
{
	int** resultMatrix = newMatrix();
	for (int i = 0; i <SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			resultMatrix[i][j] = matrix[j][i];
		}
	}
	return resultMatrix;
}

int** newMatrix()
{
	int** resultMatrix = new int*[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		resultMatrix[i] = new int[SIZE];
	}
	return resultMatrix;
}

bool hasMatrix(int ** matrix)
{
	bool result = false;
	auto end = vec.end();
	for (auto itr = vec.begin(); itr != vec.end(); itr++)
	{
		int ** vecMatrix =  *itr;
		if (isSame(matrix, vecMatrix))
		{
			result = true;
			break;
		}
	}
	return result;
}

bool isSame(int ** matrix0, int ** matrix1)
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (matrix0[i][j] != matrix1[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
#endif
