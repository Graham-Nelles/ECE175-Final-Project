1
ECE 175: Computer Programming for Engineering Applications 
Final Project: The card game – Losing Queen
Due Date: 4 PM Monday December 5, 2022 on zyBooks 
All due date: Group sign up - Tuesday November 22, 2022 by 11.59 pm 
Final project - Monday December 5, 2022 at 4.00 pm 
Administrative details: 
1.1 Group: You can work on this final project by yourself, or you can work in a group of 
(maximum) 2 students. If you choose to work as a group, use collaborative tools to 
facilitate the project development, such as replit.com, google doc, etc.
Sign up your team for the final project https://forms.gle/63rWJGARkEchyjcV6
Sign up even if you will work by yourself. The team/group must be signed-up by 11.59 
pm on November 22, 2022. No group can be formed after this date (unless approved by 
an instructor). You can check that your group signed up properly at 
https://docs.google.com/spreadsheets/d/1-
UG0UXwDnNuiifps3b5E27la0ZKJFZLC4myTkpTc4eE/edit?usp=sharing
1.2 Final Code Submission: The project is due on Monday December 5, 2022 at 4.00 pm. 
Both team members must submit the code on zyBooks. 
Late submission policy: 20% deduction per day. 
The last day of final project submission is by 4.00 PM on Wednesday December 7, 2022. 
After this date/time, the final project will NOT be accepted/graded. 
1.3 Academic Integrity Policy: Each team is expected to submit its own code. You may ask 
others for advice and/or discuss the project in general. However, you/your group MUST 
WRITE YOUR OWN CODE. 
If any part of the code submitted by different students or groups of students is identical, 
ALL involved parties will receive zero credit on the entire project and one letter 
reduction in their final grade. This policy will be very aggressively enforced. ALL 
submitted code will be checked with a plagiarism detection tool on zyBooks. 
1.4 Points distribution: See Rubric (page 6) for final project grading. 
1.5 Suggestions 
a) Spend time designing your code and use modular programming. Create all function
prototypes and describe what they do before developing your code. Create
pseudocode of your program. 
b) Determine test cases for your functions and your overall code to ensure proper
functionality.
c) Write well-documented code.
2
Background Information: 
Old Maid is a children card game that can be played by two or more players. We will use 
a standard deck of playing cards with only cards A, 2, 3, …, 10 and Queen of Heart to 
represent the Old Maid. 
The dealer deals one card at a time to each player proceeding clockwise until all the cards 
are dealt. Generally, some players will have more cards than others. The cards of one player are 
called a player’s hand. 
- The players then look at their cards and “discard” all their pairs (cards with the same face 
value (A, 2, 3 – 10)). Examples of a pair would be: 
The 9 of diamonds (♦) and the 9 of spades (♠) 
The Ace (1) of clubs (♣) and the Ace (1) of spades (♠) 
- After all matching pairs are discarded, the dealer begins by allowing the player on his/her 
left to choose one of his/her cards. The player selecting the card cannot see the card since 
he/she is only shown the backs of the cards. That player will take a card from the dealer 
and add it to his/her hand. If that card makes a pair, the player can discard the pair. That 
is the end of that player's turn. 
- Next that player offers his/her cards to the player on his/her left and the play continues 
(Note: the player is allowed to shuffle his/her hand before offering it to the player on 
his/her left). 
- This process of taking a card and discarding a pair (if the match occurs) continues until 
the player has no card left on his/her hand (get rid of all cards). Eventually all except one 
player will have no card. The player who is left holding a Queen of Heart card loses 
the game. 
Note: This game is a variant of the Old-maid card game which the background information is 
taken from http://en.wikipedia.org/wiki/Old_maid_(card_game). 
Project requirements: 
For this project your team will write a C program to implement this card game, for 
which you will use a standard deck of playing cards with only cards A, 2, 3, …, 10 and Queen 
of Heart.
There will be only 2 players, the computer (dealer) and one user/player. After the 
matching pairs are discarded, the hand with more cards will start first (choosing the card from 
the opponent). For example, after discarding the matching pairs, if a computer’s hand has 9 cards 
and the user’s hand has 6 cards, the computer will start first (choosing a card from the user’s 
hand) 
Play will continue with each player taking turns until one of the players is left with a 
Queen of Heart card in the hand. This player is the loser. 
3
Losing Queen card game 
Not using linked lists in your final project code results in 
0 point for this final project. 
2.1) A set of 41 cards and the hands of player and dealer 
2.1a) To simulate the set of 41 cards (A, 2, 3, … 10 with all 4 suits and Queen of Heart), and 
each hand, your team MUST use a dynamic list of cards with the following user-defined 
struct type: 
typedef struct card_s { 
char suit; 
int face; 
struct card_s *next; 
} card; 
Each card consists of a suit [clubs (♣),spades (♠),hearts (♥), or diamonds (♦)) 
a face (1(Ace), 2, 3, …, 10) and a Queen of Heart (Q♥) 
Each hand (computer/dealer or user) should be implemented using a linked list. The card 
removed from the hand should be removed from its linked list. 
Using a linked list to create a set of 41 cards that are in order. In other words, for each of 
the four suits, the cards should be in order from Ace (1) through 10 and a Queen of Heart. 
2.1b) Create and use a ShuffleCard( ) function to shuffle this set of 41 cards. You may use 
the algorithm below to perform cards shuffling: 
(a) For each card in the set, get a random number in the range of 0 to 40 to be used as the
index of the element to swap with that card, i.e.
if the first node holds the Ace of clubs (A♣) and the random number generated was
24, and the 24th node holds the 9 of diamonds (9♦), then after the first swap, the first
node now holds the 9 of diamonds (9♦), and the 24th node now holds the Ace of clubs
(A♣). Then proceed to the second node, find a random index of a card to swap with,
and swap those cards, etc.
(b) Repeat step (a) at least 1000 times.
Once your code is working, seed the random number generator with a call to time() with 
srand(). [see sec 2.24 Random numbers in your zyBooks] 
Note: Your code must have a ShuffleCard( ) function and should work with any 
numbers of cards, i.e., shuffling 41 cards, 10 cards or 5 cards. 
2.1c) After shuffling the set of 41-card, you deal the cards by giving one card to the 
user/player, followed by one card to the computer, followed by one card to the user, etc. 
until all of the cards have been dealt. 
2.1d) Next your program should remove all pairs from each of the players' hands and identify 
those pairs as the cards are being removed. Every time the pair is removed, your code should 
display it, i.e., 
Removing a pair: 6 of clubs and 6 of diamonds 
Note: The node must be properly removed from the linked list, otherwise, points will be 
deducted (see the grading rubric in this handout) 
4
2.1e) After the pairs are removed from both computer’s hand and the user’ hand, the user’s 
hand should be displayed, i.e., 
 John’s hand: //given that “John” was entered at the start of the game
9 of diamonds 
7 of clubs 
8 of diamonds 
King of clubs 
Jack of diamonds 
10 of diamonds 
2.2 How the game is played 
2.2a) The hand with the most numbers of cards will start first.
2.2b) Your code should display number of cards that the computer has and ask a user 
which card number to choose from, i.e. 
 Computer: I now have 7 cards: //a computer has 7 cards after discarding the pairs
 1 2 3 4 5 6 7 
 Which one do you choose? 
 Enter a number between 1 and 7: 0 //your code keeps asking until valid 
 Enter a number between 1 and 7: 10 //number is entered 
 Enter a number between 1 and 7: 1 // 1 is entered by a user
If the match occurs, display a message that the pair is removed and the user’s hand, i.e. 
 Removing a pair: King of clubs and the King of spades 
 John’s hand: 
 Jack of diamonds 
10 of diamonds 
8 of diamonds 
9 of diamonds 
7 of clubs 
 Note: If you compare the above with the hand under item 2.1e), you should see now 
that King of clubs is removed from John’s hand and the cards are shuffled. 
If the match does not occur, your code should shuffle the cards and display the cards. 
2.2c) After a player draws a card from the opponent's hand and places it into his/her hand 
(and discard the pair if a match occurs), whether the player is the computer or the user, the 
hand must be shuffled. This shuffling is necessary to keep the player from knowing where 
the Queen of Heart card is if it has just been drawn from the opponent's hand. 
2.2d) At the end of the game, your code 
- announce the winner or loser (The one with Queen of Heart is a loser); 
- ask whether a user wants to play a new game (or q or Q to quit) 
See sample code executions on pages 7 – 13 (there are 2 code execution samples) 
5
Optional Features for extra credit: 
Note: Each optional feature must be fully functional in your code to get the extra credit for that 
part. No partial credit will be given for somewhat functioning feature(s).
Make sure that your program is working correctly before attempting to do these bonus features. 
1) (+2 pt) Graphics: Add graphics to your game. Using ASCII art, your code can display the
cards as shown below. Note: this is a minimum requirement to get these bonus points.
Note: if your code does not print at least 5 cards on the same row as shown below, you
will not get bonus points for this part.
2) (+6 pts) Create a game with three hands (one computer hand and two player hands). Each
hand is implemented using a linked list.
Here are some hints that might help when working on the final project. 
1. Do not shuffle the cards right away! First, start using the sorted set of 41 cards to test
your matching algorithm (one to discard the pairs).
It is much easier to debug the code, knowing exactly which cards will be coming off the
set and moving into the hand(s).
When the program is working, then start shuffling the cards.
2. Write simple version(s) of the program first. You may want to start with a 10-card
version that you remove one card out and create two hands.
3. Make sure that your team a) Use Modular programming; b) Write well-documented code
c) Test your code (come up with suitable test cases) and
WRITE YOUR OWN CODE 
As stated in the final project handout, linked list must be used for this project. 0 point for final project if linked list is not used.
Criterion Maximum Points Exemplary (100%) Proficient (70%) Marginal (20%) Unacceptable (0%)
1
Create a 41‐card set 5 The program can create a 41‐card set (A – 10 of all 4 suits, Q of heart).
Correctly use a linked list to do this.
Deck is implemented as a linked list. However, the implementation is
incomplete, not all cards are present or the list is not properly
traversed
Some skeleton of a linked list exists but the code is not properly
compiled
The program cannot create a 41‐card set.
2 Deck or hand printing 3 The function can correct print the 41‐card set or the hand The 41‐card set or the hand is printed but the card format does not appear properly. There was an attempt to do this but not correctly function No code implementation for this part
3
Card shuffling 6 The program contain a function that can correctly and properly shuffle the
card based on the given algorithm and based on the time
(srand((int)time(0)))
The code can properly shuffle the cards but contain no function. Or
the code has some minor problems after shuffling is done or the cards
are not sufficiently shuffled.
The program attempts to shuffle the cards but can only do it a few
times. Or the code stops working after the shuffle
No code implementing cards shuffling
4
Card Dealing (computer
hand and player hand
(linked list is used)
7
Cards are dealt in the proper order. First, one card to the user, followed by
one card to the computer, one card to the user, etc. or vice versa. Linked list
is correcly created for each hand
The right number of cards is dealt, but not in a proper order. Linked
list is correcly created for each hand
Cards are not dealt correctly. Attempt to create a linked list but not
working
No code implementation for this part
5
Let a user enter a name and
propely print the name in
the game
2 Name can be entered and used throughout the game Name can be entered but used only once (not used throughout the game) No code implementation for this part
6
Card Matching (discarding a
pair) 18
Cards matching and discard is implemented correctly. All pairs are removed
and the hand is left with only cards with no pair. The node is properly
removed from the likned list
Cards matching and discard is implemented BUT (at most) 3 pairs are
not removed. The hand is left with cards that still have some pairs. Or
the node is not properly removed from the linked list (‐8 pts)
Cards matching and discard is implemented incorrectly No code implementation for this part
7 Game Turn (first time) 2
It can correct decide a turn based on number of cards on the hands after all
the matching pairs are discarded. For example, if computer's hand has more
cards, it gets to starts
Hard code one hand to always start first
8
Game Turn (during the
game) 4 The program can have the computer and player take turn draw a card There is an attempt of code but does not work No code implementation for this part
9 Choosing a card 5 The program has a code to keep asking until a user enter a valid card number the program only works when a user enter a valid card number and the program stops working if invalid card number is entered No code implementation for this part
10 Card drawing and matching 16
The computer and player's hand can be drawn correctly in each turn. The
pair is correctly discarded (if a match occurs) => The cards are REMOVED
from its linked list. If no match, the card can be correctly added to the list.
The computer and player's hand can be drawn correctly in each turn.
The pair is correctly discarded (if a match occurs). The cards are NOT
properly REMOVED from its linked list (‐6 pts). The card can be added
to the list if the match does not occur.
The chosen card is NOT drawn correctly from the hand. For example, a
user chooses card #3 but the first card is picked from the computer's
hand. Similar situation for a computer drawing a card from a player's
hand. The cards are NEVER removed from the linked list. The new card
canNOT be added to the list
The turn is not working. The card cannot be drawn
11
Hand shuffling (every turn
in the game) 4
Hands (both) are shuffled after every turn using correct number of cards on
the hand. The shuffling function produces a new sequence of cards in every
turn
1) only one hand (either computer or player); OR 2) Hands are
shuffled after every turn but using INcorrect number of cards on the
hand; OR 3) Attempt to shuffle for only 1‐2 cards on the hand
There is an attempt but it does not work Hands are not shuffled at every turn
12 Game end 6 The program can correctly end (when one hand has no card) and correctly decide the loser and displayed. The program can correctly end (when one hand has no card) but INcorrectly decide the loser and displayed. There is an attempt on ending the game or deciding a loser but not working. No code implementation for this part
13 Game continue 3 the next game continues if a user does not enter 'q' or 'Q' Only lower case 'q' works to quit or Only UPPERcase 'Q' works to quit There is an attempt but it does not work, the user cannot start a new
game
No code implementation for this part
14 Game Interface 5 The interface is intuitive. The user is able to play the game using the nagivation that the program provides The interface is intuitive for the most part. Some difficulty in understanding the game navigation. The interface is counter‐intuitive. Navigation options are not clearly stated. Interface limitations prevent proper game functionality. No code implementation for this part
Program Design
15 Code modularity 5 The code is logically divided to several functions that implement important functionality (shuffling, printing hand, etc.) The code is modular but further simplification could have been attempted The code only has a few functions (ones asked to implement: ShuffleCard( )). Most functionalities are integrated within the main function Code is not modular (all statements are written in main)
16 Code documentation 3
The code is properly documented. The input/output and goal of every
function is adequately described. Comments are provided for various parts
of the code
The code is partially documented The code is scarcely documented No documentation is provided
17 Compilation 6 Code succesfully compiles without errors or warnings. The code does not hang while in execution The code succesfully compiles, but some conditions may make it hang
(‐4 pts) Code does not compile
Total 100
Extra Credit
Graphics 2
Game with 3 players
(computer hand and 2
player hands)
6
8
ECE175‐‐Grading Rubric for Final Project
See Bonus points section of the final project handout for details
Exemplary (100%) ‐ NO PARTIAL CREDIT ‐ only get these extra credits if it works correctly
See Bonus points section of the final project handout for details
7
Note: 
- All sample code execution given below are a minimum requirement to give you an idea how 
the game should be implemented. The word “diamond”, “club”, “heart”, “spade” can be 
used in your code instead of symbols used below. 
- You are encouraged to make your game look more appealing than what is given below. 
However, your program should display very similar information for a user to be able to 
play the game. 
- It is VERY LIKELY that you will get DIFFERENT code execution (cards will be different) 
when running your program since rand() is used. 
Sample Code Execution #1 (The player lost twice): Bold/Red entered by a user
Enter your name: Wilbur
***---*** ***---*** ***---*** 
Wilbur, let's play Losing Queen 
***---*** ***---*** ***---*** 
Computer's hand: throw away pairs 
Remove pair:8♠ 8♦
Remove pair:9♠ 9♣
Remove pair:5♦ 5♠
Remove pair:6♣ 6♠
Remove pair:7♣ 7♥
Remove pair:2♠ 2♥
Remove pair:10♦ 10♣
Remove pair:4♥ 4♦
Computer: I now have 5 cards 
Wilbur's hand has 20 cards 
3♥ A♣ 7♦ 4♣ 3♦ 6♦ 9♦ 3♣
6♥ 5♥ 8♥ 7♠ 8♣ 2♦ 4♠ A♥
5♣ 3♠ A♦ 10♠
Wilbur's hand: throw away pairs 
Remove pair:3♥ 3♦
Remove pair:A♣ A♥
Remove pair:7♦ 7♠
Remove pair:4♣ 4♠
Remove pair:6♦ 6♥
Remove pair:3♣ 3♠
Remove pair:5♥ 5♣
Remove pair:8♥ 8♣
Wilbur, this is your hand: 
9♦ 2♦ A♦ 10♠
<= display the player’s hand after the cards are
distributed
<= display all the matching pairs on the computer
hand that get removed from the hand.   
Note: the nodes (cards) must be removed from
the linked list of the computer hand.
<= display number of cards that a computer has left
<= display the player’s hand after the matching pairs are discarded
<= display all the matching pairs on the player
hand that get removed from the hand.   
Note: the nodes (cards) must be removed from
the linked list of the player hand
8
***---***Hit Enter key to continue***---*** 
Wilbur, you have fewer cards, I start 
Computer: I choose card #3 from you 
Remove pair:A♠ A♦
Computer: I now have 4 cards 
Wilbur, this is your hand: 
9♦ 2♦ 10♠
***---***Hit Enter key to continue***---*** 
Computer: I now have 4 cards: 
 1 2 3 4 
Which one do you want to choose (1-4)?: 0
Computer: I have ONLY 4 cards 
Which one do you want choose (1-4)?: 7
Computer: I have ONLY 4 cards 
Which one do you want choose (1-4)?: 3
Remove pair:10♠ 10♥
Wilbur, this is your (Shuffled) hand: 
9♦ 2♦
***---***Hit Enter key to continue***---*** 
Computer: I choose card #1 from you 
Remove pair:9♥ 9♦
Computer: I now have 2 cards 
Wilbur, this is your hand: 
2♦
***---***Hit Enter key to continue***---*** 
I now have 2 cards: 
 1 2 
Which one do you want to choose (1-2)?: 2
<= Make sure that a user can only enter a valid card number
<= I create my own pause() function that make
it easier for a user to follow the game.
Your group can do as you want as long as the user
can follow your game!
Since the computer has more cards than Wilbur’s
hand, the computer starts the game by drawing
one card from Wilbur’s hand
The computer drew A♦ from Wilbur’s hand 
and get a pair of A♦ and A♠ which it can be 
removed. The computer’s hand now has 4 
(instead of 5) cards
<= display the player’s hand after the computer drew a
card. Observe that A♦ is removed from Wilbur’s hand 
Wilbur drew 10♥ from the computer hand and get a pair 
of 10♥ and 10♠ which can be removed. 
<= display the “shuffled” player’s hand after  
9
Wilbur, this is your (Shuffled) hand: 
Q♥ 2♦
***---***Hit Enter key to continue***---*** 
Computer: I choose card #1 from you 
Computer: I now have 2 cards 
Wilbur, this is your hand: 
2♦
***---***Hit Enter key to continue***---*** 
I now have 2 cards: 
 1 2 
Which one do you want to choose (1-2)?: 1
Wilbur, this is your (Shuffled) hand: 
Q♥ 2♦
***---***Hit Enter key to continue***---*** 
Computer: I choose card #1 from you 
Computer: I now have 2 cards 
Wilbur, this is your hand: 
2♦
***---***Hit Enter key to continue***---*** 
Computer: I now have 2 cards: 
 1 2 
Which one do you want to choose (1-2)?: 1
Wilbur, this is your (Shuffled) hand: 
2♦ Q♥
***---***Hit Enter key to continue***---*** 
Computer: I choose card #1 from you 
Remove pair:2♣ 2♦
Computer: I now have 0 cards 
Wilbur, this is your hand: 
Q♥
Sorry, you are a Losing Queen 
The game ends since the computer has 0 card and Wilbur is
left with Queen of Heart.
10
Do you want to continue? (q or Q to quit): y
Enter your name: John
***---*** ***---*** ***---*** 
John, let's play Losing Queen 
***---*** ***---*** ***---*** 
Computer's hand: throw away pairs 
Remove pair:2♥ 2♠
Remove pair:7♣ 7♦
Remove pair:5♣ 5♠
Remove pair:3♦ 3♠
Remove pair:8♠ 8♣
Remove pair:9♥ 9♣
Remove pair:4♣ 4♥
Computer: I now have 7 cards 
***---***Hit Enter key to continue***---*** 
John's hand has 20 cards 
10♥ 5♦ 7♠ 3♥ 9♠ A♥ Q♥ 4♠
A♣ 6♦ 2♣ 6♥ 5♥ 10♣ 8♥ 3♣
6♣ A♦ 8♦ 10♠
John's hand: throw away pairs 
Remove pair:10♥ 10♣
Remove pair:5♦ 5♥
Remove pair:3♥ 3♣
Remove pair:A♥ A♣
Remove pair:6♦ 6♥
Remove pair:8♥ 8♦
John, this is your hand: 
7♠ 9♠ Q♥ 4♠ 2♣ 6♣ A♦ 10♠
***---***Hit Enter key to continue***---*** 
John, you have more cards, you start 
***---***Hit Enter key to continue***---*** 
Computer: I now have 7 cards: 
 1 2 3 4 5 6 7 
Which one do you want to choose (1-7)?: 9
Computer: I have ONLY 7 cards 
Which one do you want choose (1-7)?: 6
Your program asks if a user want to continue. If q
or Q is not entered, your program starts over by
asking a user to enter a new name.
Since John has more cards than the computer,
John starts the drawing. The computer asks John
which card of the computer hand John wants
11
Remove pair:4♠ 4♦
John, this is your (Shuffled) hand: 
9♠ 7♠ 2♣ 6♣ A♦ Q♥ 10♠
***---***Hit Enter key to continue***---*** 
Computer: I choose card #2 from you 
Remove pair:7♥ 7♠
Computer: I now have 5 cards 
John, this is your hand: 
9♠ 2♣ 6♣ A♦ Q♥ 10♠
***---***Hit Enter key to continue***---*** 
Computer: I now have 5 cards: 
 1 2 3 4 5 
Which one do you want to choose (1-5)?: 2
Remove pair:10♠ 10♦
John, this is your (Shuffled) hand: 
2♣ Q♥ 6♣ A♦ 9♠
***---***Hit Enter key to continue***---*** 
Computer: I choose card #1 from you 
Remove pair:2♦ 2♣
Computer: I now have 3 cards 
John, this is your hand: 
Q♥ 6♣ A♦ 9♠
***---***Hit Enter key to continue***---*** 
Computer: I now have 3 cards: 
 1 2 3 
Which one do you want to choose (1-3)?: 1
Remove pair:9♠ 9♦
John, this is your (Shuffled) hand: 
A♦ 6♣ Q♥
12
***---***Hit Enter key to continue***---*** 
Computer: I choose card #1 from you 
Remove pair:A♠ A♦
Computer: I now have 1 cards 
John, this is your hand: 
6♣ Q♥
***---***Hit Enter key to continue***---*** 
Computer: I now have 1 cards: 
 1 
Which one do you want to choose (1-1)?: 1
Remove pair:6♣ 6♠
Sorry, you are a Losing Queen 
Do you want to continue? (q or Q to quit): Q
Good Bye 
Sample Code Execution #2 (The player wins): Bold/Red entered by a user
Enter your name: Sue
***---*** ***---*** ***---*** 
Sue, let's play Losing Queen 
***---*** ***---*** ***---*** 
Computer's hand: throw away pairs 
Remove pair:6♣ 6♠
Remove pair:9♠ 9♦
Remove pair:3♠ 3♦
Remove pair:7♥ 7♣
Remove pair:10♣ 10♥
Remove pair:6♦ 6♥
Remove pair:5♣ 5♦
Remove pair:4♠ 4♥
Computer: I now have 5 cards 
***---***Hit Enter key to continue***---*** 
Sue's hand has 20 cards 
5♥ 4♣ 8♣ 10♠ 9♣ 5♠ 7♠ 3♥
7♦ 2♣ A♠ A♦ 10♦ 8♠ 4♦ 2♥
8♥ 2♦ A♣ 3♣
Sue's hand: throw away pairs 
Remove pair:5♥ 5♠
Remove pair:4♣ 4♦
Remove pair:8♣ 8♠
13
Remove pair:10
♠ 10
♦
Remove pair:7
♠ 7
♦
Remove pair:3
♥ 3
♣
Remove pair:2
♣ 2
♥
Remove pair:A
♠ A
♦
Sue, this is your hand: 9♣ 8♥ 2♦ A♣
***---***Hit Enter key to continue***---*** 
Sue, you have fewer cards, I start 
***---***Hit Enter key to continue***---*** 
Computer: I choose card #3 from you 
Remove pair:2
♠ 2
♦
Computer: I now have 4 cards 
Sue, this is your hand: 9♣ 8♥ A♣
***---***Hit Enter key to continue***---*** 
Computer: I now have 4 cards: 
 1 2 3 4 
Which one do you want to choose (1-4)?: 
1
Remove pair:8
♥ 8
♦
Sue, this is your (Shuffled) hand: 9♣ A♣
***---***Hit Enter key to continue***---*** 
Computer: I choose card #1 from you 
Remove pair:9
♥ 9
♣
Computer: I now have 2 cards 
Sue, this is your hand: A♣
***---***Hit Enter key to continue***---*** 
Computer: I now have 2 cards: 
 1 2 
Which one do you want to choose (1-2)?: 
2
Remove pair:A
♣ A
♥
Congratulations, you won. I am a Losing Queen 
Do you want to continue? (q or Q to quit): 
Q
Good Bye 
