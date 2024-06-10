#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/* Шаблон для вывода выражения в ОПЗ */
template<typename T>
void print(T const& xs)
{
    std::cout << "[ ";
    for (auto const& x : xs)
        std::cout << x << ' ';
    std::cout << "]\n";
}

/* Вычисление выражения в ОПЗ */
void f2(){
    std::vector<int> stack;
    char x = 'a';
    int number;
    while (std::cin >> x){
        if (isdigit(x)){
            std::cin.putback(x);
            std::cin >> number;
            stack.push_back(number);
        }else{
            int size = stack.size() - 1;
            int a = stack[size], b = stack[size - 1];
            stack.pop_back();
            stack.pop_back();
            if(x == '+') stack.push_back(a + b);
            else if (x == '-') stack.push_back(b - a);
            else if (x == '/') stack.push_back(b / a);
            else if (x == '*') stack.push_back(a * b);
            if (stack.size() == 1) break;
        }
    }
    std::cout << stack[0] << std::endl;
}

/* Перевод в ОПЗ */
std::string f1(){
    std::vector<char> stack;
    char x = 'a';
    std::string number;
    std::string result = "";
    while (std::cin >> x){
        if (isdigit(x)){
            std::cin.putback(x);
            std::cin >> number;
            result += number + " ";
        }
        else{
            if (x == '+' || x == '-' || x == '/' || x == '*'){
                while (stack.size() != 0){
                    char el = stack[stack.size() - 1];
                    if ((x == '*' || x == '/') && (el == '+' || el == '-' )){
                        break;
                    }
                    else if (el == '(') break;
                    else{
                        stack.pop_back();
                        result += el;
                        result += " ";
                    }
                }
                stack.push_back(x);
            }
            else if (x == '(') stack.push_back(x);
            else if (x == ')') {
                char el = stack[stack.size() - 1];
                stack.pop_back();
                while (el != '('){
                    std::cout << el << std::endl;
                    result += el;
                    result += " ";
                    el = stack[stack.size() - 1];
                    stack.pop_back();
                }
            }
        }
    }
    while (stack.size() != 0){
        char el = stack[stack.size() - 1];
        stack.pop_back();
        result += el;
        result += " ";
    }
    return result;
}

std::string f1_string(std::string s){
    std::vector <char> stack;
    char x = s[0];
    s.erase(0, 1);
    std::string number;
    std::string result = "";
    while (x != '\0'){
        if (isdigit(x)){
            number = x + s.substr(0,s.find(" "));
            s.erase(0,  s.find("") + 1);
            result += number + " ";
        }
        else{
            if (x == '+' || x == '-' || x == '/' || x == '*'){
                while (stack.size() != 0){
                    char el = stack[stack.size() - 1];
                    if ((x == '*' || x == '/') && (el == '+' || el == '-')){
                        break;
                    }
                    else if (el == '(') break;
                    else{
                        stack.pop_back();
                        result += el;
                        result += " ";
                    }
                }
                stack.push_back(x);
            }
            else if (x == '(') stack.push_back(x);
            else if (x == ')') {
                char el = stack[stack.size() - 1];
                stack.pop_back();
                while (el != '('){
                    result += el;
                    result += " ";
                    el = stack[stack.size() - 1];
                    stack.pop_back();
                }
            }
        }
        if (s.length() == 0) x = '\0';
        else x = s[0];
        s.erase(0, 1);
    }
    while (stack.size() != 0){
        char el = stack[stack.size() - 1];
        stack.pop_back();
        result += el;
        result += " ";
    }
    return result;
}
int f2_string(std::string s){
    std::vector<int> stack;
    char x = s[0];
    s.erase(0, 1);
    int number;
    while (x != '\0'){
        if (isdigit(x)){
            number = stoi(x + s.substr(0, s.find(" ")));
            s.erase(0, s.find("") + 1);
            stack.push_back(number);
        }else{
            int size = stack.size() - 1;
            int a = stack[size], b = stack[size - 1];
            stack.pop_back();
            stack.pop_back();
            if(x == '+') stack.push_back(a + b);
            else if (x == '-') stack.push_back(b - a);
            else if (x == '/') stack.push_back(b / a);
            else if (x == '*') stack.push_back(a * b);
            if (stack.size() == 1) break;
        }
        if (s.length() == 0) x = '\0';
        else x = s[0];
        if (x == ' ') { x = s[1]; s.erase(0, 1); };
        s.erase(0, 1);
    }
    return stack[0];
}

/* Вводим в ОПЗ*/
void f2_another_cin(std::string s){
    std::vector<int> stack;
    std::stringstream st;
    st << s;
    char x = 'a';
    int number;
    while (st >> x){
        if (isdigit(x)){
            st.putback(x);
            st >> number;
            stack.push_back(number);
        }
        else{
            int size = stack.size() - 1;
            int a = stack[size], b = stack[size - 1];
            stack.pop_back();
            stack.pop_back();
            if (x == '+') stack.push_back(a + b);
            else if (x == '-') stack.push_back(b - a);
            else if (x == '/') stack.push_back(b / a);
            else if (x == '*') stack.push_back(a * b);
            if (stack.size() == 1) break;
        }
    }
    std::cout << stack[0] << std::endl;
}

/* Перевод в ОПЗ и вычисление */
void f3(std::string s){
    std::string pol = f1_string(s);
    std::cout << f2_string(pol) << std::endl;
}

int main()
{
    return 0;
}
