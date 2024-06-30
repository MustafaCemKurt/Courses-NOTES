#include <iostream>
using namespace std;

// Linked List (ba�l� listeler)
class Node {
public:
    int value;  // De�er de�i�keni tan�ml�yoruz
    Node* next; // Pointer olu�turuyoruz

    Node(int value) // constructor olu�turuyoruz. ( yap�c� fonksiyon )
    {
        this->value = value; // Farkl� de�i�kenleri birbirine tan�mlad�k
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
    ~LinkedList() // destructor olu�turuyoruz. ( y�k�c� fonksiyon )
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


    void PrintHead()  // head de�erini ekrana yazd�rma fonklsiyonu
    {
        if (head != NULL)
            cout << "Head :" << head->value << endl;
    }

    void PrintTail()  // tail de�erini ekrana yazd�rma fonklsiyonu
    {
        if (tail != NULL)
            cout << "Tail :" << tail->value << endl;
    }

    void PrintLen()  // Len de�erini ekrana yazd�rma fonklsiyonu
    {
        if (len != NULL)
            cout << "Len :" << this->len << endl;
    }

    void AppendList(int value) // Liste sonuna eleman ekleme fonksiyonu
    {
        Node* ne1 = new Node(value);  // yeni node olu�turuyoruz
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

    void PrintList() // listeyi ekrana yazd�rma fonksiyonu
    {
        cout << endl;
        Node* temp = head; // temp'i olu�turup head'dan ba�lat�yoruz.
        while (temp != NULL) // temp null olmad��� s�rece �al��mas�n� istiyoruz
        {
            cout << "-->" << temp->value;
            temp = temp->next; // temp'i sonrakine at�yoruz

        }
        cout << endl;

    }

    void DeleteLastNode() // soondan eleman silen fonksiyon 
    {
        Node* temp1 = head;
        Node* temp2 = head;

        while (temp1->next) // sonraki de�eri oldugu s�rece cal�smas�n� istiyoruz
        {
            temp2 = temp1;
            temp1 = temp1->next;

        }
        tail = temp2;
        tail->next = NULL; // sonraki de�erini NULL at�yoruz
        len--; //  uzunlu�u 1 azalt�yoruz
        if (len == 0)
        {
            head = NULL;
            tail = NULL;

        }
        delete temp1; // tewmp1 siliyoruz

    }

    void FirstAdd(int value) // Liste ba��na eleman ekleme
    {
        Node* n1 = new Node(value);
        if (len == 0)
        {
            head = n1;
            tail = n1;

        }
        else
        {
            n1->next = head; // head �ncesine ba�l�yoruz
            head = n1;       // head g�ncelledik 
        }

    }

    void DeleteFirst() // Liste ba��ndan eleman silen fonksiyon 
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
        Node* temp = getnode(index); // �stteki fonksiyon ile indexe direkt gidiyoruz.

        if (temp != NULL)
        {
            temp->value = newValue;  // de�eri g�ncellliyoruz.
            return true;  // bool atamas� oldugu i�in geri d�nd�rme de�eri bool olmal�d�r . 
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
        Node* n�1 = new Node(value); // eklenecek node olu�turduk 
        Node* temp = getnode(index - 1);
        Node* temp2 = getnode(index);
        temp->next = n�1;   // ba�lant�lar� yap�yoruz
        n�1->next = temp2;
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
