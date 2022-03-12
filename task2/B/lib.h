#include <iostream>

class Modular {
private:
	int x = 2007; 
	int mod = 1e9 + 7; 
public: 
	Modular(int x_, int mod_) : x(x_), mod(mod_) {}

	Modular(int x_) : x(x_) {}

	void add(int rhs); 			

	void mult(int rhs); 

	int get(); 		
}; 
