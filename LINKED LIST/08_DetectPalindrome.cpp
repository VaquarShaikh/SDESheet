#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

#include "CodeLL.h"

Node* findMidpoint(Node* head){
	Node* s = head , *f = head , *prev = NULL;
	while(f != NULL && f->next != NULL){
		prev = s;
		s = s->next;
		f = f->next->next;
	}
	return prev;
}

Node* reverse(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node* smallAns = reverse(head->next);
	Node* tail = head->next;
	tail->next = head;
	head->next = NULL;
	return smallAns;
}

bool isPalindrome(Node* head) {
	Node* temp = findMidpoint(head);
	Node* head1 = temp->next;
	temp->next = NULL;
	Node* head2 = reverse(head1);
	while(head){
		int res = head->data ^ head2->data;
		if(res != 0){
			return false;
		}
		head = head->next;
		head2 = head2->next;
	}
	return true;
}


int main(){
	Node* head = takeInput();
	// cout<<findMidpoint(head)->data<<endl;
	if(isPalindrome(head)){
		cout<<"True"<<endl;
	}else{
		cout<<"False"<<endl;
	}
}