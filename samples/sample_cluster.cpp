#include <iostream>
#include <string>
#include "proceccor.h"

using namespace std;

int main()
{
	//setlocale(LC_ALL, "RUS");
	int _size, _time, _cores;
	double _processor_rate, _queue_rate;
	cout << "Enter size of queue" << endl;
	cin >> _size;
	cout << "Enter amout of cores" << endl;
	cin >> _cores;
	cout << "Enter processor rate" << endl;
	cin >> _processor_rate;
	cout << "Enter queue rate" << endl;
	cin >> _queue_rate;
	cout << "Enter working time" << endl;
	cin >> _time;
	Proceccor proc;
	proc.Creating(_size, _time, _cores, _processor_rate, _queue_rate);
	return 0;
}
