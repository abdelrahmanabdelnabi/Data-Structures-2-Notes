#include <bits/stdc++.h>

using namespace std;

vector<int> selectionSort(vector<int> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        //Assume the i-th element is the minimum
        int Min = i;
        //Find the minimum in the unsorted array
        for (int j = i + 1; j < arr.size(); ++j)
            if (arr[j] < arr[i])
                Min = j;
        //Replace the found minimum with the assumed minimum
        swap(arr[i], arr[Min]);
    }
    return arr;
}

vector<int> selectionSortRecursive(vector<int> arr) {
    if (arr.size() <= 1) return arr;
    // Assume last element is the biggest
    int Max = arr.size() - 1;
    // Test the previous assumption
    // if wrong update your Max
    for (int i = arr.size() - 1; i > -1; --i) {
        if (arr[Max] < arr[i]) Max = i;
    }
    // Replace the assumed Max with the actual Max
    swap(arr[Max], arr[arr.size() - 1]);
    // Store the Max Value
    Max = arr[arr.size() - 1];
    // Remove it from the array
    arr.pop_back();
    // Re-run on the smaller array
    arr = selectionSortRecursive(arr);
    // Append The Max again
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


    mySortedList = selectionSortRecursive(myList);
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
