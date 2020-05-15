#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define STRLEN 1024
#include "song.h"

//  définition du type struct song.
// Comme il est dans unfichier source .c (et pas dans un header .h)
// les champs de ce type
// ne seront connus QUE dans ce fichier. C'est ce qu'on appelle en C un
// "type opaque" : hors du .c où il est déclaré, personne ne sait
// comment il est fichu. et du coup, hors de ce .c, on sera obligé
// d'utiliser les fonctions délarées dans le .h. C'est plus propre !
struct song {
  char           *artist;
  char           *title;
  char           format[4];
  unsigned int    id;
};


song_t song_new( char *artist, char *title, char *format, unsigned int id ) {
  song_t s = calloc( 1, sizeof( *s ) );

  if ( NULL == s ) {
    fprintf( stderr, "Unable to create song.\n" );
    return NULL;
  }

  //s->artist = calloc (strlen(artist) + 1, sizeof(char));
  //strcpy(s->artist, artist);
  s->artist = strdup( artist );

  s->title  = strdup( title );

  if(strlen(format) > 3) {
    fprintf( stderr, "Unable to create song : incorect format\n" );
    free(s->artist); // sinon : fuite mémoire !
    free(s->title); // sinon : fuite mémoire !
    free(s); // sinon : fuite mémoire !
    return NULL;
  }
  strcpy(s->format, format);
  s->id     = id;

  return s;
}

int song_print( song_t s ) {
  if ( s ) {
    return printf( "%s, by %s", s->title, s->artist );
  }
  return 0;
}

void song_delete( song_t s ) {
  if ( s ) {
    free( s->artist );
    free( s->title );
    // free( s->format ); // OULA surtotu pas : chaine statique !
  }
  free( s ); // appeller free() en passant NULL n'est pas une erreur en C. Ca ne fait juste rien du tout.
}



song_t song_parse( char * line ) {

  char           artist[ STRLEN ];
  char           title[ STRLEN ];
  char           format[ STRLEN ];
  unsigned int   id;

  char          *start    = NULL;
  char          *next_tab = NULL;

// on commence par extraire l'id en vérifiant qu'on trouve bien un entier
  if ( 0 == sscanf( line, "%u", &id ) ) {
    fprintf( stderr, "Parse error: Could not find a song ID in '%s'.\n", line );
    return NULL;
  }
  
   // maintenant, on va recherche les tabulation
  start    = line;
  next_tab = strchr( start, '\t' );
  
  if ( NULL == next_tab ) {
    fprintf( stderr, "Parse error: Could not find second tab in '%s'.\n", line );
    return NULL;
  }
  
   // on se place après la première tabulation
  start = next_tab+1;
  next_tab = strchr( start, '\t' );
  
  if ( NULL == next_tab ) {
    fprintf( stderr, "Parse error: Could not find second tab in '%s'.\n", line );
    return NULL;
  }
  
  // extraction du format dans la variable locale
  strncpy( format, start, next_tab - start );
 
  start = next_tab+1;
  next_tab = strchr( start, '\t' );
  
  if ( NULL == next_tab ) {
    fprintf( stderr, "Parse error:Could not find the third tab in '%s'.\n", line );
    return NULL;
  }
  strncpy( title, start, next_tab - start );

  start = next_tab+1;
  next_tab = strchr( start, '\t' );
  
  if ( NULL != next_tab ) {
    fprintf( stderr, "Parse error: to many \t in the title'%s'.\n", line );
    return NULL;
  }
  
  next_tab = strchr( start, '\0' );
  strncpy(artist,  start, next_tab - start );
  song_t s=song_new(artist,title,format,id);
    return s;
}  
  /*

    Algo parse_song
     int id;
     char format[1024] ; // on prend une chaine "assez grande", juste en variabke locale
    char artiste[1024];
    char nom[1024];

    // ETAPE 1 : lire un entier
    lire un entier dans id

    // ETAPE 2 : extraire le format
    char * ptrdebu = reperer le premier \t
    char *ptrsuite = reperer le \t suivant
    copier les caractère entre les deux pointeurs dans la chaine locale format.
        attention : 3 char max !

  // ETAPE 3 : extraire le titre
  ptrdebut = ptrsuite
  ptrsuite = repérer le \t suivant
   copier les caractère entre les deux pointeurs dans la chaine nom.


  // ETAPE 4 : extraire l'artiste
  ptrdebut = ptrsuite
   copier le reste de la chainedans la chaine artist.

// ETAPE 5 : créer la song
 song_t s = song_new( id .... etc);

retourner s*/
