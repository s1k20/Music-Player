#define MAX_SONGS_Per_Artist 3
#define ARTISTS 4
#define MAX_LENGTH 80

int insertSongAndArtist( char artists[][MAX_LENGTH] , char songs[ARTISTS][MAX_SONGS_Per_Artist][MAX_LENGTH] , int numSongsPerArtist[]);
void printSongs( char artists[ARTISTS][MAX_LENGTH] , char songs[ARTISTS][MAX_SONGS_Per_Artist][MAX_LENGTH], int numOfArtists , const int numSongsPerArtist[]);
void sortArtists(char artists[ARTISTS][MAX_LENGTH], char songs[ARTISTS][MAX_SONGS_Per_Artist][MAX_LENGTH], int numSongsPerArtist[ARTISTS], int numArtists , char sortedartists[][MAX_LENGTH]);
void sortSongs(char songs[ARTISTS][MAX_SONGS_Per_Artist][MAX_LENGTH], const int numSongsPerArtist[] , int numOfArtists , char sortedsongs[ARTISTS][MAX_SONGS_Per_Artist][MAX_LENGTH]);
void shuffleSongs(char artists[ARTISTS][MAX_LENGTH], char songs[ARTISTS][MAX_SONGS_Per_Artist][MAX_LENGTH],int numOfArtists,int numSongsPerArtist[] , int totalNumSongs);
void shuffle(char ArtistSong [][MAX_LENGTH],  int totalNumSongs);
void combine_arrays(char artists[][MAX_LENGTH], char songs[][MAX_SONGS_Per_Artist][MAX_LENGTH], int numOfArtists, const int numSongsPerArtist[] , char ArtistSong[][MAX_LENGTH] );
