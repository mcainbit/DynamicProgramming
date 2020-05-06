
 /* *
 * 0_1_knapsack.cpp
 *
 *  Created on: 01-May-2020
 *      Author: rakesh
 */

#include<iostream>
#include <vector>

using namespace std;

class Knapsack{
public:
	int getKnapsack(vector<int> &weight, vector<int> &profit, int capacity){
		vector<vector<int>> dp(profit.size(), vector<int>(capacity + 1, -1));
		bottomupApproach(dp,weight, profit,capacity+1);
		return dp[profit.size()-1][capacity];;//this->KnapsackRecursive(dp,weight, profit,capacity,0);
	}


	// Top-down approach of dynamic programming
	int KnapsackRecursive(vector<vector<int>> &dp,vector<int> &weight, vector<int> &profit, int capacity, int currentIndex){
		if(capacity <= 0 || currentIndex >= weight.size())
			return 0;

	    if (dp[currentIndex][capacity] != -1) {
	      return dp[currentIndex][capacity];
	    }

		int profit1 = 0 ;
		if( weight[currentIndex] <= capacity){
			profit1 = profit[currentIndex]+KnapsackRecursive(dp ,weight,profit,capacity-weight[currentIndex],currentIndex+1); // Take it
		}
		int profit2 = KnapsackRecursive(dp ,weight,profit,capacity,currentIndex+1);

	    dp[currentIndex][capacity] = max(profit1, profit2);
	    return dp[currentIndex][capacity];
	}

	// Bottom up approach for Dynamic programming

	void bottomupApproach(vector<vector<int>> &dp,vector<int> &weight, vector<int> &profit, int capacity){

		for(int i = 0 ; i<weight.size() ; i++){
			dp[i][0] = 0;
		}

		for(int i = 1 ; i < capacity ; i++){
			if(weight[0] < capacity){
				dp[0][i] = profit[0];
			}
		}


		for(int i  = 1 ; i < weight.size() ; i++){
			for(int j = 1 ; j < capacity ; j++) {
				// Include it
				int profit1 = 0;
				if(weight[i] <= j){
					profit1 = profit[i]+dp[i-1][j-weight[i]];
				}
				int profit2 = dp[i-1][j];
				dp[i][j] = profit1>profit2?profit1:profit2;
				cout<<" I :"<<i<<" J :"<< j <<" Include Profit: "<<profit1<<"  Exclude profit: "<<profit2<<"\n";
			}
		}

	for(int i  = 0 ; i < weight.size() ; i++){
		for(int j = 0 ; j < capacity ; j++) {

			cout<<" "<<dp[i][j];
		}
		cout<<"\n";
	}
  }
};
int main(){

	Knapsack ks;
	vector<int> profits = {1, 6, 10, 16};
	vector<int> weights = {1, 2, 3, 5};
	int capacity = 7;
    cout<<" Result :"<<ks.getKnapsack(weights,profits,capacity);

	return 0;
}



