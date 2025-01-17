#include <iostream>
#include <vector>
#include <string>
#include <mutex>


// linked list

struct Node{
    int data;
    Node* next;

    Node(int data): data(data), next(nullptr){}
};

struct LLNode{
    int data;
    LLNode* next;
    LLNode* prev;
    LLNode(int data):data(data), next(nullptr), prev(nullptr){}
};
class DoublyLinkedList{
    public:
    DoublyLinkedList(): head(nullptr), tail(nullptr){}
    ~DoublyLinkedList(){


    }
    void insertHead(int data);
    void insertTail(int data);
    void deleteNode(int data);
    void displayForward() const;
    void displayBackward() const;
    void displayWithArrows() const;

    private:
        LLNode* head;
        LLNode* tail;

};

class linkedList{
    private:
    Node* head;

    public:
    //constructor
    linkedList(): head(nullptr){}
    ~linkedList(){
        Node* current = head;
        Node* next;
        while(current != nullptr){
            next = current->next;
            delete current;
            current = next;

        }
        head = nullptr;
    }
    void insertElementEnd(int data);
    void insertElementBeginning(int data);
    void deleteElement(int data);
    void display() const;

};

void linkedList::insertElementEnd(int data){
    Node* newNode = new Node(data);
    if (head == nullptr){
        head = newNode;
    }else{
        Node* tmp = head;
        while(tmp->next != nullptr){
            tmp = tmp->next;
        }
        tmp->next =newNode;
    }

}

void linkedList::insertElementBeginning(int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void linkedList::display() const {
    Node* current = head;
    while(current != nullptr){
        std::cout<<current->data;
        current = current->next;
    }
    std::cout<<std::endl;
    std::cout<<"The end of the linked List"<<std::endl;
}

void linkedList::deleteElement(int data){
    // if it is empty it wont delete anything since it is empty
    if(head == nullptr) return;

    // if the same data is the one we are already at then we delete it
    if(head->data == data){
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }

    // to keep checking
    Node* current = head;
    Node* prev = nullptr;
    while(current->data != data && current->next != nullptr){
        prev = current;
        current = current->next;
    }

    if (current == nullptr)return;
    prev->next = current->next;
    delete current;
}

int main() {
    std::cout << "compilation verification" <<std::endl;
    linkedList list;
    list.insertElementBeginning(1);
    list.insertElementBeginning(2);
    list.insertElementEnd(10);
    list.insertElementEnd(111);
    list.display();
    list.deleteElement(111);
    list.display();
    return 0;
}
