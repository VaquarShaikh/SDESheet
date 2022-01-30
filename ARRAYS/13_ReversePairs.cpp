#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second


int merge(vector<int>& nums , int start, int mid , int end){
	int invCount = 0;
	vector<int> v1 , v2;
	for(int i = start;i <= mid;i++){
		v1.push_back(nums[i]);
	}
	for(int i = mid + 1;i <= end;i++){
		v2.push_back(nums[i]);
	}	
	int i = 0 , j = 0,k = start;
	while(i < v1.size() && j < v2.size()){
		if(v1[i] <= v2[j]){
			nums[k++] = v1[i++];
		}else if(v1[i] > 2LL*nums[j]){
			nums[k++] = v2[j++];
			invCount += (mid - i);
		}else{
			nums[k++] = v2[j++];
		}
	}
	while(i < v1.size()){
		nums[k++] = v1[i++];
	}while(j < v2.size()){
		nums[k++] = v2[j++];
	}
	return invCount;
}


int mergeSort(vector<int>& nums , int start , int end){
	if(start >= end){
		return 0;
	}
	int mid = start + (end - start)/2;
	int invCount = 0;
	invCount = mergeSort(nums , start , mid);
	invCount += mergeSort(nums , mid + 1 ,end);
	invCount += merge(nums , start , mid , end);
	return invCount;
}


int reversePairs(vector<int>& nums){
	int n = nums.size();
	return mergeSort(nums , 0 , n - 1);
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
	cout<<reversePairs(nums)<<endl;	
}