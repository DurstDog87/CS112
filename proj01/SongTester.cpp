/*
 * SongTester.cpp
 *
 *  Created on: Sep 14, 2019
 *      Author: mjs96
 */

#include "SongTester.h"
#include "Song.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

void SongTester::runTests()
{
	cout << "Testing class Song... " << endl;
	testConstructors();
	testReadFrom();
	testWriteTo();
	testEquality();
	cout << "All tests passed!" << endl;
}

void SongTester::testConstructors()
{
	cout << "- constructors... " << flush;                  // Default constructor
	Song s;
	assert( s.getTitle() == "" );
	assert( s.getArtist() == "" );
	assert( s.getYear() == 0 );
	cout << " 0 " << flush;

	Song s1("Badge", "Cream", 1969);                        // Explicit constructor
	assert( s1.getTitle() == "Badge" );
	assert( s1.getArtist() == "Cream" );
	assert( s1.getYear() == 1969 );
	cout << " 1 " << flush;
	cout << " Passed!" << endl;
}

void SongTester::testReadFrom()
{
	cout << "- readFrom()... " << flush;
	ifstream fin("testSongs.txt");
	assert( fin.is_open() );
	Song s;
	string separator;

	s.readFrom(fin);                                        // Read first song and separator in test playlist
	getline(fin, separator);
	assert( s.getTitle() == "Call Me Maybe" );
	assert( s.getArtist() == "Carly Rae Jepsen" );
	assert( s.getYear() == 2012 );
	cout << " 0 " << flush;

	s.readFrom(fin);                                        // Read second song and separator in test playlist
	getline(fin, separator);
	assert( s.getTitle() == "Let It Be" );
	assert( s.getArtist() == "The Beatles" );
	assert( s.getYear() == 1967 );
	cout << " 1 " << flush;

	s.readFrom(fin);                                        // Read third song and separator in test playlist
	getline(fin, separator);
	assert( s.getTitle() == "Let It Be" );
	assert( s.getArtist() == "Joan Baez" );
	assert( s.getYear() == 1971 );
	cout << " 2 " << flush;

	s.readFrom(fin);                                        // Read fourth song and separator in test playlist
	getline(fin, separator);
	assert( s.getTitle() == "Penny Lane" );
	assert( s.getArtist() == "The Beatles" );
	assert( s.getYear() == 1967 );
	cout << " 0 " << flush;
}

void SongTester::testWriteTo()
{
	cout << "- writeTo()... " << flush;
	Song s1("Badge", "Cream", 1969);                        // Declare three songs
	Song s2("Godzilla", "Blue Oyster Cult", 1977);
	Song s3("Behind Blue Eyes", "The Who", 1971);

	ofstream fout("testSongOutput.txt");                    // Writes songs to an output file
	assert( fout.is_open() );
	s1.writeTo(fout);
	fout << "---\n";
	s2.writeTo(fout);
	fout << "---\n";
	s3.writeTo(fout);
	fout << "---\n";
	fout.close();

	ifstream fin("testSongOutput.txt");                     // Use readFrom() to see if writeTo() worked
	assert( fin.is_open() );
	Song s4, s5, s6;
	string separator;

	s4.readFrom(fin);                                       // Read and check the first song
	getline(fin, separator);
	assert( s4.getTitle() == "Badge" );
	assert( s4.getArtist() == "Cream" );
	assert( s4.getYear() == 1969 );
	cout << " 0 " << flush;

	s5.readFrom(fin);                                       // Read and check the second song
	getline(fin, separator);
	assert( s5.getTitle() == "Godzilla" );
	assert( s5.getArtist() == "Blue Oyster Cult" );
	assert( s5.getYear() == 1977 );
	cout << " 1 " << flush;

	s6.readFrom(fin);                                       // Read and check the third song
	getline(fin, separator);
	assert( s6.getTitle() == "Behind Blue Eyes" );
	assert( s6.getArtist() == "The Who" );
	assert( s6.getYear() == 1971 );
	cout << " 2 " << flush;

	fin.close();
	cout << " Passed!" << endl;
}

void SongTester::testEquality()
{
	cout << "- Equality... " << flush;

	Song s7("A", "C", 2000);
	Song s8("A", "C", 2000);
	assert( s7 == s8 );                                     // Checks when all is equal
	cout << " 0 " << flush;

	Song s9("B", "C", 2000);
	assert( !(s7 == s9) );                                  // Checks when titles aren't equal
	cout << " 1 " << flush;

	Song s10("A", "D", 2000);
	assert( !(s7 == s10) );                                 // Checks when artists aren't equal
	cout << " 2 " << flush;

	Song s11("A", "C", 2001);
	assert( !(s7 == s11) );                                 // Checks when years aren't equal
	cout << " 3 " << flush;

	Song s12("B", "D", 2001);
	assert( !(s7 == s12) );                                 // Checks when nothing is equal
	cout << " 4 " << flush;
	cout << " Passed!" << endl;
}
