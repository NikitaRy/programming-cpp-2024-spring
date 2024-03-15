#include <iostream>
#include <string>

bool ip_checker(std::string &s){
    int i = 0;
    int count = 0;
    int digits_count = 0;

    while(i < s.size()){

        if((s[i] == '.' && s[i+1] == '.') ||
        (i == 0 && s[i] == '.') ||
        (i == s.size()-1 && s[i] == '.'))
            return false;

        digits_count++;
        if(digits_count < 4)
            if(s[i] == '.')
                digits_count = 0;
        if(digits_count == 4){
            if(s[i] != '.')
                return false;
            if(std::stoi(s.substr(i-3, 3)) > 255)
                return false;
            digits_count = 0;
        }

        if(s[i] == '.')
            count++;

        if(count > 3)
            return false;

        i++;
    }

    if(count < 3)
        return false;

    return true;
}

int main(){
    std::string s = "125.5.55.25";
    std::cout << ip_checker(s);
    return 0;
}
