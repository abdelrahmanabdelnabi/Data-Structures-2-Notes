#include <bits/stdc++.h>

using namespace std;


class BinaryMinHeap
{
private:
    //Dynamic array to hold the values
    vector<int> data;
    //Direction flag
    // 0  ==  valueRemoved  == top-down heapify-ing
    // 1  ==  valueInserted == bottom-up heapify-ing
    bool direction;

public:
    void showHeap()
    {
        for(int i = 0; i < data.size(); ++i)
        {
            cout << data[i] << " - ";
        }
        cout << endl;
    }

    void insert(int value)
    {
        //insert the new value to the first free node
        data.push_back(value);
        // set direction for bottom-up heapify-ing
        direction = 1;
        heapify();
    }

    int getMin()
    {
        if(data.empty()) return -1;
        return data[0];
    }

    int popMin()
    {
        int minValue;
        if(data.empty())
        {
            minValue = -1;
        }
        else if(data.size() == 1)
        {
            minValue = data[0];
            data.clear();
        }
        else
        {
            direction = 1;
            minValue = data[0];
            data[0] = data[data.size() - 1];
            data.pop_back();
        }
        direction = 0;
        heapify();
        return minValue;
    }


private:
    void heapify()
    {
        // Bottom-up Heapify
        if(direction)
        {
            int child = data.size() - 1;
            int parent = (child - 1) / 2;
            while(child != parent)
            {
                if(data[parent] > data[child])
                    swap(data[parent], data[child]);
                child = parent;
                parent = (child - 1) / 2;
            }
        }
        // Top-Down Heapify
        else
        {
            int parent = 0;
            int leftChild = 2 * parent + 1;
            int rightChild = 2 * parent + 2;
            int size = data.size();
            while(leftChild < size)
            {
                //if last node has both left-child and right-child
                if(rightChild < size)
                {
                    //check for the min child
                    int smaller = min(data[leftChild], data[rightChild]);
                    //if the min was the left child
                    if(smaller == data[leftChild])
                    {
                        //if the min was less than the parent value
                        if(data[leftChild] < data[parent])
                            swap(data[leftChild], data[parent]);
                        //then the new parent is equal to the left child
                        parent = leftChild;
                        leftChild = 2 * parent + 1;
                        rightChild = 2 * parent + 2;
                        continue;
                    }
                    //else if the min value was on the right child "branch"
                    else
                    {
                        //if the min was the right child
                        if(data[rightChild] < data[parent])
                            swap(data[rightChild], data[parent]);
                        //then the new parent is equal to the right child
                        parent = rightChild;
                        leftChild = 2 * parent + 1;
                        rightChild = 2 * parent + 2;
                        continue;
                    }
                }
                //if the last node has only left child
                else if(data[leftChild] < data[parent])
                {
                    swap(data[leftChild], data[parent]);
                }
                parent = leftChild;
                leftChild = 2 * parent + 1;
                rightChild = 2 * parent + 2;
            }
        }
    }
};
int main()
{
    /*
    Index is written between braces
    =========================================
    Input data: 4, 10, 3, 5, 1


             1(0)
            /   \
          3(1)   4(2)
          /   \
      10(3)    5(4)

    =========================================
    Pop Minimum:

             3(0)
            /    \
          5(1)    4(2)
         /   \
      10(3)  Removed(4)

    =========================================
     Pop Minimum Again:


             4(0)
            /    \
          5(1)    10(2)
         /   \
      Removed(3)  Removed(4)
    =========================================
    */

    BinaryMinHeap *myHeap = new BinaryMinHeap();
    myHeap->insert(4);
    myHeap->showHeap();
    myHeap->insert(10);
    myHeap->showHeap();
    myHeap->insert(3);
    myHeap->insert(5);
    myHeap->showHeap();
    myHeap->insert(1);
    myHeap->showHeap();
    myHeap->popMin();
    myHeap->showHeap();
    myHeap->popMin();
    myHeap->showHeap();

    return 0;
}
