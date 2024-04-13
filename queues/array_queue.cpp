#include <iostream>
#include <cmath>

struct Queue{
private:
    int* queue_body;
    int queue_size;
    int used_memory;
    int last_pop;

public:
    Queue(){
        this -> queue_body = new int[0];
        this -> queue_size = 1;
        this -> used_memory = 0;
        this -> last_pop = 0;
    }
    ~Queue(){
        delete[] this -> queue_body;
    }

    bool is_empty(){
        return (this -> used_memory == 0);
    }

    void push(int element){
        if(used_memory+1 >= queue_size){
            int* copy_array = new int[queue_size*2];
            for(int i = 0; i < used_memory; i++){
                copy_array[i] = queue_body[i];
            }
            this -> queue_size *= 2;
            this -> queue_body = copy_array;
        }
        queue_body[used_memory] = element;
        this -> used_memory++;

    }

    int pop(){
        if(is_empty()){
            return INFINITY;
        }
        int element = queue_body[last_pop];
        last_pop++;
        used_memory--;
        return element;
    }
};

int main() {
    Queue queue = Queue();
    queue.push(2);
    queue.push(7);
    queue.push(0);
    queue.push(5);
    queue.push(-1);
        std::cout << std::endl;
        std::cout << queue.pop() << " ";
    return 0;
}
