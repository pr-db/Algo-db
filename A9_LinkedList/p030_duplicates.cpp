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
	ll data;
	Node *next;
	void push_front(Node **head_ref, ll new_data);
	void push_back(Node *node, ll new_data);
	void push_at();
	void print_list(Node *node);
};

void Node::push_front(Node **head_ref, ll new_data)
{
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

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

Node *removeDuplicates(Node *head)
{
	map<int, int> m;
	Node *p = NULL, *h = head;
	while (h)
	{
		if (m[h->data] >= 1)
		{
			p->next = h->next;
			delete (h);
		}
		else
		{
			m[h->data]++;
			p = h;
		}
		h = p->next;
	}
	return head;
}

int main()
{
	FastIO;
	Node *head = NULL;
	ll n;
	cin >> n;
	ll inp;
	cin >> inp;
	head->push_front(&head, inp);

	for (ll i = 1; i < n; i++)
	{
		cin >> inp;
		head->push_back(head, inp);
	}

	head = removeDuplicates(head);
	head->print_list(head);
	return 0;
}
