#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct mystack {
	char *values;
	size_t size, actual, data_size;
};

struct mystack * init(size_t size, size_t data_size) {
	struct mystack * this = (struct mystack *) malloc(sizeof(struct mystack));
	this->values = NULL;
	if (this && size && data_size) {
		this->data_size = data_size;
		this->values = malloc(data_size * size);
		this->size = size;
		this->actual = 0;
	}
	return this;
}

void free_stack(struct mystack *this) {
	if (this->values) {
		free(this->values);
	}
	if (this) {
		free(this);
	}
}

int empty(struct mystack *this) {
	return this->actual == 0 ? 1 : 0;
}

void pop(struct mystack *this) {
	this->actual = this->actual > 0 ? this->actual - 1 : 0;
}

void top(struct mystack *this, void *data) {
	if (this->actual > 0) {
		char *place = (char *) this->values;
		memcpy(data, place + (this->actual - 1) * (this->data_size), this->data_size);
	}
}

void push(struct mystack *this, void *x) {
	if (this->actual == this->size) {
		this->values = realloc(this->values, 2 * this->size * this->data_size);
		this->size *= 2;
	}
	char *place = (char *) this->values;
	memcpy(place + (this->actual) * (this->data_size), x, this->data_size);
	++(this->actual);
}

void print_stack(struct mystack *this, int type) {
	int i;
	char *place = (char *) this->values;
	for (i = 0; i < this->actual; ++i) {
		if (!type) {
			int value;
			memcpy(&value, place + (i) * (this->data_size), this->data_size);
			printf("%d ", value);
		} else if (type == 1) {
			double value;
			memcpy(&value, place + (i) * (this->data_size), this->data_size);
			printf("%.2lf ", value);
		} else {
			char value;
			memcpy(&value, place + (i) * (this->data_size), this->data_size);
			printf("%c ", value);
		}
	}
	putchar('\n');
}

#define CHECK(T, N, ToT, toPrint) { \
	struct mystack *minha = init(N, sizeof(T)); \
	assert(empty(minha)); \
	pop(minha); \
	assert(empty(minha)); \
	int i; \
	T value; \
	const int type = sizeof(value) == sizeof(int) ? 0 : \
		(sizeof(value) == sizeof(double) ? 1 : 2); \
	for (i = 0; i < 2 * (N); ++i) { \
		value = (ToT(i)); \
		push(minha, &value); \
		value = (ToT(-1)); \
		top(minha, &value); \
		assert(!empty(minha)); \
		assert((ToT(i)) == value); \
		if (toPrint) print_stack(minha, type); \
	} \
	for (i = 2 * (N) - 1; i >= 0; --i) { \
		assert(!empty(minha)); \
		value = (ToT(-1)); \
		top(minha, &value); \
		assert((ToT(i)) == value); \
		pop(minha); \
		if (toPrint) print_stack(minha, type); \
	} \
	assert(empty(minha)); \
	free_stack(minha); \
}

char toChar(int value) {
	return 'a' + value % ('z' - 'a' + 1);
}

int main() {
	const int size = 1000, to_print = 0;
	CHECK(int, size, (int), to_print);
	CHECK(unsigned, size, (unsigned), to_print);
	CHECK(double, size, (double).1+, to_print);
	CHECK(char, size, toChar, to_print);
	
	puts("OK");

	return 0;
}
