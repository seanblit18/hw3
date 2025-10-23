#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

struct removeEven {
    bool operator() (int k) {
        return (k % 2 == 0);
    }
};

struct removeOdd {
    bool operator() (int k) {
        return (k % 2 == 1);
    }
};

struct Only12or3 {
    bool operator() (int k) {
        return (k == 1 || k == 2 || k == 3);
    }
};



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code

    // PIVOT FUNCTIONS
    Node* taily = new Node(10, nullptr);
    Node* p5 = new Node(9, taily);
    Node* p4 = new Node(1, p5);
    Node* p3 = new Node(3, p4);
    Node* p2 = new Node(8, p3);
    Node* p1 = new Node(2, p2);

    cout << "Second list: ";
    print(p1);


    // Node* smallheadog = nullptr;
    // Node* largeheadog = nullptr;
    // Node* small = nullptr;
    // Node* big = nullptr;
    /* 
    llpivot(head, smallheadog, largeheadog, 10);
    llpivot(p1, small, big, 5);
    cout << "Splitting Original into smaller and bigger" << endl;
    cout << "smaller: ";
    print(smallheadog);
    cout << endl << endl << "larger: ";
    print(largeheadog);
    cout << endl;

    cout << "Splitting second into smaller and bigger" << endl;
    cout << "smaller: ";
    print(small);
    cout << endl << endl << "larger: ";
    print(big);
    cout << endl;
    */

    head = llfilter(head, removeOdd());

    cout << "new list: ";
    print(head);
    cout << endl;

    p1 = llfilter(head, Only12or3());

    cout << "2nd new list: ";
    print(p1);
    cout << endl;


    return 0;

}
