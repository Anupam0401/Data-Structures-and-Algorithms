// example for static analysis

#include <cstdio>
#include <exception>
#include <cstring> 

bool someCondition(int unused_var) {
	return true;
}

int z;

// unused function
bool unused_function() {
	return true;
}

void scope_test() {
	int scope_var,l=0;
	for (int i=0; i<10; i++) {
		scope_var = 5;
		if (scope_var == l)
			;
	}
}

void exception_test() {

}

const int VAR = 10;

bool if_else(int var) {
	if (var == VAR)
		return 0;
	else if (var == VAR)
		return 1;
	else
		return 2;
}

void do_uid(int x) {
	printf("<a href='#%d'>%d</a>", x, x, x);
}

bool unsigned_test(unsigned var) {
	return (var < 0);
}

int main() {
	// Uninitialized variable
	int a;
	if (a == 10)
		;

	// memory leak
	char *leaked_var = new char[10];

	// unused parameter
	if (!someCondition(10))
		return 1;

	// Mismatching allocation and deallocation
	int *leaked_delete = new int[5];
	leaked_delete[0] = 0;
	delete leaked_delete;

	// incorrect array index
	int arr[3];
	if (arr[4] == 0);

	// memset
	char *buffer = new char[10];
	memset(buffer, 0, sizeof(buffer));
	delete buffer;

	// printf format warning/error
	do_uid(10);

	// scope
	scope_test();

	// Exception should be caught by reference
	try {
		exception_test();
	} catch (std::exception e) {
	}

	// Duplicate conditions
	if_else(5);

	// Checking if unsigned variable is less than zero
	unsigned_test(2);	

	return 0;	
}