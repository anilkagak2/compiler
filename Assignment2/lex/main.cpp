#include "declarations.h"

int main() {
    string re = "ab";
    re = "a|b";
    nfa n(re);
	dfa d = n.to_dfa();
    d.print_transitions ();
	d.print_final();
    return 0;
}
