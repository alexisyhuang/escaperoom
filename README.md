# COMP2113_group32
A brief identification of the team members.
@u3558426 : Cheung Dawn(3035584263) 
@alexisyhuang : Huang Alexis Yanyi (3033100984)
A game description with basic game rules.
The user wakes up to find himself/herself locked in the room. By chatting with the chatbot, the user can interact with the environment, and eventually escape from the room.
Features
Randomized room spawning— The items that the user can interact with will be randomised from a list of possible objects.(requirement 1) The randomised state of the room will be recorded on the output file so that the current state can be replicated when loading in the save file. (requirement 2)
Random events—There will also be an element of probability in the fact that chance that an interaction with an item will succeed is randomised. (For example, the probability of succeeding when trying to directly kick the door open would be 1 out of x, with x varying depending on the material of the door, which is randomly decided).(requirement 1)
Game progress saving/loading— Changes that are made to the room will be recorded in an output file that can be loaded to the game in order to continue where the user last left off.(requirement 4)
Effect of user interaction — After the user makes a decision in the game, the output file of the game that is used to record the current state of the room will be updated. For example, if the user chooses to make an irreversible decision of consuming a slice of cake, the variable that holds the status of the slice of cake would change from recording the fact that it is uneaten to that it is eaten. (requirement 3)
User interaction validity— When the user interacts with an object, there is a list of possible actions that can be performed on it. The chatbot will cross reference this list stored in a separate file to the user input when determining whether the user input is valid. (requirement 5)
