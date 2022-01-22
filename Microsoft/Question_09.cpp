
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left,  *right;
};

Node* newNode(int x) {
	
	Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->left = temp->right = NULL;
	return temp;
}

int traverse(Node* head, int X, int& ans) {
    
    if(head == NULL)
        return 0;
    int L = traverse(head->left, X, ans);
    int R = traverse(head->right, X, ans);
    if(X == head->data+L+R)
        ans++;
    return head->data + L + R;
}

int solve(Node *root, int X) {
	
	int ans = 0;
	traverse(root, X, ans);
	return ans;
}

int main() {
	
	struct Node *head = newNode(-2);
	head->left = newNode(1);
	head->right = newNode(2);
	
	cout << solve(head,1);
	
	return 0;
}
