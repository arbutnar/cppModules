#include <iostream>
#include <fstream>
#include <cstdio>

int main(int argc, char **argv) {

	if (argc != 4) { std::cerr << "Arg error\n";
		return 1;
	}
	int i = 0;
	std::ifstream	inFile;
	std::string		line;
	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];

	inFile.open(argv[1], std::ios::in);
	if (inFile) {
		while (argv[1]) {
			if (argv[1][i] == '.' || argv[1][i] == '\0')
				break;
			i++;
		}
		filename = filename.substr(0, i) + ".replace";
		std::ofstream	outFile(filename.c_str(), std::ios::out);
		while (std::getline(inFile, line, '\0')) {
			size_t          pos = line.find(s1);
            while ( pos != std::string::npos ) {
                line.erase(pos, s1.length());
                line.insert(pos, s2);
                pos = line.find(s1);
            }
            outFile << line;
		}
		outFile.close();
		inFile.close();
	} else {
		std::cout << "Unable to open file." << std::endl;
		return 1;
	}	
	return 0;
}