#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef struct {
    int name;
    int width;
} Book;

int main(int argc, char* argv[] ) {
    int shelfWidth; 
    char whatToDo;
	int bookCount = 0;
	bool shelfInit = true;
	ifstream myFile;
    myFile.open("input.txt", ifstream::in);
    string fileLine;
	
	while (myFile.is_open()) {
		while (getline (myFile, fileLine, ' ')) {
			int lineIndex = 0;
			/*if (shelfInit) {
				//Making this a function will be the easiest thing to check the shelfWidth
				//Probably needs a pointer (Otherwise a global variable)
				if (fileLine[lineIndex] < 5) {
					
				}
				shelfInit == false;
			}*/
			if (lineIndex == 0){
				vector<Book> shelf(shelfWidth);
				//I 'think' that this will add a book correctly, still needs to check if anything gets knocked off the shelf. 
				//Function will probably be necessary. 
				if (fileLine[lineIndex] == 'A') {
                    cout << "ljlijilj" << endl;
					shelf.push_back(Book());
					lineIndex++;
					shelf[bookCount].name = fileLine[lineIndex];
					lineIndex++;
					shelf[bookCount].width = fileLine[lineIndex];
					cout << shelf[bookCount].name << "balls" << endl;
					myFile.close();
				}
				//Probably will be the trickiest thing
				/*if (fileLine[lineIndex] == 'R') {
				
				}
				//Print Results
				if (fileLine[lineIndex] == 'X') {
				
				}*/
			}
		}
	}
    
	return 0;
}

