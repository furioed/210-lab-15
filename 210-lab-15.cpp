// COMSC-210 | Lab 15 | Mamadou Sissoko
// IDE used: Visual Studio Code
// Description: Movie class with private members, setters, getters, constructor, reading movies into a fixed-size array, and printing them

#include <iostream>
#include <fstream>
#include <array>
#include <string>
using namespace std;

// Movie class definition
class Movie {
private:
    string title;        // Movie title
    int yearReleased;    // Year the movie was released
    string screenWriter; // Name of the screenwriter

public:
    // Constructor to initialize a Movie object
    Movie(const string& t = "", int y = 0, const string& sw = "") {
        title = t;
        yearReleased = y;
        screenWriter = sw;
    }

    // Setter methods
    void setTitle(const string& t) { title = t; }
    void setYearReleased(int y) { yearReleased = y; }
    void setScreenWriter(const string& sw) { screenWriter = sw; }

    // Getter methods
    string getTitle() const { return title; }
    int getYearReleased() const { return yearReleased; }
    string getScreenWriter() const { return screenWriter; }

    // Print method to display movie information using getters
    void print() const {
        cout << "Movie: " << getTitle() << endl;
        cout << "    Year released: " << getYearReleased() << endl;
        cout << "    Screenwriter: " << getScreenWriter() << endl << endl;
    }
};

int main() {
    // Open the input file
    ifstream inputFile("movies.txt");
    if (!inputFile) {
        cerr << "Error: Could not open movies.txt. Please try again." << endl;
        return 1;
    }

    array<Movie, 4> movies;  // Fixed-size array to store Movie objects
    string title, screenWriter;
    int year;

    // Read exactly 4 movies from the file and initialize using constructor
    for (int i = 0; i < 4; i++) {
        getline(inputFile, title);
        inputFile >> year;
        inputFile.ignore(); // Ignore the leftover newline
        getline(inputFile, screenWriter);

        // Initialize Movie object using constructor
        movies[i] = Movie(title, year, screenWriter);
    }

    inputFile.close();  // Close the input file

    // Print all movies stored in the array
    for (const Movie& m : movies)
        m.print();

    return 0;
}
