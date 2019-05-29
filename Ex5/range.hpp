#pragma once

#include <iterator>
#include<iostream>

namespace itertools
{
template <class T>
class range
{

    T _start; // __starting point
    T _end;   // stopping point.
   
    class iterator
    {

    public:
        T value;

        //constructor
        iterator(T v) : value(v){}

        // operators
        bool operator!=(range::iterator const &other) const
        { 
            return value != (other.value);
        }

    bool operator== (range::iterator const &other) const
    {
       return value == other.value;

     }
        const T operator*() const
        {
            return value;
        }

        iterator &operator++()
        {

            ++value;
            return *this;
        }

    };

public:

    range(T from, T to) : _start(from), _end(to) {}  




		iterator begin() const {
			return iterator(_start);
		}

		iterator end() const {
			return iterator(_end);
		} 
}; // class



} // namespace itertools