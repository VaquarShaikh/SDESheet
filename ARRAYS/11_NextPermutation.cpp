#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

void reverse(vector<int>& nums , int start){
	int i = start ,  j = nums.size() -1 ;
	while(i < j){
		swap(nums[i],nums[j]);
		i++;j--;
	}
}

void nextPermutation(vector<int>& nums){
	int i = nums.size() - 2;
	while(i >= 0 && nums[i] >= nums[i + 1]){
		i--;
	}
	if(i >= 0){
		int j = nums.size() - 1;
		while(nums[j] <= nums[i]){
			j--;
		}
		swap(nums[i] , nums[j]);
		reverse(nums , i + 1);
	}else{
		sort(nums.begin() , nums.end());
	}
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
	nextPermutation(nums);
	for(int i = 0;i < n;i++){
		cout<<nums[i]<<" ";
	}
}