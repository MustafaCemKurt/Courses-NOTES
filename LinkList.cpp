#include <iostream>
using namespace std;

// Linked List (baðlý listeler)
class Node {
public:
    int value;  // Deðer deðiþkeni tanýmlýyoruz
    Node* next; // Pointer oluþturuyoruz

    Node(int value) // constructor oluþturuyoruz. ( yapýcý fonksiyon )
    {
        this->value = value; // Farklý deðiþkenleri birbirine tanýmladýk
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int len;

public:
    LinkedList(int value) {
        Node* n1 = new Node(value);
        head = n1;
        tail = n1;
        len = 1;
    }
    ~LinkedList() // destructor oluþturuyoruz. ( yýkýcý fonksiyon )
    {
        cout << "destructor is called";
        Node* tmp = head;
        while (head)
        {
            head = head->next;
            delete tmp;
            tmp = head;
        }

    }


    void PrintHead()  // head deðerini ekrana yazdýrma fonklsiyonu
    {
        if (head != NULL)
            cout << "Head :" << head->value << endl;
    }

    void PrintTail()  // tail deðerini ekrana yazdýrma fonklsiyonu
    {
        if (tail != NULL)
            cout << "Tail :" << tail->value << endl;
    }

    void PrintLen()  // Len deðerini ekrana yazdýrma fonklsiyonu
    {
        if (len != NULL)
            cout << "Len :" << this->len << endl;
    }

    void AppendList(int value) // Liste sonuna eleman ekleme fonksiyonu
    {
        Node* ne1 = new Node(value);  // yeni node oluþturuyoruz
        if (len == 0) // listede eleman yoksa direkt ekliyoruz
        {
            head = ne1;
            tail = ne1;
        }
        else
        {
            tail->next = ne1;
            tail = ne1;
        } len++;
    }

    void PrintList() // listeyi ekrana yazdýrma fonksiyonu
    {
        cout << endl;
        Node* temp = head; // temp'i oluþturup head'dan baþlatýyoruz.
        while (temp != NULL) // temp null olmadýðý sürece çalýþmasýný istiyoruz
        {
            cout << "-->" << temp->value;
            temp = temp->next; // temp'i sonrakine atýyoruz

        }
        cout << endl;

    }

    void DeleteLastNode() // soondan eleman silen fonksiyon 
    {
        Node* temp1 = head;
        Node* temp2 = head;

        while (temp1->next) // sonraki deðeri oldugu sürece calýsmasýný istiyoruz
        {
            temp2 = temp1;
            temp1 = temp1->next;

        }
        tail = temp2;
        tail->next = NULL; // sonraki deðerini NULL atýyoruz
        len--; //  uzunluðu 1 azaltýyoruz
        if (len == 0)
        {
            head = NULL;
            tail = NULL;

        }
        delete temp1; // tewmp1 siliyoruz

    }

    void FirstAdd(int value) // Liste baþýna eleman ekleme
    {
        Node* n1 = new Node(value);
        if (len == 0)
        {
            head = n1;
            tail = n1;

        }
        else
        {
            n1->next = head; // head öncesine baðlýyoruz
            head = n1;       // head güncelledik 
        }

    }

    void DeleteFirst() // Liste baþýndan eleman silen fonksiyon 
    {
        Node* n1 = head->next;

        if (len == 0)
        {
            cout << "listede eleman  yok " << endl;
        }
        if (len == 1)
        {
            delete head;
            head = NULL;
            tail = NULL;
            len--;

        }
        else
        {
            delete head;
            head = n1;
            len--;
        }

    }

    Node* getnode(int index) //  istenene indexteki veriyi getiren kod
    {
        if (index == 0 || index >= len)
        {
            return NULL;
        }

        Node* temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }


    }

    bool SetValue(int index, int newValue)  //            
    {
        Node* temp = getnode(index); // üstteki fonksiyon ile indexe direkt gidiyoruz.

        if (temp != NULL)
        {
            temp->value = newValue;  // deðeri güncellliyoruz.
            return true;  // bool atamasý oldugu için geri döndürme deðeri bool olmalýdýr . 
        }
        return false;

    }

    bool InsertNode(int index, int value)
    {
        if (index<0 || index > len)
        {
            return false;
        }
        if (index == 0)
        {
            FirstAdd(value);
            return true;
        }
        if (index == len)
        {
            AppendList(value);
            return true;
        }
        Node* nü1 = new Node(value); // eklenecek node oluþturduk 
        Node* temp = getnode(index - 1);
        Node* temp2 = getnode(index);
        temp->next = nü1;   // baðlantýlarý yapýyoruz
        nü1->next = temp2;
        len++;

        return true;


    }


};

int main() {
    LinkedList* l1 = new LinkedList(12);

    l1->AppendList(5);
    l1->AppendList(24);
    l1->AppendList(8);
    l1->AppendList(7);
    l1->PrintList();
    /* l1->DeleteFirst();
     l1->PrintList();*/
    l1->InsertNode(0, 22);
    l1->PrintList();








    return 0;
}
