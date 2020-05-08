
/*
 * Unbounded_Knapsack.cpp
 *
 *  Created on: 08-May-2020
 *      Author: rakesh
 */
#include<iostream>
#include <vector>

using namespace std;

class UnBoundedKnapsack{
public:
	int getKnapsack(vector<int> &weight, vector<int> &profit, int capacity){
		vector<vector<int>> dp(profit.size(), vector<int>(capacity + 1, -1));
		//return KnapsackRecursive(weight,profit,capacity,0);
		return KnapsackRecursiveTopDown(dp,weight,profit,capacity,0);

	}

	// Top-down approach of dynamic programming
	int KnapsackRecursive(vector<int> &weight, vector<int> &profit, int capacity, int currentIndex){

		if(capacity <= 0 || currentIndex >= weight.size())
			return 0;

		int profit1 = 0 ;
		if( weight[currentIndex] <= capacity){
			profit1 = profit[currentIndex]+KnapsackRecursive(weight,profit,capacity-weight[currentIndex],currentIndex); // Take it but take it again
		}
		int profit2 = KnapsackRecursive(weight,profit,capacity,currentIndex+1); // do not take it

		return max(profit1, profit2);
	}

	// Top-down approach of dynamic programming
	int KnapsackRecursiveTopDown(vector<vector<int>> &dp,vector<int> &weight, vector<int> &profit, int capacity, int currentIndex){

		if(capacity <= 0 || currentIndex >= weight.size())
			return 0;

	    if (dp[currentIndex][capacity] == -1) {
	      int profit1 = 0 ;
	      if( weight[currentIndex] <= capacity){
	    	  profit1 = profit[currentIndex]+KnapsackRecursiveTopDown(dp ,weight,profit,capacity-weight[currentIndex],currentIndex); // Take it
	      }
	      int profit2 = KnapsackRecursiveTopDown(dp ,weight,profit,capacity,currentIndex+1);

	      dp[currentIndex][capacity] = max(profit1, profit2);
	    }
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
				//cout<<" I :"<<i<<" J :"<< j <<" Include Profit: "<<profit1<<"  Exclude profit: "<<profit2<<"\n";
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

	UnBoundedKnapsack ks;
	vector<int> profits = {1, 6, 10, 16};
	vector<int> weights = {1, 2, 3, 5};
	int capacity = 7;
    cout<<" Result :"<<ks.getKnapsack(weights,profits,capacity)<<endl;
profits.clear();
weights.clear();
    profits = {15,20,50};
    weights = {1, 2, 3};
    capacity = 5;
    cout<<" Result :"<<ks.getKnapsack(weights,profits,capacity)<<endl;
    profits.clear();
    weights.clear();
    profits = {15, 50, 60, 90};
    weights = {1, 3, 4, 5};
    capacity = 8;
    cout<<" Result :"<<ks.getKnapsack(weights,profits,capacity)<<endl;
    capacity = 6;
    cout<<" Result :"<<ks.getKnapsack(weights,profits,capacity)<<endl;
	return 0;
}
