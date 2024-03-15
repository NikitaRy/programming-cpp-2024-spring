#include <iostream>
#include <vector>

void del(std::vector<int> &vector){
    std::vector<int>::iterator iter;
    for(iter = vector.begin(); iter < vector.end(); iter++)
        iter = vector.erase(iter);
}

int main(){
    std::vector<int> vector(1000, 1);
    del(vector);
    for(int x: vector)
        std::cout << x << " ";
    std::cout << vector.size();
    return 0;
}