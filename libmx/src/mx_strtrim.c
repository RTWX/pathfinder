#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) 
        return NULL;
    int fc_indx = 0;

    for ( ; str[fc_indx] != 0 && mx_isspace(str[fc_indx]); fc_indx++) {  }

    int lc_indx = 0;

    for ( ; str[lc_indx] != 0 ; lc_indx++) {
        bool b = false;
        if ( mx_isspace(str[lc_indx]) ) {
            b = true;
            for ( int n = lc_indx; str[n] != 0 ; ) {
                if (!mx_isspace(str[n])) {
                    b = false;
                    break;
                }
            }
        }
        if (b)
            break;
    }
    char *tstr = (char *)malloc( (sizeof(char) * (lc_indx - fc_indx) ) + 1);
    int j = 0;
    for (int i = fc_indx; i < lc_indx; i++, j++)
        tstr[j] = str[i];
    tstr[j] = '\0';
    return tstr;
}

