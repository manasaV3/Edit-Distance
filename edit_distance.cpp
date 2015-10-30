//
//  edit_distance.cpp
//  Algorithms
//
//  Created by Manasa on 10/27/15.
//  Copyright (c) 2015 Manasa. All rights reserved.
//

#include <stdio.h>
#include <iostream>

int min(int x, int y)
{
    if(x<y) {
        return x;
    }
    return y;
}

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int editDistDP(char str1[], char str2[], int m, int n)
{
    int dp[m+1][n+1];
    
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i==0)
                dp[i][j] = j;
            
            else if (j==0)
                dp[i][j] = i;

            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                                   dp[i-1][j],  // Remove
                                   dp[i-1][j-1]); // Replace
        }
    }
    
    return dp[m][n];
}

int main()
{
    char str1[] = "tesx";
    char str2[] = "xyzabc";
    
    std::cout << editDistDP(str1, str2, strlen(str1), strlen(str2));
    
    return 0;
}