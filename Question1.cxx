#include <iostream>
#include<string>
using namespace std;
struct Song{
   string song;
   Song *next;
    };
class SongList{
    private:
    Song* head;
    Song* tail;
    public:
    SongList(){
        head = NULL;
        tail = NULL;
        }
    void AddSongAtLast(string song){
        Song *temp = new Song;
        temp->song=song;
        temp->next=NULL;
        if (head == NULL){
            head = tail = temp;
            }
       else{
          tail ->next=temp;
          tail=temp;
        }      
        } 
    void AddAfterASong(string song,string NSong){
        Song *temp = new Song;
        temp->song=song;
        temp->next=NULL;
       Song *pointer;
        pointer = head;
           while(pointer!= NULL){
               if (pointer->song == NSong){
                   temp->next=pointer->next;                   pointer->next=temp;
                   break; 
                   }
                pointer=pointer->next;
               }
        
        }
        
   void deleteSong(string song){
    if (head->song ==song){
     Song *temp=head;
     head=head->next;
     delete temp;
     return ;
     }
     Song *pointer;
     Song *pre=NULL;
           pointer = head;
           while(pointer!= NULL){
               if (pointer->song == song){
                   if (pointer->next == NULL){
                       tail =pre ;
                       delete pointer;
                       return ;
                       }
                    pre->next=pointer->next;
                    delete pointer;
                    return ;
                   }
              pre = pointer;
              pointer=pointer->next;   
               }
    }
    void PrintList(){
           Song *pointer;
           pointer = head;
           int i=1;
           while(pointer != NULL){
               cout<<"SONG :"<<i<<":   "<<pointer->song<<endl;
               pointer=pointer->next;
               i++;
               }
        }
    };
void displayMenu() {
    cout << "\nMusic Playlist Menu\n";
    cout << "-----------------------\n";
    cout << "1. Add Song\n";
    cout << "2. Delete Song\n";
    cout << "3. Print List\n";
    cout << "4. Exit\n";
}

void addSongMenu() {
    cout << "\nAdd Song Menu\n";
    cout << "----------------\n";
    cout << "A. Add Song(by default at last)\n";
    cout << "B. Add after a Song\n";
}

int main() {
    string choiceStr;
    string songName;
    string songToDelete;
    string songToAddAfter;
    SongList List;
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choiceStr;

        if (choiceStr == "1") {
            addSongMenu();
            string choice;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == "A" || choice == "a") {
                cout << "Enter song name to add : ";
                cin.ignore();
                getline(cin, songName);
                List.AddSongAtLast(songName);
            }
            else if (choice == "B" || choice == "b") {
                cout << "Enter song name to add: ";
                cin.ignore();
                getline(cin, songName);
                cout << "Enter the song name to add after: ";
                getline(cin, songToAddAfter);
                List.AddAfterASong(songName,songToAddAfter);
            }
            else {
                cout << "Invalid choice. Please choose a number between 1 and 2.\n";
            }
        }
        else if (choiceStr == "2") {
            cout << "Enter song name to delete: ";
            cin.ignore();
            getline(cin, songToDelete);
            List.deleteSong(songToDelete);
        }
        else if (choiceStr == "3") {
            List.PrintList();
        }
        else if (choiceStr == "4") {
            cout << "Exiting program. Goodbye!\n";
            return 0;
        }
        else {
            cout << "Invalid choice. Please choose a number between 1 and 4.\n";
        }
    }

    return 0;
}
