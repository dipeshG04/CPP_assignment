#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> myQueue;

    // Add elements to the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Display the front element of the queue
    cout << "Front element: " << myQueue.front() << endl;

    // Remove the front element from the queue
    myQueue.pop();

    // Display the front element after dequeue
    cout << "Front element after dequeue: " << myQueue.front() << endl;

    // Check if the queue is empty
    if (myQueue.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }

    // Display the size of the queue
    cout << "Size of the queue: " << myQueue.size() << endl;

    // Add more elements to the queue
    myQueue.push(40);
    myQueue.push(50);

    // Display the front element of the queue
    cout << "Front element after adding more elements: " << myQueue.front() << endl;

    // Display the size of the queue after adding more elements
    cout << "Size of the queue after adding more elements: " << myQueue.size() << endl;

    return 0;
}
