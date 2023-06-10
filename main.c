#include <stdio.h>
#include <string.h>

#include "sortAndShuffle.h"
#include "sortAndShuffle.c"

#define ARTISTS 4
#define MAX_SONGS_Per_Artist 3
#define MAX_LENGTH 80




int main(void)
{
    //The array containing artists names
    char artists[ARTISTS][MAX_LENGTH];
    // The array of sorted artists
    char sortedartists[ARTISTS][MAX_LENGTH];

    //The 3d array containing the songs names
    char songs[ARTISTS][MAX_SONGS_Per_Artist][MAX_LENGTH];
    // the array of sorted songs
    char sortedsongs[ARTISTS][MAX_SONGS_Per_Artist][MAX_LENGTH];
    //The total number of artists
    int numOfArtists;
    //The total number of songs for each artist
    int numSongsPerArtist[4] = {0};

    int totalNumSongs = 0;


    // Call the InsertSongAndArtist function to get user input for artists and songs
    // and assign the value to numOfArtists to keep track of how many artists have been inputed
    numOfArtists = insertSongAndArtist( artists, songs, numSongsPerArtist);


    // Print the unordered list of artists and songs
    printf("\nUnordered List\n" );
    printSongs( artists, songs, numOfArtists , numSongsPerArtist );

    // Sort the list of artists and songs
    sortArtists( artists, songs , numSongsPerArtist , numOfArtists , sortedartists);
    sortSongs( songs, numSongsPerArtist , numOfArtists , sortedsongs);

    // Print the ordered list of artists and songs
    printf("\nOrdered List\n");
    printSongs( artists, songs, numOfArtists , numSongsPerArtist );

    // Calculate the total number of songs
    for (int i = 0; i < numOfArtists; i++)
    {
        totalNumSongs += numSongsPerArtist[i];
    }

    // 2d array of the Artists and songs all in 1 array
    char ArtistSong[totalNumSongs*2][MAX_LENGTH];


    //Combines the artists and songs into 1 array
    combine_arrays(sortedartists, sortedsongs, numOfArtists, numSongsPerArtist , ArtistSong);
    // Shuffle the array of artists and songs
    shuffle( ArtistSong,  totalNumSongs*2);

    // Prints the ArtistSong array
    for (int i = 0; i < totalNumSongs*2; i++)
    {
        printf("%s\n", ArtistSong[i]);
    }

    shuffleSongs(artists, songs, numOfArtists,  numSongsPerArtist , totalNumSongs);
    
    return 0;
}

// This function allows the user to input a list of artists and their songs
int insertSongAndArtist(char artists[ARTISTS][MAX_LENGTH], char songs[ARTISTS][MAX_SONGS_Per_Artist][MAX_LENGTH], int numSongsPerArtist[])
{
    int i, j;
    int artlength;
    int songlength;
    char input[MAX_LENGTH];

    // Loop through each artist
    for(i = 0; i < ARTISTS; i++)
    {
        // Ask the user to input the artist's name
        printf("Insert Artist %d : ", i + 1);
        fgets(artists[i], MAX_LENGTH, stdin);

        // If the user inputs a blank line, stop asking for more artists
        if(artists[i][0] == '\n')
        {
            break;
        }

        // Ensure that at least one song is entered for the current artist
        printf("Insert Song 1 for %s : " , artists[i]);
        fgets(songs[i][0], MAX_LENGTH, stdin);

        // If the user inputs a blank line for the first song, keep asking until a song is entered
        while(songs[i][0][0] == '\n')
        {

            printf("Error: At least one song must be entered for the artist %s", artists[i]);
            printf("Insert Song 1 for %s: " , artists[i]);
            fgets(songs[i][0], MAX_LENGTH, stdin);

        }

        // Remove the newline character from the song name
        songlength = strlen(songs[i][0]);
        songs[i][0][songlength - 1] = '\0';

        // Set the number of songs for the current artist to 1
        numSongsPerArtist[i] = 1;

        // Allow the user to input additional songs for the current artist
        for(j = 1; j < MAX_SONGS_Per_Artist; j++)
        {
            // Ask the user to input the next song, and give the option to stop by entering a blank line
            printf("Insert Song %d for %s (Press enter to stop): ", j + 1 , artists[i]);
            fgets(input, MAX_LENGTH, stdin);

            // If the user enters a blank line, stop asking for more songs
            if(input[0] == '\n')
            {
                break;
            }

            // Copy the user's input into the songs array
            strcpy(songs[i][j], input);

            // Remove the newline character from the song name
            songlength = strlen(songs[i][j]);
            songs[i][j][songlength - 1] = '\0';

            // Increase the number of songs for the current artist
            numSongsPerArtist[i] = j + 1;
        }

        // Remove the newline character from the artist's name
        artlength = strlen(artists[i]);
        artists[i][artlength - 1] = '\0';

    }

    return i; // return the number of artists entered
}

// This function allows to print the artists and their respective songs
void printSongs( char artists[ARTISTS][MAX_LENGTH] , char songs[ARTISTS][MAX_SONGS_Per_Artist][MAX_LENGTH], int numOfArtists , const int numSongsPerArtist[] )
{
    int i;
    int j;

    // Loop through each artist
    for(i=0; i < numOfArtists; i++)
    {
        // Print the name of the artist
        printf("\nArtist %d: %s\n", i+1, artists[i]);
        // Loop through each song for the current artist
        for (j = 0; j < numSongsPerArtist[i]; j++)
        {
            // Print the name of the song
            printf("Song %d : %s\n" , j+1 , songs[i][j]);
        }
    }

}


// This function Combines the array of artists and the array of songs and puts them all in a new array
void combine_arrays(char artists[][MAX_LENGTH], char songs[][MAX_SONGS_Per_Artist][MAX_LENGTH], int numOfArtists, const int numSongsPerArtist[] , char ArtistSong[][MAX_LENGTH] )
{
    int i, j;
    int index = 0;

    printf("Combined Array:\n");

    // Iterate over each artist and their songs and add them to the combined array
    for(i = 0; i < numOfArtists; i++)
    {
        // Repeat each artist-song combination twice to simulate a playlist
        for (int k = 0; k < 2; ++k)
        {
            // Iterate over each song of the current artist
            for (j = 0; j < numSongsPerArtist[i]; j++)
            {
                // Combine the artist name and the song name into one string and store it in a new array
                sprintf(ArtistSong[index], "%s - %s\n", artists[i], songs[i][j]);
                index++;

            }
        }
    }
}











