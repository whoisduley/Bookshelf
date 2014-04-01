// 5. Add needs to knock things off.
// 6. Change test.txt to stdin thingy

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>


using namespace std;

struct book{
    string name;
    string width;
};

int main(int argc, char* argv[] ) {
    int addTrack = 0, remTrack;
    int bookCount = 0, booksWidth = 0, shelfWidth = 10;
    int widthHolder;
	
	ifstream myFile;
    myFile.open("test.txt", ifstream::in);
    string inputThing, line;
	stringstream iss;
	vector<book> shelf(5);
	while (myFile.is_open()) {	
		while (getline (myFile, line)) {
			iss << line;
			while (getline (iss, inputThing, ' ')) {
				if (addTrack == 2) {
					shelf.push_back(book());
					shelf[bookCount].name = inputThing;
					addTrack = 1;
				}
				else if (addTrack == 1) {
					stringstream convert(inputThing);
					if (!(convert >> widthHolder)) {
						widthHolder = 0;
					}
					shelf[bookCount].width = widthHolder;
					bookCount++;
					booksWidth += widthHolder;
					if (booksWidth > shelfWidth) {
						// Should do the stringstream convert thing again. Hope for the best.
						booksWidth -= shelf[0].width;
						shelf.erase(shelf.begin());
						bookCount -= 1;
					}
					addTrack = 0;
				}
				if (remTrack == 2) {
					for (int i = 0; i != shelf.size(); i++){
						cout << "name" << shelf.size() << endl;
						if (shelf[i].name == inputThing) {
							shelf.erase(shelf.begin() + i);
							remTrack = 0;
							bookCount -= 1;
						}
					}
				}
				else {
					if (inputThing[0] == 'A') {
						addTrack = 2;
					}
					else if (inputThing[0] == 'R') {
						remTrack = 2;
					}
					else if (inputThing[0] == 'X') {
					}
				}
			}
			iss.clear();
		}
		myFile.close();
	}
	cout << shelf[0].name << " a " << shelf[0].width << endl;
	cout << shelf[1].name << " b " << shelf[1].width << endl;
	cout << shelf[2].name << " c " << shelf[2].width << endl;
	return 0;
}