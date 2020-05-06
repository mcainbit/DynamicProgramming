/*
 * Subset_Sum.cpp
 *
 *  Created on: 06-May-2020
 *      Author: rakesh
 */
/*
 * Given a set of positive numbers, determine if there exists a subset whose sum is equal to a given number ‘S’.
 * Input: {1, 2, 3, 7}, S=6
 *	Output: True
 *	The given set has a subset whose sum is '6': {1, 2, 3}
 *
 *
 *	Input: {1, 2, 7, 1, 5}, S=10
    Output: True
    The given set has a subset whose sum is '10': {1, 2, 7}
 *
 *
 *	Input: {1, 3, 4, 8}, S=6
    Output: False
    The given set does not have any subset whose sum is equal to '6'.
 *
 */

using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:

	bool canPartition(vector<int> arr , int sum){
        vector<vector<bool>> dp(arr.size(),vector<bool>(sum+1,false));
		//return canPartitionRecusrion(arr,0,sum);
        //bool result =  canPartitionTopDownDP(arr,0,sum,dp);
        return canPartitionBottonUpDP(arr,sum,dp);
	}


	bool canPartitionRecusrion(vector<int> arr , int currentIndex , int sum){

		if( currentIndex >= arr.size())
			return false;
		if(sum  == 0)
			return true;

		if( sum >= arr[currentIndex]){ // Include
			if(canPartitionRecusrion(arr, currentIndex+1 , sum-arr[currentIndex])){
				return true;
			}
		}
		return canPartitionRecusrion(arr, currentIndex+1 , sum);
	}

	bool canPartitionTopDownDP(vector<int> arr , int currentIndex , int sum,vector<vector<bool>> &dp){

		if( currentIndex >= arr.size())
				return false;
			if(sum  == 0)
				return true;

			if(dp[currentIndex][sum]){
				return dp[currentIndex][sum];
			}

			if( sum >= arr[currentIndex]){ // Include
				if(canPartitionTopDownDP(arr, currentIndex+1 , sum-arr[currentIndex],dp)){
					dp[currentIndex][sum] = true;
					return true;
				}
			}
			dp[currentIndex][sum] = canPartitionTopDownDP(arr, currentIndex+1 , sum,dp);
			return dp[currentIndex][sum];
	}

	bool canPartitionBottonUpDP(vector<int> arr, int sum , vector<vector<bool>> &dp){

		for(int i = 0 ; i<arr.size() ; i++ ){
				dp[i][0] = true;
			}
			for(int j = 0 ; j<=sum ; j++){
				if(arr[0]>= j){
					dp[0][j] = true;
				} else {
					dp[0][j] = false;
				}
			}
			for(int i  = 1 ; i < arr.size() ; i++){
			      for(int j = 1 ; j <=sum ; j++) {
			    	  bool include = false;
			    	  if(j >= arr[i] ){ //Include
			    		  include = dp[i-1][j-arr[i]];
			    	  }
			    	  bool exclude = dp[i-1][j];
			    	  dp[i][j] = (include || exclude) ;
			      }
			}
			return dp[arr.size()-1][sum];
	}
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 2, 3, 7};
  cout << ss.canPartition(num, 6) << endl;
  num.clear();
  num = {1, 2, 7, 1, 5};
  cout << ss.canPartition(num, 10) << endl;
  num.clear();
   num = {1, 3, 4, 8};
  cout << ss.canPartition(num, 6) << endl;
}
