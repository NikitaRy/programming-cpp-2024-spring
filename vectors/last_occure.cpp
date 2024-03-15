#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int>::iterator last_occure(std::vector<int> &vector, int element){
    std::vector<int>::iterator iterator;
    iterator = std::find(vector.begin(), vector.end(), element);
    std::vector<int>::iterator last;
    last = iterator;
    while (iterator != vector.end()){
        iterator = std::find(iterator+1, vector.end(), element);
        if(iterator != vector.end())
            last = iterator;
    }
    return last;
}

int main(){
    std::vector<int> vector{0,1,2,3,4,5,3,3,0};
    std::cout << last_occure(vector, -1)-vector.begin();
    return 0;
}