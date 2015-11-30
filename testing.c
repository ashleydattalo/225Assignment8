#include <stdio.h>
#include <string.h>

int main(void) {
	char arr1[] = "hello";
	char arr2[] = "hello";
	char arr3[] = "a";

	int a12 = strcmp(arr1, arr2);
	int a23 = strcmp(arr2, arr3);

	printf("%d\n", a12);
	printf("%d\n", a23);
}