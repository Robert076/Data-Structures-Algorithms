#include <exception>
#include "../include/BagIterator.h"
#include "../include/Bag.h"

using namespace std;

BagIterator::BagIterator(const Bag &c) : bag(c)
{
	this->current = 0;
}

void BagIterator::first()
{
	this->current = 0;
}

void BagIterator::next()
{
	if (this->valid())
		this->current++;
	else
	{
		throw exception();
	}
}

bool BagIterator::valid() const
{
	return this->current < this->bag._size;
}

TElem BagIterator::getCurrent() const
{
	if (this->valid())
		return this->bag.elems[this->current];
	else
		throw exception();
}
