#include <iostream>
#include <string>

int main(){
//    std::cout << "Please input your name ";
//
//    std::string name;
//
//    std::cin >> name;
//
//    std::cout << "Hello " << name << "!";

    std::cout << "Please input your name ";

    std::string name;
    std::cin >> name;

    const std::string greating = "Hello, " + name + "!";
    const std::string space(greating.size(), ' ');
    const std::string secondLine = "* " + space + " *";

    const std::string firstLine(secondLine.size(), '*');

    std::cout << firstLine << std::endl;
    std::cout << secondLine << std::endl;
    std::cout << "* " << greating << " * " << std::endl;
    std::cout << secondLine << std::endl;
    std::cout << firstLine << std::endl;

    char a[] = "沈国栋";

//    { std::string s = "hello";std::cout << s << std::endl;}
//    { std::string s = "world";std::cout << s << std::endl;}
    return 0;
}
