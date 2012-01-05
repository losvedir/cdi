#include <sys/types.h>
#include <sys/dir.h>
#include <stdio.h>
#include <stdlib.h>
#include "dirent.h"
#include "dir.h"

#define T Dir_T

struct dir_item {
    Dirent_T entry;
    struct dir_item *next;
};

struct T {
    int fd;  /* file descriptor for directory */
    char name[MAX_NAME];
    struct dir_item *head;
    struct dir_item *cursor;
    struct dir_item *last;
};

static T Dir_newempty() {
    T dir;
    dir = (T) malloc( sizeof(T*) );
    dir->head = NULL;
    dir->cursor = NULL;
    dir->last = NULL;
    return dir;
}

T Dir_new( Dirent entry ) {
    T dir = Dir_newempty();
    int count, i;
    struct direct **files;
    int file_select();

    if (getwd(Dirent_getname(entry)) == NULL ) {
        printf("Error getting path\n");
        exit(0);
    }

    count = scandir( Dirent_getname(entry), &files, file_select, alphasort);
    if (count <= 0) {
        printf("No files found\n");
        exit(0);
    }

    

}

int Dir_isempty( T dir ) {
    return (dir == NULL ||  dir->head == NULL );
}

void Dir_appendentry( T dir, Dirent_T entry ) {
    struct dir_item *item = (struct dir_item *) malloc(sizeof(struct dir_item));

    item->entry = entry;
    item->next = NULL;

    if (Dir_isempty(dir)) {
        dir->head = dir->cursor = dir->last = item;
    } else {
        dir->last->next = item;
        dir->last = item;
    }
}

Dirent_T Dir_getnextentry( T dir) {
    struct dir_item *curitem = dir->cursor;
    dir->cursor = curitem->next;

    return curitem->entry;
}

void Dir_resetcursor( T dir) {
    dir->cursor = dir->head;
}

void Dir_free( T *dir_p) {
    struct dir_item *item = (*dir_p)->head;
    struct dir_item *next;
    while (item) {
        next = item->next;
        Dirent_free(&(item->entry));
        free(item);
        item = next;
    }
    free(*dir_p);
    *dir_p = NULL;
}

#undef T
