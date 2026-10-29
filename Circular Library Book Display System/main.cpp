int main()
{
    CircularLinkedList library;
    int ch, id, index, a, b;
    string title;
    BookNode* r;

   
library.InsertAt(CreateBook(103, "Operating Systems"), 0);
library.InsertAt(CreateBook(101, "Data Structures"), 1);
library.InsertAt(CreateBook(105, "Computer Networks"), 2);
library.InsertAt(CreateBook(102, "Database Systems"), 3);
library.InsertAt(CreateBook(104, "Software Engineering"), 4);

    do
    {
        cout << "\n=== CIRCULAR LIBRARY SYSTEM ===\n";
        cout << "1. Display All Books\n";
        cout << "2. Insert Book at Head\n";
        cout << "3. Remove Book from Head\n";
        cout << "4. Insert Book at Index\n";
        cout << "5. Remove Book at Index\n";
        cout << "6. Swap Books\n";
        cout << "7. Sort Books by ID\n";
        cout << "8. Reverse Collection\n";
        cout << "9. Move to Next Book\n";
        cout << "10. Check Collection Status\n";
        cout << "11. Exit\n";
        cout << "Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            library.Print();
            break;

        case 2:
        case 4:
            cout << "Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Book title: ";
            getline(cin, title);

            if (ch == 2)
                library.Insert(CreateBook(id, title));
            else
            {
                cout << "Index: ";
                cin >> index;
                library.InsertAt(CreateBook(id, title), index);
            }
            break;

        case 3:
        case 5:
            if (ch == 3)
                r = library.Remove();
            else
            {
                cout << "Index: ";
                cin >> index;
                r = library.RemoveAt(index);
            }

            if (r != NULL)
            {
                cout << "Removed: " << r->title << endl;
                delete r;
            }
            else
                cout << "Library is empty!\n";
            break;

        case 6:
            cout << "Enter two indexes: ";
            cin >> a >> b;
            library.Swap(a, b);
            break;

        case 7:
            library.Sort();
            cout << "Books sorted!\n";
            break;

        case 8:
            library.Reverse();
            cout << "Books reversed!\n";
            break;

        case 9:
            library.MoveNext();
            break;

        case 10:
            library.Status();
            library.Print();
            break;

        case 11:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (ch != 11);

    return 0;
}
