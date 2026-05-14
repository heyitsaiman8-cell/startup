#include<iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    cout << "Welcome to C++ programming." << endl;
    int x = 10; 
    int y = 20;
    int sum = x + y;
    cout << "The sum of " << x << " and " << y << " is: " << sum << endl;       
    cout<<"now its time to swap the values of x and y" << endl;
    int temp = x;   
    x = y;
    y = temp;
    cout << "After swapping, x is: " << x << " and y is:    " << y << endl;
    cout << "Now we will check if x is greater than y" << endl;
    if (x > y) {
        cout << "x is greater than y" << endl;
    } else if (x < y) {
        cout << "x is less than y" << endl;
    } else {
        cout << "x and y are equal" << endl;
    }
    cout << "Now we will use a loop to print numbers from 1 to 5" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }   
    cout << endl;

}   