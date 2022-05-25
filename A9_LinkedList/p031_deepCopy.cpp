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
map<Node *, Node *> m;
Node *copyRandomList(Node *head)
{
	if (head == NULL)
		return NULL;
	if (m.find(head) != m.end())
		return m[head];
	m[head] = new Node(head->val);

	m[head]->next = copyRandomList(head->next);
	m[head]->random = copyRandomList(head->random);

	return m[head];
}
int main()
{
	FastIO;

	return 0;
}
