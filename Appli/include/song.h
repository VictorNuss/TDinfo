#ifndef SONG_H
#define SONG_H

struct song;
typedef struct song * song_t;

song_t song_new( char *artist, char *title, char *format, unsigned int id );
void song_delete( song_t s );

int song_print( song_t s );

// analyse la chaine str
// retourne l'adresse de la chanson qui a pu être parsée. La chanson est dans ce cas allouée dynamiquement et devra être libérée avec song_delete()
// ou NULL en cas d'erreur
song_t song_parse(char *str) ;
#endif


