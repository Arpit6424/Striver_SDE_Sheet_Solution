class Queue {
public:
    int arr[1000];
    int frontind;
    int rear;
    public:
    Queue() {
        frontind = -1;
        rear = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(frontind==-1 || frontind > rear)return true;
        return false;
    }

    void enqueue(int data) {
        if(rear+1 == 1000)return ;
            rear++;
            arr[rear]= data;
        if(frontind==-1)frontind++;
        
    }

    int dequeue() {
        // Implement the dequeue() function
        if(frontind==-1 ||  frontind > rear)return -1;
        int element = arr[frontind];
        frontind++;
        if( frontind > rear){
            frontind = rear = -1;
        }
        return element;
        
    }

    int front() {
        // Implement the front() function
        if(frontind==-1 ||  frontind > rear)return -1;
        else return arr[frontind];
    }
};