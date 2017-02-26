#include <bits/stdc++.h>

using namespace std;

// Bubble Sort Iterative Method
vector<int> bubbleSort(vector<int> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        // Last i elements are already in place
        for (int j = 1; j < (arr.size() - i); ++j)
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
    }
    return arr;
}

// Bubble Sort Recursive Method
vector<int> bubbleSortRecursive(vector<int> arr) {
    if (arr.size() <= 1) return arr;
    // Find max value and move it the last index
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] > arr[i])
            swap(arr[i], arr[i - 1]);
    }
    // Store the max element
    int Max = arr[arr.size() - 1];
    // Remove it from the Array
    arr.pop_back();
    // Sort the remaining items
    arr = bubbleSortRecursive(arr);
    // Append the max value to the sorted array
    arr.push_back(Max);
    return arr;
}


int main() {
    //Testing
    vector<int> myList, mySortedList;
    myList.push_back(10);
    myList.push_back(4);
    myList.push_back(2);
    myList.push_back(90);
    myList.push_back(100);
    myList.push_back(3);
    myList.push_back(13);
    myList.push_back(17);
    myList.push_back(9);
    myList.push_back(76);
    myList.push_back(77);
    myList.push_back(77);
    myList.push_back(77);
    myList.push_back(-99);


    mySortedList = bubbleSortRecursive(myList);
    for (int i = 0; i < myList.size(); ++i) {
        cout << myList[i];
        //Just formatting the output
        if (i + 1 < myList.size()) cout << " - ";
        else cout << endl;
    }

    for (int i = 0; i < myList.size(); ++i) {
        cout << mySortedList[i];
        //Just formatting the output
        if (i + 1 < mySortedList.size()) cout << " - ";
        else cout << endl;
    }
}
