#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

struct Node {
    bool flg; // To mark if the string is closed.
    struct Node *child[26];
} *root;

int m;
char opt[39], val[39];

int main(int argc, char *argv[]) {

    //Initialization
    root = (struct Node *)malloc(sizeof(struct Node));
    root->flg = false;

    //Inputting
    freopen("./q2105-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; k != m; ++k) {
        scanf("%s %s", opt, val);

        if (!strcmp(opt, "insert")) {
            //Insertion
            struct Node * q = root;
            for (int l = 0; l != strlen(val); ++l) {
                int newkey = val[l] - 'A';
                if (q->child[newkey] == nullptr) {
                    q->child[newkey] = (struct Node *)malloc(sizeof(struct Node));
                    q->child[newkey]->flg = false;
                }
                q = q->child[newkey];
            }
            q->flg = true;
        } else if (!strcmp(opt, "find")) {
            //Searching
            struct Node * q = root;
            bool res = true;
            for (int l = 0; l != strlen(val); ++l) {
                int newkey = val[l] - 'A';
                if (q->child[newkey] != nullptr)
                    q = q->child[newkey];
                else {
                    res = false;
                    break;
                }
            }
            if (res && q->flg)
                printf("yes\n");
            else
                printf("no\n");
        }
    }

    return 0;
}

