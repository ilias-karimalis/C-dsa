#include "heap.cpp"

class MinQueue {
    private:
        MinHeap h;
    public:
        void insert(int x) {
            h.push(x);
        }

        int min() {
            return h.top();
        }

        int getMin() {
            return h.pop();
        }

        //decreaseKey(int key, int newKey);
};

int main() {
    MinQueue q;
    q.insert(5);
    q.insert(2);
    q.insert(1);
    q.insert(9);
    cout << q.getMin() << endl;
    cout << q.getMin() << endl;
    cout << q.getMin() << endl;
    cout << q.getMin() << endl;
}
