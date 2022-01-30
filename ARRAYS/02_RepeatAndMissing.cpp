#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

// There will be a repeating and a missing number in a stream of numbers from 1 to n in 
// an array of size n . We have to find the repeating and the missing number .

// ********THE APPROACH WHICH CAME IN TO MY MIND**********
// If we could make equations out of repeating and missing number . 
// A is the repeating number  
// B is the missing number 
// Try thinking something related to the summation .
// If we actually add the numbers from 1 to n and actual numbers in the array ,
// with trial and error we can analyze that they are basically A-B.

// A+B can be easily found out by getting the difference of (sum(array)^2 - sum(theory)^2)/(sum(1ton) - sum(1ton))

typedef long long ll;

pair<ll,ll> RepeatAndMissing(vector<int>& nums){
	ll n = nums.size();
	ll sum = n*(n+1)/2;
	ll ssum = n*(n+1)*(2*n+1)/6;
	for(int i = 0;i < n;i++){
		sum -= nums[i];
		ssum -= (nums[i]*nums[i]);
	}	
	int x = (ssum/sum + sum)/2;
	int y = (ssum/sum - sum)/2;
	pair<ll,ll> ans;
	ans.first = x;
	ans.second = y;
	return ans;

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
	cout<<RepeatAndMissing(nums).second<<" "<<RepeatAndMissing(nums).first;
}