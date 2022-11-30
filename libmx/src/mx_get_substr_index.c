#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL)
        return -2;
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == sub[0]) {
            int x = 0;
            int n = i;
            for (int j = 0; sub[j] != 0 && str[n] != 0; j++, n++) {
                if (str[n] != sub[j]) {
                    x = 0;
                    break;
                }
                if (str[n+1] == 0 && sub[j+1] != 0)
                    x = 0;
                if ( sub[j+1] == 0 )
                    x = 1;
            }
            if (x == 1)
                return i;
        }
    }
    return -1;
}

