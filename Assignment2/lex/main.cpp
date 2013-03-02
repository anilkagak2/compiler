#include "declarations.h"

int main() {
    string re = "abc";
//    re = "a*";
    nfa n(re);

    n.print_transitions ();
    return 0;
}
