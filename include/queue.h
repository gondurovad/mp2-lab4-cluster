#pragma once
#define MaxSizeQueue   100 //максимальный размер очереди

using namespace std;
template <class T>
class Queue
{
	int first_ind; //индекс элемента массива, в котором хранится первый элемент очереди
	int last_ind; //индекс элемента массива, в котором хранится последний элемент очереди
	int data_counter; //количество элементов в очереди
	int size; //размер очереди
	T* pMem;
public:
	Queue(int _size)
	{
		size = _size;
		if ((size > MaxSizeQueue) || (size < 1))
			throw "error";
		else
		{
			data_counter = 0;
			first_ind = 0;
			last_ind = 0;
			pMem = new T[size];
		}
	}

	~Queue()
	{
		delete[]pMem;
	}

	int IsEmpty()
	{
		return (data_counter == 0);
	}

	int IsFull()
	{
		return (data_counter == size);
	}

	void Push(T val)
	{
		if (!IsFull())
		{
			pMem[++last_ind] = val;
			data_counter++;
			//if (last_ind > size - 1)
				//last_ind = 0;
		}
		else
		{
			throw "error";
		}
	}

	/*T Get()
	{
		if (IsEmpty())
			throw "error";
		T res = pMem[first_ind++];
		if (first_ind > size - 1)
			first_ind = 0;
		data_counter--;
		return res;
	}*/

	T Pop()
	{
		if (IsEmpty())
			throw "error";
		T res = pMem[first_ind];
		for (int i = first_ind; i < last_ind; i++) {
			pMem[i] = pMem[i + 1];
		}
		last_ind--;
		data_counter--;
		return(res);
	}

	T Put()
	{
		if (!IsEmpty())
		{
			return pMem[first_ind];
		}
		else
			throw "error";
	}

	int Size()
	{
		return data_counter;
	}
};