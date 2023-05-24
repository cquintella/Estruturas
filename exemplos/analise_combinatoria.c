#include <stdio.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutations(char *elements, int start, int size) {
    if (start == size - 1) {
        printf("%s\n", elements);
    } else {
        for (int i = start; i < size; i++) {
            swap(&elements[start], &elements[i]);
            permutations(elements, start + 1, size);
            swap(&elements[start], &elements[i]);
        }
    }
}

void combinations(char *elements, int size, int start, char *result, int resultSize, int position) {
    if (position == resultSize) {
        result[position] = '\0';
        printf("%s\n", result);
    } else {
        for (int i = start; i <= size - resultSize + position; i++) {
            result[position] = elements[i];
            combinations(elements, size, i + 1, result, resultSize, position + 1);
        }
    }
}

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    char elements[] = "ABC";
    int size = sizeof(elements) - 1;

    printf("Permutations:\n");
    permutations(elements, 0, size);

    printf("\nCombinations:\n");
    char result[size + 1];
    for (int i = 1; i <= size; i++) {
        combinations(elements, size, 0, result, i, 0);
    }

    printf("\nFactorial of %d: %d\n", size, factorial(size));

    return 0;
}
