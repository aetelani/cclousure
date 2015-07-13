/*
 * FoCit programming framework
 * 
    Copyright (C) 2015  Anssi Eteläniemi

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdio.h>

struct foc_object;
struct foc_object {
	long int value;
	struct foc_object (*add) (int);
	struct foc_object (*mul) (int);
};

struct foc_object adder(int);
struct foc_object multiplier(int);

static struct foc_object foc_instance;

struct foc_object adder(int added_value) {
	foc_instance.value += added_value;
	return foc_instance;
}

struct foc_object multiplier(int mul_value) {
	foc_instance.value *= mul_value;
	return foc_instance;
}

int main(int arg, char * argv[]) {
	foc_instance.add = (void *) adder;
	foc_instance.mul = (void *) multiplier;
	foc_instance.add(10).mul(4).add(2);
	printf("Answer is %li\n", foc_instance.value);
	return 0;
}

