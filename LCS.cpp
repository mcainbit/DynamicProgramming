/*
 * LCS.cpp
 *
 *  Created on: 06-Jun-2020
 *      Author: rakesh
 */
#include <iostream>
#include <string.h>
using namespace std;
int dp[20][20];

int LCSMemoization(string s1, string s2 , int len1 , int len2){

	if(len1 == 0 || len2 == 0)
	{
		return 0;
	}

	if(dp[len1][len2] != -1){
		return dp[len1][len2];
	}

	if(s1[len1-1] == s2[len2-1]){
		return dp[len1][len2] = 1 + LCSMemoization(s1,s2,len1-1,len2-1);
	} else {
		return dp[len1][len2] = max(LCSMemoization(s1,s2,len1,len2-1) ,LCSMemoization(s1,s2,len1-1,len2));
	}
}
int LCSrecursive(string s1, string s2 , int len1 , int len2){
	if(len1 == 0 || len2 == 0)
	{
		return 0;
	}

	if(s1[len1-1] == s2[len2-1]){
		return 1 + LCSrecursive(s1,s2,len1-1,len2-1);
	} else {
		return max(LCSrecursive(s1,s2,len1,len2-1) ,LCSrecursive(s1,s2,len1-1,len2));
	}
}

int LCSTopdown(string s1, string s2 , int len1 , int len2){
	for(int i = 0 ; i<=len1; i++){
		for(int j =0;j<=len2 ; j++){
			if(i ==0 || j == 0)
			dp[i][j] = 0;
		}
	}

	for(int i = 1 ; i<=len1; i++){
		for(int j =1;j<=len2 ; j++){
			if(s1[i-1] == s2[j-1]){
					dp[i][j] = 1+ dp[i-1][j-1];
				} else {
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				}
		}
	}
	return dp[len1][len2];
}

int main(){

	string s1 = "Rakesh";
	string s2 = "Rajesh";

	cout<<" RC :"<<LCSrecursive(s1,s2,s1.size(),s2.size())<<endl;
	memset(dp,-1,sizeof dp);
	cout<<" Memoization :"<<LCSMemoization(s1,s2,s1.size(),s2.size())<<endl;
	memset(dp,-1,sizeof dp);
	cout<<" TopDown :"<<LCSTopdown(s1,s2,s1.size(),s2.size())<<endl;
	return 0;
}
