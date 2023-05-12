#include "ozVector.h"

template <class T>
ozVector<T>::ozVector(int maxCAP)
{
	cap = maxCAP;
	elem = 0;
	vector = new T[cap];
}

template <class T>
ozVector<T>::~ozVector()
{
	delete[] this->vector;
	elem = 0;
	cap = 0;
}

template <class T>
ozVector<T>::ozVector(const ozVector &vec)
{
	vector = new int;
	cap = vec.cap;
	elem = vec.elem;
	*vector = vec.vector;
}

template <class T>
ozVector<T> &ozVector<T>::operator=(const ozVector &trns)
{
	cout << "Copy assignment\n";
	cap = trns.cap;
	elem = trns.elem;
	vector = new T[cap];
	for (int i = 0; i < size(); i++)
	{
		vector[i] = trns.vector[i];
	}
	return *this;
}

template <class T>
ozVector<T> &ozVector<T>::operator=(const ozVector &&trns)
{
	vector = move(trns.vector);
	elem = move(trns.elem);
	cap = move(trns.cap);
	return *this;
}

template <class T>
T ozVector<T>::pop_back()
{
	T poped = vector[size() - 1];
	elem--;
	return poped;
}

template <class T>
T &ozVector<T>::operator[](int index)
{
	try
	{
		if (index >= elem || index < 0)
		{
			throw index;
		}
		return vector[index];
	}
	catch (int index)
	{
		cerr << "invalid index:"
			 << "out of range" << endl;
	}
}

template <class T>
void ozVector<T>::push_back(T item)
{
	if (cap == elem)
	{
		T *temp = new T[cap * 2];
		for (int i = 0; i < cap; i++)
		{
			temp[i] = vector[i];
		}
		delete[] vector;
		vector = temp;
		cap *= 2;
	}
	vector[elem] = item;
	elem++;
}

template <class T>
int ozVector<T>::size() const
{
	return elem;
}

template <class T>
int ozVector<T>::capacity()
{
	return cap;
}

template <class T>
int ozVector<T>::resize()
{
	cap *= 2;
}

template <class T>
bool ozVector<T>::empty()
{
	if (elem == 0)
	{
		return true;
	}
	return false;
}

template <class T>
ozVector<T>::ozVector(T *arr, int n)
{
	elem = 0;
	vector = new T[n];
	for (int i = 0; i < n; i++)
	{
		vector[i] = arr[i];
		elem++;
	}
	cap = n;
}

template <class T>
void ozVector<T>::erase(Iterator first, Iterator second)
{
	static int counter = 0;
	T *temp = new T[cap];
	for (Iterator it = begin(); it != end(); it++)
	{
		if (it >= first && it < second)
		{
			continue;
		}
		else
		{
			temp[counter] = it;
			counter++;
		}
	}
	delete[] vector;
	T vector = new T[cap];
	for (int i = 0; i < counter; i++)
	{
		vector[i] = temp[i];
	}

	delete[] temp;
	elem = counter;
}

template <class T>
void ozVector<T>::clear()
{
	Iterator it1 = &vector[0];
	Iterator it2 = &vector[elem];
	erase(it1, it2);
	elem = 0;
	cap = 0;
}

template <class T>
bool ozVector<T>::operator<(ozVector<T> &vTEST)
{
	if (size() > vTEST.size())
	{
		return false;
	}
	else if (size() == vTEST.size())
	{
		for (int i = 0; i < size(); i++)
		{
			if (vector[i] < vTEST.vector[i])
			{
				return true;
			}
			else if (vector[i] == vTEST.vector[i])
			{
				continue;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

template <class T>
bool ozVector<T>::operator==(ozVector<T> &vTEST)
{
	if (size() != vTEST.size())
		return false;
	for (int i = 0; i < size(); i++)
	{
		if (vector[i] == vTEST.vector[i])
			return true;
	}
}

template <class T>
void ozVector<T>::erase(Iterator itr)
{
	for (int i = *(itr - 1); i < size(); ++i)
		vector[i] = vector[i + 1];
	--elem;
}