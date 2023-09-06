#include <iostream>

int main(int argc, char **argv) {
    int r;
    int c;

    if (argc < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }
    else {
        for (r = 1; r < argc; r++)
            for (c = 0; argv[r][c] != '\0'; c++)
                std::cout << (char)std::toupper(argv[r][c]);
    }
    std::cout << std::endl;
    return 0;
}