#pragma once
#include <iostream>
#include <string>

using namespace std;

class Song
{
public:

		Song(string songArtist, string songTitle);
		string getSongArtist() { return _songArtist; }
		string getSongTitle() { return _songTitle; }

		friend ostream& operator << (ostream& stream, const Song& song)
		{
			stream << "Artist: " << song._songArtist << endl;
			stream << "Title: " << song._songTitle << endl;
			return stream;
		}

private:
	string _songArtist;
	string _songTitle;

};