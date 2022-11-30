#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL) 
        return NULL;
    int subcnt = mx_count_substr(str, sub);

    int nlen = (mx_strlen(str) - subcnt*mx_strlen(sub)) + subcnt*mx_strlen(replace);

    char *nstr = (char *)malloc( (nlen + 1) * sizeof(char) );

    int y = 0;
    for (int i = 0; str[i] != 0; i++) {//+
        
        if (str[i] == sub[0]) {//+
            bool x = 0;
            int n = i;
            for (int j = 0; sub[j] != 0 && str[n] != 0; j++) { //
                if (str[n] != sub[j]) {//+
                    x = 0;
                    break;
                }
                if (str[n+1] == 0 && sub[j+1] != 0)//
                    x = 0;
                if ( sub[j+1] == 0 )//
                    x = 1;
                n++;
            }
            if (x == 1) {
                for (int m = 0; replace[m] != 0; m++) { //
                    nstr[y] = replace[m];
                    y++;
                }
                i = n - 1;
            }
        }
        else { //+
            nstr[y] = str[i];
            y++;
        }
    }
    nstr[y] = '\0';//+
    return nstr;
}


