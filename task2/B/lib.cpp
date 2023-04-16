#include "lib.h"
#include <iostream>

void Modular::add(int rhs) {		
	x += rhs; 
	x %= mod; 
}

void Modular::mult(int rhs) {
	x *= rhs; 
	x %= mod; 
}

int Modular::get() {
	return x; 
}
