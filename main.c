#include <stdio.h>

struct integer;
struct integer {
	unsigned long int value;
	struct integer (*add) (unsigned int);
	struct integer (*mul) (int);
};

struct integer adder(unsigned int);
struct integer multiplier(int);

static struct integer integer_object;

struct integer adder(unsigned int added_value) {
	integer_object.value += added_value;
	return integer_object;
}

struct integer multiplier(int mul_value) {
	integer_object.value *= mul_value;
	return integer_object;
}

int main(int arg, char * argv[]) {
	integer_object.add = (void *) adder;
	integer_object.mul = (void *) multiplier;
	integer_object.add(21);
	integer_object.mul(2);
	printf("Integer result sum %lu\n", integer_object.value);
	return 0;
}
