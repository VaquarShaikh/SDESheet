#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

#include "CodeLL.h"

Node* reverseLLRec(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node* smallAns = reverseLLRec(head->next);
	Node* tail = head->next;
	tail->next = head;
	head->next = NULL;
	return smallAns;
}

Node* reverseIter(Node* head){
	Node *prev = NULL , *cur = head , *nex = NULL;
	while(cur){	
		nex = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nex;
	}
	return prev;
}

int main(){
	Node* head = takeInput();
	Node* temp = head;
	// Node* newHead = reverseLLRec(temp);
	Node* newHead = reverseIter(temp);
	printList(newHead);
	// printList(head);
}