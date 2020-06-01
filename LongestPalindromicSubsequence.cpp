
/*
 * LongestPalindromicSubsequence.cpp
 *Given a sequence, find the length of its Longest Palindromic
Subsequence (LPS). In a palindromic subsequence, elements read the
same backward and forward.
A subsequence (https://en.wikipedia.org/wiki/Subsequence) is a
sequence that can be derived from another sequence by deleting
some or no elements without changing the order of the remaining
elements.
Example 1:
Input: "abdbca"
Output: 5
Explanation: LPS is "abdba".

Example 2:
Input: = "cddpd"
Output: 3
Explanation: LPS is "ddd".


Example 2:

Example 3:
Input: = "pqr"
Output: 1
Explanation: LPS could be "p", "q" or "r".


 *
 *  Created on: 13-May-2020
 *      Author: rakesh
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class LongestPalindromicSubsequence{
	public:
	   int getResult(string &str){
		vector<vector<int>> dp(str.length(), vector<int>(str.length(), -1));
		//return Recursive(str,0,str.length()-1);
		return TopDownDp(str,0,str.length()-1,dp);
	}

	private:
	 int Recursive(string &str , int start , int end){


		 if(start == end ) {
			 return 1;
		 }
		    if(start > end)
							 return 0;
		 if(str[start] == str[end]){
			return 2 + Recursive(str, start+1 , end-1);
		 } else {
			 int res1 = Recursive(str,start+1,end);
			 int res2 = Recursive(str,start,end-1);
			 return max(res1,res2);
		 }
	 }

	 int TopDownDp(string &str , int start , int end ,vector<vector<int>> &dp){
		         if(start > end)
					 return 0;

		 	 if(start == end ) {
					 return 1;
				 }


				 if(dp[start][end] == -1){
				 if(str[start] == str[end]){
					 dp[start][end] = 2 + TopDownDp(str, start+1 , end-1,dp);
				 } else {
					 int res1 = TopDownDp(str,start+1,end,dp);
					 int res2 = TopDownDp(str,start,end-1,dp);
					 dp[start][end] = max(res1,res2);
				 	 }
				 }
				 return dp[start][end];
	 }
};

int main(){
	LongestPalindromicSubsequence mj;

	string str = "abdbca";
	cout<<"Result:"<<mj.getResult(str)<<endl;

	 str = "cddpd";
	cout<<"Result:"<<mj.getResult(str)<<endl;;

	str = "pqr";
	cout<<"Result:"<<mj.getResult(str)<<endl;
	return 0;
}






