# include<iostream>
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

int main() {
    minHeap h(10);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);
    h.insert(3);
    h.insert(2);
    h.insert(1);
    h.printArr();
    return 0;
}