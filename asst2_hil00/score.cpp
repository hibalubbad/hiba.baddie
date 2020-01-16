#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void getHighScore (string &player, int &highscore, int counter)
{
    ifstream file;
    file.open ("scores.txt");
    for(int i = 0; i < counter; i++){
        string name;
        int score;
        file >> name;
        file>> score;
        if (score > highscore){
            highscore = score;
            player = name;
        
        }
    }
    file.close();
    cout << player << " has the high score of " << highscore << endl;

    }

int main(){

    int counter = 0;
    string line;

    ifstream file("scores.txt");

    while (getline(file, line))
        counter++;

    int highscore = -1;
    string player = " ";
    getHighScore (player,highscore, counter);
}

