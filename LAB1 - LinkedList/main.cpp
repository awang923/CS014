//
//  main.cpp
//  LAB1-Linked_list
//
//  Created by jerrywang on 2020/3/30.
//  Copyright © 2020 anniewang. All rights reserved.
//

#include <iostream>
#include "Playlist.h"

int main(int argc, const char * argv[]) {
    Playlist list;
    string title;
    string id, song, artist;
    int length;
    char input;
    int currPos,newPos;
    cout << "Enter playlist's title:" << endl;
    getline(cin, title);
    cout << endl;
    cout << title<< " PLAYLIST MENU" << endl;
    list.printMenu();
    cout << "Choose an option:" << endl;
    cin >> input;
    while (input != 'q'){
        if (input == 'a'){
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin.ignore();
            getline(cin, id);
            cout << "Enter song's name:" << endl;
            getline(cin, song);
            cout << "Enter artist's name:" << endl;
            getline(cin, artist);
            cout << "Enter song's length (in seconds):"<< endl;
            cin >> length;
            list.addSong(id, song, artist, length);
            cout<< endl;
        }
        if (input == 'd'){
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin.ignore();
            getline(cin, id);
            list.removeSong(id);
            cout << endl;
        }
        if (input == 'c'){
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> currPos;
            cout << "Enter new position for song:" << endl;
            cin >> newPos;
            list.changePosition(currPos, newPos);
        }
        if (input == 's'){
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            cin.ignore();
            getline(cin, artist);
            list.printSongByArtist(artist);
        }
        if (input == 't'){
            int totalTime;
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            totalTime = list.printTotal();
            cout << "Total time: " << totalTime << " seconds"<< endl << endl;
        }
        if (input == 'o'){
            cout << title << " - OUTPUT FULL PLAYLIST" << endl;
            list.printFull();
        }
        cout << title<< " PLAYLIST MENU" << endl;
        list.printMenu();
        cout << "Choose an option:" << endl;
        cin >> input;
    }
    return 0;
}