#include "../include/Bag.h"
#include "../include/BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

Bag::Bag()
{
	this->elems = new TElem[16];
	this->_size = 0;
	this->_capacity = 16;
}

void Bag::add(TElem elem)
{
	if (this->_size == this->_capacity)
		this->resize();

	this->elems[this->_size++] = elem;
}

bool Bag::remove(TElem elem)
{
	for (int i = 0; i < this->_size; i++)
	{
		if (this->elems[i] == elem)
		{
			for (int j = i; j < this->_size - 1; j++)
				this->elems[j] = this->elems[j + 1];
			this->elems[this->_size - 1] = NULL_TELEM;
			this->_size--;
			return true;
		}
	}
	return false;
}

bool Bag::search(TElem elem) const
{
	for (int i = 0; i < this->_size; i++)
	{
		if (this->elems[i] == elem)
			return true;
	}
	return false;
}

int Bag::nrOccurrences(TElem elem) const
{
	int count = 0;
	for (int i = 0; i < this->_size; i++)
	{
		if (this->elems[i] == elem)
			count++;
	}
	return count;
}

int Bag::size() const
{
	return this->_size;
}

bool Bag::isEmpty() const
{
	return this->_size == 0;
}

void Bag::resize()
{
	TElem *newElems = new TElem[2 * this->_capacity];

	for (int i = 0; i < this->_size; i++)
		newElems[i] = this->elems[i];

	delete[] this->elems;
	this->elems = newElems;
	this->_capacity *= 2;
}

BagIterator Bag::iterator() const
{
	return BagIterator(*this);
}

Bag::~Bag()
{
	delete[] this->elems;
}
