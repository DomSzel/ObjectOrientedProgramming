#include <iostream>
#include<cstring>

namespace your_name
{
    class Book {
    public:
// Constructor with default values
        Book(std::string _t = "none", std::string _a = "none", int _pd = 2023) {
            book_counter++;
            title = _t;
            author = _a;
            publication_date = _pd;
            std::cout << "object has been created, the total of books:" << book_counter << std::endl;

        }
        // Display book information
        void reveal() {
            std::cout << title << " " << author << " " << publication_date << std::endl;
        }
        // Getters
        std::string getTitle() { return title; }
        std::string getAuthor() { return author; }
        int getPublicationDate() { return publication_date; }
        // Setters
        void setTitle(std::string _t) { title = _t; }
        void setAuthor(std::string _a) { author = _a; }
        void setPublicationDate(int _rw) {
            publication_date = _rw;
        }
        // Static method to get total created books
        static int getCounter() { return book_counter; }

        // Check if book was published in the 20th century
        bool isTwentiethCentury() const {
            return (publicationDate_ <= 2001 && publicationDate_ > 1900);
        }

    private:
        std::string title;
        std::string author;
        int publication_date;
        static int book_counter;
    };

}

using namespace your_name;

int Book::book_counter = 0;

void selectionSort(Book arr[], int size) {

    for (int i = 0; i < size; i++) {
        int oldest = i;
        for (int j = i; j < size; j++) {
            if (arr[j].getPublicationDate() > arr[oldest].getPublicationDate())
                oldest = j;
        }
        Book x = arr[oldest];
        arr[oldest] = arr[i];
        arr[i] = x; 
    }
}

int main() {
    Book book1;

    const int size = 4;
    Book* arr = new Book[size];

    arr[0].setPublicationDate(442);
    arr[1].setPublicationDate(1878);
    arr[2].setPublicationDate(1943);
    arr[3].setPublicationDate(1890);

    arr[0].setAuthor("Sofokles");
    arr[1].setAuthor("Boleslaw Prus");
    arr[2].setAuthor("Antoine de Saint-Exupéry");
    arr[3].setAuthor("Oscar Wilde");

    arr[0].setTitle("Antygona");
    arr[1].setTitle("Lalka");
    arr[2].setTitle("Maly Ksiaze");
    arr[3].setTitle("Portret Doriana Graya");

    std::cout << std::endl;
    book1.reveal();

    // Display all books
    for (int i = 0; i < size; i++) {
        arr[i].reveal(); 
    }

    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        if (arr[i].isTwentiethCentury()) {
            std::cout << "Book from the 20th century ." << std::endl;
        } else {
            std::cout << "Book not from the 20th century" << std::endl;
    }
 }

    selectionSort(arr, size);

    std::cout << std::endl << "Sorted array: " << std::endl;

// Display all books after sorting
    for (int i = 0; i < size; i++) {
        arr[i].reveal();
    }

    std::cout << std::endl << "Available " << Book::getCounter() << std::endl;

    delete[] arr;
}
