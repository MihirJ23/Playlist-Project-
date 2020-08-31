#include <iostream>
#include <string>

using namespace std;

#include "Playlist.h"

PlaylistNode::PlaylistNode()
{
    string uniqueID = "none";
    string songName = "none";
    string artistName = "none";
    int songLength = 0;
    nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string ID, string name, string artist, int length)
{
    this->uniqueID = ID;
    this->songName = name;
    this->artistName = artist;
    this->songLength = length;
    this->nextNodePtr = nullptr;
}

const string &PlaylistNode::GetSongName() const
{
    return songName;
}

const string &PlaylistNode::GetID() const
{
    return uniqueID;
}

const string &PlaylistNode::GetArtistName() const
{
    return artistName;
}

const int &PlaylistNode::GetSongLength() const
{
    return songLength;
}

PlaylistNode *PlaylistNode::GetNext()
{
    return this->nextNodePtr;
}

void Playlist::OutputFullList(string title) const
{
    cout << title << " - OUTPUT FULL PLAYLIST" << endl;

    if (!head)
    {
        cout << "Playlist is empty" << endl
             << endl;
        return;
    }

    int x = 1;

    for (PlaylistNode *curr = head; curr != nullptr; curr = curr->GetNext())
    {
        cout << x << "." << endl;
        curr->PrintPlaylistNode();
        ++x;
    }
}

void Playlist::OutputTotalTime() const
{
    int sumTime = 0;

    for (PlaylistNode *curr = head; curr != nullptr; curr = curr->GetNext())
    {
        sumTime += curr->GetSongLength();
    }

    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl
         << "Total time: " << sumTime << " seconds" << endl << endl;
}

void Playlist::OutputSpecificSong() const
{
    string artist;

    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl
         << "Enter artist's name:" << endl;
    cin.ignore();
    getline(cin, artist);
    cout << endl;

    int x = 1;

    for (PlaylistNode *curr = head; curr->GetNext() != nullptr; curr = curr->GetNext())
    {
        if (curr->GetArtistName() == artist)
        {
            cout << x << "." << endl;
            curr->PrintPlaylistNode();
        }
        ++x;
    }
    return;
}

void Playlist::AddSong()
{
    string name;
    string artist;
    string id;
    int length = 0;

    cout << "ADD SONG" << endl << "Enter song's unique ID:";
    cin.ignore();
    cin >> id;
    cout << endl;
    cout << "Enter song's name:";
    cin.ignore();
    getline(cin, name);
    cout << endl;
    cout << "Enter artist's name:";
    getline(cin, artist);
    cout << endl;
    cout << "Enter song's length (in seconds):";
    cin >> length;
    cout << endl << endl;

    PlaylistNode *newSong = new PlaylistNode(id, name, artist, length);

    if (head == nullptr)
    {
        head = newSong;
        tail = newSong;
    }
    else
    {
        tail->InsertAfter(newSong);
        tail = newSong;
    }
}

void Playlist::RemoveSong()
{
    string id;
    string oldSong;

    cout << "REMOVE SONG" << endl
         << "Enter song's unique ID: " << endl;
    cin >> id;

    if (head != nullptr)
    {
        return;
    }
    else if (head->GetID() == id)
    {
        PlaylistNode *temp = head;
        head = head->GetNext();
        oldSong = temp->GetSongName();
        delete temp;
        cout << "\"" << oldSong << "\" removed." << endl
             << endl;
        return;
    }
    else
    {
        for (PlaylistNode *curr = head; curr->GetNext() != nullptr; curr = curr->GetNext())
        {
            if (curr->GetNext()->GetID() == id)
            {
                PlaylistNode *temp = curr->GetNext()->GetNext();
                oldSong = curr->GetNext()->GetSongName();
                delete curr->GetNext();
                curr->SetNext(temp);
                cout << "\"" << oldSong << "\" removed." << endl
                     << endl;
            }
        }
    }
}

void PlaylistNode::SetNext(PlaylistNode *next)
{
    nextNodePtr = next;
}

//referred to zybooks for InsertAfter function
void PlaylistNode::InsertAfter(PlaylistNode *newSong)
{
    PlaylistNode *temp = nullptr;

    temp = this->nextNodePtr;
    this->nextNodePtr = newSong;
    newSong->nextNodePtr = temp;
}

void PlaylistNode::PrintPlaylistNode() const
{
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl << endl;
}

//source referred GeeksforGeeks Switching positions in linked lists
void Playlist::ChangePosition()
{
    int oldPosition;
    int newPosition;

    cout << "CHANGE POSITION OF SONG" << endl;
    cout << "Enter song's current position: " << endl;
    cin >> oldPosition;
    cout << "Enter new position for song: " << endl;
    cin >> newPosition;

    if (head == NULL)
    {
        cout << "Playlist is empty" << endl;
    }

    PlaylistNode *prev = NULL;
    PlaylistNode *curr = head;

    int currPosition;
    for (currPosition = 1; curr != NULL && currPosition < oldPosition; currPosition++)
    {
        prev = curr;
        curr = curr->GetNext();
    }
    if (curr != NULL)
    {
        string currentSong = curr->GetSongName();
        if (prev == NULL)
        {
            head = curr->GetNext();
        }
        else
        {
            prev->SetNext(curr->GetNext());
        }

        if (curr == tail)
        { //if we removed the tail node
            tail = prev;
        }

        PlaylistNode *curr1 = curr;
        prev = NULL;
        curr = head;

        for (currPosition = 1; curr != NULL && currPosition < newPosition; currPosition++)
        {
            prev = curr;
            curr = curr->GetNext();
        }

        if (prev == NULL)
        {
            curr1->SetNext(head);
            head = curr1;
        }
        else
        {
            curr1->InsertAfter(prev);
        }
        if (curr == NULL)
        {
            tail = curr1;
        }

        cout << "\"" << currentSong << "\" moved to position " << newPosition << endl;
    }
}

//I asked Daniel Von Rhein for setting up on the Playlist class function and Remove Song Function
Playlist::Playlist(string title)
{
    // string artistName = "";
    // string songName = "";
    // string uniqueID = "";
    // string playlistTitle = title;

    head = tail = 0;
}
