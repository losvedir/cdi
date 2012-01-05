#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dirent.h"

#define T Dirent_T

struct T {
    char name[FILE_MAXNAME];
    char shortname[FILE_MAXNAME];
    long ino;
    int type;
    int statreturn;
};

T Dirent_new( char *name ) {
    struct stat stbuf;
    int res;

    res = stat(name, &stbuf);
    T fl;

    fl = (T)malloc(sizeof(struct T));
    strncpy(fl->name, name, FILE_MAXNAME);
    fl->name[FILE_MAXNAME-1] = '\0';
    fl->statreturn = res;
    
    return fl;
}
 
char *Dirent_getname( T fl ) {
    return fl->name;
}

void Dirent_free( T *fl ) {
    free(*fl);
    *fl = NULL;
}

#undef T
