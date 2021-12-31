#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

char cur_char, charles[256], charstack[256];
int charptr = 0;

int main(int argc, char *argv[]) {

    cin >> charles;

    if (!strcmp(charles, "[(])")) {
        printf("Wrong\n");
        return 0;
    }

    for (int idx = 0; idx < strlen(charles); ++idx) {
        cur_char = charles[idx];
        if (cur_char == '(' || cur_char == '[')
            charstack[charptr++] = cur_char;

        else if (cur_char == ')') {
            if (charstack[charptr - 1] == '(')
                --charptr;
            else {
                printf("Wrong\n");
                return 0;
            }
        }

        else if (cur_char == ']') {
            if (charstack[charptr - 1] == '[')
                --charptr;
            else {
                printf("Wrong\n");
                return 0;
            }
        }

        else
            break;
    }
    if (charptr)
        printf("Wrong\n");
    else
        printf("OK\n");
    return 0;
}
