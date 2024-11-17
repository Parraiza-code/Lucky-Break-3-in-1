#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

// function that produces a coinflip
// 0 = heads 1 = tails
int coinflip() {
    if (rand() % 2 == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int main() {

    //Variables used in the games

    // variables del Fight Club game

    int num, eneNum, eneHp, opcion, bigD = 0, playerHp;
    bool heal = false;

    // variables del Cards game

    int card1, card2, card3, cardchoose, playCard, eneCard, playPoints, enePoints;

    //variables y arrays de Horse Race

    int posiC1;
    int posiC2;
    int posiC3;
    int posiC4;
    int posiC5;
    int winner ,boost;
    bool endRace = false, endLoop = false ,boostbool;
    string enter;

    // Array para los nombres del caballos 0  start - 4 end   
    string caballo[5] = { "Secretariat #1","Man o' War #2","Seabiscuit #3","Bucephalus #4","Black Caviar #5" };

    // Array para las posiciones de los caballos 
    // 0 - 4 vertical
    // 0 - 5 horizontal
    string posicion[5][6] = {
    {"o-----","-o----","--o---","---o--","----o-","------|o"},
    {">-----","->----","-->---","--->--","---->-","------|>"},
    {"<-----","-<----","--<---","---<--","----<-","------|<"},
    {"*-----","-*----","--*---","---*--","----*-","------|*"},
    {"#-----","-#----","--#---","---#--","----#-","------|#"}
    };

    // Win conditions
    bool winCon1 = false, winCon2 = false, winCon3 = false;

    // seed for rand inputs 
    srand(time(NULL));

    // empieza todo el Juego

    cout << "Lucky Break! \n3-in-1 Arcade Machine \n\n";

    //Menu loop using do-while
    do {

        cout << "Choose a Game, they go from easy to hard\n";
        cout << "1. Fight Club \n2. Card Game \n3. Horse Race \n4. Quit \n";
        cin >> opcion;

        system("CLS");

        switch (opcion) {
        case 1: // starts the fight club minigame

            // reset variables
            heal = false;
            playerHp = 40;

            cout << "Choose an action to perform, but be careful!\n";

            for (eneHp = 40; eneHp > 0; eneHp = eneHp - num) {

                cout << "Player health: " << playerHp << "\n";
                cout << "Enemy health: " << eneHp << "\n\n";
                cout << "Attack(1)      Block(2)\n         Heal(3)\n";
                cin >> opcion;
                system("CLS");

                switch (opcion) {
                case 1: //attack

                    num = rand() % 11;
                    cout << "You did " << num << " damage.\n";
                    break;

                case 2: //block

                    num = 0;
                    cout << "You blocked the attack, reducing enemy damage.\n";
                    break;

                case 3: //heal

                    if (heal == false) {
                        cout << "You healed 10 hp.\n";
                        playerHp = playerHp + 10;
                        heal = true;
                        num = 0;
                    }
                    else {
                        cout << "You've already used your heal, so you do nothing.\n";
                        num = 0;
                    }
                    break;

                default: //invalid input

                    num = 0;
                    cout << "That input doesn't do anything, try again. Dummy.\n";
                    break;

                }

                
            
                // enemy attack
                while (playerHp > 0) {

                    eneNum = rand() % 8;

                    // if-else to reduce enemy damage when blocking
                    if (opcion == 2) {

                        eneNum = eneNum * 0.5;
                        // enemy critical hits when blocked
                        if (bigD == 3 or bigD == 6) {
                            eneNum = eneNum * 2;
                        }
                        // damage message when blocking
                        cout << "Enemy did " << eneNum << " reduced damage.\n";

                    }
                    else {
                        // if-else for enemy critical hit warning/crit damage if not blocked
                        if (bigD == 2 or bigD == 5) {

                            cout << "Enemy is charging up a devastating attack.\n";

                        }
                        else if (bigD == 3 or bigD == 6) {

                            eneNum = 10;

                        }
                        // enemy damage message
                        cout << "Enemy did " << eneNum << " damage.\n";
                    }

                    bigD++;
                    playerHp = playerHp - eneNum;
                    break;
                }
            

                cout << "-----------------------------------------------------\n";
                // player loss
                if (playerHp <= 0) {

                cout << "You died. \n";
                //generates random card numbers
                break;

                }
            }

                //victory message
                if (eneHp <= 0) {

                cout << "Enemy defeated, you win!\n";

                winCon1 = true;

                }

                break;
        

        case 2: // starts the card minigame

            //reset variables
            playPoints = 0;
            enePoints = 0;

            cout << "Try to choose a higher card than your opponent, first to 2 points wins!\n \n";
            while (playPoints < 2 && enePoints < 2) {
                card1 = rand() % 13;
                card2 = rand() % 13;
                card3 = rand() % 13;
                cout << "Your card numbers are: " << card1 << " " << card2 << " " << card3 << "\n";
                cout << "Choose one of your cards (1,2,3) to place: ";
                cin >> cardchoose;
                system("CLS");
                switch (cardchoose) {


                    //generates enemy card, and outputs both card choicesase 1:

                    playCard = card1;
                    break;


                    //determines which card won                    
                case 2:

                    playCard = card2;
                    break;

                case 3:

                    playCard = card3;
                    break;

                default:



                    //checks who won with an if-else statement     
                    break;

                }
                eneCard = rand() % 13;
                cout << "Your card: " << playCard << "\n";
                cout << "Enemy card: " << eneCard << "\n";
                if (playCard > eneCard) {

                    cout << "Your card wins!\n";
                    playPoints++;

                }
                else if (playCard < eneCard) {

                    cout << "Enemy card wins...\n";
                    enePoints++;

                }

            }
            if (playPoints == 2) {
                cout << "You win! \n";
                winCon2 = true;
            }
            else if (enePoints == 2) {
                cout << "You lose... \n";
            }

            break;
        case 3: //comienza el juego del Horse Race 

            // esto es para determinar a cual caballo escogiste 

            do {
                cout << "Bet on a horse and pray it wins Good Luck \n";

                cout << "who do you want to bet on :" << "\n";

                cout << "1. Secretariat {o} \n" << "2. Man o' War {>} \n" << "3. Seabiscuit {<}\n" << "4. Bucephalus {*} \n" << "5. Black Caviar {#} \n";

                cin >> opcion;

                // uso opcion para el switch case para no crear otra variable 

                switch (opcion) {
                case 1:

                    cout << "You are beting on Secretariat {o} " << "\n";

                    endLoop = true;

                    break;

                case 2:

                    cout << "You are beting on Man o' War {>} " << "\n";

                    endLoop = true;

                    break;

                case 3:

                    cout << "You are beting on Seabiscuit {<} " << "\n";

                    endLoop = true;

                    break;

                case 4:

                    cout << "You are beting on Bucephalus {*} " << "\n";

                    endLoop = true;

                    break;
                case 5:

                    cout << "You are beting on Black Caviar {#} " << "\n";

                    endLoop = true;

                    break;
                default:

                    cout << "input invalid...  " << "\n";

                    break;
                }

            } while (endLoop == false);

            system("CLS");
            // Reseting las variables
            posiC1 = 0;
            posiC2 = 0;
            posiC3 = 0;
            posiC4 = 0;
            posiC5 = 0;
            winner = 0;
            boost = 0;
            endRace = false;
            boostbool = false;
            //Comiensa la carrera

            cout << "Ready" << "\n" << "Set" << "\n" << "GOOOOOOO" << "\n";

            cout << posicion[0][0] << "\n" << posicion[1][0] << "\n" << posicion[2][0] << "\n" << posicion[3][0] << "\n" << posicion[4][0] << "\n";

            // esto es para darle una pausa al loop para que no tire la carrera de cantaso

            cout << "Cheer on your horse: " << "\n";

            cin >> enter;

            //para borrar la pantalla
            system("CLS");

            //esto es un loop que determina si el caballo se mueve o se queda parado con un coin flip
            while (endRace == false) {

                posiC1 = posiC1 + coinflip();
                posiC2 = posiC2 + coinflip();
                posiC3 = posiC3 + coinflip();
                posiC4 = posiC4 + coinflip();
                posiC5 = posiC5 + coinflip();

                //Printing de pociciones de los caballos

                cout << posicion[0][posiC1] << "\n";
                cout << posicion[1][posiC2] << "\n";
                cout << posicion[2][posiC3] << "\n";
                cout << posicion[3][posiC4] << "\n";
                cout << posicion[4][posiC5] << "\n";

                // este if es para encontrar si uno de los caballos llegaron al final y de vuelve una variable que detemina el espacio del array y termina el loop
                if (posiC1 >= 5 or posiC2 >= 5 or posiC3 >= 5 or posiC4 >= 5 or posiC5 >= 5) {
                    if (posiC1 >= 5) {

                        winner = 0;
                        endRace = true;
                    }
                    else if (posiC2 >= 5) {

                        winner = 1;
                        endRace = true;

                    }
                    else if (posiC3 >= 5) {

                        winner = 2;
                        endRace = true;

                    }
                    else if (posiC4 >= 5) {

                        winner = 3;
                        endRace = true;
                    }
                    else if (posiC5 >= 5) {

                        winner = 4;



                        endRace = true;

                    }

                }
                else {


                    cout << "Cheer on your horse: " << "\n";


                    cin >> enter;

                    boost = enter.length();
                    if (boost > 10) {
                        
                       if (opcion == 1 and boostbool == false) {

                        posiC1 = posiC1 + 2;
                        boostbool = true;
                       }
                       else if (opcion == 2 and boostbool == false) {

                        posiC2 = posiC2 + 1;
                        boostbool = true;
                       }
                       else if (opcion == 3 and boostbool == false) {

                         posiC3 = posiC3 + 1;
                         boostbool = true;
                       }
                       else if (opcion == 4 and boostbool == false) {

                         posiC4 = posiC4 + 1;
                         boostbool = true;
                       }
                       else if (opcion == 5 and boostbool == false){

                        posiC5 = posiC5 + 1;
                        boostbool = true;
                       }
                       
                    }
                    system("CLS");
                }
            }
            //esto es para determinar si el caballo que escogiste gano restandole uno al opcion para que sea como el aray

            opcion = opcion - 1;
           
            if (opcion == winner) {

                    cout << "your horse won and you won the bet!!!! \n !!!!CONGRATULATIONS!!!!" << "\n";

                    winCon3 = true;
            
            }
            else {

                    cout << "Sadly your horse did not win, better luck next time. \n";

            }

            break;

        case 4:
           
            system("CLS");
           // this is a opcion to get out of the game
            cout << " thanks for trying the game i guess luck was not on your side -_-\n \n \n";

            if (winCon1 == true or winCon2 == true or winCon3 == true) {

                cout << "at least you won a game Good for you ;3 \n \n \n";

            }
            return 0;

        default:

            cout << "input invalid...\n";
            
            break;
        }


        
    }while (winCon1 == false or winCon2 == false or winCon3 == false);
    system("CLS");

    cout << "Congrats, you won all the games!!" << "\n \n \n";

    cout << "... what, were you expecting money? lol.\n \n \n";

    return 0;
}
