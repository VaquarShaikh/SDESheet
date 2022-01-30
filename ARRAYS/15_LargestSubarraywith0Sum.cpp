#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second


int ZeroSum(vector<int>& nums){   
	int n = nums.size();
	int sum = 0;
	int max_len = 0;
	unordered_map<int,int> mapp;
	for(int i = 0;i < n;i++){
		sum += nums[i];

		if(nums[i] == 0 && max_len == 0){
			max_len = 1;
		}if(sum == 0){
			max_len = i + 1;
		}if(mapp.find(sum) != mapp.end()){
			max_len = max(max_len , i - mapp[sum]);
		}else{
			mapp[sum] = i;
		}
	}
	return max_len;
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
	cout<<ZeroSum(nums)<<endl;
}