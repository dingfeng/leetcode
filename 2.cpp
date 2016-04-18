#ifdef test2
#include <iostream>
#include <vector>
#include <string>
#include <set>
#define forItr(j,size) for(int i=j;i<size;++i)
using namespace std;
struct mynode
{
	int index;
	string filename;
	vector<mynode>  depend;
};
bool getResult(vector<mynode> & nodes, vector<string> & result);
void getNext(vector<mynode> & nodes, vector<mynode>  result, vector<vector<mynode>>  & vvmynode);
void removeFrom(int index, vector<mynode> & nodes);

//ÍØÆËÅÅÐò
int main()
{
	int count,n,m;
	cin >> count;
	string filename;
	forItr(0, count)
	{
		vector<mynode> nodeVec;
		cin >> n;
		forItr(0,n)
		{
			cin >> filename>>m;
			mynode nodeTmp;
			nodeTmp.index = nodeVec.size();
			nodeTmp.filename = filename;
			forItr(0, m)
			{
				nodeTmp.depend.push_back(nodeVec[i]);
			}
		}
		vector<string> result;
		getResult(nodeVec,result);
		forItr(0, result.size())
		{
			cout << result[0] << endl;
		}
		cout << endl;
	}
}

bool getResult(vector<mynode> & nodes, vector<string> & result)
{
	vector<vector<mynode>> vvmynode;
	vector<mynode>  result0;
	getNext(nodes, result0, vvmynode);
	if (vvmynode.size() == 0)
	{
		return false;
	}
	return true;
}

void getNext(vector<mynode> & nodes, vector<mynode>  result, vector<vector<mynode>>  & vvmynode)
{
	set<int> sint;
    
}

void removeFrom(int index, vector<mynode> & nodes)
{
	auto  end = nodes.end();
	for (auto tmp = nodes.begin(); tmp != end; ++tmp)
	{
		if ((*tmp).index == index)
		{
			nodes.erase(tmp);
		}
	}

}
#endif