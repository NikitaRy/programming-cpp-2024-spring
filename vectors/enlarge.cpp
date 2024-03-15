#include <iostream>
#include <vector>

void enlarge(std::vector<double> &vector){
    std::vector<double>::iterator iter;
    for (iter = vector.begin()+1; iter < vector.end(); iter++){
        iter = vector.insert(iter, (*iter+*(iter-1))/2);
        iter++;
    }
}


int main(){
    std::vector<double> vector{0,1,2,3,4,5};
    enlarge(vector);
    for (double x: vector)
        std::cout << x << " ";
    return 0;
}
