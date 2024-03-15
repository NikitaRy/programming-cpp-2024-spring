#include <iostream>
#include <string>

std::string pseudo_eval(std::string &string){
    std::string helpful_str = "";
    int begin, end;
    begin = 0;
    end = 0;
    int number1 = 0;
    int number2 = 0;

    for(int i = 0; i < string.size(); i++) {
        if(i == 0 && isdigit(string[i])){
            begin = i;
        }
        if(i == string.size()-1 && isdigit(string[i]))
            end = i;
        if(isalpha(string[i]) || string[i] == '-'){
            helpful_str += string[i];
        }
        std::string substr = string.substr(begin, end-begin);
    }
    return helpful_str;
}

int main(){
    std::string string = "5+26-72+35gh32+45";
    std::cout << pseudo_eval(string);
    return 0;
}