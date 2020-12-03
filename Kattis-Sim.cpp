#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string>
#include <stdio.h>
#include <cstdio>
#include <cstring>

int main()
{
    char line[1000000];
    std::string temp;
    std::string line_count;
    char line_count_char[2];
    bool front = true;
    int space_to_front = 0;
    int count = 0;
    std::string backspaced;
    getline(std::cin, line_count);
    while(count < stoi(line_count)) {
        
        // Read in line
        fgets(line, 1000000, stdin);
        space_to_front = 0;
        for (int i = 0; i < strlen(line); i++) {

            if (line[i] == '[') {
		// If character is '[' and cursor was at front already, concatenate temp string onto beginning of output string
                if (front) {
                    backspaced.insert(0, temp);
                    temp.clear();
                }

		// If cursor was at the back, concatenate temp string onto the end of output string
                else {
                    backspaced.append(temp);
                    temp.clear();
                }

		// Set the cursor to the front and current space to front to zero
                front = true;
                space_to_front = 0;
            }

            else if (line[i] == ']') {

		// If character is ']' and cursor was moved to the front, concatenate the temp string onto the beginning of the output string
                if (front) {
                    backspaced.insert(0, temp);
                    temp.clear();
                }

		// Otherwise, add the temp string to the back of the output string
                else {
                    backspaced.append(temp);
                    temp.clear();
                }

		// Move cursor to the end and set space to front to the length of the string
                front = false;
                space_to_front = backspaced.size() - 1;
            }

	    // If backspace and the cursor is not at the very beginning, erase the last character
            else if (line[i] == '<' && space_to_front > 0) {
                space_to_front--;

		// if there is an existing character on the temp string already, delete that
                if (temp.size() > 0) {
                    temp.erase(temp.size()-1);
                }

		// if there isnt an existing character on the temp string, erase from the end of the output string
                else if (!front && backspaced.size() > 0) {
                    backspaced.erase(backspaced.size() - 1);
                }
            }

	    // if not a special character, add the character to the temp string and increase the space to front tracker
            else if(line[i] != '<') {
                temp.push_back(line[i]);
                space_to_front++;
            }
        }
	
	// if cursor was moved to the front on the last pass through, concatenate the last temp string to the front  of the output string
        if (front) {
            backspaced.insert(0, temp);
        }

	// if cursor was moved to the back on the last pass through, concatenate the last temp string to the back of the output string
        else {
            backspaced.append(temp);
        }
        printf("%s", backspaced.c_str());
        temp.clear();
        backspaced.clear();
        count++;
   }
}