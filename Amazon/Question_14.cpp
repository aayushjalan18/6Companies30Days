
#include <bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int x) {
	
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

vector<int> traverse(Node* root, int target, int& ans) {
    
    if(root == NULL)
        return {-1,0};
    vector<int> L = traverse(root->left, target, ans);
    vector<int> R = traverse(root->right, target, ans);
    if(L[1] == 1 || R[1] == 1) {
        ans = max(ans, 2+L[0]+R[0]);
        if(L[1] == 1)
            return {1+L[0],1};
        return {1+R[0],1};
    }
    if(root->data == target) {
        ans = 1 + max(L[0],R[0]);
        return {0,1};
    }
    return {1+max(L[0],R[0]),0};
}
  
int solve(Node* root, int target) {
    
    int ans = 0;
    traverse(root, target, ans);
    return ans;
}

int main() {
	
	struct Node *head = newNode(10);
	head->left = newNode(20);
	head->right = newNode(30);
	head->left->left = newNode(40);
	head->left->right = newNode(50);
	head->right->left = newNode(60);
	head->right->right = newNode(70);
	
	int target;
	cin >> target;
	
	cout << solve(head, target) << '\n';
	
	return 0;
}
