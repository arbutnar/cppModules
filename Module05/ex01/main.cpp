#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat    balbio("Ash", 2);
        Form          form("sheet", 10, 5);
        std::cout << std::boolalpha << form << "\n";

        try {
            form.beSigned(&balbio);
            std::cout << balbio;
            balbio.signForm(&form);
            std::cout << "\n" << form;
        } catch(std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;

    }
    return 0;
}
