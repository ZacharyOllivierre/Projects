#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void addNode(Node*& head, int data);
void outputList(Node*head, int size);

int main() {
    Node* head = nullptr;
    int size;

    cout << "Enter number of nodes to create: ";
    cin >> size;

    for (int x = 0; x < size; x++) {
        addNode(head, x + 1);
    }
    outputList(head, size);

    return 0;
}

void addNode(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr};
    Node* temp = head;

    if (head == nullptr) {
        head = newNode;
        return;
    } 

    while (temp->next != nullptr) {
        temp = temp->next;
    }
    
    temp->next = newNode;
}

void outputList(Node*head, int size) {
    for (int x = 0; x < size; x++) {
        cout << head->data << " ";
        head = head-> next;
    }
    cout << endl;
}