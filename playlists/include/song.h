#ifndef SONG
#define SONG

typedef struct song *song_t; /* A song_t is a pointer to a song structure */

/* Interface for song_t */
song_t song_new( char *artist, char *title );
void song_print( song_t s );
void song_delete( song_t s );


#endif
