#include "proceccor.h"
#include <ctime>

Task Proceccor::TaskGeneration() //Создание задач 
{
	srand((unsigned int)time(NULL));
	int pr1 = rand() % 9 + 1;
	if (pr1 < (queue_rate * 10))
	{
		srand((unsigned int)time(NULL));
		int pr2 = rand() % 9 + 1;
		Task task;
		task.cores = pr2;
		return task;
	}
	else
	{
		Task task = {};
		//task.cores = 0;
		return task;
	}
}
void Proceccor::Work(Queue<Task>& queue, Proc& proc, int Time)
{
	for (int i = 0; i < Time; i++)
	{
		if (!queue.IsFull()) //если очередь не переполнена, добавляем задачу
		{
			Task task1;
			task1 = TaskGeneration();
			if (task1.cores != 0)
			{
				queue.Push(task1);
			}
		}
		else
		{
			queue_errors++;
		}
		if (queue.IsEmpty())
		{
			queue_idle++;
		}
		else //если очередь не пуста 
		{
			for (int i = 0; i < queue.Size(); i++)
			{
				Task task2;
				task2 = queue.Put();
				if (task2.cores <= proc.proc_cores) //имеется нужное колво ядер, отправляем задачу на выполнение
				{
					proc.proc_cores -= task2.cores;
					proc.proces.push_back(task2);
					task_amount++;
					queue.Pop();
					continue;
				}
				else
				{
					if (task2.cores > proc.proc_cores) //ядер для выполнения задачи требуется больше, чем может предоставить процессор
					{
						proc_failure++;
						queue.Pop();
					}
					else
						break;
				}
			}
		}
		//выполнение 
		if (proc.proces.size() != 0) //в процессоре есть задачи, ожидающие исполнение
		{
			for (int i = 0; i < proc.proces.size(); i++)
			{
				proc.proces[i].tacts++;
				srand((unsigned int)time(NULL));
				int pr = rand() % 9 + 1;
				if (pr < (processor_rate * 10))
				{
					Task task2;
					task2 = proc.proces[i];
					if (task2.tacts == 1)
					{
						continue;
					}
					completed++; //задача завершается
					proc.proces.erase(proc.proces.begin() + i); //удаляется из процессора
					proc.proc_cores += task2.cores; //освобождаются ядра
					cycle += task2.tacts;
				}
			}
		}
		else
		{
			proc_idle++;
		}
	}
	Print(task_amount, queue_idle, proc_idle, Time, completed, cycle);
}
void Proceccor::Creating(int _size, int _time, int _cores, double _processor_rate, double _queue_rate)
{
	Proc proc;
	proc.proc_cores = _cores;
	Time = _time;
	size = _size;
	processor_rate = _processor_rate;
	queue_rate = _queue_rate;
	Queue<Task> q2ue(size);
	Work(q2ue, proc, Time);
}
void Proceccor::Print(int task_amount, int queue_idle, int proc_idle, int time, int completed, int cycle)
{
	cout << "Statistics:" << endl;
	cout << "Number of tasks received in the computer system: " << task_amount << endl;
	if (task_amount != 0)
		cout << "Number of failures in sevice job: " << (queue_idle * 100 / task_amount) << "%" << endl;
	else
		cout << "Number of failures in sevice job: " << 0 << endl;
	cout << "Idle clock cycles: " << (proc_idle * 100 / time) << "%" << endl;
	if (completed != 0)
		cout << "Average time of task execution: " << (double(time - proc_idle) / double(completed)) << endl;
	else
		cout << "Average time of task execution: " << 0 << endl;
	cout << "Task comleted: " << completed << endl;
	cout << "Total cycles: " << cycle << endl;
}