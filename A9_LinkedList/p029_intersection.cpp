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

Node *getIntersectionNode(Node *headA, Node *headB)
{
	int a = 0, b = 0;
	Node *ha = headA, *hb = headB;
	while (ha->next)
	{
		a++;
		ha = ha->next;
	}
	while (hb->next)
	{
		b++;
		hb = hb->next;
	}
	if (ha != hb)
		return NULL;
	ha = headA, hb = headB;
	if (b >= a)
		for (int i = 0; i < b - a; i++)
			hb = hb->next;
	else
		for (int i = 0; i < a - b; i++)
			ha = ha->next;
	while (ha != hb)
	{
		ha = ha->next;
		hb = hb->next;
	}

	return ha;
}

int main()
{
	FastIO;
	Node *head = NULL;
	head->push_front(&head, 12);
	head->push_front(&head, 13);
	head->push_back(head, 11);

	head->print_list(head);
	return 0;
}
