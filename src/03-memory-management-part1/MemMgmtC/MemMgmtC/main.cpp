#include <stdio.h>
#include <stdlib.h>

void PrintArray(const int* arr, size_t count) {
	for (size_t i = 0; i < count; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	const size_t count = 5;

	// malloc (uninitialized)
	int* p = (int*)malloc(count * sizeof(*p));
	if (p == NULL) {
		fprintf(stderr, "malloc failed\n");
		return 1;
	}

	// NOTE: reading uninitialized memory is undefined behavior (demo only)
	printf("malloc (uninitialized): ");
	PrintArray(p, count);

	p[0] = 5;
	p[1] = 10;

	printf("malloc (after assignment): ");
	PrintArray(p, count);

	free(p);
	p = NULL;

	// calloc (zero-initialized)
	p = (int*)calloc(count, sizeof(*p));
	if (p == NULL) {
		fprintf(stderr, "calloc failed\n");
		return 1;
	}

	printf("calloc (initialized to 0): ");
	PrintArray(p, count);

	p[0] = 5;
	p[1] = 10;

	printf("calloc (after assignment): ");
	PrintArray(p, count);

	free(p);
	p = NULL;

	return 0;
}