#include <iostream> 
#include <string>
#include <stack>
int main()
{
    std::string line;
    std::stack<char> stack;
    getline(std::cin, line);
    stack.push(NULL);
    int dupe_count = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == stack.top()) {
            stack.pop();
            dupe_count++;
        }
        else {
            stack.push(line[i]);
        }
    }
    if (dupe_count % 2 == 0 || dupe_count == 0) {
        std::cout << "No";
    }
    else {
        std::cout << "Yes";
    }
}