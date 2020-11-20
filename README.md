# COMP2113_group32

### A brief identification of the team members.

- @u3558426 : Cheung Dawn(3035584263)
- @alexisyhuang : Huang Alexis Yanyi (3033100984)

### A game description with basic game rules.
The user wakes up to find himself/herself locked in a room. By chatting with the chatbot, using simple sentances, the user can interact with the environment, and eventually escape from the room.

### Code Requirement Fulfillments
- **1. Generation of random game sets or events** - If the user chooses not to continue a game from a previous save file, a new escape room is generated with randomization in what objects appear in the room. This is implemented with rand() and choosing a random index of an array with possible choices for the randomized elements, such as the type of animal and decoration that appears in the room.

- **2. Data structures for storing game status** - Each object in the game is implemented as a myitem object, which has variables such as knowExistence and inPossession that are updated as the user interacts with the objects in order to constantly update the progress made in the game. 

- **3. Dynamic memory management** - A vector is used to read from the savefile txt and resume the game from where the user last left off.

- **4. File input/output** - savefile.txt is used for saving and loading the game status, where the properties of all of the objects in the master array all_items are printed. To read from the file, a vector is used to reassign these properties to the objects.

- **5. Program code in multiple files** - The game is split up into multiple files, notably structure.h that contains the myitem structure that all of the objects are created from, and chatbot.cpp which is used to allow user interaction with the objects in the escape room.

### Features
- **Randomized room spawning** - The items that the user can interact with will be randomised from a list of possible objects.(requirement 1) The randomised state of the room will be recorded on the output file so that the current state can be replicated when loading in the save file. (requirement 2)

- **Random events** — There will also be an element of probability in the fact that chance that an interaction with an item will succeed is randomised. (For example, the probability of succeeding when trying to directly kick the door open would be 1 out of x, with x varying depending on the material of the door, which is randomly decided).(requirement 1)

- **Game progress saving/loading** — Changes that are made to the room will be recorded in an output file that can be loaded to the game in order to continue where the user last left off.(requirement 4)

- **Effect of user interaction** — After the user makes a decision in the game, the output file of the game that is used to record the current state of the room will be updated. For example, if the user chooses to make an irreversible decision of consuming a slice of cake, the variable that holds the status of the slice of cake would change from recording the fact that it is uneaten to that it is eaten. (requirement 3)

- **User interaction validity** — When the user interacts with an object, there is a list of possible actions that can be performed on it. The chatbot will cross reference this list stored in a separate file to the user input when determining whether the user input is valid. (requirement 5)
