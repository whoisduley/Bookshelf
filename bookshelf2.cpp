// 4. Then worry about removal.
// 5. Then can use the removal in the add section with an object that keeps track of shelf width and knocks stuff off. (This is where I'll have to worry about changing the width string to an int, probably with atoi)

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

struct book{
    string name;
    string width;
};

int main(int argc, char* argv[] ) {
    int addTrack = 0, remTrack, exTrack;
    int bookCount = 0;
	
	ifstream myFile;
    myFile.open("input.txt", ifstream::in);
    string inputThing, line;
	stringstream iss;
	vector<book> shelf(5);
	while (myFile.is_open()) {	
		// nested getlines. First gets the line, second splits on space.
		while (getline (myFile, line)) {
			iss << line;
			while (getline (iss, inputThing, ' ')) {
				if (addTrack == 2) {
					shelf.push_back(book());
					shelf[bookCount].name = inputThing;
					addTrack = 1;
				}
				else if (addTrack == 1) {
					shelf[bookCount].width = inputThing;
					bookCount++;
					addTrack = 0;
				}
				if (remTrack == 2) {
					cout << shelf[0].name << " c " << shelf[0].width << endl;
					for (int i = 0; i != shelf.size(); i++){
						if (shelf[i].name == inputThing) {
							shelf.erase(shelf.begin()+i);
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
						remTrack = 2;
					}
				}
			}
			iss.clear();
		}
		myFile.close();
	}
	cout << shelf[0].name << " a " << shelf[0].width << endl;
	cout << shelf[1].name << " b " << shelf[1].width << endl;
	return 0;
}