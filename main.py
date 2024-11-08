import random
def get_random_number(low, high):
    return random.randint(low, high)

def play_game():
    while True:
        try:
            answer = int(input("Enter a number: "))
            break
        except ValueError:
            print("Invalid input. Please enter a whole number.")

    max_guesses = 20
    low = abs(answer) * -10
    high = abs(answer) * 10
    guesses = []

    for i in range(max_guesses):
        guess = get_random_number(low, high)
        while guess in guesses:
            guess = get_random_number(low, high)
        guesses.append(guess)

        print(f"Is {guess} the correct answer?")
        while True:
            response = input("y/n: ").lower()
            if response == "y":
                print("I win!")
                return
            elif response == "n":
                break
            else:
                print("Invalid input. Please enter y or n.")

        while True:
            hint = input("Is the correct answer higher or lower? (h/l): ").lower()
            if hint == "h":
                low = guess + 1
                break
            elif hint == "l":
                high = guess - 1
                break
            else:
                print("Invalid input. Please enter h or l.")

        if low > high:
            low, high = high, low

        print(f"Range: [{low}, {high}]")

    print("Out of guesses! You win!")

play_game()

def play_game_auto():
    while True:
        try:
            answer = int(input("Enter a number: "))
            break
        except ValueError:
            print("Invalid input. Please enter a whole number.")

    max_guesses = 20
    low = abs(answer) * -10
    high = abs(answer) * 10
    guesses = []

    for i in range(max_guesses):
        guess = get_random_number(low, high)
        while guess in guesses:
            guess = get_random_number(low, high)
        guesses.append(guess)

        print(f"Is {guess} the correct answer?")

        if guess == answer:
            print(f"i win after {i} guesses!")
            return
        elif guess < answer:
            print("Too low!")
            low = guess + 1
        else:
            print("Too high!")
            high = guess - 1

        print(f"Range: [{low}, {high}]")

    print("Out of guesses!")
