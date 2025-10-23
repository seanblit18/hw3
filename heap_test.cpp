#include <iostream>
#include <fstream>
#include <functional>
#include "heap.h"
using namespace std;

int main() {
    cout << "sample heap: " << endl;

    Heap<int> h;

    h.push(2);
    h.push(4);
    h.push(7);
    h.push(15);
    h.push(19);

    cout << "size: " << h.size() << endl;
    cout << "top item: " << h.top() << endl;

    h.pop();
    cout << "new top after pop: " << h.top() << endl; 

    while (!h.empty()) {
        cout << "pop: " << h.top() << endl;
        h.pop();
    }

    return 0;
}