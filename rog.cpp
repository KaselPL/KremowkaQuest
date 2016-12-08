#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

// #include "resouorce.rc"

using namespace std;

string version = "0.2-dev1";
stack <string> textBox;

char splash[22][20]={

{' ',' ',' ',' ',' ',' ',' ',' ',' ',201,187,' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',201,205,188,200,205,187,' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',201,205,188,176,176,176,176,200,205,187,' ',' ',' ',' ',' '},
{' ',' ',' ',201,205,188,176,176,176,176,176,176,176,176,200,205,187,' ',' ',' '},
{' ',' ',201,188,176,176,176,176,176,176,176,176,176,176,176,176,200,187,' ',' '},
{' ',' ',200,187,176,176,176,176,176,176,176,176,176,176,176,176,201,188,' ',' '},
{' ',' ',186,200,205,187,176,176,176,176,176,176,176,176,201,205,188,186,' ',' '},
{' ',' ',186,176,176,200,205,187,176,176,176,176,201,205,188,176,176,186,' ',' '},
{' ',' ',186,176,176,176,176,200,205,187,201,205,188,176,176,176,176,186,' ',' '},
{' ',' ',186,176,176,176,176,176,176,200,188,176,176,176,176,176,176,186,' ',' '},
{' ',' ',204,205,205,187,176,176,176,176,176,176,176,176,201,205,205,185,' ',' '},
{' ',' ',186,177,177,200,205,187,176,176,176,176,201,205,188,177,177,186,' ',' '},
{' ',' ',186,177,177,177,177,200,205,187,201,205,188,177,177,177,177,186,' ',' '},
{' ',' ',186,177,177,177,177,177,177,200,188,177,177,177,177,177,177,186,' ',' '},
{' ',' ',200,187,177,177,177,177,177,177,177,177,177,177,177,177,201,188,' ',' '},
{' ',' ',' ',200,205,187,177,177,177,177,177,177,177,177,201,205,188,' ',' ',' '},
{' ',' ',' ',' ',' ',200,205,187,177,177,177,177,201,205,188,' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',200,205,187,201,205,188,' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',200,188,' ',' ',' ',' ',' ',' ',' ',' ',' '}
};



char A[13][31] ={
//0   1   2   3   4   5   6   7   8   9  10  11  12  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29
{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
{'X',' ',' ',1  ,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X',' ','X','X','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X',' ','X','X','X',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X',' ','X','X','X',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X',' ',' ',' ',' ',' ','F',' ',' ',' ','K',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X',' ',' ', 1 ,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X',' ',' ',' ','O',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},

};

/**
0 ID
1 nameM
2 meet
3 kill
4 attackFail
5 rightAttack
6 defeated
7 run
8 nameD
**/
string enemyDef[2][9] ={
{"P", "Jan Pawel II", "Nie oddam kremowki bez walki!", "*dzwiek rozpinanego rozporka*", "Myslisz, ze mnie tym pokonasz?", "2137", "Zawiodlem cie kremowko...", "Won!", "Janem Pawlem II"},
{"T", "Testoviron", "No jak tam polskie kuhwy pierdolone smiecie?!", "Polak lapie ta sline jak Niemiec pluje", "A NIE DLA PSA, KUHWA!","prokurator dziura w dupie","jestem scigany z urzedu!","polaaaacy rhobaaacy!","Testoviron"}
};
/**
Item ID
**/
vector <string> inventory;

/**
0 Item ID
1 Display name
2 Equip region

ITEM ID NIE MOZE BYC PUSTE BO SIE POPSUJE WSZYSTKO

**/
string itemDef[5][3] = {
{"K", "kremufka", "A"},
{"F", "Flaga Watykanu", "A"},
{"A", "Akt aneksji Krymu", ""},
{string(1, 1), "Male dziecko", ""},
{"J", "jarmu³ka", "A"}
};

/**
0 Item ID
1 Display name
Equip regions : 0-A, 1-Arm2(NYI), 2-Head, 3-Torso, 4-Boots
**/
string equipment[5][2] = {
{"", ""},
{"", ""},
{"", ""},
{"", ""},
{"", ""},
};

/// return pair (x,y) of coordinates
pair<int, int> findPostac(int x, int y, char c){
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            if(A[i][j] == c){
                return make_pair(j, i);
            }
        }
    }
}

pair <int, int> respawnPoint = findPostac(sizeof A[0] / sizeof(char),sizeof A / sizeof(A[0]), 'O');
bool zdech;
void respawnPostac(char c){
    pair<int,int> coord = findPostac(sizeof A[0] / sizeof(char), sizeof A / sizeof(A[0]), c);
    A[respawnPoint.second][respawnPoint.first] = c;
    A[coord.second][coord.first] = ' ';
    textBox.push("Zdechlo ci sie");
    zdech =1;
}



void fight(pair<int, int> postac){
    int failcount = 0;
    char *scan[] = {
    &A[postac.second+1][postac.first],
    &A[postac.second-1][postac.first],
    &A[postac.second][postac.first+1],
    &A[postac.second][postac.first-1]};
    for(int i = 0; i < sizeof enemyDef / sizeof enemyDef[0]; i++){
        for(int j = 0; j<4; j++){
            if(enemyDef[i][0].at(0) == *scan[j]){
                cout << "*Walczysz z "<< enemyDef[i][8] << "\n";
                cout << "*Aby pokonac przeciwnika musisz wpisac nazwe ruchu ktory go zabije\n";
                cout << "*Jesli nie chcesz walczyc z przeciwnikiem mozesz uciec wpisujac \"Uciekam\"\n";
                cout << "\n"<< enemyDef[i][1]<< ": " << enemyDef[i][2] << "\n";
                bool defeated= 0;
                string in;
                while(!defeated){
                    getline(cin, in);
                    transform(in.begin(), in.end(), in.begin(), ::tolower);
                    if(in == enemyDef[i][5]){
                        textBox.push(enemyDef[i][1] + ": " + enemyDef[i][6]);
                        *scan[j] = ' ';
                        defeated = 1;
                    }
                    else if(in == "uciekam"){
                        textBox.push(enemyDef[i][1] + ": " + enemyDef[i][7]);
                        defeated = 1;
                    }
                    else {
                        cout << enemyDef[i][1] << ": " << enemyDef[i][4] << "\n";
                        failcount++;
                    }
                    if(failcount ==  5){
                        defeated = 1;
                        textBox.push(enemyDef[i][1]+": "+enemyDef[i][3]);
                        respawnPostac('O');
                    }
                }
            }
        }
    }
}
void renderSplash(int x, int y){
    cout << "KREMOWKA QUEST v" << version << "\n";
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            cout << splash[i][j];
        }
        cout << "\n";
    }
    cout << "Nacisnij dowolny przycisk aby kontynuowac...";
}
///return position of c
void render(int x, int y){
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            cout << A[i][j];
        }
        cout << "\n";
    }
}

/// return 1 if successful
bool movePostac(pair <int, int> start, pair<int,int> cel, bool sw){
    if(sw){
        swap(A[start.second][start.first], A[cel.second][cel.first]);
        return 1;
    }
    else if(A[cel.second][cel.first] == ' '){
        swap(A[start.second][start.first], A[cel.second][cel.first]);
        return 1;
    }
    else{
        textBox.push("Nie mozesz tu wejsc");
        return 0;
    }
}

/// pickup item
void pickup(pair<int, int> postac){
    char *scan[] = {
    &A[postac.second+1][postac.first],
    &A[postac.second-1][postac.first],
    &A[postac.second][postac.first+1],
    &A[postac.second][postac.first-1]};
    cout << "scan done\n";
    for(int i = 0; i < sizeof itemDef / sizeof itemDef[0]; i++){
        for(int j = 0; j<4; j++){
            if(itemDef[i][0].at(0) == *scan[j]){
                inventory.push_back(itemDef[i][0]);
                cout << "pusz bak done\n";
                *scan[j] = ' ';
                cout << "done\n";
            }
        }
    }

}

int findItemNum(char ID){
    for(int i =0; i < sizeof itemDef / sizeof(itemDef[0]);i++ ){
        //cout << "obrot " << i << "/" << sizeof itemDef / sizeof(itemDef[0])-1 << "\n";
        if(itemDef[i][0].at(0) == ID){
            return i;
        }
    }
    return -1;
}
void renderInvScr(int cursorPos) {
    int i = 0;
    cout << "********\n";
    cout << "|PLECAK|\n";
    cout << "********\n";
    for(int i = 0; i < inventory.size(); i++) {
        cout << (char) 219;
        if(i==cursorPos){
            cout << (char) 254;
        }
        else {
            cout << " ";
        }
        cout << " " << inventory[i] << " " << itemDef[findItemNum(inventory[i].at(0))][1] << "\n";
    }
    if(inventory.size()== 0){
        cout << "Nic nie masz w plecaku...\n";
    }
}
void InvScrAccess() {
    system("cls");
    bool exit = 1;
    int cursorPos = 0;
    renderInvScr(cursorPos);
    //cout << cursorPos;
    while(exit){
        while(kbhit()){
            char a = getch();
            switch(a){
            case 'w': cursorPos--; break;
            case 's': cursorPos++; break;
            case ' ': break;
            case 27: exit = 0; break;
            }
            system("cls");
            if(cursorPos < 0){
                cursorPos = 0;
            }
            if(cursorPos > inventory.size()-1){
                cursorPos = inventory.size()-1;
            }
            renderInvScr(cursorPos);
            //cout << cursorPos;
        }
    }

}
/// nie dziala zbytnio
void improveWalls(int x, int y, char c){
    for(int i = 0; i<y; i++){
        for(int j = 0; j<x; j++){
            if(A[i][j] == c){
                //cout << "scan begin for " << j << ", " << i << "\n";
                char *scan[4] = {&A[0][0],&A[0][0],&A[0][0],&A[0][0]};
                try{
                    scan[0] = &A[i+1][j];
                }
                catch(exception ex){

                }
                try{
                    scan[0] = &A[i-1][j];
                }
                catch(exception ex){

                }
                try{
                    scan[0] = &A[i][j+1];
                }
                catch(exception ex){

                }
                try{
                    scan[0] = &A[i][j-1];
                }
                catch(exception ex){

                }

                //cout << "scan successful\n";
                bool u =0, d =0, r= 0, l= 0;
                for(int a = 0; a<4; a++){
                    if(*scan[a] == c || *scan[a] >= 185&& *scan[a]<=188 || *scan[a] >= 200 && *scan[a] <=206){
                        switch(a){
                        case 0:
                        d =1;
                        break;
                        case 1:
                        u =1;
                        break;
                        case 2:
                        r =1;
                        break;
                        case 3:
                        l =1;
                        break;
                        }
                    }
                }
                if(u||d) A[i][j] = 186;
                if(r||l) A[i][j] = 205;
                if(u&&r) A[i][j] = 200;
                if(u&&l) A[i][j] = 188;
                if(d&&r) A[i][j] = 201;
                if(d&&l) A[i][j] = 187;
                if(u&&d&&l) A[i][j] = 185;
                if(u&&d&&r) A[i][j] = 204;
                if(r&&d&&l) A[i][j] = 203;
                if(r&&u&&l) A[i][j] = 202;
                if(r&&d&&u&&u) A[i][j] = 206;
            }
        }
    }
}

main(){
    ///init stuff
    bool run = 1;
    int attempt = 0;
    int sizeX = sizeof A[0] / sizeof(char);
    int sizeY = sizeof A / sizeof(A[0]);
    char input;
    pair<int, int> postac = findPostac(sizeX, sizeY, 'O');

    renderSplash(21, 20);
    // improveWalls(sizeX, sizeY, 'X');
    while(!kbhit()){

    }
    while(run){
        while(kbhit()){
            if(zdech==1){
                zdech = 0;
                postac = findPostac(sizeX, sizeY, 'O');
            }
            input = getch();
            switch(input){
            // ESC
            case 27:
                if(attempt == 1){
                    run = 0;
                }
                attempt = 2;
                textBox.push("Nacisnij jeszcze raz aby wyjsc");
                break;
            case 'w':
                if(movePostac(postac, make_pair(postac.first,postac.second-1), 0)){
                    postac.second--;
                }
                break;
            case 's':
                if(movePostac(postac, make_pair(postac.first,postac.second+1), 0)){
                    postac.second++;
                }
                break;
            case 'a':
                if(movePostac(postac, make_pair(postac.first-1,postac.second), 0)){
                    postac.first--;
                }
                break;
            case 'd':
                if(movePostac(postac, make_pair(postac.first+1,postac.second), 0)){
                    postac.first++;
                }
                break;
            case ' ':
                fight(postac);
                pickup(postac);
                break;
            case 'e':
                InvScrAccess();
                break;
                //equipment access
            }
            if(attempt == 1) attempt =0;
            if(attempt == 2) attempt =1;


            system("cls");
            render(sizeX, sizeY);
            for(int i = 0; i < textBox.size(); textBox.pop()){
                cout << textBox.top() << "\n";
            }
            ///Debug
            cout << input;

        }
    }
}
