#include <iostream>
#include <string>

std::string strange_copy(std::string &string, std::string pattern){
    int len_pattern = pattern.size();
    int begin = 0;

    while(string.find(pattern, begin) != std::string::npos){
        begin = string.find(pattern, begin);
        string.insert(begin, "(");
        string.insert(begin+len_pattern+1, ")");
        begin += len_pattern+3;
    }

    return string;

}

int main(){
    std::string string = "ertabcsdftyuabczevbh";
    std::string pattern = "abc";
    std::cout << strange_copy(string, pattern);
    return 0;
}