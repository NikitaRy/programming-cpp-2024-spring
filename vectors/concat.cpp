#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> concat(std::vector<int> vector1, std::vector<int> vector2){
    int size = vector1.size()+vector2.size();

    std::vector<int> result(size);
    std::copy(vector1.begin(), vector1.end(), result.begin());
    std::copy(vector2.begin(), vector2.end(), result.begin()+vector1.size());

    return result;

}

int main(){
    std::vector<int> vector1(10, 1);
    std::vector<int> vector2(5, 0);
    std::vector<int> result;

    result = concat(vector1, vector2);
    for(int x: result)
        std::cout << x << " ";
}