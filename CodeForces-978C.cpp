#include <iostream> 
#include <string>
#include <vector>
 
using namespace std;

int main()
{
	long long int n, m, letter_address;
	long long int dorm_rooms = 0;
	long long int letters_delivered = 0;
	long long int dorm = 0;
	long long int rooms_checked = 0;

	// read in # of dorms and # of letters
	cin >> n >> m;

	// Declare key-value array to link dorms with their associated # of rooms
	vector<long long int> rooms(n);

	// Assign # of rooms for each dorm
	while (dorm_rooms < n) {
		cin >> rooms[dorm_rooms];
		dorm_rooms++;
	}

	// Main algorithm
	while (letters_delivered < m) {
		cin >> letter_address;
		letter_address -= rooms_checked;
		while (dorm < n) {
			// If the letter address is less than the amount of rooms in the dorm, print out that dorm # and room #
			if (letter_address <= rooms[dorm]) {
				cout << dorm + 1 << " " << letter_address << "\n";
				break;
			}

			// Otherwise, substract the number of rooms from the letter address and move to the next dorm to check if it's a room inside that dorm
			else {
				letter_address -= rooms[dorm];
				rooms_checked += rooms[dorm];
			}
			dorm++;
		}
		letters_delivered++;
	}
}