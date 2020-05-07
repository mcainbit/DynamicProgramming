
/*
 * Subset_Sum.cpp
 *
 *  Created on: 06-May-2020
 *      Author: rakesh
 */
/*
 * Given a set of positive numbers, partition the set into two subsets with a minimum difference between their subset sums.
 *  Input: {1, 2, 3, 9}
	Output: 3
	Explanation: We can partition the given set into two subsets where minimum absolute difference
	between the sum of numbers is '3'. Following are the two subsets: {1, 2, 3} & {9}.
 *
 *
 *	Input: {1, 2, 7, 1, 5}
	Output: 0
	Explanation: We can partition the given set into two subsets where minimum absolute difference
	between the sum of number is '0'. Following are the two subsets: {1, 2, 5} & {7, 1}.
 *
 *
 *	Input: {1, 3, 100, 4}
	Output: 92
	Explanation: We can partition the given set into two subsets where minimum absolute difference
	between the sum of numbers is '92'. Here are the two subsets: {1, 3, 4} & {100}.
 *
 */

using namespace std;

#include <iostream>
#include <vector>

class MinSubsetDiff {
public:

	int partitionDiff(vector<int> arr){
		 int sum = 0;
		    for (int i = 0; i < arr.size(); i++) {
		      sum += arr[i];
		}
        vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
		//return partitionDiffRecusrion(arr,0,0,0);
        return partitionTopDownDP(arr,0,0,0,dp);
	}


	int partitionDiffRecusrion(vector<int> arr , int currentIndex, int totalSub1, int totalSub2){

		if(arr.size() == currentIndex){
			int diff = totalSub1-totalSub2;
			if(diff < 0)
				diff*=-1;
			return diff;
		}
		int diff1 = partitionDiffRecusrion(arr,currentIndex+1,totalSub1+arr[currentIndex],totalSub2);

		int diff2 = partitionDiffRecusrion(arr,currentIndex+1,totalSub1,totalSub2+arr[currentIndex]);
		return min(diff1,diff2);
	}

	int partitionTopDownDP(vector<int> arr , int currentIndex, int totalSub1, int totalSub2,vector<vector<int>> &dp){


		if(arr.size() == currentIndex){
			int diff = totalSub1-totalSub2;
			if(diff < 0)
				diff*=-1;
			return diff;
		}
		if(dp[currentIndex][totalSub1] == -1){
			int diff1 = partitionDiffRecusrion(arr,currentIndex+1,totalSub1+arr[currentIndex],totalSub2);

			int diff2 = partitionDiffRecusrion(arr,currentIndex+1,totalSub1,totalSub2+arr[currentIndex]);
			dp[currentIndex][totalSub1] = min(diff1,diff2);
		}
		return dp[currentIndex][totalSub1];
	}
};

int main(int argc, char *argv[]) {
  MinSubsetDiff ss;
  vector<int> num = {1, 2, 3, 9};
  cout << ss.partitionDiff(num) << endl;
  num.clear();
  num = {1, 2, 7, 1, 5};
  cout << ss.partitionDiff(num) << endl;
  num.clear();
   num = {1, 3, 100, 4};
  cout << ss.partitionDiff(num) << endl;
  return 0;
}

