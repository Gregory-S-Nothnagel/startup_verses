#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

int main(){
    srand(time(NULL));
    cout << "type 'more' for context verses" << endl;
    cout << "type anything else for another randomly picked verse" << endl << "----------------------------------------------------------" << endl;
    vector <string> verses;
    std::ifstream myfile;
    myfile.open("verses.txt");
    while(!myfile.eof()){
        char c;
        string temp = "";
        while(!myfile.eof()){
            c = myfile.get();
            temp += c;
            if(c == '\n') break;
        }
        if(temp.size() > 0) verses.push_back(temp);
    }
    myfile.close();

    unsigned int verse_number = rand()%verses.size();
    cout << verses[verse_number] << endl;

    while(1){
        string command;
        cin >> command;
        cout << "----------------------------------------------------------" << endl;
        if(command == "more"){
            unsigned int start, stop;
            if(verse_number < 2) start = 0;
            else start = verse_number - 2;

            if(verses.size() - verse_number < 3) stop = verses.size();
            else stop = verse_number + 3;

            for(unsigned int i = start; i < stop; i++) cout << verses[i] << endl;
        }
        else{
            verse_number = rand()%verses.size();
            cout << verses[verse_number] << endl;
        }
    }

    return 0;
}
