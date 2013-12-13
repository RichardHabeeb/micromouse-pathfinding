#pragma once
#define QUEUE_LENGTH 256 

template <class T>
class Queue
{
public:
	Queue();
	~Queue();

	Queue* Enqueue
		(
		T* item
		);

	T* Dequeue
		(
		void
		);

	T* Peek
		(
		void
		);

	Queue* Reset
		(
		void
		);

	unsigned int get_count() const { return count; }

private:


public:
private:
	T* elements[QUEUE_LENGTH];
	unsigned int start;
	unsigned int end;
	unsigned int count;

};




template <class T> inline
Queue<T>::Queue()
{
	Reset();
}


template <class T> inline
Queue<T>::~Queue()
{
}



template <class T> inline
Queue<T>* Queue<T>::Enqueue(T* item)
{
	elements[(start++)%QUEUE_LENGTH] = item;
	count++;
	return this;
}


template <class T> inline
T* Queue<T>::Dequeue(void)
{
	if (count == 0)
	{
		return nullptr;
	}
	else
	{
		count--;
		return elements[(end++)%QUEUE_LENGTH];
	}
}


template <class T> inline
T* Queue<T>::Peek(void)
{
	if (count == 0)
	{
		return nullptr;
	}
	else
	{
		return elements[(end)%QUEUE_LENGTH];
	}
}



template <class T> inline
Queue<T>* Queue<T>::Reset(void)
{
	start = 0;
	end = 0;
	count = 0;
	return this;
}