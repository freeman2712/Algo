#include <iostream>
#include <vector>
#include <sstream>
#include <string>
typedef std::vector<int> vi;
int minDiff(vi, int, int);
int min(int, int);
int main()
{
    int sum = 0;
    vi array;
    std::string input;
    std::string temp;
    getline(std::cin, input);
    std::stringstream ss(input);
    while(getline(ss, temp, ' '))
        array.push_back(std::stoi(temp));
    for(int i = 0; i<array.size(); i++)
        sum = sum + array[i];
    std::cout << minDiff(array, array.size(), sum);
}
int minDiff(vi ar, int n, int sum)
{
    int mind = sum;
    int dp[n+1][sum+1];
    for(int i = 0; i<=sum; i++)
        dp[0][i] = 0;
    for(int i = 0; i<=n; i++)
        dp[i][0] = 1;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=sum; j++)
        {
            if(j>=ar[i - 1])
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - ar[i - 1]];
            if(j<ar[i - 1])
                dp[i][j] = dp[i - 1][j];
        }
    
    for(int i = 0; i<=sum; i++)
        if(dp[n][i] && i<=(sum/2))
            mind = min(mind, sum - (2*i));
    return mind;

            
}
int min(int a, int b)
{
    if(a<b)
        return a;
    return b;
}