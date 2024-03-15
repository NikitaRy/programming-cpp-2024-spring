#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> repeat(std::vector<int> vector, int n){
    int size = vector.size();
    std::vector<int> result(size*n);

    for(int i = 0; i < n; i++){
        std::copy(vector.begin(), vector.end(), result.begin()+i*size);
    }

    return result;
}

int main(){

    std::vector<int> vector(5, 5);
    int n = 3;
    std::vector<int> result = repeat(vector, n);

    for (int x: result)
        std::cout << x << " ";

    return 0;
}