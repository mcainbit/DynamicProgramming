/*
 * Rod_Cutting.cpp
 *
 *  Created on: 08-May-2020
 *      Author: rakesh
 */


#include<iostream>
#include<vector>
using namespace std;

class RodCutting{
public:
	int getRodCuttingProfit(vector<int> prices, vector<int> lengths,int maxlength){
		vector<vector<int>> dp(prices.size(), vector<int>(maxlength + 1, -1));
		//return getRodCuttingProfitRecursive(prices,lengths,maxlength,0);
		return getRodCuttingProfitRecursiveTopDown(dp,prices,lengths,maxlength,0);
	}

	int getRodCuttingProfitRecursive(vector<int> prices, vector<int> lengths,int maxlength, int currentIndex){

		if(maxlength == 0 || currentIndex >= lengths.size())
			return 0;
		int profit1 = 0;
		if(lengths[currentIndex] <= maxlength){
			profit1 = prices[currentIndex] + getRodCuttingProfitRecursive(prices,lengths,maxlength-lengths[currentIndex], currentIndex); //take it and take it again
		}
		int profit2 = getRodCuttingProfitRecursive(prices,lengths,maxlength, currentIndex+1);
		return max(profit1 ,profit2);
	}

	int getRodCuttingProfitRecursiveTopDown(vector<vector<int>> dp,vector<int> prices, vector<int> lengths,int maxlength, int currentIndex){

		if(maxlength == 0 || currentIndex >= lengths.size())
			return 0;

		if(dp[currentIndex][maxlength] == -1){
			int profit1 = 0;
			if(lengths[currentIndex] <= maxlength){
				profit1 = prices[currentIndex] + getRodCuttingProfitRecursive(prices,lengths,maxlength-lengths[currentIndex], currentIndex); //take it and take it again
			}
			int profit2 = getRodCuttingProfitRecursive(prices,lengths,maxlength, currentIndex+1);
			dp[currentIndex][maxlength] = max(profit1 ,profit2);
		}
		return dp[currentIndex][maxlength];
	}
};


int main(){
	RodCutting rc;
	vector<int> prices = {2, 6, 7, 10, 13};
	vector<int> lengths = {1, 2, 3, 4, 5};
	int maxlength = 5;
    cout<<" Result :"<<rc.getRodCuttingProfit(prices,lengths,maxlength)<<endl;
	return 0;
}
