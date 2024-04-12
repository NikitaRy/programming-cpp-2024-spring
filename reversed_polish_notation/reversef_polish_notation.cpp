#include <iostream>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>

/*
 * Считает выражение в обратной польской нотации.
 * Дана строка в ОПЗ
 *
 * В стек кидаем числа при помощи вспомогательного потока (его мы очищаем,
 * когда встречаем пробел);
 *
 * При арифметической операции мы достаем два числа из стека
 * и выполняем операцию, а после кидаем результат в стек
 *
 * В конце концов достаем результат из стека и возвращаем
 *
 * Непонятно, зачем нужен костыль в виде зануления переменных --
 * без него все портится...
 * */
int f2(std::string string_in_rpo){
    int result;
    int x, y;
    std::stack<int> numbers_in_rpo;
    std::stringstream helpful_stream;

    for(int i = 0; i < string_in_rpo.size(); i++){

        switch (string_in_rpo[i]) {

            /* Достаем из стека два числа и складываем и обратно в стек,
             * а потом обнуляем вспомогательные переменные.
             * Аналогично для других операций
             * */

            case '+':
                x = numbers_in_rpo.top();
                numbers_in_rpo.pop();
                y = numbers_in_rpo.top();
                numbers_in_rpo.pop();
                numbers_in_rpo.push(x+y);
                x = NULL;
                y = NULL;
                break;
            case '-':
                x = numbers_in_rpo.top();
                numbers_in_rpo.pop();
                y = numbers_in_rpo.top();
                numbers_in_rpo.pop();
                numbers_in_rpo.push(x-y);
                x = NULL;
                y = NULL;
                break;
            case '/':
                x = numbers_in_rpo.top();
                numbers_in_rpo.pop();
                y = numbers_in_rpo.top();
                numbers_in_rpo.pop();
                numbers_in_rpo.push(x/y);
                x = NULL;
                y = NULL;
                break;
            case '*':
                x = numbers_in_rpo.top();
                numbers_in_rpo.pop();
                y = numbers_in_rpo.top();
                numbers_in_rpo.pop();
                numbers_in_rpo.push(x*y);
                x = NULL;
                y = NULL;
                break;
            default:

                /* Если видим цифру, то кидаем ее во вспомогательный поток
                 * Если пробел, то все, что нашли в потоке, кидаем в стек.
                 * И очищаем поток...*/

                if(isdigit(string_in_rpo[i])){
                    helpful_stream << string_in_rpo[i];
                }
                if(isspace(string_in_rpo[i])){
                    int number;
                    helpful_stream >> number;
                    helpful_stream.clear();
                    numbers_in_rpo.push(number);
                }
                break;
        }
    }
    result = numbers_in_rpo.top();
    return result;
}

int main() {
    std::cout << f2("1 2 + 4 * 3 +");
    return 0;
}
