#ifdef cirsscross_sum
#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
using namespace std;
long crisscross_sum(long value, vector<unsigned char> & decimal);
long crisscross_sum(long value);
int digitsNum(long long num);
#define forBetween(start,end) for( long i=start;i<=end;++i)
#define forItr(i,size) for(int i=0;i<size;++i)
long long  total = 0;
long long  sum;
long long  max;
long long min;
void add(vector<unsigned char> & decimal, long long llNum, int digit, int dir, bool isToAdd);
long long toLongLongValue(vector<unsigned char> & decimal);
void printVector(vector<unsigned char> & vec);
int getBitCount(vector<unsigned char> & vec);
long long pow10(int exp);

int main()
{
	long long num0 , num1 , num2 ;
	//long long num0 = 4344, num1 = 9999, num2 = 3;
	cin >> num0 >> num1 >> num2;
	min = num0;
	max = num1;
	sum = num2;
	int digitNum = digitsNum(num1);
	vector<unsigned char> decimal0;
	for (int i = 0; i < digitNum; ++i)
	{
		decimal0.push_back(0);
	}

	'
		; int count = 1;
	forBetween(num0, num1)
	{
		long sum = crisscross_sum(i,decimal0);
		
		if (sum == num2)
		{
			add(decimal0, i, 0, 1 ,true);
			add(decimal0, i, 0, 0, false);
			i = pow10(getBitCount(decimal0))-1;
			
			/*
			cout << i << endl;
			total += i;*/
		}
	}
	long modNum = pow10(9);
	modNum += 7;
	total %= modNum;
	cout << total << endl;
	
}

void printVector(vector<unsigned char> & vec)
{
	auto end = vec.end();
	for (auto tmp = vec.begin(); tmp != end; ++tmp)
	{
		cout << (int)*tmp << " ";
	}
	cout << endl;
}

void add(vector<unsigned char> & decimal, long long llNum,int digit,int dir,bool isToAdd)
{
	if (isToAdd)
	{
		total += llNum;
		//cout  << llNum << endl;
	}
	if (digit == decimal.size() - 1)
	{
		return;
	}
	int decimalBitCount = getBitCount(decimal);
	int digitValue = decimal[decimal.size() - 1 - digit];
	if (dir == 1)
	{
		int digit_value_temp = digitValue;
		int index = decimal.size() - digit - 1;
		if (index >= 0)
		{
			vector<unsigned char> upDecimal_temp = decimal;
			while ((digit_value_temp + 1) < 10)
			{
				vector<unsigned char> upDecimal = upDecimal_temp;
				upDecimal[upDecimal.size() - 1 - digit] = digit_value_temp + 1;
				int chan_index = index - 1;
				//bool odd = false;
				while (chan_index != -1)
				{
					if ((index-chan_index) % 2 != 0)
					{
						if ((upDecimal_temp[chan_index] + 1) < 10)
						{
							upDecimal[chan_index] = upDecimal_temp[chan_index] + 1;
						//	odd = true;
							break;
						}
					}
					else
					{
						if ((decimal[chan_index] - 1) > -1)
						{
							upDecimal[chan_index] = upDecimal_temp[chan_index] - 1;
							break;
						}
					}
					--chan_index;
				}
				if (chan_index == -1)
				{
					break;
				}
				long long longLongValue = toLongLongValue(upDecimal);
				if (getBitCount(upDecimal) != decimalBitCount)
				{
					break;
				}
				if (longLongValue <= max && longLongValue >= min)
				{
					//cout << "num " << longLongValue << " before : " << llNum << " digit: " << digit <<" dir: "<<dir<< endl;
					add(upDecimal, longLongValue, digit + 1, 1, true);
					add(upDecimal, longLongValue, digit + 1, 0, false);
				}
				else
				{
					add(upDecimal, longLongValue, digit + 1, 1, false);
					add(upDecimal, longLongValue, digit + 1, 0, false);
				}
				upDecimal_temp = upDecimal;
				++digit_value_temp;
			}
		}
	}
	else
	{
		int digit_value_temp = digitValue;
		int index = decimal.size() - 1 - digit ;
		int chan_index = index - 1;
		if (chan_index >= 0)
		{
			vector<unsigned char> downDecimal_temp = decimal;
			while ((digit_value_temp - 1) > -1)
			{
				vector<unsigned char> downDecimal = downDecimal_temp;
				downDecimal[downDecimal.size() - 1 - digit] = digit_value_temp - 1;
				while (chan_index != -1)
				{
					if ( (index - chan_index) % 2 == 0)
					{
						if ((downDecimal_temp[chan_index] + 1) < 10)
						{
							downDecimal[chan_index] = downDecimal_temp[chan_index] + 1;
							break;
						}
					}
					else
					{
						if ((downDecimal_temp[chan_index] - 1) > -1)
						{
							downDecimal[chan_index] = downDecimal_temp[chan_index] - 1;
							break;
						}
					}
					--chan_index;
				}
				if (chan_index == -1)
				{
					break;
				}
				long long longLongValue = toLongLongValue(downDecimal);
				if (getBitCount(downDecimal) != decimalBitCount)
				{
					break;
				}
				if (longLongValue <= max && longLongValue >=min)
				{
					//cout << "num " << longLongValue << " before : " << llNum << " digit: " << digit << " dir: " << dir << endl;
					add(downDecimal, longLongValue, digit + 1, 0, true);
					add(downDecimal, longLongValue, digit + 1, 1, false);
				}
				else
				{
					add(downDecimal, longLongValue, digit + 1, 0, false);
					add(downDecimal, longLongValue, digit + 1, 1, false);
				}
				downDecimal_temp = downDecimal;
				--digit_value_temp;
			}
		}
	}
	add(decimal, llNum, digit + 1, dir, false);
}


int digitsNum(long long num)
{
	int count=0;
	while (num)
	{
		num /= 10;
		++count;
	}
	return count;
}

long crisscross_sum(long value, vector<unsigned char> & decimal)
{
	stack<unsigned char> stk;
	unsigned char digitValue;
	int count = decimal.size() - 1;
	while (value)
	{
		digitValue = value % 10;
		decimal[count--] = digitValue;
		stk.push(digitValue);
		value /= 10;
	}
	int i = 1;
	long total = 0;
	while (!stk.empty())
	{
		total += stk.top()*i;
		i *= (-1);
		stk.pop();
	}
	return total;
}

long long toLongLongValue(vector<unsigned char> & decimal)
{
	int i = 1;
	int size = decimal.size();
	long long value = 0;
	int count = 0;
	forItr(count, size)
	{
		value += decimal[size-1-count]*i;
		i *= 10;
	}
	return value;
}

long crisscross_sum(long value)
{
	stack<unsigned char> stk;
	unsigned char digitValue;
	while (value)
	{
		digitValue = value % 10;
		stk.push(digitValue);
		value /= 10;
	}

	int i = 1;
	long total = 0;
	while (!stk.empty())
	{
		total += stk.top()*i;
		i *= (-1);
		stk.pop();
	}
	return total;
}

int getBitCount(vector<unsigned char> & vec)
{
	int size = vec.size();
	forItr(i, size)
	{
		if (vec[i] != 0)
		{
			return size - i;
		}
 	}
	return 0;
}

long long pow10(int exp)
{
	long long result = 1;
	forItr(i, exp)
	{
		result *= 10;
	}
	return result;
}

#endif