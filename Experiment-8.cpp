// By Ashutosh Kumar Yadav 22BAI10242
#include <iostream>      
#include <vector>        
#include <limits>        

using namespace std;      

template <typename T>
class Vector {
private:
    vector<T> vec;  // Internal vector to store elements

public:
    // Constructor to initialize the vector with a given size and default value
    Vector(int size, T defaultValue) {
        vec.resize(size, defaultValue);
    }

    // Adds an element to the vector
    void addElement(T element) {
        vec.push_back(element);
    }

    // Finds the smallest element in the vector
    T findSmallest() {
        T smallest = numeric_limits<T>::max();
        for (const auto& element : vec) {
            if (element < smallest) {
                smallest = element;
            }
        }
        return smallest;
    }

    // Searches for a specific element in the vector
    bool searchElement(T element) {
        for (const auto& elem : vec) {
            if (elem == element) {
                return true;
            }
        }
        return false;
    }

    // Calculates the average of the elements in the vector
    double findAverage() {
        T sum = 0;
        for (const auto& element : vec) {
            sum += element;
        }
        return static_cast<double>(sum) / vec.size();
    }

    // Prints all elements in the vector
    void printElements() {
        for (const auto& element : vec) {
            cout << element << " ";
        }
        cout << endl;
    }
};

int main() {
    Vector<int> intVector(0, 0);

    intVector.addElement(10);
    intVector.addElement(20);
    intVector.addElement(5);
    intVector.addElement(15);

    cout << "Elements in the vector: ";
    intVector.printElements();

    cout << "Smallest element: " << intVector.findSmallest() << endl;

    int searchFor = 20;
    cout << "Is " << searchFor << " present? " 
         << (intVector.searchElement(searchFor) ? "Yes" : "No") << endl;

    cout << "Average of elements is: " << intVector.findAverage() << endl;

}
