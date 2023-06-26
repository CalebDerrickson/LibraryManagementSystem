/*
Project Idea: Library Management System

Description:
Develop a simple library management system that allows users to manage books and borrowers. 
The system should provide basic functionalities such as adding new books, registering borrowers, 
borrowing books, returning books, and displaying available books.

Features:

Book Management:

    Add new books to the library.
    Update book information (e.g., title, author, genre).
    Remove books from the library.

Borrower Management:

    Register new borrowers.
    Update borrower information (e.g., name, contact details).
    Remove borrowers from the system.

Book Borrowing:

    Allow borrowers to check out books.
    Maintain a record of borrowed books and their due dates.
    Limit the number of books a borrower can borrow at a time.

Book Returning:

    Enable borrowers to return books.
    Update the status of the returned books.

Book Availability:

    Display a list of available books.
    Show information about borrowed books, including the borrower's details.

User Interface:

Implement a user-friendly command-line interface.
Use appropriate menus and prompts to guide users.
You can further enhance the project by incorporating features like searching for books, 
generating reports, or implementing a graphical user interface (GUI) if you are comfortable with it.
Remember to focus on writing clean and modular code, following best practices, and implementing error handling.

By completing this project, you'll demonstrate your proficiency in C++ programming, data structures, file handling, 
and potentially user interface design. Mentioning it on your resume will show potential employers that you can
develop practical applications and work with real-world scenarios.
*/

#include <iostream>
#include "MainManager.h"

int main()
{
    MainManager mainManager;
    mainManager.run();
    return 0;
}
