#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;

//Linked List Node
struct node{
    int data;
    struct node* next;
};

void push(struct node** listHead, int new_data){
    struct node* newNode = new node;

    newNode->data = new_data;

    newNode->next = (*listHead);

    (*listHead) = newNode;
}

bool detectCycle(node* head){
    node* curr = head;
    std::unordered_set<node*> hashTable;

    while(curr){
        if(hashTable.find(curr) != hashTable.end()){
            return true;
        }

        hashTable.insert(curr);

        curr = curr->next;
    }

    return false;
}

bool Floyds(node* head){
    node* tortoise = head, *hare = head;

    while(hare && hare->next){
        tortoise = tortoise->next;
        hare = hare->next->next;

        if(tortoise==hare)
            return true;
    }

    return false;
}


int main() {
    int dataVals[] = {1,2,3,4,5};
    int n = sizeof(dataVals) / sizeof(dataVals[0]);

    node* head = nullptr;
    for(int i = n-1; i >= 0; i--){
        push(&head, dataVals[i]);
    }

    head->next->next->next->next->next = head->next->next;

    if(Floyds(head))
        cout << "Cycle found" << endl;
    else
        cout << "Cycle not found" << endl;

    return 0;
}
