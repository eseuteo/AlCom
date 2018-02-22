#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include <math.h>

typedef struct Node {
	uint64_t number;
	uint64_t sum;
	uint64_t depth;
} Node;

uint64_t powers[10];
uint64_t max = 0;
uint64_t checks = 0;
uint64_t stop_flag = 0;
uint64_t found_flag = 0;

uint64_t get_max_num(uint64_t number_of_digits) {
	uint64_t ans = 0;
	uint64_t i = 0;
	for (i = 0; i < number_of_digits; i++) {
		ans += 9 * (uint64_t) pow(10, i);
	}
	return ans;
}

void evaluate(Node tree, uint64_t input) {
	uint64_t i = 0;

	if (tree.depth == input) {
		checks++;
		if (tree.sum == tree.number) {
			found_flag = 1;
			printf("\t%" PRIu64 "\n",tree.number);
		} 	
	}

	if (tree.depth < input) {
		if (tree.sum > tree.number * (uint64_t) pow(10, input - tree.depth) + get_max_num(input - tree.depth)) {
			stop_flag = 1;
			return;
		}
		if (tree.depth == input - 1) {
			for (i = tree.depth ? 0 : 1; i < 10; i++) {
				Node aux;
				aux.number = tree.number * 10 + i;
				aux.sum = tree.sum + powers[i];
				aux.depth = tree.depth + 1;
				if (aux.sum%2 == i%2) {
					evaluate(aux, input);
					if (stop_flag) {
						stop_flag = 0;
						return;
					}
				}
			}
		} else {
			for (i = tree.depth ? 0 : 1; i < 10; i++) {
				Node aux;
				aux.number = tree.number * 10 + i;
				aux.sum = tree.sum + powers[i];
				aux.depth = tree.depth + 1;
				evaluate(aux, input);
				if (stop_flag) {
					stop_flag = 0;
					return;
				}
				if (aux.depth == input - 1 && i == 0 && !found_flag) {
					i++;
				}
				found_flag = 0;
			}
		}
	} else {
		return;
	}
}

int main(int argc, char ** av){
	uint64_t input = 3;
	uint64_t i = 0;
	Node tree;

	if (argc == 2)
		input = (uint64_t) atoi(av[1]);
	if (argc > 2) {
		printf("Invalid number of arguments");
		exit(0);
	}

	max = get_max_num(input);

	for (i = 0; i < 10; i++) {
		powers[i] = pow(i, input);
	}

	tree.number = 0;
	tree.sum = powers[i];
	tree.depth = 0;
	evaluate(tree, input);
	printf("Total checks:\t\t%" PRIu64 "\n", checks);
	printf("Brute force checks:\t%" PRIu64 "\n", max + 1);
}