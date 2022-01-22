
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left,  *right;
	Node *nextRight;
};

Node* newNode(int x) {
	
	Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->left = temp->right = temp->nextRight = NULL;
	return temp;
}

int solve(Node *head) {
	
	queue<Node*> q;
    q.push(head);
       
    while(!q.empty()) {
       
        Node *curr = NULL;
        queue<Node*> temp;
       
        while(!q.empty()) {
           
            if(q.front()->left != NULL)
                temp.push(q.front()->left);
            if(q.front()->right != NULL)
                temp.push(q.front()->right);
            if(curr == NULL)
                curr = q.front();
            else {
                curr->nextRight = q.front();
                curr = q.front();
            }
            q.pop();
       }
       
       q = temp;
   }
}

int main() {
	
	struct Node *head = newNode(3);
	head->left = newNode(1);
	head->right = newNode(2);
	
	return 0;
}
