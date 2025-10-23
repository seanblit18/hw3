#include <iostream>
#include <fstream>
#include <functional>
#include "stack.h"
using namespace std;

int main() {
    Stack<int> s;

    cout << "is it empty? " << endl;

    if (s.empty()) {
        cout << "yes it is" << endl;
    }
    else {
        cout << "no it's not" << endl << endl;
    }

    cout << "let's add some elements just to make sure" << endl;

    s.push(2);
    s.push(3);
    s.push(24);
    s.push(3);
    s.push(90);
    s.push(67);

    int sizy = s.size();

    cout << "what is the size? should be 6" << endl;
    cout << "size is officially " << sizy << endl << endl;

    int lastitem = s.top();
    cout << "removing last item which is " << lastitem << endl;
    s.pop();

    cout << "remaining list is ";

    for (size_t i = 0; i < s.size(); i++) {
        int temp = s[i];
        cout << temp << " ";
    }
    cout << endl;

    return 0;
}