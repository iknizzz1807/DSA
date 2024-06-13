#include <iostream>

using namespace std;

struct hocSinh {
    int maSV;
    string hoTen;
    hocSinh(int maSV, string hoTen) : maSV(maSV), hoTen(hoTen) {};
};

struct node {
    hocSinh *hocSinh;
    node *next;
};

struct list {
    node *head;
    node *tail;
};

struct hashTable {
    int size = 10;
    list *table;
};

int hf(int maSV) {
    return maSV % 10;
}

void createEmptyTable(hashTable &hashTable) {
    hashTable.table = new list[hashTable.size];
    for (int i = 0; i < hashTable.size; i++) {
        hashTable.table[i].head = nullptr;
        hashTable.table[i].tail = nullptr;
    }
}

void insert(hashTable &hashTable, hocSinh *hocSinh) {
    if(hashTable.table[hf(hocSinh->maSV)].head == nullptr) {
        hashTable.table[hf(hocSinh->maSV)].head = new node();
        hashTable.table[hf(hocSinh->maSV)].head->hocSinh = hocSinh;
        hashTable.table[hf(hocSinh->maSV)].head->next = nullptr;
        hashTable.table[hf(hocSinh->maSV)].tail = hashTable.table[hf(hocSinh->maSV)].head;
    }
    else {
        hashTable.table[hf(hocSinh->maSV)].tail->next = new node();
        hashTable.table[hf(hocSinh->maSV)].tail->next->next = nullptr;
        hashTable.table[hf(hocSinh->maSV)].tail->next->hocSinh = hocSinh;
        hashTable.table[hf(hocSinh->maSV)].tail = hashTable.table[hf(hocSinh->maSV)].tail->next;
    }
}

void search(hashTable hashTable, int maSV) {
    node *traveler = hashTable.table[hf(maSV)].head;
    while(traveler != nullptr and traveler->hocSinh->maSV != maSV) {
        traveler = traveler->next;
    }
    if(traveler == nullptr) {
        cout << "Khong tim thay hoc sinh." << endl;
        return;
    }
    else {
        cout << "Ma: " << traveler->hocSinh->maSV << endl;
        cout << "Ho va ten: " << traveler->hocSinh->hoTen << endl;
        return;
    }
}

int main() {
    hashTable hashTable;
    createEmptyTable(hashTable);
    insert(hashTable, new hocSinh(31245, "Nguyen My Thong"));
    insert(hashTable, new hocSinh(47133, "Tran Van Trong"));
    insert(hashTable, new hocSinh(53403, "Dao Thi Thy")); // Collision
    search(hashTable, 47133);
    return 0;
}
