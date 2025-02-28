#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>

std::string catName = "Luna";
int catHunger = 0;
int catThirst = 0;
int catHappyness = 5;
int state = 0; // 0 - running, 1 - waiting
bool catSleeping = false;
bool quit = false;

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void printCat() {
    std::cout << "\e[39;49;1m                " << catName << "\e[0m" << std::endl;
    if (catHunger < 7 && catThirst < 7 && !catSleeping) {
        std::cout << std::endl;
        std::cout << "          ##          ##                        " << std::endl;
        std::cout << "        ##  ##      ##  ##                      " << "Honger: \e[1m" << catHunger << "/10\e[0m" << std::endl;
        std::cout << "        ##    ######      ##########            " << "Dorst: \e[1m" << catThirst << "/10\e[0m" << std::endl;
        std::cout << "      ##                            ####        " << "Blijheid: \e[1m" << catHappyness << "/10\e[0m" << std::endl;
        std::cout << "  ######                  ####          ##      " << std::endl;
        std::cout << "      ##  ##    ##    ##                  ##    " << std::endl;
        std::cout << "  ####        ######      ####            ##    " << "1) Voeder" << std::endl;
        std::cout << "    ##                                      ##  " << "2) Water" << std::endl;
        std::cout << "    ##                                      ##  " << "3) Spelen" << std::endl;
        std::cout << "    ##                                      ##  " << "4) Wachten" << std::endl;
        std::cout << "    ##                                      ##  " << std::endl;
        std::cout << "    ##                                ##    ##  " << "5) Stoppen" << std::endl;
        std::cout << "      ##                        ######    ##    " << std::endl;
        std::cout << "        ##                    ##        ##      " << std::endl;
        std::cout << "          ##############################        " << std::endl;
    }
    std::cout << std::endl;
    if (state == 1) {
        std::cout << "._____________________________________________________________________________________." << std::endl;
        std::cout << "|                                                                                     |" << std::endl;
        std::cout << "|                                     Wachten...                                      |" << std::endl;
        std::cout << "|_____________________________________________________________________________________|" << std::endl;
    }
    else if (state == 2) {
        std::cout << "._____________________________________________________________________________________." << std::endl;
        std::cout << "|                                                                                     |" << std::endl;
        std::cout << "|                                     Spelen...                                       |" << std::endl;
        std::cout << "|_____________________________________________________________________________________|" << std::endl;
    }
    else if (state == 3) {
        std::cout << "._____________________________________________________________________________________." << std::endl;
        std::cout << "|                                                                                     |" << std::endl;
        std::cout << "|        Je kat kan niet spelen omdat hij niet genoeg energie heeft, voer hem.        |" << std::endl;
        std::cout << "|_____________________________________________________________________________________|" << std::endl;
    }
    else if (state == 4) {
        std::cout << "._____________________________________________________________________________________." << std::endl;
        std::cout << "|                                                                                     |" << std::endl;
        std::cout << "|                             Je kat heeft geen honger.                               |" << std::endl;
        std::cout << "|_____________________________________________________________________________________|" << std::endl;
    }
    else if (state == 5) {
        std::cout << "._____________________________________________________________________________________." << std::endl;
        std::cout << "|                                                                                     |" << std::endl;
        std::cout << "|                                   Eten geven...                                     |" << std::endl;
        std::cout << "|_____________________________________________________________________________________|" << std::endl;
    }
    else if (state == 6) {
        std::cout << "._____________________________________________________________________________________." << std::endl;
        std::cout << "|                                                                                     |" << std::endl;
        std::cout << "|                                   Water geven.                                      |" << std::endl;
        std::cout << "|_____________________________________________________________________________________|" << std::endl;
    }
    else if (state == 7) {
        std::cout << "._____________________________________________________________________________________." << std::endl;
        std::cout << "|                                                                                     |" << std::endl;
        std::cout << "|                              Je kat heeft geen dorst.                               |" << std::endl;
        std::cout << "|_____________________________________________________________________________________|" << std::endl;
    }
}

std::string askCatName() {
    std::string name;
    std::cout << "Hoe wil je je kat noemen?" << std::endl << "> ";
    std::cin >> name;
    return name;
}

void render() {
    clearScreen();
    printCat();
    std::string awnser = "";
    std::cin >> awnser;
    switch (std::stoi(awnser)) {
        case 1: 
            std::cout << "1";
            state = 5;
            clearScreen();
            printCat();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            if (catHunger == 0) {
                state = 4;
                clearScreen();
                printCat();
                std::this_thread::sleep_for(std::chrono::seconds(5));
            }
            else {
                catHunger--;
            }
            state = 0;
            break;
        case 2:
            std::cout << "2";
            state = 6;
            clearScreen();
            printCat();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            if (catThirst == 0) {
                state = 7;
                clearScreen();
                printCat();
                std::this_thread::sleep_for(std::chrono::seconds(5));
            }
            else {
                catHunger--;
            }
            state = 0;
            break;
        case 3:
            std::cout << "3";
            state = 2;
            clearScreen();
            printCat();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            if (catHunger > 7) {
                state = 3;
                clearScreen();
                printCat();
                std::this_thread::sleep_for(std::chrono::seconds(5));
            }
            else if (catHappyness < 10) {
                catHappyness++;
                catHunger+=random()%2 + 1;
            }
            state = 0;
            break;
        case 4:
            std::cout << "4";
            state = 1;
            clearScreen();
            printCat();
            std::this_thread::sleep_for(std::chrono::seconds(5));
            state = 0;
            break;
        case 5:
            quit = true;
            return;
        default:
            break;
        
        int randomAction = random()%4 + 1;
        switch (randomAction) {
            case 1:
                break;
            case 2:
                if (catHunger < 10) {
                    catHunger++;
                }
                break;
            case 3:
                if (catThirst < 10) {
                    catThirst++;
                }
                break;
            case 4:
                if (catHappyness < 10) {
                    catHappyness--;
                }
                break;
        }
    }
}

int main() {
    clearScreen();
    catName = askCatName();
    clearScreen();
    while (!quit) {
        render();
    }
    return 0;
}