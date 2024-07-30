#include "Game.h"
#include "showcarddialog.h"

#include "QListWidgetItem"
#include "ui_showcarddialog.h"

#include <QString>
#include <string>


// Constructor
Game::Game(): currentBattle(nullptr), winner(nullptr), NeshaneSolhSetter("N") {
}
// destructor
Game::~Game() {
    if (currentBattle) {
        delete currentBattle;
    }
}

// Start the game by initializing and sorting players
void Game::startGame() {
    showCards();
    while (true) {
        setNeshaneJangProvince();
        initiateBattle();
        if (checkForWinner() == true){
            break;
        }
    }
    endGame();
    
}

// Initialize players
void Game::initPlayers(std::vector<Player> players) {

    for (auto player : players) {
        addPlayer(player);
    }
}


// Add player to the players list
void Game::addPlayer(const Player& player) {
    players.push_back(player);
}

// Sort players vector based on their age ( for initializing the first province to attack )
void Game::sortPlayers() {
    int n = players.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (players[j].getAge() > players[j + 1].getAge()) {
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
    NeshaneJangSetter = players[0].getName();
}

void Game::showCards() {
    int numberOfPlayers = players.size();
    for (int i = 0; i < numberOfPlayers; i++) {

        deck.deal(players[i]);

        showCardDialog *dialog = new showCardDialog;


        dialog->show();

        dialog->ui->lblText->setText(QString::fromStdString("Here is " + players[i].getName() + "'s cards: "));

        std::vector<std::shared_ptr<Card>> playerCards = players[i].getCardsInHand();

        for(int j = 0; j < playerCards.size(); j++) {
            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(playerCards[j]->getName()), dialog->ui->lstCards);
            dialog->ui->lstCards->addItem(item);
        }



        // std::system("cls");

        // std::cin.get();

        // std::cout << "I Want Wo Show " << players[i].getName() << "'s Cards \n";
        // std::cout << "Press ENTER To Continue!";

        // std::cin.get();
        // std::system("cls");

        // deck.deal(players[i]);

        // std::vector<std::shared_ptr<Card>> playerCards = players[i].getCardsInHand();
        // std::cout << "Here is " << players[i].getName() << "'s cards :" << std::endl << std::endl;
        // for(int j = 0; j < playerCards.size(); j++) {
        //     std::cout << playerCards[j]->getName() << std::endl;
            
        // }

        // std::cout << std::endl << "Press ENTER To Continue!";
        // std::cin.get();

    }
    
    std::cout <<std::endl <<std::endl<<std::endl;
    std::cout << "The Game Is About To Start ........! \n";    
    
}

// A function for getting the neshanejang from the user (independent from the case size that user enters\)
void Game::setNeshaneJangProvince(){

    system("clear");

    // Map of province names to enum values
    std::unordered_map<std::string, prov> provinceMap = {
        {"bella", BELLA},
        {"caline", CALINE},
        {"enna", ENNA},
        {"atela", ATELA},
        {"pladaci", PLADACI},
        {"borge", BORGE},
        {"dimase", DIMASE},
        {"morina", MORINA},
        {"olivia", OLIVIA},
        {"rollo", ROLLO},
        {"talmone", TALMONE},
        {"armento", ARMENTO},
        {"lia", LIA},
        {"elina", ELINA}
    };

    std::string NeshaneSolhProvince = "";

    if (NeshaneSolhSetter != "N") {

        std::cout << "( " << NeshaneSolhSetter << " )" << "should set Neshan Solh";
        std::cout << "HERE IS A LIST OF PROVNICES ----->  ";
        map.provinceListPrinter();
        std::cout << "Please Select The Province You Want The Neshane Solh To Be On  : "<<std::endl;
        std::string InputProvince ;

        // Check if the provinceName exists in the map
        bool flag = true; 
        while (flag)
        {
        std::cin>> InputProvince ;
        std::string lowerCaseProvinceName = InputProvince;
        std::transform(lowerCaseProvinceName.begin(), lowerCaseProvinceName.end(), lowerCaseProvinceName.begin(), ::tolower);
        if (provinceMap.find(lowerCaseProvinceName) != provinceMap.end()) {

            // check if the province has been seleted before 
            if (std::find(totalConqueredProvinces.begin(), totalConqueredProvinces.end(), lowerCaseProvinceName) != totalConqueredProvinces.end()) {
                std::cout << "This province has been conquered before \nTry another : ";
                continue;
            }
            
            NeshaneSolhProvince = lowerCaseProvinceName;
            std::cout << "Neshane Solh set to province:      " << InputProvince << std::endl;
            flag = false ; 
        } else {
            std::cout << "Province not found. Neshane Solh not set." << std::endl;
        }
            
        }

    }

    std::cout << "( " << NeshaneJangSetter << " )" << "should set Neshan Jang";
    std::cout << "HERE IS A LIST OF PROVNICES ----->  ";
    map.provinceListPrinter();
    std::cout << "Please Select The Province You Want The War To Be On  : "<<std::endl;

    std::string InputProvince ;

    // Check if the provinceName exists in the map
    bool flag = true ; 
    while (flag)
    {
    std::cin>> InputProvince ;
    std::string lowerCaseProvinceName = InputProvince;
    std::transform(lowerCaseProvinceName.begin(), lowerCaseProvinceName.end(), lowerCaseProvinceName.begin(), ::tolower);
    if (provinceMap.find(lowerCaseProvinceName) != provinceMap.end()) {

        // check if the province has been seleted before 
        if (std::find(totalConqueredProvinces.begin(), totalConqueredProvinces.end(), lowerCaseProvinceName) != totalConqueredProvinces.end()) {
            std::cout << "This province has been conquered before \nTry another : ";
            continue;
        }

        if (NeshaneSolhProvince == lowerCaseProvinceName) {
            std::cout << "Neshane Solh is the same as Neshane Jang\n";
            continue;
        }
        

        totalConqueredProvinces.push_back(lowerCaseProvinceName);
        NeshaneJangProvince = provinceMap[lowerCaseProvinceName];
        std::cout << "NeshaneJang set to province:      " << InputProvince << " \n  So Whoever Wins The Round "<<InputProvince<<"Is Gonna Be In His Conquered Province List  "<<std::endl;
        flag = false ; 
    } else {
        std::cout << "Province not found. NeshaneJang not set." << std::endl;
    }
        
    }

}

void Game::initiateBattle() {
    if (currentBattle) {
        delete currentBattle;
    }

    currentBattle = new Battle(map.getProvinceByIndex(int(NeshaneJangProvince)), players, deck);

    currentBattle->startBattle();

    

    NeshaneJangSetter = currentBattle->endBattle();

    NeshaneSolhSetter = currentBattle->getNeshaneSolhSetter();


}

bool Game::checkForWinner() { 
    for (auto &player : players) {
        if (player.winnerDeterminer()) {
            winner = &player;
            return true;
        }
    }
    return false;
}

void Game::endGame() {
    system("clear");
    std::cout << "\n\n\tPlayer " << winner->getName() << " has won the game!!";
}
