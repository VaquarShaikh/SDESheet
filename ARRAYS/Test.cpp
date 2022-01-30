#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

class TrieNode{
public:
	TrieNode* left;
	TrieNode* right;
};


void insert(TrieNode* head , int n){
	TrieNode* curr = head;
	for(int i = 31;i >= 0;i--){
		int b = (n>>i)&1;
		if(b == 0){
			if(!curr->left){
				curr->left = new TrieNode();
			}
			curr = curr->left;
		}else{
			if(!curr->right){
				curr->right = new TrieNode();
			}
			curr = curr->right;
		}
	}
}

int findMaxxXor(TrieNode* head , vector<int>& nums){
	int n = nums.size();
	int max_xor = INT_MIN;
	for(int i = 0;i < n;i++){
		int value = nums[i];
		int curr_xor = 0;
		TrieNode* curr = head;
		for(int j = 31;j >= 0;j--){
			int b = (value>>j)&1;
			if(b == 0){
				if(curr->right){
					curr_xor += pow(2,j);
					curr = curr->right;
				}else{
					curr = curr->left;
				}
			}else{
				if(curr->left){
					curr_xor += pow(2,j);
					curr = curr->left;
				}else{
					curr = curr->right;
				}
			}
		}
		if(curr_xor > max_xor){
			max_xor = curr_xor;
		}
	}
	return max_xor;
}

int findMaximumXOR(vector<int>& nums){
	int n = nums.size();
	TrieNode* head = new TrieNode();
	for(int i = 0;i < n;i++){
		insert(head , nums[i]);
	}
	return findMaxxXor(head , nums);
}


int main(){
	int n;
	cin>>n;
	vector<int> nums;
	for(int i = 0;i < n;i++){
			int temp;
			cin>>temp;
			nums.push_back(temp);
		}	
	cout<<findMaximumXOR(nums)<<endl;
}