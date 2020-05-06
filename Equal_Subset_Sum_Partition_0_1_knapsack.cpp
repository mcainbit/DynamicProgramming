
/*Given a set of positive numbers, find if we can partition it into two subsets such that the sum of elements in both the subsets is equal.
 * Equal_Subset_Sum_Partition.cpp
 *
 *  Created on: 04-May-2020
 *      Author: rakesh
 */
/*	Input: {1, 2, 3, 4}
	Output: True
	Explanation: The given set can be partitioned into two subsets with equal sum: {1, 4} & {2, 3}

	Input: {1, 1, 3, 4, 7}
	Output: True
	Explanation: The given set can be partitioned into two subsets with equal sum: {1, 3, 4} & {1, 7}

	Input: {2, 3, 4, 6}
	Output: False
	Explanation: The given set cannot be partitioned into two subsets with equal sum.

	*/

// First from vector and then array
#include<iostream>
#include <vector>
using namespace std;
bool subArray(const vector<int> &num,int sum , int index,vector<vector<int>> &dp){
	if(sum == 0){
		return true;
	}

	if(num.empty() || index >= num.size() )
		return false;

	if( dp[index][sum] == -1){
		if(num[index] <= sum ) // include
		{
			if( subArray(num,sum-num[index], index+1,dp))
			{
				dp[index][sum] = 1;
				return true;
			}
		}
		dp[index][sum] = subArray(num,sum, index+1,dp) ? 1:0; // Exclude
	}
	cout<<"Hello "<<"\n";
	return dp[index][sum]==1 ? true:false;

}
void findSubArray(const vector<int> &num){
	int sum = 0;
	for(int i = 0 ; i<num.size(); i++){
			sum+=num[i];
	}
	if(sum %2 != 0 ){
		return;
	}
	vector<vector<int>> dp(num.size(), vector<int>(sum / 2 + 1, -1));
	for(int i = 0 ; i<num.size() ; i++){
		for(int j = 0 ; j<sum/2 ; j++){
			cout<<" "<< dp[i][j];
		}
		cout<<"\n";
	}
	cout<<" result "<<subArray(num,sum/2,0,dp);
	for(int i = 0 ; i<num.size() ; i++){
		for(int j = 0 ; j<sum/2 ; j++){
			cout<<" "<< dp[i][j];
		}
		cout<<"\n";
	}
}

bool BottomUpDp(const vector<int> &num){
	int sum = 0;
		for(int i = 0 ; i<num.size(); i++){
				sum+=num[i];
		}
		if(sum %2 != 0 ){
			return false;
		}

	vector<vector<bool>> dp(num.size(), vector<bool>(sum / 2 + 1, false));
	for(int i = 0 ; i<num.size() ; i++ ){
		dp[i][0] = true;
	}
	for(int j = 0 ; j<=(sum / 2) ; j++){
		if(num[0]>= j){
			dp[0][j] = true;
		} else {
			dp[0][j] = false;
		}
	}


	for(int i = 1 ; i<num.size() ; i++ ){
		for(int j = 1 ; j<=(sum / 2) ; j++){

			// include
			bool result1 = false ;
			if( j >= num[i])
			{
				result1 = dp[i-1][j-num[i] ];
			}
			//Exclude
			bool result2 = dp[i-1][j];
			dp[i][j] = result1 || result2;
		}
	}
	for(int i = 0 ; i<num.size() ; i++ ){
			for(int j = 0 ; j<=(sum / 2) ; j++){
				cout<<" "<<dp[i][j];
			}
			cout<<"\n";
	}

	return dp[num.size()-1][sum/2];

}
int main(){

	vector<int> num{1, 2, 3, 4};
	//findSubArray(num);
	cout<<"Result :"<<BottomUpDp(num);
return 0;
}





