#include <stdio.h>

/*
 * - Algorithm:
 * 		+ Move the top n – 1 disks from Source to Auxiliary tower,
 * 		+ Move the nth disk from Source to Destination tower,
 * 		+ Move the n – 1 disks from Auxiliary tower to Destination tower.
 * 		+ Transferring the top n – 1 disks from Source to Auxiliary tower can again be thought
 * of as a fresh problem and can be solved in the same manner. Once we solve Towers of Hanoi 
 * with three disks, we can solve it with any number of disks with the above algorithm.
 * */
void towersOfHanoi(int n, const char *frompeg, const char *topeg, const char *auxpeg);

int main() {
	towersOfHanoi(5, "Source", "Destinate", "Auxiliary");

	printf("\n");
	return 0;
}

void towersOfHanoi(int n, const char *frompeg, const char *topeg, const char *auxpeg) {
	// if only one disk, make the move and return
	if (n == 1) {
		printf("\nMove disk 1 from %s to %s", frompeg, topeg);
		return;
	}

	// Move the top n – 1 disks from Source to Auxiliary tower
	towersOfHanoi(n - 1, frompeg, auxpeg, topeg);

	// Move the nth disks (remaining disks) from Source to Destination tower
	printf("\nMove disk %d from %s to %s", n, frompeg, topeg);

	// Move the n – 1 disks from Auxiliary tower to Destination tower.
	towersOfHanoi(n - 1, auxpeg, topeg, frompeg);
}
