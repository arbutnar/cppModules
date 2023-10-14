#include "Bureaucrat.hpp"

int main() {   
    try {
        Bureaucrat        balbio("Ash", 100);
        balbio.incrementGrade(10);
        balbio.decrementGrade(1);
        std::cout << balbio;
        std::cout << std::endl;
        Bureaucrat        diddio(balbio);
        std::cout << diddio;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
