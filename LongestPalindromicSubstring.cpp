
/*
 * LongestPalindromicSubstring.cpp
 *
 *  Created on: 1-June-2020
 *      Author: rakesh
 *
 *      Problem Statement #
Given a string, find the length of its Longest Palindromic Substring
(LPS). In a palindromic string, elements read the same backward and
forward.
Example 1:
Input: "abdbca"
Output: 3
Explanation: LPS is "bdb".
Example 2:
Input: = "cddpd"
Output: 3
Explanation: LPS is "dpd".
Example 3:
Input: = "pqr"
Output: 1
Explanation: LPS could be "p", "q" or "r".


 *
 */

#include<iostream>
#include<vector>

using namespace std;

class LongestPalindromicSubstring{
	public:
	   int getResult(string &input){
			vector<vector<int>> dp(input.length(), vector<int>(input.length(), -1));
		//return Recursive(input,0,input.size()-1);
		return TopDownDp(input,0,input.size()-1,dp);
	}

	private:
	 int Recursive(string &input, int start , int end){

		 if(start > end)
			 return 0;

		 if(start == end )
			 return 1;

		 if(input[start] == input[end]){
			 int remainLength = end-start-1;
			 if(remainLength == Recursive(input,start+1,end-1)){
				 return remainLength+2;
			 }
		 }
			 int res1 = Recursive(input,start+1,end);
			 int res2 = Recursive(input,start,end-1);
			 return max(res1, res2);
	 }

	 int TopDownDp(string &input, int start , int end, vector<vector<int>> &dp){
		 if(start > end)
			 return 0;

		 if(start == end )
			 return 1;
		 if(dp[start][end] == -1){
		 if(input[start] == input[end]){
			 int remainLength = end-start-1;
			 if(remainLength == TopDownDp(input,start+1,end-1,dp)){
				 dp[start][end] = remainLength+2;
				 return dp[start][end];
			 }
		 }
			 int res1 = TopDownDp(input,start+1,end,dp);
			 int res2 = TopDownDp(input,start,end-1,dp);
			 dp[start][end] = max(res1, res2);
		 }
		 return dp[start][end];
	 }
};

int main(){
	LongestPalindromicSubstring lps;

	string input = "abdbca";
	cout<<"Result:"<<lps.getResult(input)<<endl;

    input = "cddpd";
	cout<<"Result:"<<lps.getResult(input)<<endl;

    input = "pqr";
	cout<<"Result:"<<lps.getResult(input)<<endl;
	return 0;
}
