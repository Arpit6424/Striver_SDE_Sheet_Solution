class MedianFinder {
public:
    
    priority_queue<int> maxheap;
    priority_queue<int, vector<int> , greater<int>> minheap;
    int maxheap_size;
    int minheap_size;
    MedianFinder() {
        minheap_size = 0;
        maxheap_size = 0;
        
    }
    
    void addNum(int num) {
        
       if(maxheap_size==0 || maxheap.top() >= num){
           maxheap.push(num);
           maxheap_size++;
       }else{
           minheap.push(num);
           minheap_size++;
       }
        
        
        
      if(maxheap_size -1 > minheap_size){
          
          minheap.push(maxheap.top());
          maxheap.pop();
          maxheap_size--,minheap_size++;
      }
      else if(maxheap_size < minheap_size){
          maxheap.push(minheap.top());
          minheap.pop();
          minheap_size--;maxheap_size++;
      }
        
        
        
        
        
    }
    
    double findMedian() {
        
        if(maxheap_size == minheap_size)return ( maxheap.top() + minheap.top())/2.0;
        else return maxheap.top()*1.0;
    }
};

















// class MedianFinder {
// public:
    
//     priority_queue<int> maxheap;
//     priority_queue<int, vector<int> , greater<int>> minheap;
//     int maxheap_size;
//     int minheap_size;
//     MedianFinder() {
//         minheap_size = 0;
//         maxheap_size = 0;
        
//     }
    
//     void addNum(int num) {
        
//         if(maxheap_size == 0  && minheap_size == 0  ){
//             maxheap.push(num);
//             maxheap_size++;
//         } 
        
//         else if (maxheap_size == minheap_size){
            
//             if(maxheap.top()<num){
//                 minheap.push(num);
//                 minheap_size++;
//             }
//             else{
//                 maxheap.push(num);
//                 maxheap_size++;
//             }
//         }
//         else if(maxheap_size > minheap_size){
//              if(maxheap.top()>num){
//                  int temp = maxheap.top();
//                  maxheap.pop();
//                  minheap.push(temp);
//                  maxheap.push(num);
//              }
//             else
//                 minheap.push(num);
//             minheap_size++;            
//         }
//         else if(maxheap_size < minheap_size){
            
//             if(minheap.top() < num){
//                 int temp = minheap.top();
//                 minheap.pop();
//                 maxheap.push(temp);
//                 minheap.push(num);
//             }
//             else
//                 maxheap.push(num);
                
//             maxheap_size++;
                
//         }
        
        
//     }
    
//     double findMedian() {
        
//         if(maxheap_size == minheap_size)return ( maxheap.top() + minheap.top())/2.0;
//         else if(maxheap_size > minheap_size)return maxheap.top() * 1.0;
//         else return  minheap.top() * 1.0;
        
//     }
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */