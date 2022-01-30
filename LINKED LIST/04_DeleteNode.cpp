#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second


#include "CodeLL.h"

void deleteNode(Node* node){
	Node* x = node->next;
	node->data = x->data;
	node->next = x->next;
	x->next = NULL;
	
}


int main(){
	Node* head = takeInput();
	int data;
	cin>>data;
	Node* node = new Node(data);
	deleteNode(node);
	printList(head);
}