#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void greeting(){
    cout << "-------------WELCOME TO TIC-TAC TOE CHAMPIONSHIP-------------" << endl;
    cout << endl << endl << endl << endl;
}

void Total_match(vector<string> &players,int no_players){
    cout << "\t\tTotal " << (no_players * (no_players - 1)) << "matches will be played in this championship" << endl;
    cout << "\t\t\t\tOn Winning, winner will get 5 points and loser will get 0 points" << endl;
    cout << "\t\t\t\tOn Draw!! Both player will get 2 - 2 points" << endl;
    int m = 1;
    for(int i = 0; i < no_players; i++){
        for(int j = 0; j < no_players; j++){
            if(j == i)
                continue;
            cout << "\t\t\t"<< m++ << ".  " << players[i] << "\tv/s\t" << players[j] << endl;
        }
    }
}

void check_score(vector<pair<int, pair<int, int>>> &scorecard, int i){
    cout << "Your score till now is " << scorecard[i].first << " and Total time used(in second) " << scorecard[i].second.first<< endl;
}


void board(vector<char> &arr, vector<string> &players, int i, int j){
    system("cls");
    time_t now = time(0);
    char *dt = ctime(&now);
    cout << "\tWelcome to Tic-Tac Game:~\t\t\t\t\t\t\t\t\t\t\t" << dt << endl;
    cout << "\t\t" << players[i] << endl;
    cout << "\t\t" << "  V/s" << endl;
    cout << "\t\t" << players[j] << endl;
    cout << "\t\t\t     |     |     " << endl;
    cout << "\t\t\t  "<<arr[0]<<"  |  "<<arr[1]<<"  |  "<<arr[2]<<"   " << endl;
    cout << "\t\t\t_____|_____|_____" << endl;
    cout << "\t\t\t     |     |     " << endl;
    cout << "\t\t\t "<<arr[3]<<"   |  "<<arr[4]<<"  |  "<<arr[5]<<"   " << endl;
    cout << "\t\t\t_____|_____|_____" << endl;
    cout << "\t\t\t     |     |     " << endl;
    cout << "\t\t\t "<<arr[6]<<"   |  "<<arr[7]<<"  |  "<<arr[8]<<"   " << endl;
    cout << "\t\t\t     |     |     " << endl;
}

void Turn(vector<char> &arr, bool &one, vector<string> &players,vector<pair<int, pair<int, int>>> &scorecard, int i, int j, int &cnt){
     int choice;
     if( one)
        cout << players[i] <<"[X] turn: ";
     else
        cout << players[j] <<"[0] turn: ";
     time_t before = time(0);
     //tm *ltm1 = localtime(&before);
     cin >> choice;
     time_t after = time(0);
     //tm *ltm2 = localtime(&after);
     if((arr[choice-1] != 'X' && arr[choice-1] != '0')&&(choice >=1 && choice <= 9)){
        if(one){
            scorecard[i].second.first += (int) difftime(after, before);
            arr[choice-1] = 'X';
            one = false;
        }
        else{
            scorecard[j].second.first += (int) difftime(after, before);
            arr[choice-1] = '0';
            one = true;
        }
        cnt++;
     }
     else{
        cout << "Invalid Input!!" << endl;

    }

}

bool decision(vector<char> &arr){
    for(int i = 0; i < 9; i += 3){
        if(arr[i] == arr[i+1] && arr[i+1] == arr[i+2])
            return true;
    }
    for(int i = 0; i < 3; i++){
        if(arr[i] == arr[i+3] && arr[i+3] == arr[i+6])
            return true;
    }
    if(arr[0] == arr[4] && arr[4] == arr[8])
        return true;
    if(arr[2] == arr[4] && arr[4] == arr[6])
        return true;
    return false;
}

int main()
{
    greeting();
    int no_players, cnt_game = 0;
    cout << "Enter number of players: ";
    cin >> no_players;

    vector<string> players(no_players);
    vector<pair<int, pair<int, int>>> scorecard(no_players);
    for(int i = 0; i < no_players; i++){
        scorecard[i].second.second = i;

    }

    cout << "Please, Enter the names of all players: " << endl;
    for(int i = 0; i < no_players; i++){
        cout << "Player " << i+1 << ": ";
        cin >> players[i];
    }

    Total_match(players, no_players);
    int proc;
    cout << "Enter any number to proceed further: ";
    cin >> proc;

    for(int i = 0; i < no_players; i++){
        for(int j = 0; j < no_players; j++){
            if(j == i)
                continue;
            bool one = true;
            int cnt = 0;
            cnt_game++;
            vector<char> arr(9);
            for(int i = 0; i < 9; i++)
                arr[i] = (i+1) + '0';
            while(cnt < 9){

                board(arr, players, i, j);
                Turn(arr, one,players,scorecard, i, j, cnt);
                if(decision(arr)){
                    board(arr, players, i, j);
                    if(!one){
                        cout <<endl<<endl<< "\t\tCongratulation, " << players[i] << " Win!" << endl;
                        scorecard[i].first += 5;
                        if(cnt_game == (no_players * (no_players - 1)))
                            break;
                        int score;
                        cout << "Enter 1 to check your score: ";
                        cin >> score;

                        if(score == 1)
                            check_score(scorecard, i);

                        int next;
                        cout << "Enter any number for next game: ";
                        cin >> next;
                        break;

                    }
                    else{
                        cout <<endl<<endl<< "\t\tCongratulation, " << players[j] << " Win!" << endl;
                        scorecard[j].first += 5;
                        if(cnt_game == (no_players * (no_players - 1)))
                            break;
                        int score;
                        cout << "Enter 1 to check your score: ";
                        cin >> score;

                        if(score == 1)
                            check_score(scorecard, j);

                        int next;
                        cout << "Enter any number for next game: ";
                        cin >> next;
                        break;
                    }
                }
            }
            if(cnt == 9){
                board(arr, players, i, j);
                scorecard[i].first += 2;
                scorecard[j].first += 2;
                cout <<endl<<endl<< "\t\tDRAW!!, Both Players played well.." << endl;
                if(cnt_game == (no_players * (no_players - 1)))
                    break;
                for(int l = 0; l < 2; l++){
                    int score;
                    cout << "Enter 1 to check your score: ";
                    cin >> score;

                    if(score == 1){
                        string name;
                        cout << "Enter your name: ";
                        cin >> name;

                        int player_no = -1;
                        for(int k = 0; k < no_players; k++){
                            if(players[k] == name){
                                player_no = k;
                                break;
                            }
                        }
                        if(player_no == -1){
                            cout << "!!!    INVALID NAME    !!!" << endl;
                            continue;
                        }
                        check_score(scorecard, player_no);
                    }
                }
                int next;
                cout << "Enter any number for next game: ";
                cin >> next;
            }

        }
    }
    system("cls");
    sort(scorecard.begin(), scorecard.end());
    cout << "-----------------Following is the scorecard----------------- " << endl;
    for(int i = no_players-1; i >= 0; i--){
        cout << "\t\t\tRank " << (no_players - i) << ": " << players[scorecard[i].second.second]  << "\tTotal score: " << scorecard[i].first << "\tTotal Time Used:(in second) " << scorecard[i].second.first<< endl << endl;
    }


    return 0;
}
