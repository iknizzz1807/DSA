#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

struct list {
    node *head;
    node *tail;
};

void addTail(list *&list, int data) {
    node *newNode = new node;
    if (list->head == nullptr) {
        newNode->data = data;
        newNode->next = nullptr;
        list->head = list->tail = newNode;
    } else {
        newNode->data = data;
        list->tail->next = newNode;
        list->tail = newNode;
        list->tail->next = nullptr;
    }
}

void addHead(list *&list, int data) {
    node *newNode = new node;
    if (list->head == nullptr) {
        newNode->next = nullptr;
        newNode->data = data;
        list->head = list->tail = newNode;
    } else {
        newNode->data = data;
        newNode->next = list->head;
        list->head = newNode;
    }
}

void createEmptyList(list *&lst) {
    lst = new list;
    lst->head = nullptr;
    lst->tail = nullptr;
}

void importList(list *&list) {
    addTail(list, 3);
    addHead(list, 8);
    addTail(list, 5);
    addHead(list, 1);
    addHead(list, 7);
    addTail(list, 9);
    addHead(list, 13);
}

void printList(list *list) {
    node* pointer = list->head;
    while(pointer != nullptr) {
        cout << pointer->data << " ";
        pointer = pointer->next;
    }
}

int main() {
    list *list;
    createEmptyList(list);
    importList(list);
    printList(list);
    return 0;
}
