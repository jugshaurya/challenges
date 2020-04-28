#include<bits/stdc++.h>
class Solution {

public:
	int helper(string text1, string text2, int m, int n){
	    int L[m + 1][n + 1];  
	    for (int i = 0; i <= m; i++)  {  
	        for (int j = 0; j <= n; j++)  {  
	        if (i == 0 || j == 0)  
	            L[i][j] = 0;  
	        else if (text1[i - 1] == text2[j - 1])  
	            L[i][j] = L[i - 1][j - 1] + 1;  
	        else
	            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
	        }  
	    }  
	    return L[m][n];  
	}

    int longestCommonSubsequence(string text1, string text2) {

    	int m = text1.length();
    	int n = text2.length();
    	return helper(text1, text2, m,n);
    }
};