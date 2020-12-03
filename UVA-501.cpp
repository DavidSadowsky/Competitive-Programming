#include <iostream> 
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::string a;

    // Get 'K' - number of sets
    getline(std::cin, a);
    int loops = stoi(a);
    int loop_count = 0;

    // Loop K times
    while (loop_count < loops) {
        
        // Consume blank line
        getline(std::cin, a);
        std::queue<int> gets;
        std::string number;
        std::string u;
        std::vector<int> box;
        int num;
        int count = 0;
        int n;
        int index = 0;

        // Get m & n
        getline(std::cin, number);

        // Get adds
        getline(std::cin, a);

        // Get gets
        getline(std::cin, u);

        std::stringstream s(u);
        std::stringstream ss(a);
        std::stringstream sss(number);
        sss >> n;

        // Parse gets into a queue
        while (s >> num) {
            gets.emplace(num);
        }

        // algorithm loop
        while ( count <= n) {
            // Parse number to be added to blackbox
            ss >> num;

            // if gets are empty end the loop
            if (gets.empty()) {
                break;
            }
            if (!gets.empty()) {

                // if number of elements in box is equal to the get value then print out get value at 'i' (index)
                while (count == gets.front()) {
                    printf("%d\n", box[index]);
                    gets.pop();
                    index++;
                    
                    // end loop if gets queue is empty
                    if (gets.empty()) {
                        break;
                    }
                }
            }
                // binary search algorithm to maintain sorted array in non-descending order on element addition
                auto pos = std::lower_bound(box.begin(), box.end(), num);
                box.insert(pos, num);
            count++;
        }
        // extra newline between data sets
        printf("\n");
        loop_count++;
    }
}