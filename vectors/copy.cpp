#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> vector1(10);

    for(int i = 0; i < 10; i++)
        vector1[i] = std::rand()%10;

    int array[10];
    std::copy(vector1.begin(), vector1.end(), array);

    for(int x: array)
        std::cout << x << " ";

    return 0;
}