using namespace std;

struct BookNode
{
    int bookID;
    string title;
    BookNode* next;
};

class CircularLinkedList
{
    BookNode* head;
    BookNode* current;
    int count;

    BookNode* GetNodeAt(int index)
    {
        BookNode* p = head->next;

        for (int i = 0; i < index; i++)
            p = p->next;

        return p;
    }

    int Normalize(int index)
    {
        return ((index % count) + count) % count;
    }

public:
    CircularLinkedList()
    {
        head = NULL;
        current = NULL;
        count = 0;
    }

    bool IsEmpty()
    {
        return count == 0;
    }

    bool IsNotEmpty()
    {
        return count > 0;
    }

    // Insert at head's next node
    void Insert(BookNode* b)
    {
        if (head == NULL)
        {
            head = b;
            b->next = b;
        }
        else
        {
            b->next = head->next;
            head->next = b;
        }

        count++;
        current = head->next;
    }

    BookNode* Remove()
    {
        if (IsEmpty()) return NULL;

        BookNode* b = head->next;

        if (head == b)
            head = NULL;
        else
            head->next = b->next;

        b->next = NULL;
        count--;
        current = IsEmpty() ? NULL : head->next;

        return b;
    }

    void InsertAt(BookNode* b, int index)
    {
        if (count == 0 || index == 0 || index < 0)
        {
            Insert(b);
            return;
        }

        if (index == count)
        {
            b->next = head->next;
            head->next = b;
            head = b;
            count++;
        }
        else
        {
            index = index % count;
            BookNode* p = GetNodeAt(index - 1);

            b->next = p->next;
            p->next = b;
            count++;
        }

        current = head->next;
    }

    BookNode* RemoveAt(int index)
    {
        if (IsEmpty()) return NULL;

        index = Normalize(index);

        if (index == 0)
            return Remove();

        BookNode* p = GetNodeAt(index - 1);
        BookNode* b = p->next;

        p->next = b->next;

        if (b == head)
            head = p;

        b->next = NULL;
        count--;
        current = head->next;

        return b;
    }

    void Swap(int a, int b)
    {
        if (IsEmpty()) return;

        a = Normalize(a);
        b = Normalize(b);

        BookNode* x = GetNodeAt(a);
        BookNode* y = GetNodeAt(b);

        swap(x->bookID, y->bookID);
        swap(x->title, y->title);
    }

    void Sort()
    {
        for (BookNode* i = head->next, *p = i; ; )
        {
            BookNode* j = i->next;

            while (j != head->next)
            {
                if (i->bookID > j->bookID)
                {
                    swap(i->bookID, j->bookID);
                    swap(i->title, j->title);
                }
                j = j->next;
            }

            i = i->next;
            if (i == head->next) break;
        }
    }

    void Reverse()
    {
        if (count < 2) return;

        BookNode* oldHead = head;
        BookNode* first = head->next;
        BookNode* p = head;
        BookNode* c = first;

        while (c != oldHead)
        {
            BookNode* n = c->next;
            c->next = p;
            p = c;
            c = n;
        }

        oldHead->next = p;
        head = first;
        current = head->next;
    }

    void Print()
    {
        if (IsEmpty())
        {
            cout << "No books!\n";
            return;
        }

        BookNode* p = head->next;

        cout << "\nIndex\tID\tTitle\n";

        for (int i = 0; i < count; i++)
        {
            cout << i << "\t" << p->bookID
                 << "\t" << p->title << endl;
            p = p->next;
        }

        cout << "Total books: " << count << endl;
    }

    void MoveNext()
    {
        if (IsEmpty())
        {
            cout << "No books!\n";
            return;
        }

        current = current->next;
        cout << "Now showing: " << current->title << endl;
    }

    void Status()
    {
        if (IsEmpty())
            cout << "Library is empty!\n";
        else
            cout << "Library has " << count << " books.\n";
    }

    ~CircularLinkedList()
    {
        while (!IsEmpty())
            delete Remove();
    }
};

BookNode* CreateBook(int id, string title)
{
    return new BookNode{id, title, NULL};
}
