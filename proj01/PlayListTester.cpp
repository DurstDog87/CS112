/*
 * PlayListTester.cpp
 *
 *  Created on: Sep 14, 2019
 *      Author: mjs96
 */

#include "PlayListTester.h"
#include "PlayList.h"
#include <iostream>
#include <cassert>
using namespace std;

void PlayListTester::runTests()
{
	cout << "\nTesting class PlayList..." << endl;
	testConstructors();
	testSearchByArtist();
	testSearchByYear();
	testSearchByTitlePhrase();
	testAddSong();
	testRemoveSong();
	testSave();
	cout << "All tests passed!" << endl;
}

void PlayListTester::testConstructors()
{
	cout << "- constructors..." << flush;
	PlayList pList("testSongs.txt");
	assert( pList.getNumSongs() == 4 );
	cout << " 0 " << flush;
	cout << " Passed!" << endl;
}

void PlayListTester::testSearchByArtist()
{
	cout << "- searchByArtist()... " << flush;
	PlayList pList("testSongs.txt");                                // Loads test playlist

	vector<Song> searchResult = pList.searchByArtist("NULL");
	assert( searchResult.size() == 0 );                             // When 0 artist results exist
	cout << " 0 " << flush;

	searchResult = pList.searchByArtist("Baez");
	assert( searchResult.size() == 1 );                             // When 1 artist results exist
	assert( searchResult[0].getTitle() == "Let It Be" );
	cout << " 1 " << flush;

	searchResult = pList.searchByArtist("Beatles");
	assert( searchResult.size() == 2 );                             // When 2 artist results exist
	assert( searchResult[0].getTitle() == "Let It Be" );
	assert( searchResult[1].getTitle() == "Penny Lane" );
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

void PlayListTester::testSearchByYear()
{
	cout << "- searchByYear()... " << flush;
	PlayList pList("testSongs.txt");                                // Loads test playlist

	vector<Song> searchResult = pList.searchByYear(9999);
	assert( searchResult.size() == 0 );                             // When 0 year results exist
	cout << " 0 " << flush;

	searchResult = pList.searchByYear(2012);
	assert( searchResult.size() == 1 );                             // When 1 year results exist
	assert( searchResult[0].getTitle() == "Call Me Maybe" );
	cout << " 1 " << flush;

	searchResult = pList.searchByYear(1967);
	assert( searchResult.size() == 2 );                             // When 2 year results exist
	assert( searchResult[0].getArtist() == "The Beatles" );
	assert( searchResult[1].getArtist() == "The Beatles" );
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

void PlayListTester::testSearchByTitlePhrase()
{
	cout << "- searchByTitlePhrase()... " << flush;
	PlayList pList("testSongs.txt");                                // Loads test playlist

	vector<Song> searchResult = pList.searchByTitlePhrase("NULL");
	assert( searchResult.size() == 0 );                             // When 0 title phrase results exist
	cout << " 0 " << flush;

	searchResult = pList.searchByTitlePhrase("Call");
	assert( searchResult.size() == 1 );                             // When 1 title phrase results exist
	assert( searchResult[0].getArtist() == "Carly Rae Jepsen" );
	cout << " 1 " << flush;

	searchResult = pList.searchByTitlePhrase("Let");
	assert( searchResult.size() == 2 );                             // When 2 title phrase results exist
	assert( searchResult[0].getArtist() == "The Beatles" );
	assert( searchResult[1].getArtist() == "Joan Baez" );
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

void PlayListTester::testAddSong()
{
	cout << "- addSong()..." << flush;

	PlayList pList("testSongs.txt");                                // Create a list
	assert( pList.getNumSongs() == 4 );

	Song s1("On A Plain", "Nirvana", 1991);                         // Adds a song to playlist
	pList.addSong(s1);
	assert( pList.getNumSongs() == 5 );                             // Checks for an increase in number of songs
	cout << " 0 " << flush;

	vector<Song> searchResult = pList.searchByTitlePhrase("On");
	assert( searchResult.size() == 1 );                             // Verify song addition by searching playlist
	assert( searchResult[0].getTitle() == "On A Plain" );           // Search song title
	assert( searchResult[0].getArtist() == "Nirvana" );             // Search artist
	assert( searchResult[0].getYear() == 1991 );                    // Search year
	cout << " 1 " << flush;
	cout << " Passed!" << endl;
}

void PlayListTester::testRemoveSong()
{
	cout << "- removeSong()..." << flush;

	PlayList pList("testSongs.txt");                                // Create a list
	assert( pList.getNumSongs() == 4 );

	Song s1("On A Plain", "Nirvana", 1991);
	pList.addSong(s1);                                              // Adds a song to playlist
	assert( pList.getNumSongs() == 5 );                             // Verifies that a song has been added
	cout << " 0 " << flush;

	pList.removeSong(s1);                                           // Removes a song from playlist
	assert( pList.getNumSongs() == 4 );                             // Verifies that a song has been removed
	cout << " 1 " << flush;

	vector<Song> searchResult = pList.searchByArtist("Nirvana");    // Search by artist to check removal
	assert( searchResult.size() == 0 );
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

void PlayListTester::testSave()
{
	cout << "- save()..." << flush;

	PlayList pList1("testPlayList.txt");                               // Create a list
	assert( pList1.getNumSongs() == 0 );

	Song s1("On A Plain", "Nirvana", 1991);
	pList1.addSong(s1);                                             // Adds a song
	assert( pList1.getNumSongs() == 1 );                            // Verifies song addition
	pList1.save();                                                  // Saves a song
	cout << " 0 " << flush;

	PlayList pList2("testPlayList.txt");                               // Create secondary list
	vector<Song> searchResult1 = pList2.searchByTitlePhrase("On");
	assert( searchResult1.size() == 1 );                            // Verify song existence
	cout << " 1 " << flush;

	pList2.removeSong(s1);                                          // Removes a song
	assert( pList2.getNumSongs() == 0 );                            // Verifies song removal
	pList2.save();                                                  // Saves a song
	cout << " 2 " << flush;
	PlayList pList3("testPlayList.txt");                               // Create a tertiary list
	vector<Song> searchResult2 = pList3.searchByTitlePhrase("On A Plain");
	assert( searchResult2.size() == 0 );
	cout << " 3 " << flush;
	cout << " Passed!" << endl;
}

