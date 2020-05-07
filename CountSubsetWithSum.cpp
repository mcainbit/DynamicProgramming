/*
 * Given a set of positive numbers, find the total number of subsets whose sum is equal to a given number ‘S’.
 *
 *
 *  Input: {1, 1, 2, 3}, S=4
	Output: 3
	The given set has '3' subsets whose sum is '4': {1, 1, 2}, {1, 3}, {1, 3}
	Note that we have two similar sets {1, 3}, because we have two '1' in our input.
 *
 *
 *  Input: {1, 2, 7, 1, 5}, S=9
	Output: 3
	The given set has '3' subsets whose sum is '9': {2, 7}, {1, 7, 1}, {1, 2, 1, 5}
 *
 *
 *
 */
#include<iostream>
#include<vector>
using namespace std;

class CountOfSubset{
public:
	int getCountOfSubsets(vector<int> arr, int sum){
		vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
		return getCountOfSubsetsRecusrion(arr,sum,0,dp);
	}

	int getCountOfSubsetsRecusrion(vector<int> &arr, int sum, int currentIndex,vector<vector<int>> &dp){

			if( sum == 0)
				return 1;

			if(currentIndex >= arr.size())
				return 0;

			if(dp[currentIndex][sum] == -1){
				int result1 = 0;
				if( arr[currentIndex] <= sum){
					result1 = getCountOfSubsetsRecusrion(arr,sum-arr[currentIndex],currentIndex+1,dp);
				}
				int result2  = getCountOfSubsetsRecusrion(arr,sum,currentIndex+1,dp);
				dp[currentIndex][sum] = result1 + result2;
			}
			return dp[currentIndex][sum];
	}
};
int main(){
	CountOfSubset obj;
	vector<int> num = {1, 1, 2, 3};
	cout << obj.getCountOfSubsets(num,4);
	num.clear();
	  num = {1, 2, 7, 1, 5};
	  cout << obj.getCountOfSubsets(num, 9) << endl;
	return 0;
}

