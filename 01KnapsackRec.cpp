// 01 Knapsack Problem Using Naíve Recursion


#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int Knapsack(int, std::vector<int>, std::vector<int>, int);
int max(int, int);

int main()
{
    std::vector<int> weight;
    std::vector<int> price;
    int W;
    std::cin >> W;
    std::string weight_input;
    std::cin.ignore();
    std::getline(std::cin, weight_input);
    std::string price_input;
    std::getline(std::cin, price_input);
    std::string temp;
    std::stringstream ss(weight_input);
    while(getline(ss, temp, ' '))
        weight.push_back(std::stoi(temp));
    std::stringstream ss1(price_input);
    while(getline(ss1, temp, ' '))
        price.push_back(std::stoi(temp));
    std::cout << Knapsack(W, weight, price, weight.size());
}
int Knapsack(int W, std::vector<int> weight, std::vector<int> price, int n)
{
    if(W == 0 || n == 0)
        return 0;
    if(weight[n-1] > W)
        return Knapsack(W, weight, price, n-1);
    else
        return max(price[n-1] + Knapsack(W - weight[n-1], weight, price, n-1), Knapsack(W, weight, price, n-1));
    
}
int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}
