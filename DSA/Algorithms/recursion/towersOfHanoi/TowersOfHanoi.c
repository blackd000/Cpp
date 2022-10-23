#include "TowersOfHanoi.h"

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
