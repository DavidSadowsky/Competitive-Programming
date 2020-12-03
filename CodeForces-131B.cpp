#include <iostream> 
#include <string>
#include <sstream>

struct num {
    long long int count;
    long long int neg_count;
};

int main()
{
    num *nums[11];
    for (int i = 0; i < 11; i++) {
        nums[i] = new num();
    }
    std::string line;
    getline(std::cin, line);
    getline(std::cin, line);
    long long int num;
    std::stringstream s(line);
    while (s >> num) {
        if (num >= 0) {
            nums[num]->count++;
        }
        else {
            nums[abs(num)]->neg_count++;
        }
    }
    long long int sum = 0;
    if (nums[0]->count > 1) {
        sum = (nums[0]->count * (nums[0]->count - 1)) / 2;
    }
    for (int i = 1; i < 11; i++) {
        sum += nums[i]->count * nums[i]->neg_count;
    }
    std::cout << sum;
}


