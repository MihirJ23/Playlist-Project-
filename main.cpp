#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Playlist.h"

void PrintMenu(const string playlistTitle)
{
    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option:" << endl;
    // Output menu option, prompt users for valid selection
}

//source of parts of int main- professor lependu example on slack

int main()
{
    string playlistTitle;
    cout << "Enter playlist's title:" << endl;
    getline(cin, playlistTitle);
    cout << endl;

    Playlist myPlaylist(playlistTitle);

    char letter = ' ';

    while (letter != 'q')
    {
        PrintMenu(playlistTitle);

        cin >> letter;

        if (letter == 'a')
        {
            myPlaylist.AddSong();
        }
        else if (letter == 'd')
        {
            myPlaylist.RemoveSong();
        }
        else if (letter == 'c')
        {
            myPlaylist.ChangePosition();
        }
        else if (letter == 's')
        {
            myPlaylist.OutputSpecificSong();
        }
        else if (letter == 't')
        {
            myPlaylist.OutputTotalTime();
        }
        else if (letter == 'o')
        {
            myPlaylist.OutputFullList(playlistTitle);
        }
        else if (letter == 'q')
        {
            return 0;
        }
    }

    return 0;
}