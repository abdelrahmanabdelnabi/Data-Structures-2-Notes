#include <bits/stdc++.h>

using namespace std;

//Function to merge two sorted arrays
//Returns a sorted array of size (a.size() + b.size())
vector<int> Merge(vector<int> a, vector<int> b) {
    vector<int> mergedList;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) mergedList.push_back(a[i++]);
        else mergedList.push_back(b[j++]);
    }

    while (i < a.size())
        mergedList.push_back(a[i++]);

    while (j < b.size())
        mergedList.push_back(b[j++]);

    return mergedList;
}

vector<int> MergeSort(vector<int> arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    //Get Array Middle index
    size_t n = arr.size() / 2;

    // Split Array into two smaller Arrays
    vector<int> leftArr(arr.begin(), arr.begin() + n);
    vector<int> rightArr(arr.begin() + n, arr.end());

    // Recursive calls to move to smaller sub-problems;
    // and save the return value which is a sorted array of size n/2
    leftArr = MergeSort(leftArr);
    rightArr = MergeSort(rightArr);

    //Merge the two sorted array into 1 array;
    vector<int> sortedArr = Merge(leftArr, rightArr);
    return sortedArr;
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


    mySortedList = MergeSort(myList);

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
