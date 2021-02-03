#include <iostream>
#include <vector>

#define LEFT(i) (2 * i)
#define RIGHT(i) (2 * i + 1)

using namespace std;

class MinHeap {
    private:
        vector<int> arr;

        int parent(int i) {
            return i / 2;
        }

        void heapify_down(int i) {
            int left = LEFT(i);
            int right = RIGHT(i);
            int smallest = i;
            if (left < size() && arr[left] < arr[i]) {
                smallest = left;
            }
            if (right < size() && arr[right] < arr[smallest]) {
                smallest = right;
            }
            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                heapify_down(smallest);
            }
        }

        void heapify_up(int i) {
            if (i > 1 && arr[i] < arr[parent(i)]) {
                swap(arr[i], arr[parent(i)]);
                heapify_up(parent(i));
            }
        }

    public:
        MinHeap() {
            arr.push_back(0);
        }

        unsigned int size() {
            return arr.size() - 1;
        }

        bool empty() {
            return arr.size() == 1;
        }

        void push(int key) {
            arr.push_back(key);
            heapify_up(size()); // Might be wrong
        }

        int pop() {
            int res = arr[1];
            if (!empty()) {
                arr[1] = arr.back();
                arr.pop_back();
                heapify_down(1);
            } else {
                cout << "MinHeap is empty" << endl;
            }
            return res;
        }

        int top() {
            if (!empty()) {
                return arr[1];
            } else {
                cout << "MinHeap is empty" << endl;
            }
            return 0;
        }

        void print() {
            for (int i = 1; i < arr.size(); i++) {
                cout << arr[i] << endl;
            }
        }
};

//int main() {
//    MinHeap h;
//    h.push(100);
//    h.push(312);
//    h.push(32);
//    h.push(545);
//    h.push(12);
//    h.push(2);
//    h.push(1);
//    h.print();
//    return 1;
//}

