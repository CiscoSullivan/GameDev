# include <iostream>
# include <ctime>
void PrintIntroduction(int Difficulty)
{
// Print welcome messages to terminal
    std::cout << "\n\nYou are an idiot who forgot his three number safe combination. That's pretty dumb of you... Your Current difficulty level is: " << Difficulty; 
    std::cout << "\nYou need to guess the the correct sequence of nubmers, to access your BitCoin inside.\n\n";
    return;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    //Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty; //Maps the random value for int a to a range between 1-9, to prevent combined value of A B C from going beyond 1-999 range
    const int CodeB = rand() % Difficulty + Difficulty; //Difficulty increase causes the range of numbers to increase, resulting in potentially higher sums and products that are harder for player to compute.
    const int CodeC = rand() % Difficulty + Difficulty;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print sum and product to terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add up to: " <<  CodeSum;
    std::cout <<"\n+ The product of the codes is equal to: "<< CodeProduct << std::endl;

    //Store the players Guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessProduct = GuessA * GuessB * GuessC;
    int GuessSum = GuessA + GuessB + GuessC;

    //Check if player guess is correct
    if (GuessProduct == CodeProduct && GuessSum == CodeSum)
    {
        std::cout << "\nYou win!";
        std::cout <<"\n***You got the right answer!***";
        return true;
        
    }
    else
    {
        std::cout <<"\nWrong answer. Try again.";
        std::cout <<"\n***You must retry and pass this level to progress.***";
        return false;
        
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty) //Loops game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete)
        {
            //Increase the level difficulty
            ++LevelDifficulty;
        }
    }
    std::cout << "\nCongratulations, the game is complete!";
    return 0;
}
