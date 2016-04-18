#ifdef TRIETREE
#include<iostream>
#include<string>
using namespace std;
struct node{
	char ch;
	int childTreeNodeCount;
	node * sibling;
	node * child;
	node(char ch, int num = 0)
	{
		this->ch = ch;
		this->childTreeNodeCount = num;
		sibling = NULL;
		child = NULL;
	};
	node()
	{
		this->childTreeNodeCount = 0;
		sibling = NULL;
		child = NULL;
	};

};

void addNode(node * root, string & in_str, unsigned int depth);
int search(node * root, string & search_str, int depth);
void printTree(node * root);

int main()
{
	int wordNum=0;
	cin >> wordNum;
	node root;
	string in_temp;
	for (int i = 0; i < wordNum; ++i)
	{
		cin >> in_temp;
		addNode(&root, in_temp, 0);
	}
	//printTree(&root);
	int search_num = 0;
	cin >> search_num;
	string search_temp;
	for (int i = 0; i < search_num; ++i)
	{
		cin >> search_temp;
		cout << search(&root, search_temp, 0) << endl;
	}
	return 1;
}

int search(node * root, string & search_str, int depth)
{
	char ch = search_str[depth];
	node * rootChild = root->child;
	while (rootChild != NULL)
	{
		if (rootChild->ch == search_str[depth])
		{

			if (depth == search_str.length() - 1)
			{
				return rootChild->childTreeNodeCount;
			}
			else
			{
				return search(rootChild,search_str,depth+1);
			}
		}
		rootChild = rootChild->sibling;
	}
	return 0;
}

void addNode(node * root, string & in_str,unsigned int depth)
{
	root->childTreeNodeCount++;
	if (depth == in_str.length())
	{
		return;
	}
	char node_ch = in_str[depth];
	node * rootChild = root->child;
	node * child_pre = NULL;
	while (rootChild != NULL)
	{
		if (rootChild->ch == node_ch){
			addNode(rootChild, in_str, depth + 1);
			return;
		}
		child_pre = rootChild;
		rootChild = rootChild->sibling;
	}
	if (rootChild == NULL)
	{
		node * add_node = new node(in_str[depth]);
		if (child_pre == NULL)
		{
			root->child = add_node;
		}
		else
		{
			child_pre->sibling = add_node;
		}
		addNode(add_node, in_str, depth + 1);
	}
}

void printTree(node * root)
{
	node* child = root->child;
	while (child != NULL)
	{
	 	cout << child->ch;
		cout << "ги";
		printTree(child);
		cout << ")";
		child = child->sibling;
	}

}
#endif