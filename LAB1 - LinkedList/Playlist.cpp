//
// Created by jerrywang on 2020/3/30.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include "Playlist.h"

PlaylistNode::PlaylistNode(){
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}
PlaylistNode::PlaylistNode(string id, string song, string artist, int length){
    uniqueID = id;
    songName = song;
    artistName = artist;
    songLength = length;
    nextNodePtr = 0;
}
string PlaylistNode::GetID()const{
    return uniqueID;
}
string PlaylistNode::GetArtistName() const {
    return artistName;
}
string PlaylistNode::GetSongName() const {
    return songName;
}
int PlaylistNode::GetSongLength() const {
    return songLength;
}
void PlaylistNode::SetNext(PlaylistNode* next) {
    nextNodePtr = next;
}
PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}
void PlaylistNode::InsertAfter(PlaylistNode* ptr) {
    PlaylistNode* temp = nextNodePtr;
    nextNodePtr = ptr;
    ptr->SetNext(temp);
}
void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << uniqueID << endl
         << "Song Name: " << songName << endl
         << "Artist Name: " << artistName << endl
         << "Song Length (in seconds): " << songLength << endl;
}


Playlist::Playlist(){
    head = nullptr;
    tail = nullptr;
}
void Playlist::printMenu(){
    cout << "a - Add song" << endl
         << "d - Remove song" << endl
         << "c - Change position of song" << endl
         << "s - Output songs by specific artist" << endl
         << "t - Output total time of playlist (in seconds)" << endl
         << "o - Output full playlist" << endl
         << "q - Quit" << endl << endl;
}
void Playlist::addSong(string id, string song, string artist, int length){
    PlaylistNode* p = new PlaylistNode(id, song, artist, length);
    if (head == nullptr){
        head = p;
        tail = p;
    }
    else{
        tail->SetNext(p);
        tail = p;
    }
}
void Playlist::removeSong(string id){
    PlaylistNode* curr = head;
    PlaylistNode* prev = head;
    if (head == nullptr){
        cout << "Playlist is empty" << endl;
    }
    if (head->GetID() == id){
        PlaylistNode* temp = head->GetNext();
        cout << "\"" << head->GetSongName() << "\""<< " removed." << endl;
        delete head;
        head = temp;
        return;
    }
    else {
        while (curr != nullptr) {
            if (curr->GetID() == id) {
                prev->SetNext(curr->GetNext());
                if (tail == curr){
                    tail = prev;
                }
                cout << "\"" << curr->GetSongName() << "\"" << " removed." << endl;
                delete curr;
                return;
            }
            else{
                if (curr != head){
                    prev = prev->GetNext();
                }
            }
            curr = curr->GetNext();
        }
    }
}
void Playlist::changePosition(int currPos, int newPos){
    if (head == nullptr){
        cout << "Playlist is empty" << endl;
    }
    int nodeCount = 0;
    PlaylistNode* temp = head;
    while (temp!= nullptr){
        nodeCount++;
        temp = temp->GetNext();
    }
    PlaylistNode* prevPtr, *prevNew = head;
    PlaylistNode* currPtr = head;
    PlaylistNode* newPtr = head;
    temp = head;
    for (int pos = 1; pos <= nodeCount; pos++){
        if (pos == currPos){
            currPtr = temp;
        }
        if (pos == currPos-1 && currPos != 1){
            prevPtr = temp;
        }
        if (currPos == 1){
            currPtr = temp;
            prevPtr = temp;
        }
        if (currPos == nodeCount){
            currPtr = temp;
            if (pos == newPos - 1){
                prevNew = temp;
            }
        }
        if (pos == newPos){
            newPtr = temp;
        }

        temp = temp->GetNext();
    }
    if (newPos <= 1){
        prevPtr->SetNext(currPtr->GetNext());
        currPtr->SetNext(head);
        head = currPtr;
    }
    else if (newPos >= nodeCount){
        prevPtr->SetNext(currPtr->GetNext());
        tail->SetNext(currPtr);
        currPtr->SetNext(nullptr);
        tail = currPtr;
    }
    else if (currPos == 1){
        currPtr = head;
        PlaylistNode* node = currPtr->GetNext();
        head = node;
        currPtr->SetNext(newPtr->GetNext());
        newPtr->SetNext(currPtr);
        cout << "\"" << currPtr->GetSongName() << "\" moved to position " << newPos
             << endl << endl;
    }
    else if (currPos == nodeCount){
        prevPtr->SetNext(nullptr);
        currPtr->SetNext(prevNew->GetNext());
        prevNew->SetNext(currPtr);
        cout << "\"" << currPtr->GetSongName() << "\" moved to position " << newPos
             << endl << endl;
    }
    else if (currPos < newPos){
        prevPtr->SetNext(currPtr->GetNext());
        currPtr->SetNext(newPtr->GetNext());
        newPtr->SetNext(currPtr);
        cout << "\"" << currPtr->GetSongName() << "\" moved to position " << newPos
             << endl << endl;
    }
    else if (currPos > newPos){
        prevPtr->SetNext(currPtr->GetNext());
        currPtr->SetNext(prevNew->GetNext());
        prevNew->SetNext(currPtr);
        cout << "\"" << currPtr->GetSongName() << "\" moved to position " << newPos
             << endl << endl;
    }
}
void Playlist::printSongByArtist(string artist){
    if (head == nullptr){
        cout << "Playlist is empty" << endl;
    }
    else{
        PlaylistNode* temp = head;
        int count = 1;
        while (temp!= nullptr){
            if (temp->GetArtistName()== artist){
                cout << endl;
                cout << count << "." << endl;
                temp->PrintPlaylistNode();
            }
            count++;
            temp = temp->GetNext();
        }
        cout << endl;
    }
}
int Playlist::printTotal(){
    int total = 0;
    if (head == nullptr){
        cout << "Playlist is empty" << endl;
    }
    else{
        PlaylistNode* temp = head;
        while (temp!= nullptr){
            total += temp->GetSongLength();
            temp = temp->GetNext();
        }
    }
    return total;
}
void Playlist::printFull(){
    if (head == nullptr){
        cout << "Playlist is empty" << endl << endl;
    }
    else{
        int count = 1;
        PlaylistNode* temp = head;
        while (temp != nullptr){
            cout << count << "." << endl;
            temp->PrintPlaylistNode();
            cout << endl;
            count++;
            temp = temp->GetNext();
        }
    }
}