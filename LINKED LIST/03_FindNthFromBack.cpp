#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

#include"CodeLL.h"

int retLen(Node* head){
	int count = 0;
	Node* temp = head;
	while(temp){
		temp = temp->next;
		count++;
	}
	return count;
}

Node* removeNthFromEnd(Node* head, int n) {
	int len = retLen(head);
	int pos = len - n + 1;
	if(head->next == NULL){
		return NULL;
	}
	if(pos == 1){
		Node* temp = head;
		temp = temp->next;
		delete head;
		head = temp;
		return head;
	}
	Node* temp = head , *prev = NULL;
	while(pos > 1){
		prev = temp;
		temp = temp->next;
		pos--;
	}
	prev->next = temp->next;
	temp->next = NULL;
	return head;
}

int main(){
	Node* head = takeInput();
	int n;
	cin>>n;
	Node* res = removeNthFromEnd(head , n);
	printList(res);
}