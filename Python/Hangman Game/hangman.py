import random
from words_alpha import dictionary


def load_words():
    difficulty = input("Choose Difficulty: (Easy, Medium, Hard): ")
    if difficulty.upper() == "EASY":
        word = random.choice(dictionary)
        while len(word) > 4:
            word = random.choice(dictionary)
    if difficulty.upper() == "MEDIUM":
        word = random.choice(dictionary)
        while len(word) > 8:
            word = random.choice(dictionary)
    if difficulty.upper() == "HARD":
        word = random.choice(dictionary)
        while len(word) < 7:
            word = random.choice(dictionary)    
    return word.upper()

def play(word):
    word_display = "-" * len(word)    # Displays an underscore relative to the ammount of letters in the word
    guessed = False
    guessed_letters = []
    guessed_words = []
    tries = 6
    print("Guess the Word")
    print(display_hangman(tries))
    print(word_display)
    print("\n")
    # Main While Loop
    while not guessed and tries > 0:
        guess = input("Guess a letter or word: ").upper()
        if len(guess) == 1 and guess.isalpha():
            if guess in guessed_letters:
                print("This letter was already guessed. Try another.")
                print(*guessed_letters, sep = ", ")
            
            elif guess not in word:
                print(guess, "is not in the word.")
                tries -= 1
                guessed_letters.append(guess)
                guessed_letters.sort()
                print(*guessed_letters, sep = ", ")
            
            else:
                print(guess, "is in the word.")
                guessed_letters.append(guess)
                guessed_letters.sort()
                print(*guessed_letters, sep = ", ")
                # Transforms the word into a list
                word_to_list = list(word_display)
                # Allows for the traversal through the word
                indicies = [i for i, letter in enumerate(word) if letter == guess]
                for index in indicies:
                    word_to_list[index] = guess
                word_display = "".join(word_to_list)
                if "-" not in word_display:
                    guessed = True

        elif len(guess) == len(word) and guess.isalpha():
            if guess in guessed_words:
                print("This word was already guessed. Try again.")
            
            elif guess != word:
                print(guess, "is not the correct word.")
                tries -= 1
                guessed_words.append(guess)
                
            else:
                guessed = True
                word_display = word
        else:
            print("Enter a valid guess.")
        
        print(display_hangman(tries))
        print(word_display)
        print("\n")
    
    if guessed:
        print(word + " is the correct word.")
    
    else:
        print("Try limit exceeded. " + word + " was the correct word.")



def display_hangman(tries): # Prints the stage of Hangman
    stages = [ 
                """
                   --------
                   |      |
                   |      O
                   |     \\|/
                   |      |
                   |     / \\
                  ---
                """,
                """
                   --------
                   |      |
                   |      O
                   |     \\|/
                   |      |
                   |     / 
                  ---
                """,
                """
                   --------
                   |      |
                   |      O
                   |     \\|/
                   |      |
                   |      
                  ---
                """,
                """
                   --------
                   |      |
                   |      O
                   |     \\|
                   |      |
                   |     
                  ---
                """,
                """
                   --------
                   |      |
                   |      O
                   |      |
                   |      |
                   |     
                  ---
                """,
                """
                   --------
                   |      |
                   |      O
                   |    
                   |      
                   |     
                  ---
                """,
                """
                   --------
                   |      |
                   |      
                   |    
                   |      
                   |     
                  ---
                """
    ]
    return stages[tries]

def main():
    word = load_words()
    play(word)
    while input("Another Round? (Y/N) ").upper() == "Y":
        word = load_words()
        play(word)

if __name__ == "__main__":  # Needed in order to run the code on the command line
    main()