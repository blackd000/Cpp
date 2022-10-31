#include <stdio.h>
#include "InfixToPostfix.h"

int main() {
	const char *expression = "A*B-(C+D)+E"; // AB*CD+-E+
	/* const char *expression = "A+B*(C+D)+E"; // ABCD+*+E+ */
	/* const char *expression = "A*B-C+D+E";  // AB*C-D+E+ */
	/* const char *expression = "(A+B)*C-D"; // AB+C*D- */

	infixToPostfix(expression);

	printf("\n");
	return 0;
}
