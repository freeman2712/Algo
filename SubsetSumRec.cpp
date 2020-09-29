//SubsetSum Naíve Recursion

#include <iostream>
int SubsetSum(int*, int, int);
int main()
{
    int n, sum;
    std::cin >> n;                  //Number of element in Array
    int ar[n];                      
    for(int i = 0; i<n; i++)
        std::cin >> ar[i];
    std::cin >> sum;                //Sum
    std::cout << SubsetSum(ar, n, sum); 
}
int SubsetSum(int* ar, int n, int sum)
{
    if(n == 0 || sum <0)
        return 0;
    if(sum == 0)
        return 1;
    return SubsetSum(ar, n-1, sum-ar[n-1])||SubsetSum(ar, n-1, sum);
}