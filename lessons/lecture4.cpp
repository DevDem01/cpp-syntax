#include <iostream>

struct Node {

    int value; 
    Node* next;

};

// insert new node to tail of the linked list
void insert (Node*& head, int value) {

    Node* newNode = new Node {value, nullptr};

    // if linked list is empty:
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // find the tail and insert
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;

}

// remove the first node with target value
void remove(Node*& head, int target) {

    // case 1: the list is empty
    if (head == nullptr) {
        return;
    }

    // case 2: head.value == target
    if (head->value == target) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    // case 3: search then remove
    Node* current = head; // start the search from the head

    while(current->next != nullptr 
        && current->next->value != target) {
        current = current->next;
    }

    // // case 3.1: cannot find the target
    // if (current->next == nullptr) {
    //     return;
    // }
    // // case 3.2: find the target node
    // else {
    //     Node* temp = current->next;  // target node
    //     current->next = temp->next;
    //     delete temp;
    //     return;
    // }

    if (current->next != nullptr) {
        Node* temp = current->next;  // target node
        current->next = temp->next;
        delete temp;
        return;
    }

}

void printList(Node* head) {

    while(head != nullptr) {
        std::cout << head->value ;
        if (head->next != nullptr) {
            std::cout << "->"; 
        }
        head = head->next;
    }

    std::cout << std::endl;

}

void clearList(Node*& head) {

    while(head != nullptr) {
        Node* temp = head;
        head = head->next;
        std::cout << "deleting node " << temp->value << std::endl;
        delete temp;
    }

}

int main() {

    Node* head = nullptr;

    insert(head, 10);
    printList(head);
    insert(head, 20);
    printList(head);
    insert(head, 30);
    printList(head);

    // remove(head, 20);
    // printList(head);
    // remove(head, 10);
    // printList(head);

    clearList(head);

    return 0;
}