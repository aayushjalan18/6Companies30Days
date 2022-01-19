
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

struct Node *head = nullptr;

struct Node* newNode(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = nullptr;
	return temp;
}

void solve(struct Node *head, int M, int N)
{
    //Add code here   
    struct Node *curr = head;
    
    while(curr != nullptr)
    {
        int m = M;
        struct Node *prev = nullptr;
        while(curr != nullptr && m > 0)
        {
            prev = curr;
            curr = curr->next;
            m--;
        }
        int n = N;
        struct Node* nxt = nullptr;
        while(curr != nullptr && n > 0)
        {
            nxt = curr->next;
            curr->next = nullptr;
            free(curr);
            curr = nxt;
            n--;
        }
        if(prev != nullptr)
            prev->next = curr;
    }
}

void display(struct Node *curr)
{
	while(curr)
	{
		cout << curr->data << ' ';
		curr = curr->next;
	}
}

int main() 
{
	head = newNode(9);
	head->next = newNode(1);
	head->next->next = newNode(3);
	head->next->next->next = newNode(5);
	
	int M, N;
	cin >> M >> N;
	
	solve(head, M, N);
	
	display(head);
	
	return 0;
}
