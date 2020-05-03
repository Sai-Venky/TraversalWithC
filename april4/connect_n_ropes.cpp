#include<iostream>
using namespace std;
class minHeap {
    int capacity;
    int curHeapSize;
    int *heapArr;
    public:

    minHeap(int cap) {
        capacity = cap;
        curHeapSize = 0;
        heapArr = (int *)malloc(sizeof(int) * cap);
    }
    
    void swap (int * arr, int i , int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }    

    int parent(int i) {
        return (i-1)/2;
    }

    int left(int i) {
        return (2*i)+1;
    }

    int right(int i) {
        return (2*i)+2;
    }

    int heapSize() {
        return curHeapSize;
    }

    void minHeapify(int i) {
        int l = left(i); 
        int r = right(i); 
        int smallest = i; 
        if (l < curHeapSize && heapArr[l] < heapArr[i]) 
            smallest = l; 
        if (r < curHeapSize && heapArr[r] < heapArr[smallest]) 
            smallest = r; 
        if (smallest != i) 
        { 
            swap(heapArr, i, smallest);
            minHeapify(smallest); 
        } 
    }

    int extractMin() {
        if(curHeapSize==0) {
            return INT_MAX;
        }
        else if(curHeapSize==1) {
            curHeapSize--;
            return heapArr[curHeapSize];
        }

        int root = heapArr[0];
        curHeapSize--;
        heapArr[0] = heapArr[curHeapSize];
        minHeapify(0);
        return root;
    }

    void decreaseKey(int key, int reduceValue) {
        heapArr[key] = reduceValue;
        int i = key;
        while(i!=0) {
            int curParent = parent(i);
            int curParentValue = heapArr[curParent];
            if(curParentValue > heapArr[i]) {
                swap(heapArr, i, curParent);
                i = curParent;
            }
        };
    }

    void deleteKey(int key) {
        decreaseKey(key, INT_MAX);
        int value = extractMin();
    }

    void insert(int newValue) {
        heapArr[curHeapSize] = newValue;

        for(int k = curHeapSize; k!=0;) {
            int curParent = parent(k);
            int curParentValue = heapArr[curParent];
            if(curParentValue > newValue) {
                swap(heapArr, k, curParent);
                k = curParent;
            } else {
                break;
            }
        }
        curHeapSize++;
    }

    void printArr() {
        for (int i =0; i<curHeapSize; i++) {
            cout<<heapArr[i]<<" ";
        }
        cout<<"\n";
    }
};

int calculateMinCost(int *arr, int size) {
    minHeap h(20);
    for (int i=0; i<size;i++) {
        h.insert(arr[i]);
    }
    int sum = 0;
    int smallestElement, nextSmallestElement;
    while (h.heapSize()!=1) {
        smallestElement = h.extractMin();
        nextSmallestElement = h.extractMin();
        int sumOfElements = smallestElement + nextSmallestElement;
        sum = sum + sumOfElements;
        h.insert(sumOfElements);
    };

    return sum;
}
int main() {
    int len[] = { 4, 3, 2, 6}; 
    int sum = 0;
    int size = sizeof(len) / sizeof(len[0]); 
    cout<<calculateMinCost(len, size);

    return 0;
}