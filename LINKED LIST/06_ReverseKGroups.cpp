#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second


#include "CodeLL.h"

int retLen(Node* head){
	int count = 0;
	Node* temp = head;
	while(temp){
		temp = temp->next;
		count++;
	}
	return count;
}


Node* reverseKGroup(Node* head , int k){
	stack<Node*> s1;
	stack<Node*> s2;
	int count = k;
	Node* temp = head;
	Node* tail = NULL;
	int len = retLen(head);
	int numIter = int(len/k);
	int tIter = 0;
	while(temp){
		while(count){
			s1.push(temp);
			temp = temp->next;
			count--;
		}
		while(!s1.empty()){
			Node* top = s1.top();
			s2.push(top);
			s1.pop();
		}
		count = k;
		tIter++;
		if(tIter == numIter){
			break;
		}
	}
	while(!s2.empty()){
		Node* top = s2.top();
		s1.push(top);
		s2.pop();
	}
	Node* top = s1.top();
	head = top;
	tail = top;
	s1.pop();
	while(!s1.empty()){
		Node* top = s1.top();
		tail->next = top;
		tail = tail->next;
		s1.pop();
	}
	if(temp!=NULL){
		tail->next = temp;
	}else{
		tail->next = NULL;
	}
	return head;
}


int main(){
	Node* head = takeInput();
	Node* temp = head;
	int k;
	cin>>k;
	Node* newHead = reverseKGroup(temp , k);
	// cout<<newHead->data<<endl;
	printList(newHead);	
}