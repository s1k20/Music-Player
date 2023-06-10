#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAX_SONGS_Per_Artist 3
#define ARTISTS 4
#define MAX_LENGTH 80


// This Function sorts the artists alphabetically using bubble sort and switches the sorted songs to there respective sorted artists
void sortArtists(char artists[ARTISTS][MAX_LENGTH], char songs[ARTISTS][MAX_SONGS_Per_Artist][MAX_LENGTH], int numSongsPerArtist[ARTISTS], int numOfArtists , char sortedartists[ARTISTS][MAX_LENGTH])
{
    char tempA[MAX_LENGTH];
    char tempS[MAX_LENGTH];
    int tempNumSongs;
    int i , j ,k;

    // Perform bubble sort on the artist names
    // The outer loop iterates through all the artists except the last one
    for (i = 0; i < numOfArtists - 1; i++)
    {
        // The inner loop iterates through all the artists except the sorted ones
        for(j = 0; j < numOfArtists - i - 1; j++)
        {
            // If the current artists ASCII value is greater than the next one, swap them
            if(strcmp(artists[j], artists[j + 1]) > 0) // Compare adjacent artist names
            {

                // Swap the artist names
                strcpy(tempA, artists[j]);
                strcpy(artists[j], artists[j + 1]);
                strcpy(artists[j + 1], tempA);

                //Swap the songs so that they match for each respective artists after they get swapped
                for(k = 0; k < numSongsPerArtist[j]; k++)
                {
                    // Swamp the song names
                    strcpy(tempS, songs[j][k]);
                    strcpy(songs[j][k], songs[j + 1][k]);
                    strcpy(songs[j + 1][k], tempS);
                }
                // Swap the number of songs for the artists so that they match
                tempNumSongs = numSongsPerArtist[j];
                numSongsPerArtist[j] = numSongsPerArtist[j + 1];
                numSongsPerArtist[j + 1] = tempNumSongs;
            }
        }
    }

    // Copies the artist to the sortedartists
    for (int l = 0; l < numOfArtists ; ++l)
    {
        strcpy(sortedartists[l],artists[l]);
    }
}

// This Function sorts the songs alphabetically using bubble sort
void sortSongs(char songs[ARTISTS][MAX_SONGS_Per_Artist][MAX_LENGTH], const int numSongsPerArtist[] , int numOfArtist , char sortedsongs[ARTISTS][MAX_SONGS_Per_Artist][MAX_LENGTH] )
 {
     int i, j, k;
     char temp[MAX_LENGTH];

     // Performs bubble sort on the song names
     // loop through all artists
     for(i = 0; i < numOfArtist ; i++)
     {
         // The inner loop iterates through all the songs except the last one
         for (j = 0; j < numSongsPerArtist[i] - 1; j++)
         {
             // The innermost loop iterates through all the songs except the sorted ones
             for (k = 0; k < numSongsPerArtist[i] - j - 1; k++)
             {
                 // If the current songs ASCII value is greater than the next one, swap them
                 if (strcmp(songs[i][k], songs[i][k + 1]) > 0) // Compare adjacent song names
                 {
                     // Swap the song names
                     strcpy(temp, songs[i][k]);
                     strcpy(songs[i][k], songs[i][k + 1]);
                     strcpy(songs[i][k + 1], temp);
                 }
             }
         }
     }

     // Copies the songs to the sortedsongs array
     for (int l = 0; l < numOfArtist; ++l)
     {
         for (int m = 0; m < numSongsPerArtist[l]; ++m)
         {
             strcpy(sortedsongs[l][m] , songs[l][m] );
         }
     }
 }


void shuffle(char ArtistSong[][MAX_LENGTH],  int totalNumSongs)
{
    char temp[MAX_LENGTH];
    int i , j;

    srand(time(NULL));

    for(i = 0 ; i < totalNumSongs - 1 ; i++)
    {
        j = rand() % (i + 1);
        if(j != i)
        {
            strcpy(temp, ArtistSong[i]);
            strcpy(ArtistSong[i], ArtistSong[j]);
            strcpy(ArtistSong[j], temp);
        }
    }
}

// This function shuffles the songs and ensures no songs are repeated within 5
void shuffleSongs(char artists[ARTISTS][MAX_LENGTH], char songs[ARTISTS][MAX_SONGS_Per_Artist][MAX_LENGTH],int numOfArtists,int numSongsPerArtist[] , int totalNumSongs)
{

    int cond = 0;
    int count = 0;
    char ShuffledSongs[totalNumSongs*2][MAX_LENGTH];//an array of songs that have been shuffled


    printf("Shuffled Playlist:\n");

    // Loops through the total number of songs by 2
    for (int i = 0; i < totalNumSongs * 2; i++)
    {
        // Finds a random number from 0 to the amount of artists at random
        int ra = rand() % (numOfArtists);
        //variable for the index of numSongsPerArtists
        int numbSPA = numSongsPerArtist[ra];
        // Finds a random num of songs based on the num of songs for that artist
        int rs = rand() % (numbSPA);

        //compares the last 5 songs added to the playlist array to the current random song.
        for(int j = i - 1; j > i - 5; j--)
        {
            if(strcmp(ShuffledSongs[j], songs[ra][rs]) == 0)
            {
                cond = 1;
            }
        }
        //Checks the entire ShuffledSongs array to see if the song has been entered in previously
        for(int k = 0; k < i; k++)
        {
            if(strcmp(ShuffledSongs[k], songs[ra][rs]) == 0)
            {
                count++;
            }

        }

        // If the song has not been entered before and no two consecutive songs are from the same artist, add it to the playlist
        if (cond == 0 && count < 2)
        {
            strcpy(ShuffledSongs[i], songs[ra][rs]);
            printf("%s - %s\n", artists[ra], songs[ra][rs]);
        }
        // If the song has been entered before or two consecutive songs are from the same artist, go back one step in the loop
        if(cond == 1 || count > 1)
        {
            cond = 0;
            count = 0;
            i--;
        }

    }

}








