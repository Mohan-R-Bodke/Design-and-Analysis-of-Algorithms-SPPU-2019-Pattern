
// Problem Statement:-Write a program for analysis of quick sort by using deterministic and randomized variant.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//******************************************************************************


int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSortDe(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int p = partition(arr, start, end);

	quickSortDe(arr, start, p - 1);

	quickSortDe(arr, p + 1, end);
}

//******************************************************************************
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int generateRandomPivot(int low, int high) {
	srand(time(NULL));
	return low + rand() % (high - low + 1);
}

void quickSortRa(int arr[], int low, int high) {
	if (low < high) {
		int pivotIndex = generateRandomPivot(low, high);
		int pivotValue = arr[pivotIndex];

		swap(&arr[pivotIndex], &arr[high]);

		int i = low - 1;

		for (int j = low; j < high; j++) {
			if (arr[j] < pivotValue) {
				i++;
				swap(&arr[i], &arr[j]);
			}
		}

		swap(&arr[i+1], &arr[high]);

		quickSortRa(arr, low, i);
		quickSortRa(arr, i+2, high);
	}
}
//*************************************************************************
int main() {
	int n,choice;
	char ch;
	
	
	do
	{
	cout<<"\n*************Menu***************";
	cout<<"\n1. deterministic varient";
	cout<<"\n2. Randomize varient";
	cout<<"\n3. Exit";
	cout<<"\n********************************";
	cout<<"\nEnter Choice:";
	cin>>choice;
	
	if(choice==1)
	{
	cout<<"\nEnter Total No. of Element:";
	cin>>n;
	int arr[n];
	
	for(int i=0; i<n; i++)
	{
		cout<<"\nEnter Element "<<i+1<<":";
		cin>>arr[i];
	}
	cout << "\nOriginal array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	quickSortDe(arr, 0, n-1);

	cout << "\n\nSorted array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	}
	
	else if(choice==2)
	{
	cout<<"\nEnter Total No. of Element:";
	cin>>n;
	int arr[n];
	
	for(int i=0; i<n; i++)
	{
		cout<<"\nEnter Element "<<i+1<<":";
		cin>>arr[i];
	}
	
	cout << "\nOriginal array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	quickSortRa(arr, 0, n-1);

	cout << "\n\nSorted array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	}
	
	else if(choice==3)
	{
	exit(0);
	break;
	}
	
	else
	{
		cout<<"\n You Entered Wrong Choice";
	}
	
	cout<<"\n\nDo you want to continue:";
	cin>>ch;
	}while(ch=='Y'||ch=='y');

	return 0;
}


/*Output:
*************Menu***************
1. deterministic varient
2. Randomize varient
3. Exit
********************************
Enter Choice:1

Enter Total No. of Element:7

Enter Element 1:4

Enter Element 2:
2

Enter Element 3:7

Enter Element 4:5

Enter Element 5:4

Enter Element 6:3

Enter Element 7:6

Original array: 4 2 7 5 4 3 6 

Sorted array: 2 3 4 4 5 6 7 

Do you want to continue:y

*************Menu***************
1. deterministic varient
2. Randomize varient
3. Exit
********************************
Enter Choice:2

Enter Total No. of Element:8

Enter Element 1:56

Enter Element 2:3

Enter Element 3:6

Enter Element 4:34

Enter Element 5:3

Enter Element 6:
65

Enter Element 7:3

Enter Element 8:2

Original array: 56 3 6 34 3 65 3 2 

Sorted array: 2 3 3 3 6 34 56 65 

Do you want to continue:y

*************Menu***************
1. deterministic varient
2. Randomize varient
3. Exit
********************************
Enter Choice:3

Time Complexity: 
1. deterministic varient:O(n)
2. Randomize varient: O(n*n)

Space Complexity: 
1. deterministic varient: O(n)
2. Randomize varient ; O(n)

*/

