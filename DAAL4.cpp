
// Problem Statement:-Write a program to solve a 0-1 Knapsack problem using dynamic programming or branch and bound strategy.

#include <iostream>
using namespace std;

int max(int a, int b) 
{ return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
	if (n == 0 || W == 0)
		return 0;

	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);
	else
		return max(
			val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
			knapSack(W, wt, val, n - 1));
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int *profit = new int[n];
    int *weight = new int[n];

    
    for (int i = 0; i < n; i++)
    {
    	cout << "Enter the profits of the items "<<i+1<<": ";
        cin >> profit[i];
        cout << "Enter the weights of the items "<<i+1<<": ";
        cin >> weight[i];
    }

    cout<<"\nProfit --> Weight";
    for (int i = 0; i < n; i++)
    {
      cout<<"\n"<<profit[i]<<"-->"<<weight[i];  
    }

	int W;
    cout << "\nEnter the knapsack capacity: ";
	cin >> W;

	cout << "\nMaximum value in the knapsack: " << knapSack(W, weight, profit, n) << endl;

	delete[] profit;
	delete[] weight;

	return 0;
}

/*Output:
Enter the number of items: 3
Enter the profits of the items 1: 2
Enter the weights of the items 1: 4
Enter the profits of the items 2: 3
Enter the weights of the items 2: 5
Enter the profits of the items 3: 4
Enter the weights of the items 3: 3

Profit --> Weight
2-->4
3-->5
4-->3
Enter the knapsack capacity: 4

Maximum value in the knapsack: 4


Time Complexity: O(n*w)

Space Complexity: O(n*w)
*/

