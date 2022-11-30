#include "../inc/libmx.h"

bool mx_isspace(char c) {
    if (c == 32) {
        return true;
    }
    if (c == 10) {
        return true;
    }
    if (c == 9) {
        return true;
    }
    if (c == 11) {
        return true;
    }
    if (c == 12) {
        return true;
    }
    if (c == 13) {
        return true;
    }
    return false;
}
