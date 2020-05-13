/*
 * PlayList.h
 *
 *  Created on: Sep 10, 2019
 *      Author: mjs96
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Song.h"
#include <vector>   // STL vector
#include <string>
using namespace std;

class PlayList {
public:
   PlayList(const string& fileName);
   unsigned getNumSongs() const;
   vector<Song> searchByArtist(const string& artist) const;
private:
   vector<Song> mySongs;
};

#endif /*PLAYLIST_H_*/
