    #include <iostream>
    #include <vector>
    #include <algorithm>

    std::vector<int>::iterator second_occure(int element, std::vector<int> &vector){
        std::vector<int>::iterator iterator;
        iterator = std::find(vector.begin(), vector.end(), element);
        iterator = std::find(iterator+1, vector.end(), element);
        return iterator;
    }

    int main(){
        int element = rand()%10;
        std::cout << "Element to find: " << element << std::endl;
        std::vector<int> vector = {0,1,2,3,4,5,3,3,0};
        std::cout << std::endl;
        std::vector<int>::iterator iterator = second_occure(element, vector);
        std::cout << "Second occure of " << element << ": " << iterator-vector.begin();

    }