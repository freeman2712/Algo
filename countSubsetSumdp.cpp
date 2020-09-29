#include <iostream>
#include <sstream>
#include <vector>
typedef std::vector<int> vi;
int countSubset(vi, int, int);
int main()
{
    int sum;
    std::string inp, temp;
    vi array;
    std::cin >> sum;
    std::cin.ignore();
    getline(std::cin, inp);
    std::stringstream ss(inp);
    while(getline(ss, temp, ' '))
        array.push_back(std::stoi(temp));
    std::cout << countSubset(array, array.size(), sum);

}
int countSubset(vi array, int n, int sum)
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
            if(j>=array[i-1])
                dp[i][j] = dp[i-1][j] + dp[i-1][j - array[i - 1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}