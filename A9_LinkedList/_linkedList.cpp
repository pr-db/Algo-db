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

	Node();
	Node(int _data)
	{
		data = _data;
		next = NULL;
	}

	void push_front(Node **head_ref, ll new_data);
	void push_back(Node *node, ll new_data);
	void print_list(Node *node);
};

void Node::push_front(Node **head_ref, ll new_data)
{
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void Node::push_back(Node* node, ll new_data)
{
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = NULL;
	while(node->next!=NULL)
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
