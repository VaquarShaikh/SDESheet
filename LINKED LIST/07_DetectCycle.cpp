#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

bool hasCycle(ListNode *head) {
	if(head == NULL){
		return false;
	}
	ListNode* s = head , *f = head;
	while(f != NULL && f->next != NULL){
		s = s->next;
		f = f->next->next;
		if(s==f){
			return true;
		}
	}
	return false;
}

int main(){
	
}	