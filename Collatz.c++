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
    int v = 0;
    int m = 0; 
    for(int n = x; n <= y; n++) {
	m = collatz_cylce_length(x);
	if(m > v )
	    v = m;}
    assert(v > 0);
    return v;}

int collatz_cycle_length (int n) {
    while(n > 1) {
	if(n % 2)
	    n = 3 * n + 1;
	else
	    n = n / 2;
    return n;
}

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
