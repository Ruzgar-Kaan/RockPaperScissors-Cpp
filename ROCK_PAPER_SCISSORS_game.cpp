#include <iostream>
#include <ctime>

// Function declarations
char getUserChoice();            // Gets player's choice
char getComputerChoice();        // Generates computer's choice randomly
void showChoice(char choice);    // Prints the choice in readable format
void chooseWinner(char player, char computer); // Determines and prints the winner

int main(){
    char player;
    char computer;

    // Get the player's choice
    player = getUserChoice();
    std::cout << "Your choice: ";
    showChoice(player);

    // Generate computer's choice
    computer = getComputerChoice();
    std::cout << "Computer's choice: ";
    showChoice(computer);

    // Decide who wins
    chooseWinner(player, computer);

    return 0;
}

// Function to get the player's choice
char getUserChoice(){
    char player;
    std::cout << "Rock-Paper-Scissors Game!\n"; 

    // Loop until a valid choice is entered
    do{
        std::cout << "Choose one of the following\n"; 
        std::cout << "*************************\n"; 
        std::cout << "'r' for rock\n";
        std::cout << "'p' for paper\n";
        std::cout << "'s' for scissors\n";
        std::cin >> player;
    } while(player != 'r' && player != 'p' && player != 's');

    return player;
}

// Function to generate the computer's choice randomly
char getComputerChoice(){
    srand(time(NULL));              // Seed the random generator
    int num = rand() % 3 + 1;      // Random number between 1-3

    switch(num){
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's'; 
    }

    return 0;
}

// Function to display the choice in readable format
void showChoice(char choice){
    switch(choice){
        case 'r': std::cout << "Rock\n"; break;
        case 'p': std::cout << "Paper\n"; break;
        case 's': std::cout << "Scissors\n"; break;
    }
}

// Function to decide the winner
void chooseWinner(char player, char computer){
    switch(player){
        case 'r': 
            if(computer == 'r') std::cout << "It's a Tie!\n";
            else if(computer == 'p') std::cout << "You Lose!\n";
            else std::cout << "You Win!\n";
            break;

        case 'p': 
            if(computer == 'p') std::cout << "It's a Tie!\n";
            else if(computer == 's') std::cout << "You Lose!\n";
            else std::cout << "You Win!\n";
            break;

        case 's': 
            if(computer == 's') std::cout << "It's a Tie!\n";
            else if(computer == 'r') std::cout << "You Lose!\n";
            else std::cout << "You Win!\n";
            break;
    }
}
