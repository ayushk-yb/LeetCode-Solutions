class MyStack {
private:
    queue<int> myQueue;

public:
    MyStack() {
    }

    void push(int x) {
        myQueue.push(x);
        int size = myQueue.size();
        for (int i = 0; i < size - 1; ++i) {
            myQueue.push(myQueue.front());
            myQueue.pop();
        }
    }

    int pop() {
        if (empty()) {
            return -1; 
        }

        int popped_element = myQueue.front();
        myQueue.pop();
        return popped_element;
    }

    int top() {
        if (empty()) {
            return -1;
        }

        return myQueue.front();
    }

    bool empty() {
        return myQueue.empty();
    }
};
