#include <iostream>
#include <cmath>

struct Stack{
private:
    int* stack_body;
    int stack_size;
    int used_memory;

public:
    Stack(){
        this -> stack_body = new int[0];
        this -> stack_size = 0;
        this -> used_memory = 0;
    }
    ~Stack(){
        delete[] stack_body;
    }

    bool is_empty(){
        return (this -> used_memory == 0);
    }

    void push(int element){
        if(used_memory+1 >= stack_size){
            int* copy_array = new int[stack_size*2];
            for(int i = 0; i < used_memory; i++){
                copy_array[i] = stack_body[i];
            }
            this -> stack_size *= 2;
            this -> stack_body = copy_array;
        }
        stack_body[used_memory] = element;
        this -> used_memory++;

    }
    void print(){
        if(is_empty())
            std::cout << "Empty stack";
        else{
            for(int i = 0; i < used_memory; i++)
                std::cout << stack_body[i] << " ";}
    }
    int pop(){
        if(is_empty()){
            return INFINITY;
        }
        used_memory--;
        return this -> stack_body[used_memory];
    }
};

int main() {
    Stack stack = Stack();
    stack.push(1);
    stack.push(100);
    stack.print();
    std::cout << stack.pop();
    return 0;
}
