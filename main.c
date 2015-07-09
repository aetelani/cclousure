#include <stdio.h>

struct integer;
struct integer {
	long int value;
	struct integer (*add) (int);
	struct integer (*mul) (int);
};

struct integer adder(int);
struct integer multiplier(int);

static struct integer integer_object;

struct integer adder(int added_value) {
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
	integer_object.add(10).mul(4).add(2);
	printf("Answer is %li\n", integer_object.value);
	return 0;
}
