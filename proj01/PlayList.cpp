/*
 * PlayList.cpp
 *
 *  Created on: Sep 14, 2019
 *      Author: mjs96
 */

#include "PlayList.h"
#include <fstream>
#include <cassert>
using namespace std;
PlayList::PlayList() {

}
PlayList::PlayList(const string& fileName)
{
	myPlayList = fileName;
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	Song s;
	string separator;
	while ( true )
	{
		s.readFrom(fin);
		if ( !fin ) { break; }
		getline(fin, separator);
		mySongs.push_back(s);
	}
	fin.close();
}

unsigned PlayList::getNumSongs() const { return mySongs.size(); }               // Returns size of playlist

/*=============START SEARCHING FUNCTIONS===================*/
vector<Song> PlayList::searchByArtist(const string& artist) const
{
	vector<Song> v;
	for (unsigned i = 0; i < mySongs.size(); i++)
	{
		if ( mySongs[i].getArtist().find(artist) != string::npos ) { v.push_back( mySongs[i] ); }
	}
	return v;
}
vector<Song> PlayList::searchByYear(unsigned year)
{
	vector<Song> v;
	for (unsigned i = 0; i < mySongs.size(); i++)
	{
		if ( mySongs[i].getYear() == year) { v.push_back( mySongs[i] ); }
	}
	return v;
}
vector<Song> PlayList::searchByTitlePhrase(const string& phrase)
{
	vector<Song> v;
	for (unsigned i = 0; i < mySongs.size(); i++)
	{
		if ( mySongs[i].getTitle().find(phrase) != string::npos ) { v.push_back( mySongs[i] ); }
	}
	return v;
}

void PlayList::addSong(const Song& newSong) { mySongs.push_back(newSong); }     // Adds new song

		void PlayList::removeSong(const Song& aSong) {
			for (unsigned i = 0; i < mySongs.size(); i++)
			{
				if ( mySongs[i] == aSong ) { mySongs.erase(mySongs.begin() + i); }
			}
		}

		void PlayList::save() const
		{
			ofstream fout( "testPlayList.txt" );                                    // Saves song into playlist
			for (unsigned i = 0; i < mySongs.size(); i++)
			{
				mySongs[i].writeTo( fout );
				fout << "\n";
			}
		}

