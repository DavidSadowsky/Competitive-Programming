#include <iostream> 
#include <string>
#include <stack>
#include <sstream>

int main()
{
    std::string line;
    while (getline(std::cin, line)) {
        int num;
        int abs_val;
        int check;

        std::stack<int> sequence;
        std::stack<int> sequence_check;

        bool no_mat = false;

        std::stringstream s(line);

        s >> num;
        abs_val = abs(num);
        sequence.push(num);
        sequence_check.push(abs_val);

        if (s.peek() == '\n') {
            std::cout << ":-( Try again." << std::endl;
        }

        else {
            while (s >> num) {
                abs_val = abs(num);
                if (sequence.empty()) {
                    std::cout << ":-( Try again." << std::endl;
                    no_mat = true;
                    break;
                }
                else if (num == sequence.top() * -1 && num > 0) {
                    sequence.pop();
                    sequence_check.pop();
                    if (!sequence_check.empty()) {
                        check = sequence_check.top() - num;
                        if (check < 1) {
                            std::cout << ":-( Try again." << std::endl;
                            no_mat = true;
                            break;
                        }
                        else {
                            sequence_check.pop();
                            sequence_check.push(check);
                        }
                    }
                }
                else if (num != sequence.top() * -1 ) {
                    sequence.push(num);
                    sequence_check.push(abs_val);
                }
            }
            if (sequence.empty() && !no_mat) {
                std::cout << ":-) Matrioshka!" << std::endl;
            }
            else if(!no_mat) {
                std::cout << ":-( Try again." << std::endl;
            }
        }
    }
}