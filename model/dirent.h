#ifndef MODEL_DIRENT_H
#define MODEL_DIRENT_H

#define T Dirent_T
#define FILE_MAXNAME 256

typedef struct T *T;

extern T Dirent_new( char *name );
extern char *Dirent_getname( T fl );
extern int Dirent_gettype( T fl );
extern void Dirent_free( T *fl );

#undef T
#endif /* MODEL_DIRENT_H */
