//this is just a skeleton. It does not compile without your partial or full solution
//it might contains some syntax error. it is given just as a starter
#include <iostream>
#include <fstream>
using namespace std;
// Define the song (node) class 
class Song{
    private:
    string artist;
    string title;
    Song* next;
    public:
    // define a constructor to initialize artist and title but next to null
    Song(string artist,string title){
        this->artist =artist;
        this->title = title;
        this->next = NULL;
    }
	// define a constructor  to initialize artist, title, and next to another song object
    Song(string artist,string title,Song* next){
        this->artist =artist;
        this->title = title;
        this->next = new Song;
    }
	
  // define a deafault constructor
    Song(){
        this->artist ="";
        this->title = "";
        this->next = NULL;
        
    }
    string getArtist(){
        return artist;
    }
    string getTitle(){
        return title;
    }
	//print the object in a format Artist: artist \nTitle: title such as
	//Artist: The Beatles
	//Title: The Fool on the Hill
     friend ostream& operator <<(ostream& outs,  Song& song);

	// compareTo two song objects first by artist and then by title
	//return 0 if they are equal 
	//return <0 if this object is smaller than other
	//return > 0 if this object is greater than other
    int compareTo(Song* other){
        if(artist < other->artist)
        return -1;
      else if (artist > other->artist) 
        return 1;
      else{
        if (title < other->title) 
          return -1;
         else if(title < other->title) 
          return 1;
         else
          return 0;
        }
      }
    
    

    friend class SongList;
};
ostream& operator <<(ostream& outs, Song& song){
         outs<< "Artist: "<< song.getArtist()<<endl<<"Title: "<< song.getTitle()<<endl;
         return outs;
    }

// Define a songList class 
class SongList{
    private:
    Song* head;
    int numSongs;
    public:
    SongList():head(NULL), numSongs(0) {};

    // This method reads data from a file and populates the list
	// songs.txt has the following format: 
        // Artist: ...
        // Title: ....
        // empty line 
        // Artist: ...
        // Title: ...
        // empty line ... and so on 
    void readFile (string aFile){
      ifstream fin("songs.txt");
      string artist;
      string title;
    //fin.ignore(7);
      while(getline(fin,artist)){
          fin.ignore(7);
          getline(fin,title);
          addSong(artist,title);
          numSongs++;
          fin.ignore(9);
      }
    }
    
    
   // This method adds a song to the list while maintaining its sorted order in the list  
  // node should be created and added in the right position
    void addSong (string artist, string title){
        Song* s = new Song(artist,title);
      if(head == NULL)
        head = s;
      else if(s->compareTo(head) < 0){
        s->next = head;
        head = s;
      } else{
        Song* current = head;
        while (s->compareTo(current->next)== -1 && current->next != NULL) {
          current = current->next;
        }
        s->next = current->next;
        current->next = s;
      }
    }
		
    // This method deletes all songs by an artist 
    void deleteByArtist (string artist){
        Song *current = head;                
    if (head->artist==artist){
        head = head->next;
        delete current;
        current=NULL;
        } 
        else{
        while(current->next !=NULL){
            if(current->next->artist == artist){
                Song* temp = current->next;
                current->next=current->next->next;
                delete temp; 
            }
            else
            current = current ->next;            
        }
    }
}

  // This method should return a song list that contains all songs by an artist
  // without deleting them from the main SongList object.
   SongList * getSongsByArtist (string artist){
       Song *v = head;
       SongList *list = new SongList(); 
       while(v!= NULL){
           v= v->next;
           if(v->artist == artist){
               list->addSong(v->artist,v->title);
           }
       }
       return list; 
   }

  // This method deletes a given song
    void deleteByTitle (string title){
    Song *current = head;                
    if (head->title==title){
        head = head->next;
        delete current;
        current=NULL;
        } 
        else{
        while(current->next !=NULL){
            if(current->next->title == title){
                Song* temp = current->next;
                current->next=current->next->next;
                delete temp; 
            }
            else
            current = current ->next;            
        }
    }
}
	
  // This method returns a song object matching the given title
  //without deleting the song from the main list. It returns NULL if the object does not exist
    Song* getByTitle (string title){
        Song *current = head;
        while (current != NULL) {
        if (current->title == title) {
          Song* result = new Song(current->artist,current->title);
          return result;
        }else{
          current = current->next;
        }
      }
      return NULL; //in case the song does not exist
    }
    
  // This method searches for all songs by an artist and displays them
    void searchByArtist (string artist){

        SongList * song = getSongsByArtist(artist);
        Song * v = song->head;
        if(v==NULL)
            cout<<"no songs found by the artist";
        else{
        while(v->next!=NULL){
            cout<<v<<endl;
            v=v->next;
        }
        }
    }
  // This method searches for a given song and displays it
    void searchByTitle (string title){
        cout << (*getByTitle(title));
    }
  // This method displays all entries in the collection
    void displayCatalog (){
        Song *v= head;
        while(v!=NULL){
            cout<<*v<<endl;
            v= v->next;

        }
    }

  // This method over-writes the file
    void writeFile (){
        ofstream myfile ;
        myfile.open("songs.txt");
        Song *v= head;
        while(v!=NULL){
            myfile<<*v<<endl;
            v= v->next;
        }
        myfile.close();
        
    }

    
};

void displayMenue(){
     cout<< "Song Catalog Menu\n1. Import songs from a file\n2. Add a song\n3. Delete a song\n4. Search for a song\n5. Get a song by title\n6. Get all songs by artist\n7. Display all songs\n8. Exit program\nEnter selection (1 - 8):\n";
}

int main() 
{
    SongList* list= new SongList();
   displayMenue();
   int userInput;
    cin >> userInput;
    string artist;
    string title;
    string choice;
    while (userInput!=8){
        string emptyLine;
        getline(cin,emptyLine); // to drop the \n line which is generated by userInput 
        if (userInput==1){
            cout << "Please insert the file name: " ;
            string fileName;
             cin >> fileName;
            list->readFile(fileName);
            cout << "------------------------------------------" << endl << endl;
        }else if (userInput==2){
            cout<< "Enter Artist: ";
            getline(cin, artist);
            cout << "Enter Title: ";
           getline(cin , title);
            list->addSong(artist,title);
            cout<< "Song has been added successfuly!" << endl;
            cout << "------------------------------------------" << endl << endl;
        
        }else if (userInput==3){
            cout << "Delete by artist or title (A or T): ";
            getline(cin,choice);
            if(choice.compare("A")==0){
                cout << "Enter Artist name: ";
                getline(cin,artist);
                list->deleteByArtist(artist);
            }else{
                // means delete by Title 
                cout << "Enter Title: ";
                getline(cin,title);
                list->deleteByTitle(title);
            }
            cout << "------------------------------------------" << endl << endl;
        }else if (userInput==4){
            cout << "Search by Artist or Title (A or T): ";
            getline (cin,choice);
            if( choice.compare("A")==0){
                cout << "Enter Artist: ";
                getline(cin,artist);
                list->searchByArtist(artist);
                
            }else{
                // means by Title
                 cout << "Enter Title: ";
                getline(cin,title);
                list->searchByTitle(title);
            }
            cout << "------------------------------------------" << endl << endl; 
        }else if (userInput==5){
            cout << "Enter Title: ";
            getline(cin,title);
            Song* song= list->getByTitle(title);
            if (song==NULL)
                cout << "No Match found!" << endl;
            else
                //cout << song->toString()<< endl;
            cout << "------------------------------------------" << endl << endl;
        
        }else if (userInput==6){
            cout << "Enter Artist: ";
            getline(cin,artist);
            SongList* newList=list->getSongsByArtist(artist);
            if (newList==NULL)
                cout<< "No Match found!" <<endl;
            else 
                newList->displayCatalog();
            cout << "------------------------------------------" << endl << endl;
        
        }else if (userInput==7){
            list->displayCatalog();
            cout << "------------------------------------------" << endl << endl;
    
        }
        displayMenue();
        cin >> userInput;
        if (userInput==8)
            list->writeFile();
    } 

     return 0;
}
