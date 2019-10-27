#include <stdio.h>
#include <math.h>

char token[2];

void get_token () {
    token[0] = getchar ();
    if (token[0] != '\n')
        token[1] = getchar ();
    else token[1] = ' ';
    printf ("%s\n", token);
}

int charcmp (char *str_1, char *str_2) {
    return strcmp (str_1, str_2) == 0;
}

int rule_A ();
int rule_B ();
int rule_C ();
int rule_D ();
int rule_E ();
int rule_F ();

int rule_A () {
    get_token();
    if (charcmp (token, "ba"))
        return rule_A ();
    if (charcmp (token, "br"))
        return rule_B ();
    return 0;
}

int rule_B () {
    get_token();
    if (charcmp (token, "br"))
        return rule_B ();
    if (charcmp (token, "ba"))
        return rule_B ();
    if (charcmp (token, "bb"))
        return rule_C ();
    if (charcmp (token, "bv"))
        return rule_D ();
    return 0;
}

int rule_C () {
    get_token();
    if (charcmp (token, "bb"))
        return rule_C ();
    if (charcmp (token, "bv"))
        return rule_D ();
    return 0;
}

int rule_D () {
    get_token();
    if (charcmp (token, "ba"))
        return rule_D ();
    if (charcmp (token, "br"))
        return rule_E ();
    return 0;
}

int rule_E () {
    get_token();
    if (charcmp (token, "ba"))
        return rule_E ();
    if (charcmp (token, "br"))
        return rule_F ();
    if (charcmp (token, "\n "))
        return 1;
    return 0;
}

int rule_F () {
    return 1;
}

int main(int argc, char **argv) {
    printf(rule_A () == 1 ? "true\n" : "false\n");
    return 0;
}
