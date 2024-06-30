#include <iostream>
using namespace std;

// Linked List (baðlý listeler)
class Node {
public:
    int value;  // Deðer deðiþkeni tanýmlýyoruz
    Node* next; // Pointer oluþturuyoruz
    Node* prev; // önceki konumu gösteren pointer

    Node(int value) // constructor oluþturuyoruz. ( yapýcý fonksiyon )
    {
        this->value = value; // Farklý deðiþkenleri birbirine tanýmladýk
        next = NULL;
        prev = NULL; 
    }
};

class DoublyLinkList
  {
  private:
      Node* head;
      Node* tail;
      int len;

  public:
      DoublyLinkList(int value)
      {
          Node* no1 = new Node(value);
          head = no1;
          tail = no1;
          len = 1;
      }

      ~DoublyLinkList()
      {
          Node* temp = head;
          while ( head!=NULL)
          {
              head = head->next;
              delete temp;
              temp = head;
          }
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
              ne1->prev = tail;
              tail = ne1;
          } len++;
      }

      void DeleteLastNode()
      {
          if (len == 0) return;

          Node* temp = tail;

          if (len != 1)
          {
             tail = tail->prev;
             tail->next = NULL;

          }
          else if (len == 1)
          {
              head = NULL;
              tail = NULL; 

          }
        

          delete temp;
          len--;


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
              head->prev = n1;
              head = n1;       // head güncelledik 
          }
          len++;

      }

      void DeleteFirst() // Liste baþýndan eleman silen fonksiyon 
      {
          

          if (len == 0)
          {
              return;
          }

          Node* n1 = head;
          if (len == 1)
          {
              delete head;
              head = NULL;
              tail = NULL;
              len--;

          }
          else
          {
              head = head->next;
              head->prev = NULL;
              
          }
          delete n1;
          len--;

      }

      Node* getnode(int index) //  istenene indexteki veriyi getiren kod
      {
          if (index == 0 || index >= len)
          {
              return NULL;
          }

          Node* temp = head;

          if (index < len / 2)
          {
                  for (int i = 0; i < index; i++)
                {
                  temp = temp->next;
                }
          }
          else
          {
              temp = tail;
              for (int i = len - 1; i > index; i--)
              {
                  temp = temp->prev;
              }

          }
          
          return temp;

      }

      bool SetValue(int index, int newValue)  //            
      {
          Node* temp = getnode(index); // üstteki fonksiyon ile indexe direkt gidiyoruz.

          if (temp != NULL)
          {
              temp->value = newValue;  // deðeri güncellliyoruz.
              return true;  // bool atamasý oldugu için geri döndürme deðeri bool olmalýdýr . 
          }
          else 
          {
                return false;
          }
          

      }

      bool InsertNode(int index, int value) {
          if (index < 0 || index > len) {
              return false;
          }
          if (index == 0) {
              FirstAdd(value);
              return true;
          }
          if (index == len) {
              AppendList(value);
              return true;
          }

          Node* n1 = new Node(value);
          Node* left = getnode(index - 1);
          Node* right = left->next;

          n1->next = right;
          n1->prev = left;
          left->next = n1;
          if (right != NULL) {
              right->prev = n1;
          }

          len++;
          return true;
      }


      void DeleteNode(int index)
      {
          if (index >= 0 && index < len)
          {
              if (index == 0)
              {
                  DeleteFirst();
              }
              else if (index == len - 1)
              {
                  DeleteLastNode();
              }
              else
              {
                  Node* del = getnode(index);
                  del->next->prev = del->prev;
                  del->prev->next = del->next;
                  delete del;
                  len--;

              }

          }

      }


  };

  int main() {
      int choice, value, index;
      DoublyLinkList list(10); // Ýlk deðeri 10 olan bir liste oluþturuyoruz

      while (true) {
          cout << "1. Append to List\n";
          cout << "2. Delete Last Node\n";
          cout << "3. Add to First\n";
          cout << "4. Delete First Node\n";
          cout << "5. Print List\n";
          cout << "6. Print Head\n";
          cout << "7. Print Tail\n";
          cout << "8. Print Length\n";
          cout << "9. Insert Node\n";
          cout << "10. Delete Node\n";
          cout << "11. Set Value\n";
          cout << "12. Exit\n";
          cout << "Secim yapiniz: ";
          cin >> choice;

          switch (choice) {
          case 1:
              cout << "Eklemek istediðiniz deðeri giriniz: ";
              cin >> value;
              list.AppendList(value);
              break;
          case 2:
              list.DeleteLastNode();
              break;
          case 3:
              cout << "Baþa eklemek istediðiniz deðeri giriniz: ";
              cin >> value;
              list.FirstAdd(value);
              break;
          case 4:
              list.DeleteFirst();
              break;
          case 5:
              list.PrintList();
              break;
          case 6:
              list.PrintHead();
              break;
          case 7:
              list.PrintTail();
              break;
          case 8:
              list.PrintLen();
              break;
          case 9:
              cout << "Index ve deðeri giriniz: ";
              cin >> index >> value;
              list.InsertNode(index, value);
              break;
          case 10:
              cout << "Silmek istediðiniz indexi giriniz: ";
              cin >> index;
              list.DeleteNode(index);
              break;
          case 11:
              cout << "Index ve yeni deðeri giriniz: ";
              cin >> index >> value;
              list.SetValue(index, value);
              break;
          case 12:
              return 0;
          default:
              cout << "Geçersiz seçim!" << endl;
          }
      }

      return 0;
  }