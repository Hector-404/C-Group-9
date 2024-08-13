#include <iostream>
using namespace std;

template <typename T>
T findLargest(T a, T b, T c) {
    T largest = a;
    if (b > largest) {
        largest = b;
    }
    if (c > largest) {
        largest = c;
    }
    return largest;
}


int main() {
    int a, b, c;
    cout<<"Enter the first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    cout<<"Enter third number: ";
    cin>>c;
    cout << "Largest of three integers: " << findLargest(a, b, c) << endl;

    return 0;
};