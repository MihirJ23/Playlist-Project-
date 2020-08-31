#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <iostream> 
#include <string>

using namespace std;

class PlaylistNode {
public:
    PlaylistNode();
    PlaylistNode(string uniqueID, string songName, string artistName, int songLength);
    void InsertAfter(PlaylistNode *ptr);
    void SetNext(PlaylistNode *newNode); // - Mutator (1 pt)
    const string &GetID() const;         //done
    const string &GetSongName() const;   //done
    const string &GetArtistName() const; //done
    const int &GetSongLength() const;           //done
    PlaylistNode *GetNext();
    void PrintPlaylistNode() const;
    void PrintMenu(string playlist);

private:
PlaylistNode* nextNodePtr; 
string uniqueID; 
string songName;
int songLength;
string artistName;
// Playlist *head;
// Playlist *tail;
PlaylistNode* next;
};

class Playlist {
    private:
    string title;
    PlaylistNode *head;
    PlaylistNode *tail;
    
    public:
    void RemoveSong();
    void AddSong(); //done
    void ChangePosition();
    void OutputFullList(string title) const;
    void OutputSpecificSong() const; //done
    void OutputTotalTime() const;    //done
    Playlist(string title);
};

#endif