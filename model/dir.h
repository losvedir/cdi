#ifndef MODEL_DIR_H
#define MODEL_DIR_H

#include "dirent.h"

#define T Dir_T
#define MAX_NAME 30  /* max name length of filename or part of path */

typedef struct T *T;

extern T        Dir_new( Dirent );
extern int      Dir_isempty( T );
extern void     Dir_appendentry( T , Dirent_T );
extern Dirent_T Dir_getnextentry( T );
extern void     Dir_resetcursor( T );
extern void     Dir_free( T* );

#undef T
#endif /* MODEL_DIR_H */
