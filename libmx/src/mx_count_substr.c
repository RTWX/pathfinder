#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) 
        return -1;
    int count = 0;
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == sub[0]) {
            int x = 1;
            int n = i + 1;
            for (int j = 1; sub[j] != 0 && str[n] != 0; j++, n++) {
                if (str[n] != sub[j]) {
                    x = 0;
                    break;
                }
                if (str[n+1] == 0 && sub[j+1] != 0)
                    x = 0;
                if ( (str[n+1] != 0 || str[n+1] == 0) && sub[j+1] == 0 )
                    x = 1;
            }
            if (x == 1) {
                count++;
                i = n - 1;
            }
        }
    }
    return count;
}

