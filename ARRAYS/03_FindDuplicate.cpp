#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second

// ************PROBLEM STATEMENT**************
// In the array of integers input [1,n] , find the duplicate number .

// You cannot modify the elements of the array , neither can you use an 
// n squared approach .

// ***********APPROACH NUMBER 1***************
// The idea is to use binary search . 
// eg :
// array elements : 1 2 4 2 5
// count the elements for every element in the array which are less than 
// or equal to the array . 
// 1 -> 1
// 2 -> 3
// 4 -> 4
// 5 -> 5

// You can observe clearly that for the repeated element (2) , the 
// the number on rhs is strictly greater than the number on the lhs .

// We perform a plain binary search.
// Now we get the middle element . 
// Our goal is to find the smallest number that fits into our requirements .
// We will get an unsorted array , so we dont perform the search on the array . 
// We perform the search on the stream of numbers from [1,n] .

// If the middle element satisfies the condition , we go to the left half , else
// we go to the right half . 
// NOTE :
// Even if the element between [1,n] is not in the array , still we perform 
// binary search on it .

int returnCount(vector<int>& nums , int cur){
	int count = 0;
	for(int i = 0;i < nums.size();i++){
		if(nums[i] <= cur){
			count++;
		}
	}
	return count;
}
int findDuplicate(vector<int>& nums) {
	int l = 1, h = nums.size() , dup = -1;
	while(l <= h){
		int cur = (l+h)/2;

		if(returnCount(nums,cur) > cur){
			dup = cur;
			h = cur - 1;
		}else{
			l = cur + 1;
		}
	}
	return dup;
}

// ***********APPROACH 2*************
// This was the approach that actually came into my mind while solving the problem .
// I tried to use the xor operator . Remember the two properties of the xor operator.
// if 'n' is any number , then :
// n ^ 0 = n
// n ^ n = 0

// now in our case : 
// 1 2 2 3 4 5
// 1 2 3 4 5 (actual numbers between 1 to n inclusive)
// now these two will cancel out each other till the duplicate element is remained . 
// Algo :
// 1) xor the given array and store in an answer . 
// 2) xor the elements from 1 to n inclusive . 
// 3) the xor of these elements is the answer . 

int fun(vector<int>& nums){
	int x = nums[0];
	for(int i = 1;i < nums.size();i++){
		x = x^nums[i];
	}
	for(int i = 0;i < nums.size();i++){
		x = x^i;
	}
	return x;
}

// The following solution somehow does not get accepted on leetcode .
// They have a random bullshitty testcase : 
// 2 2 2 2 2 2
// output comes out as 6 
// The expected output is 2 

// again , this is an invalid testcase , how the fuck are we supposed to get this testcase 

// There is a third approach using two pointers , where in you can use 
// two pointers , hare and tortoise , the hare moves two points and the 
// tortoise moves a single point ahead . 



int main(){
	int n;
	cin>>n;
	vector<int> nums;
	for(int i = 0;i < n;i++){
		int temp;
		cin>>temp;
		nums.push_back(temp);
	}
	cout<<fun(nums);
	// for(int i = 0;i < nums.size();i++){
	// 	cout<<nums[i]<<" ";
	// }
}