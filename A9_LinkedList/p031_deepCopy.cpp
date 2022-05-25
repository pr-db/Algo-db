#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define cn cout << "\n";

class Node
{
public:
	int val;
	Node *next;
	Node *random;

	Node(int _val)
	{
		val = _val;
		next = NULL;
		random = NULL;
	}
};

Node *copyRandomList(Node *head)
{
	Node *h = head;
	map<Node *, Node *> m;

	if(h==NULL)
		return NULL;
}
int main()
{
	FastIO;
	
	return 0;
}
