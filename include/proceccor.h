#pragma once
#ifndef _Proccecor_
#define _Proceccor_
#include "queue.h"
#include <Windows.h>
#include <iostream>
#include <vector>

using namespace std;

struct Task
{
	int cores = 0;
	int tacts = 0;
};

struct Proc
{
	vector <Task> proces;
	int proc_cores = 0;
};

class Proceccor
{
private:
	int Time;
	int cycle = 0; //������ ������
	int completed = 0; //����������� ������
	int random = 0;
	int size = 0;
	double processor_rate = 0; //������������� ����������
	double queue_rate = 0; //������������� �������
	int queue_errors = 0;
	int queue_idle = 0; //������� � �������
	int proc_failure = 0; //����� ����������
	int proc_idle = 0; //������� � ����������
	int task_amount = 0; //����� ���������� �������
public:
	void Work(Queue<Task> &queue, Proc &proc, int time);
	void Creating(int _queueSize, int _time, int _cores, double _processorInt, double _queueInt);
	Task TaskGeneration();
	void Print(int task_amount, int queue_idle, int proc_idle, int time, int completed, int cycle);
};

#endif