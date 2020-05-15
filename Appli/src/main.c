#include <stdlib.h>
#include <stdio.h>

#include "song.h"

int main () {

  song_t s = song_new( "Marilyn Manson", "Reflecting God", "MP3", 5533 );
  song_print( s );
  printf("\n"); // passage à la ligne...
  song_delete( s );

  // test d'erreur sur la taille de la chaine format
  s = song_new( "Marilyn Manson", "Reflecting God", "FORMAT INVALIDE", 5533 );

  exit( EXIT_SUCCESS );
}

