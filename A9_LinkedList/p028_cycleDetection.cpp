#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FastIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

class Node
{
public:
	ll data;
	Node *next;
	void push_front(Node **head_ref, ll new_data);
	void push_back(Node *node, ll new_data);
	void push_at();
	void print_list(Node *node);
};

void Node::push_back(Node *node, ll new_data)
{
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = NULL;
	while (node->next != NULL)
		node = node->next;
	node->next = new_node;
}

void Node::print_list(Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

bool hasCycle(Node *head)
{
	if (head == NULL)
		return false;
	Node *fh = head;
	Node *sh = head;
	while (sh && fh && fh->next)
	{
		sh = sh->next;
		fh = fh->next->next;

		if (sh == fh)
			return true;
	}
	return false;
}
int main()
{
	FastIO;
	Node *head = NULL;
	ll n, p;
	cin >> n >> p;
	for (ll i = 0; i < n; i++)
	{
		ll inp;
		cin >> inp;
		head->push_back(head, inp);
	}
	head->print_list(head);

	cout << hasCycle(head);
	return 0;
}
