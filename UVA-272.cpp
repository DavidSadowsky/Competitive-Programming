#include <iostream> 
#include <string>

int main()
{
    int quoteCount = 0;
    std::string line = "";
    while (getline(std::cin, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '\"' && quoteCount % 2 == 0) {
                std::cout << "``";
                quoteCount++;
            }
            else if (line[i] == '\"' && quoteCount % 2 == 1) {
                std::cout << "''";
                quoteCount++;
            }
            else std::cout << line[i];
        }
        std::cout << "\n";
    }
}