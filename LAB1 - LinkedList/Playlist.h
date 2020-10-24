//
// Created by jerrywang on 2020/3/30.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#ifndef LAB1_LINKED_LIST_PLAYLIST_H
#define LAB1_LINKED_LIST_PLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

class PlaylistNode {
public:
    PlaylistNode();
    PlaylistNode(string id, string song, string artist, int length);
    void InsertAfter(PlaylistNode* ptr);
    void SetNext(PlaylistNode* next);
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;
    void PrintPlaylistNode();

private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

class Playlist {
public:
    Playlist();
    void printMenu();
    void addSong(string id, string song, string artist, int length);
    void removeSong(string id);
    void changePosition(int currPos, int newPos);
    void printSongByArtist(string artist);
    int printTotal();
    void printFull();

private:
    PlaylistNode* head;
    PlaylistNode* tail;

};


#endif //LAB1_LINKED_LIST_PLAYLIST_H
