#include <iostream>

using namespace std;

typedef struct {
    int name;
    int width;
} Book;

int shelfInput() {
    int shelfSize;
    cout << "Number of Books: " << endl;
    cin >> shelfSize;
    
    if (shelfSize < 5) {
		shelfInput();
	}
	return shelfSize;
}

int main(int argc, char* argv[] ) {
    int shelfWidth;
    shelfWidth = shelfInput();
    cout << shelfWidth << endl;
	return 0;
}

