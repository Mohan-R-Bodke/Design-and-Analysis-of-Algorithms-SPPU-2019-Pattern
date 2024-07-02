
/* Problem Statement:- Write a program non-recursive and recursive program to calculate Fibonacci numbers and analyze
their time and space complexity. */

#include<iostream>
using namespace std;

int rfib(int n)
{
int a = 0;
int b = 1;

if (n == 0)
    return 0;
else if(n ==1 )
    return 1;
else
{
    return rfib(n-1)+rfib(n-2);
}
}

int nrfib(int n)
{
int a=0,b=1,c;
cout<<a<<"\t"<<b<<"\t";
for(int i=2;i<n;i++)
{
c=a+b;
cout<<c<<"\t";
a=b;
b=c;
}
}

int main()
{
int n,choice;
char ch;
do{

cout<<"**************MENU***************\n";
cout<<"1. Non Recursion fibonacci series\n";
cout<<"2. Recursion fibonacci series\n";
cout<<"3. Exit\n";
cout<<"*********************************\n";
cout<<"Enter the Choice:";
cin>>choice;

switch(choice)
{

case 1:
    cout<<"\nRecursion fibonacci series";
    cout<<"\nEnter the number:";
    cin>>n;
    nrfib(n);
    break;

case 2:
    cout<<"\nRecursion fibonacci series";
    cout<<"\nEnter the number:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<rfib(i)<<"\t";
    }
    break;

case 3:
    exit(0);
    break;
    
default:
    cout<<"\nEnter Valid Choice(1 to 3)";
    break;
}
cout<<"\nDo you want to return menu(Y/N):";
cin>>ch;

}while(ch=='y'||ch=='Y');
return 0;
}



/*Output:

**************MENU***************
1. Non Recursion fibonacci series
2. Recursion fibonacci series
3. Exit
*********************************
Enter the Choice:1

Non Recursion fibonacci series
Enter the number:18
0	1	1	2	3	5	8	13	21	34	55	89	144	233	377	610	987	1597	
Do you want to return menu(Y/N):y
**************MENU***************
1. Non Recursion fibonacci series
2. Recursion fibonacci series
3. Exit
*********************************
Enter the Choice:2

Recursion fibonacci series
Enter the number:13
0	1	1	2	3	5	8	13	21	34	55	89	144	
Do you want to return menu(Y/N):y
**************MENU***************
1. Non Recursion fibonacci series
2. Recursion fibonacci series
3. Exit
*********************************
Enter the Choice:3


Time Complexity:
    Recursion     :- O(n)
    Non-Recursion :- O(n)

Space Complexity:
    Recursion     :- O(n)
    Non-Recursion :- O(1)
*/
