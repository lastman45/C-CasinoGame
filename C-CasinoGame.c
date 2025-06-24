#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Include for input/output and random number generation

int round(int deposit);
int rules();

int main()
{
    srand(time(NULL)); // Seed the random number generator
    rules();

    printf("\n\n");
    int initialDeposit;
    printf("Please enter your initial deposit amount: ");
    scanf("%d", &initialDeposit);
    if (initialDeposit < 0)
    {
        printf("Invalid deposit amount. Please enter a positive number.\n");
        return 1; // Exit if the deposit is invalid
    }

    round(initialDeposit); // Start the first round with the initial deposit

    return 0;
}

int round(int deposit)
{
    char name[50];
    printf("\n***CASINO GAME***\n");
    printf("\nPlease enter your name: ");
    scanf("%s", name);

    printf("\n\n");
    printf("Hello %s, your current balance is: $%d\n", name, deposit);

    int bet;
    while (1) // Loop until a valid bet is entered
    {
        printf("%s, Please enter your bet amount: $", name);
        scanf("%d", &bet);
        if (bet <= 0 || bet > deposit)
        {
            printf("\nInvalid bet amount. Please enter a positive number that does not exceed your deposit.\n");
        }
        else
        {
            break; // Exit the loop if the bet is valid
        }
    }

    printf("You have placed a bet of: $%d\n", bet);
    printf("You are now ready to play the game!\n");

    int computer = rand() % 10 + 1; // Random number between 1 and 10
    int guess;
    printf("Guess a number between 1 and 10: \n");
    scanf("%d", &guess);
    while (guess < 1 || guess > 10)
    {
        printf("Invalid guess. Please enter a number between 1 and 10: \n");
        scanf("%d", &guess);
    }
    printf("You guessed: %d\n", guess);

    if (guess == computer)
    {
        printf("Congratulations %s! You guessed the correct number: %d\n", name, computer);
        printf("You win $%d!\n", bet * 2);
        deposit += bet; // Update the deposit with the winnings
    }
    else
    {
        printf("Sorry %s, the correct number was: %d\n", name, computer);
        printf("You lose your bet of $%d.\n", bet);
        deposit -= bet; // Update the deposit with the loss
    }
    printf("Your final balance is: $%d\n", deposit);

    if (deposit <= 0)
    {
        int restart;
        printf("You have lost all your money. Would you like to restart the game? (1 for Yes, 0 for No): \n");
        scanf("%d", &restart);
        if (restart == 1)
        {
            printf("Please enter your initial deposit amount: \n");
            scanf("%d", &deposit);
            if (deposit < 0)
            {
                printf("Invalid deposit amount. Please enter a positive number.\n");
                return 1; // Exit if the deposit is invalid
            }
            return round(deposit); // Restart the game with the new deposit
        }
        else
        {
            printf("Thank you for playing, %s! Your final balance is: $%d\n", name, deposit);
            return 0; // Exit the game
        }
    }

    int newGame;
    printf("Do you want to play another round? (1 for Yes, 0 for No): \n");
    scanf("%d", &newGame);
    if (newGame == 1)
    {
        printf("Starting a new round...\n");
        return round(deposit); // Start a new round with the updated balance
    }
    else
    {
        printf("Thank you for playing, %s! Your final balance is: $%d\n", name, deposit);
        return 0; // Exit the game
    }
}

int rules()
{
    printf("***CASINO GAME***\n");
    printf("\nHere are the rules:\n");
    printf("1. You will start by entering a Deposit Amount and your Username\n");
    printf("2. You can place a bet, which must be less than or equal to your deposit.\n");
    printf("3. You will guess a number between 1 and 10.\n");
    printf("4. If you guess correctly, you win double your bet; otherwise, you lose your bet.\n");
    printf("5. You can choose to play another round or exit the game.\n");
    return 0;
}
