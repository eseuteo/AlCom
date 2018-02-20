#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include <math.h>

int main(int argc, char ** av){
	uint64_t input = 3;
	if (argc == 2) {
		printf("yolo\n");
		input = (uint64_t) atoi(av[1]);
	}
	if (argc > 2) {
		printf("Invalid number of arguments");
		exit(0);
	}

	uint64_t i = 0;
	uint64_t max = 0;

	for (i = 0; i < input; i++) {
		max += 9 * (uint64_t) pow(10, i);
	}

	uint64_t powers[10];

	for (i = 0; i < 10; i++) {
		powers[i] = pow(i, input);
	//	printf("%" PRIu64 "\n", powers[i]);
	}

	uint64_t acu = 0;
	uint64_t current = 0;

	//printf("%" PRIu64 "\n", max);

	for (i = 0; i < max; i++) {
		current = i;
		while (current > 0) {
			acu += powers[current % 10];
			current /= 10;
		}
//		printf("%" PRIu64 " - %" PRIu64 "\n", acu, i);
		if (acu == i) {
			printf("%" PRIu64 "\n", acu);
		}
		acu = 0;
	}

	// Si argumentos == 0, sacar los narcisistas-3
	// Si argumentos > 1, error
	// Tomar argumento av y buscar los narcisistas-av
	// en primera instancia, dado av, calcular la potencia av de los números de 0 a 9 y guardarlos en un array
	// definir la cota superior
		// determinar a partir de qué número no puede haber narcisistas-av
		// determinar si a partir de x número de números grandes (8, 9, etc) deja de haber narcisistas
	// uso de threads?
		// calcular tamaño del espacio de búsqueda
}