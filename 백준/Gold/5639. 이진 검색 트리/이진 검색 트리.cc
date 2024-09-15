#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};


node root;

void preOrder(int data)
{
	node* n = &root;

	node* new_node = new node();
	new_node->value = data;

	while (1)
	{
		if (n->value > data)
		{
			if (n->left == NULL)
			{
				n->left = new_node;
				return;
			}
			else n = n->left;
		}
		else
		{
			if (n->right == NULL)
			{
				n->right = new_node;
				return;
			}
			else n = n->right;
		}
	}

}

void postOrder(node* n)
{
	if (n->left != NULL) postOrder(n->left);
	if (n->right != NULL) postOrder(n->right);
	cout << n->value << "\n";
}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int data;

	cin >> data;

	root.value = data;

	while (cin >> data)
	{ 
		preOrder(data);
	}
	
	postOrder(&root);
}


