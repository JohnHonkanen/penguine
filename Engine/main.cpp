#include <iostream>
#include "Clock.h"

using namespace std;

int main(int argc, char *argv[])
{
	Clock clock;
	clock.startClock();
	clock.setDelay(5000);
	bool flag = true;
	while (flag) {
		clock.updateClock();
		cout << clock.getMilliseconds() << endl;
		if (clock.alarm()) {
			cout << "5 Seconds has passed" << endl;
			flag = false;
		}
	}
	return 0;
}
