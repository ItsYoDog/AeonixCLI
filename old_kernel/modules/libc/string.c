#include <string.h>

#include <memory.h>

#include <screen.h>

#define NULL ((char * ) 0)

void swap(char * x, char * y) {
    char t = * x;* x = * y;* y = t;
}

int compare(const char * X,
    const char * Y) {
    while ( * X && * Y) {
        if ( * X != * Y) {
            return 0;
        }

        X++;
        Y++;
    }

    return ( * Y == '\0');
}

char * strremove(char * str,
    const char * sub) {
    char * p, * q, * r;
    if ((q = r = strstr(str, sub)) != NULL) {
        int len = strlen(sub);
        while ((r = strstr(p = r + len, sub)) != NULL) {
            while (p < r)
                *
                q++ = * p++;
        }
        while (( * q++ = * p++) != '\0')
            continue;
    }
    return str;
}

// Function to implement `strstr()` function
const char * strstr(const char * X,
    const char * Y) {
    while ( * X != '\0') {
        if (( * X == * Y) && compare(X, Y)) {
            return X;
        }
        X++;
    }

    return NULL;
}

// function to reverse buffer[i..j]
char * reverse(char * buffer, int i, int j) {
    while (i < j)
        swap( & buffer[i++], & buffer[j--]);

    return buffer;
}

int strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') ++i;
    return i;
}

int strcmp(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') return 0;
    }
    return s1[i] - s2[i];
}

char * strcat(char * destination,
    const char * source) {
    // make `ptr` point to the end of the destination string
    char * ptr = destination + strlen(destination);

    // appends characters of the source to the destination string
    while ( * source != '\0') {
        * ptr++ = * source++;
    }

    // null terminate destination string
    * ptr = '\0';

    // the destination is returned by standard `strcat()`
    return destination;
}

char * strpbrk(const char * s,
    const char * accept) {
    while ( * s != '\0') {
        const char * a = accept;
        while ( * a != '\0')
            if ( * a++ == * s)
                return (char * ) s;
        ++s;
    }
    return NULL;
}

int strspn(const char * s,
    const char * accept) {
    const char * p;
    const char * a;
    int count = 0;

    for (p = s;* p != '\0'; ++p) {
        for (a = accept;* a != '\0'; ++a)
            if ( * p == * a)
                break;
        if ( * a == '\0')
            return count;
        else
            ++count;
    }
    return count;
}

char * strtok(char * s,
    const char * delim) {
    static char * olds;
    char * token;
    if (s == 0)
        s = olds;
    s += strspn(s, delim);
    if ( * s == '\0') {
        olds = s;
        return NULL;
    }
    token = s;
    s = strpbrk(token, delim);
    if (s == 0) {
        olds = token;
    } else {
        * s = '\0';
        olds = s + 1;
    }
    return token;
}

char * strcpy(char * destination,
    const char * source) {
    // return if no memory is allocated to the destination
    if (destination == NULL) {
        return NULL;
    }

    // take a pointer pointing to the beginning of the destination string
    char * ptr = destination;

    // copy the C-string pointed by source into the array
    // pointed by destination
    while ( * source != '\0') {
        * destination = * source;
        destination++;
        source++;
    }

    // include the terminating null character
    * destination = '\0';

    // the destination is returned by standard `strcpy()`
    return ptr;
}


int octtodec(int n) {
    int num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 8^0
    int base = 1;

    int temp = num;
    while (temp == 1) {

        // Extracting last digit
        int last_digit = temp % 10;
        temp = temp / 10;

        // Multiplying last digit with appropriate
        // base value and adding it to dec_value
        dec_value += last_digit * base;

        base = base * 8;
    }

    return dec_value;
}

unsigned char * memcpy(unsigned char * dest,
    const unsigned char * src, int count) {
    int i;
    for (i = 0; i < count; i++) dest[i] = src[i];
    return dest;
}

unsigned char * memset(unsigned char * dest, unsigned char val, int count) {
    int i;
    for (i = 0; i < count; i++) dest[i] = val;
    return dest;
}

int memcmp(const void * s1,
    const void * s2, int len) {
    unsigned char * p = s1;
    unsigned char * q = s2;
    int charCompareStatus = 0;
    if (s1 == s2) {
        return charCompareStatus;
    }
    while (len > 0) {
        if ( * p != * q) {
            charCompareStatus = ( * p > * q) ? 1 : -1;
            break;
        }
        len--;
        p++;
        q++;
    }
    return charCompareStatus;
}