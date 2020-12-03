#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

int main()
{
    int array_count = 0;
    int num_indexes = 0;

    // Read n & m vals
    std::cin >> array_count >> num_indexes;

    // Declare line to read in array as a string and vector to store the integers
    std::string line = "";
    std::vector<long long int> arr;

    // Vector to store computations required to calculate big array max sum
    std::vector<std::vector<long long int>> individual_arr_maxes;

    int counter = 0;

    // Weird C++ thing to clear buffer
    getline(std::cin, line);

    // While-loop to iterate 'n' times
    while(getline(std::cin, line) && counter <= array_count) {
       
        // Read in current lines integer values into vector
        std::stringstream stream(line);
        bool first_check = true;
        while (!stream.eof()) {
            int num;
            if (first_check && counter != array_count) {
                first_check = false;
                stream >> num;
            }
            else {
                stream >> num;
                arr.push_back(num);
            }
        }

        // Break loop if all array have been computed on and indexed array has been stored in 'arr'
        if (counter == array_count) {
            break;
        }

        // Declare variables that store array computations necessary to calculate the max sum of the big array
        int max_sum = 0;
        int total_sum = 0;
        int max_with_first = 0;
        int max_with_last = 0;

        // Variables required for Kadane's algorithm
        int current_max = 0;
        int current_max_with_first = 0;
        int current_max_with_last = 0;
        int count = 0;

        for (std::vector<long long int>::iterator it = arr.begin(); it != arr.end(); it++) {
 
            // Skip Kadanes algorithm on first loop to set maxSum, in case of a completely negative array
            if (count == 0) {

                // Initializing sums to first index
                max_sum = *it;
                max_with_first = *it;
                current_max = *it;
                current_max_with_first = *it;
                total_sum = *it;
            }

            else {
                // Tracks maximum sum of the array
                current_max = std::max(*it, current_max + *it);
                max_sum = std::max(current_max, max_sum);

                // Tracks max sum of the array that includes the first index
                current_max_with_first = current_max_with_first + *it;
                max_with_first = std::max(max_with_first, current_max_with_first);

                // Tracks total sum of the array
                total_sum += *it;
            }
            count++;
        }

        count = 0;

        // Kadane's including last index of array
        for (std::vector<long long int>::reverse_iterator it = arr.rbegin(); it != arr.rend(); it++) {

            // Skip Kadanes algorithm on first loop to set maxSum, in case of a completely negative array
            if (count == 0) {
                max_with_last = *it;
                current_max_with_last = *it;
            }

            else {
               // Tracks max sum of the array that includes the last index
                current_max_with_last += *it;
                max_with_last = std::max(max_with_last, current_max_with_last);
            }
            count++;
        }
        
        // Store computed values
        std::vector<long long int> max_vals;
        max_vals.push_back(max_sum);
        max_vals.push_back(total_sum);
        max_vals.push_back(max_with_first);
        max_vals.push_back(max_with_last);

        individual_arr_maxes.push_back(max_vals);

        // Clear vectors for next array's analysis
        max_vals.clear();
        arr.clear();

        counter++;
    }

        long long int curr_sum = std::max(individual_arr_maxes[arr[0] - 1][1], individual_arr_maxes[arr[0] - 1][3]);
        long long int max_sum = individual_arr_maxes[arr[0] - 1][0];

    // For loop to compute big-array max sum
    for (int l = 1; l < num_indexes; l++) {

        // Comparing max sum to current_sum + total sum of small array & max sum to total sum of small array
        max_sum = std::max(max_sum, curr_sum + individual_arr_maxes[arr[l] - 1][1]);
        max_sum = std::max(max_sum, individual_arr_maxes[arr[l] - 1][1]);

        // Comparing max sum to current sum + max val/ w first index of small array & max sum to max val w/ first index of small array
        max_sum = std::max(max_sum, curr_sum + individual_arr_maxes[arr[l] - 1][2]);
        max_sum = std::max(max_sum, individual_arr_maxes[arr[l] - 1][2]);

        // Comparing max sum to max sum of small array
        max_sum = std::max(max_sum, individual_arr_maxes[arr[l] - 1][0]);

        // Comparing current sum + total sum of small array to total sum of small array
        curr_sum = std::max(curr_sum + individual_arr_maxes[arr[l] - 1][1], individual_arr_maxes[arr[l] - 1][1]);
        
        // Comparing current sum to max value of small array given last index is included
        curr_sum = std::max(curr_sum, individual_arr_maxes[arr[l] - 1][3]);
    }
    std::cout << max_sum;
}
