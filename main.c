#include <stdio.h>
#include "lex.h"

main ()
{
	statements ();
	if (!match (EOI)) {
		printf ("Error: Input not according to grammar\n");
	}
}
