#include <iostream>
int SubsetSum(int*, int, int);
int main()
{
    int n, sum;
    std::cin >> sum;
    std::cin >> n;
    int ar[n];
    for(int i = 0; i<n; i++)
        std::cin >> ar[i];
    std::cout << SubsetSum(ar, sum, n);
}
int SubsetSum(int* ar, int sum, int n)
{
    int dp[n+1][sum+1];
    for(int i = 0; i<=sum; i++)
        dp[0][i] = 0;
    for(int i = 0; i<=n; i++)
        dp[i][0] = 1;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=sum; j++)
        {
            if(ar[j]<=sum)
                dp[i][j] = dp[i-1][j] || dp[i-1][j - ar[j]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}