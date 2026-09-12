class MinStack {
    int topStack;
    int arr[30000] = {};

    int topMinStack;
    int arrMin[30000] = {};

public:
    MinStack() {
        this->topStack = -1;
        this->topMinStack = -1;
    }

    void push(int val) {
        topStack++;
        arr[topStack] = val;
        if (topMinStack == -1 || val <= arrMin[topMinStack]) {
            topMinStack++;
            arrMin[topMinStack] = val;
        }
    }

    void pop() {
        if (arrMin[topMinStack] == arr[topStack]) {
            topMinStack--;
        }
        topStack--;
    }

    int top() {
        return arr[topStack];
    }

    int getMin() {
        return arrMin[topMinStack];
    }
};