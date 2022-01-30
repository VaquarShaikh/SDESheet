#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

#include "CodeLL.h"

Node* findMiddle(Node* head){
	Node *s = head , *f = head;
	while(f != NULL && f->next != NULL){
		s = s->next;
		f = f->next->next;
	}
	return s;
}

int main(){
	Node* head = takeInput();
	Node* res = findMiddle(head);
	cout<<res->data<<endl;
}