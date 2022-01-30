#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second


#include "CodeLL.h"


Node* rotateRight(Node* head , int k){
	if(head == NULL){
		return head;
	}
	Node* last = head;
	int count = 1;
	while(last->next != NULL){
		last = last->next;
		count++;
	}
	last->next = head;
	if(count > k){
		count = count - k;
	}
	else{
		count = count - k%count;
	}
	while(count){
		last = last->next;
		count--;
	}
	head = last->next;
	last->next = NULL;
	return head;
}



int main(){
	Node* head = takeInput();
	Node* temp = head;
	int k;
	cin>>k;
	Node* newHead = rotateRight(temp , k);
	printList(newHead);
}