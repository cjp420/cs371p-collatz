// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

const int cache_size = 1000000;
int cache [cache_size];

// ------------
// collatz_read
// ------------

bool collatz_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;}

// --------------------
// collatz_cycle_length
// --------------------

int collatz_cycle_length (unsigned int n) {
    assert(n > 0);
    int x = n;
    //std::cout << n << ", checking cache " << std::endl;
    if (cache[n] != 0)
        return cache[n];
    int len = 1;
    while(x > 1) {
	//std::cout << x << ", computing " << std::endl;
	if(x % 2 == 1)
	    x = 3 * x + 1;
	else
	    x = x / 2;
	len++;}
    assert(len > 0);
    //std::cout << n << ", storing in cache " << len << std::endl;
    cache[n] = len;
    return len;}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);
    // <your code>
    int x = 0;
    int y = 0;
    if(i <= j) {
        x = i;
        y = j;}
    else {
	x = j;
	y = i;}
    assert(x > 0);
    assert(y > 0);
    assert(x <= y);
    int v = 0;
    int m = 0; 
    for(int n = x; n <= y; n++) {
	m = collatz_cycle_length((unsigned int)n);
	//std::cout << n << ", " << m << std::endl;
	if(m > v)
	    v = m;}
    assert(v > 0);
    return v;}


// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    assert(i > 0);
    assert(j > 0);
    assert(v > 0);
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
