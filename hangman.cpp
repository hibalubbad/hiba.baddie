#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> words;
bool ray[26]= {false};

void readFile()
{
    ifstream file;
    file.open ("words.txt");
    if (!file.is_open()) return;

    string word;
    while (file >> word)
    {
		words.push_back(word);
    }
}

string getRandomWord()
{
	srand((int)time(0));
	int index = rand() % words.size();
	return words.at(index);
}


bool iswordsguesed(string secretWord){
    for(int i = 0; i< secretWord.length(); i++){
        int index= secretWord[i]-'a';
        if(ray[index] == false){
            return false;
         }
    }
    return true;
}
void getGuessedWord(string secretWord){
    for(int i = 0; i< secretWord.length(); i++){
        int index= secretWord[i]-'a';
        if(ray[index] == false){
            cout<<"_";
        }
        else{
            cout<<secretWord[i];
        }
}
    cout<<endl;
}
string getAvailableLetters(){
    string left;
    for(int i = 0; i< sizeof(ray); i++){
        if(ray[i] == false)
             left += char (i+'a');     
    }
    return left;
}

void Hangman(string secretWord){
    cout<< " Welcome to Hangman!";
    cout<< " I am thinking of a word that is" ;
    cout<< secretWord.length();
    cout<< " characters long"<<endl;
    cout<< "--------------------"<<endl;
    int mistakes = 0;
    string guessed = " "; 
    while(iswordsguesed(secretWord) == false){
        cout<< getAvailableLetters()<<endl;
        char toguess;
        cin >> toguess;
        ray[toguess-'a']= true;
    for(int i = 0; i< 26; i++){
        if((ray[i] == true) && (guessed.find((char) (i+'a')) == std::string::npos)){
            guessed += (char) (i+'a') ;
        }
    }
    cout<<  "lettersguessed: ";
    cout<<  guessed<< endl;  
        if(secretWord.find(toguess)!= std::string::npos){
            getGuessedWord( secretWord);
        }
        else{
            mistakes += 1;
            cout<<mistakes<<endl;
            getGuessedWord( secretWord);
        }
    
    }
        
    }

int main()
{
	readFile();
	string randomWord = getRandomWord();
	cout << randomWord << endl;
    Hangman(randomWord);
}
