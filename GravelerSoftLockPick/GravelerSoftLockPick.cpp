#include "GravelerSoftLockPick.h"
#include <chrono>
#include <cmath>
#include <iomanip>

int main()
{
	srand(time(NULL)); //seeds RNG
	GravelerSoftLockPick geo;
	auto start = std::chrono::high_resolution_clock::now();  //timer ON

	while (geo.getRolls() < 1000000000) {
		int count = 0; //holds count for 1s this turn
		//begin turn
		for (int i = 0; i < 231; i++) {
			int roll = 0;
			roll = std::rand() % 4 + 1; //rolls 1 to 4
			if (roll == 1) {  //counts 1s this turn
				count++;
			}
		}
		//end turn
		geo.update(count); //updates using results of turn

		if (geo.getOnes() >= 177) {  //if # of 1s meets or exceeds 177
			break;  //stop looping
		}
	}

	auto stop = std::chrono::high_resolution_clock::now();  //timer OFF
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	std::cout << "Highest Ones Roll: " + std::to_string(geo.getOnes()) << std::endl;
	std::cout << "Number of Roll Sessions: " + std::to_string(geo.getRolls()) << std::endl;
	auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
	duration -= hours;
	auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration);
	duration -= minutes;
	auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
	std::cout << std::setprecision(3) << "Time to complete: " + std::to_string(hours.count()) + " hours, " + std::to_string(minutes.count()) + " minutes, " + std::to_string(seconds.count()) << " seconds" << std::endl;
	return 0;
}