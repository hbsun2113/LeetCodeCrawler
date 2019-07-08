class MyCircularQueue {
public:
    // 算是自己写的吧，别人的代码参考价值可能不大，这个基本自己能写出来的
    // 这个做法也比较简洁，下回可以看一下：https://leetcode.com/problems/design-circular-queue/discuss/149420/Concise-Java-using-array
    
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        vec.clear();
        vec.resize(k);
        front=0;
        tail=0;
        is_empty=true;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        vec[tail]=value;
        tail++;
        tail%=vec.size();
        if(tail==front) is_empty=false;  // 只有insert的时候，队列才可能为慢
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        front++;
        front%=vec.size();
        if(tail==front) is_empty=true;   // 只有insert的时候，队列才可能为空
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return vec[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return vec[(tail-1+vec.size())%vec.size()]; // 这行需要特别留心一下
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (tail==front && is_empty);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(front==tail && !is_empty) return true;
        return false;
    }
    
    vector<int> vec;
    bool is_empty; // 这个标志位应该是必须的：用来辨别到底是空的，还是满的
    
    
    // front指向的是有效的头结点
    // tail指向的是第一个空位置
    int tail,front;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */