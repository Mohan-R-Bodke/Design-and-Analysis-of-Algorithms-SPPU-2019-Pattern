
// Problem Statement:-Write a program to solve a fractional Knapsack problem using a greedy method.


#include <iostream>
using namespace std;

void readObjects(int n, int weights[], int profits[]){
    for (int i = 0; i < n; i++) {
        cout << "Enter weight for object " << i + 1 << ": ";
        cin >> weights[i];
        cout << "Enter profit for object " << i + 1 << ": ";
        cin >> profits[i];
    }
}
void sortByRatio(int n, int weights[], int profits[], double ratios[]){
    for (int i = 0; i < n; i++) {
        ratios[i] = (double)profits[i] / weights[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratios[i] < ratios[j]) {
                swap(ratios[i], ratios[j]);
                swap(weights[i], weights[j]);
                swap(profits[i], profits[j]);
            }
        }
    }
}
double solveKnapsack(int n, int weights[], int profits[], double ratios[], int capacity){
    double totalProfit = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weights[i] <= capacity) {
            currentWeight += weights[i];
            totalProfit += profits[i];
        } else {
            double remainingCapacity = capacity - currentWeight;
            totalProfit += ratios[i] * remainingCapacity;
            break;
        }
    }

    return totalProfit;
}

int main() {
    int choice;
    int n;
    int weights[100], profits[100];
    double ratios[100];
    int capacity;
    double totalProfit;

    while (true) {
        cout << "************Menu*********"<<endl;
        cout << "1. Read objects info"<<endl;
        cout << "2. Calculate maximum profit"<<endl;
        cout << "3. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter total number of objects: ";
                cin >> n;
                readObjects(n, weights, profits);
                break;
            case 2:
                if (n > 0) {
                    sortByRatio(n, weights, profits, ratios);
                    cout << "Enter knapsack capacity: ";
                    cin >> capacity;
                    totalProfit = solveKnapsack(n, weights, profits, ratios, capacity);
                    cout << "Maximum profit: " << totalProfit << endl;
                } else {
                    cout << "read object info first." << endl;
                }
                break;
            case 3:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. " << endl;
        }
    }

    return 0;
}


/*************Menu*********
1. Read objects info
2. Calculate maximum profit
3. Exit
Enter your choice: 1
Enter total number of objects: 7
Enter weight for object 1: 1
Enter profit for object 1: 5
Enter weight for object 2: 3
Enter profit for object 2: 10
Enter weight for object 3: 5
Enter profit for object 3: 15
Enter weight for object 4: 4
Enter profit for object 4: 7
Enter weight for object 5: 1
Enter profit for object 5: 8
Enter weight for object 6: 3
Enter profit for object 6: 9
Enter weight for object 7: 2
Enter profit for object 7: 4
************Menu*********
1. Read objects info
2. Calculate maximum profit
3. Exit
Enter your choice: 2
Enter knapsack capacity: 15
Maximum profit: 51
************Menu*********
1. Read objects info
2. Calculate maximum profit
3. Exit
Enter your choice: 3
Exiting program.

Time Complexity: O(n* log n)

Space Complexity: O(n)

*/

