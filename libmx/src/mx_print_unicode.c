#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    unsigned char uchar[4];
    int uc_size = 4;
    if (c < 0x80)
        uc_size = 1;
    else if (c < 0x0800) 
        uc_size = 2;
    else if (c < 0x010000) 
        uc_size = 3;
    int shift = (uc_size - 1) * 6; 
    for (int i = 0; i < uc_size; i++) {
        if (i == 0 && uc_size == 1)
            uchar[i] = (c >> shift & 0x7F) | 0x00;
        else if (i == 0 && uc_size == 2)
            uchar[i] = (c >> shift & 0x1F) | 0xC0;
        else if (i == 0 && uc_size == 3) 
            uchar[i] = (c >> shift & 0x0F) | 0xE0;
        else if (i == 0 && uc_size == 4) 
            uchar[i] = (c >> shift & 0x07) | 0xF0;
        else
            uchar[i] = (c >> shift & 0x3F) | 0x80;
        shift -= 6;
    }
    write(1, &uchar, (size_t)uc_size);
}

