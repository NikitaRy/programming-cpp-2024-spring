#include <iostream>
#include <cmath>

struct Node{
    int element;
    Node *next;

    Node(int element = 0, Node *node = nullptr){
        this -> element = element;
        this -> next = node;
    }
};

class List{
private:
    Node *Head, *Tail, *deleted_element;
    int size;
public:
    List(){
        this -> Head = nullptr;
        this -> Tail = nullptr;
        this -> size = 0;
    }
    void add_node(int element){
        static Node *tmp = new Node;
        tmp->element = element;
        tmp->next = nullptr;

        if(Head == nullptr){
            Head = tmp;
            Tail = tmp;
        }
        else{
            Tail-> next = tmp;
            Tail = Tail-> next;
        }
        this -> size++;
    }
    Node* getHead(){
        return this -> Head;
    }

    void del(){
    if(Head != nullptr){
        static Node* tmp = Head;
        static Node* hlp = Head;

        for(int i = 0; i < this -> size-1; i++){
            hlp = tmp;
            tmp = tmp -> next;
        }
        if(tmp == Head)
            Head = tmp -> next;
        else
          hlp->next = tmp;
        deleted_element = tmp;
        size--;
    }
    }
};

class Stack: List{
public:
    void push(int element){
        Stack::add_node(element);
    }
    int pop(){
        auto head = Stack::getHead();
        std::cout << head->element;
        Stack::del();
    }
};

int main() {
    Stack stack = Stack();
    stack.push(0);
    stack.push(1);
    stack.push(7);
    stack.pop();
    return 0;
}
