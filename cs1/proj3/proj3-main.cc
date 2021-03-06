/**********************************************************************
 * Project 3: Bulls and Cows
 *
 * This program is a guessing game the asks the user to guess randomly
 * generated numbers.  The computer gives the user hints in the from of
 * bulls and cows.  Specific instructions about gameplay are provided
 * as well.
 *
 * Author: Nicholas J. Primiano <nprimiano@fordham.edu>
 * Date: 5 March 2013
 *
 **********************************************************************/

//include standard libraries
#include <bjarne/std_lib_facilities.h>

//function to provide instructions for the user
void offer_help(vector<int>solution);
//function that runs one game
bool play_one_game(vector<int> solution);
//function that checks if given input is a cow or neither a bull or a cow
bool check_cows(vector<int> solution, 
		vector<int> guess_solution, int k, int game_length);

//the usual main function
int main(){
    //solution function to be passed into play_one_game
    vector<int> solution; 
    //variable to check if the user requests help
    int help;  
    //variable to check if the user wants to play again
    int play_again;
    //number of solutions and guesses
    const int game_length = 4;
    //range of numbers for random number generation
    const int random_range = 10;

    //asks if the user needs instructions before playing
    cout << "Need help? (0/1)? ";  					   
    cin >> help;
    if(!cin)  //general bad input check
	error("Bad input.  I give up!");
    if (help == 1)
	offer_help(solution); //runs function to provide instructions
				       
    //loop to generate random numbers and play again
    while(true){ 	
	vector<int> solution; //vector to hold solution	
	srand(time(0));  //seed random number generator
	//generate random numbers for solution
	for(int i = 0; i < game_length; ++i) {  	 
	    int random = randint (random_range);
	    //push_back random number to solution vector
	    solution.push_back(random);
	}

	if (play_one_game(solution))
	    //prints congratulatory message upon completion
	    cout << "Congratulations!" << endl;
        else {
	    //prints solution if the user enters a negative number
	    cout << "Too bad! Solution was ";
	    for(int i = 0; i < game_length; ++i){
		cout << solution[i] << " ";
	    }
	    cout << endl;
	}

	//asks user to play again after game completion
	cout << "Play again (0/1)? ";
 	cin >> play_again;
	if(!cin)  //general bad input check
	    error("Bad input data! I give up!");
	if (play_again == 0)
	    //closes program if the user no longer wants to play
	    return 0;   
    }
}

//play_one_game definition
bool play_one_game(vector<int> solution){
    int guess = 0;  //current guess value
    int guess_count = 1;  //current number of guesses in one game
    const int game_length = 4;  //number of solutions and guesses
    const int range = 9;  //range of number to guess between

    while (true) {
	int bull = 0;  //current number of bulls
	int cow = 0;  //current number of cows
	vector<int> guess_solution; // vector to hold user guesses
    
	cout << "Guess # " << guess_count << ":" << endl;
	for(int i = 0; i < game_length; ++i){   	    
	    cin >> guess;
	    if(!cin) //general bad input check
		error("Bad input.");
	    //adds acceptable guess to guess vector
	    guess_solution.push_back(guess);
	    //determines if the user entered extra numbers
	    if(guess_solution.size() > game_length){
		error("Out of range. Too many guesses");
	    }
	}

	//check for bulls then determine possible cows
	for(int k = 0; k < game_length; ++k){
	    //if negative input, return false and execute main()
	    if(guess_solution[k] < 0) {
		return false;
	    }	
	    if(solution[k] == guess_solution[k])
		++bull;  
	    else{
		if(check_cows(solution, guess_solution, k, game_length))
		    ++cow;
	    } 
	}

	//print current bulls and cows to the screen
	cout << bull << " bulls , " << cow << " cows" << endl;
	++guess_count;	// add to the number of guess rounds

	/*when all bulls are guessed, return true and continue
	  executing main()*/
	if(bull == game_length)
	    return true;  
    }
}

//funtion ot determine if a possible cow is a cow
bool check_cows(vector <int> solution, 
		vector<int> guess_solution, int k, int game_length){
    //if a possible cow is a cow return true, if not return false
    for (int i = 0; i < game_length; ++i){  
	if (guess_solution[k] == solution[i])
	    return true;
    }
    return false;
}

//function to offer instrutions to the user
void offer_help(vector<int>solution){
    //print instructions to the screen
    cout << endl   
	 << "I will generate a pattern of 4 numbers, " 
	 << "each in the range 0 through 9." << endl
	 << "You will give a series of guesses " 
	 << "of this pattern." << endl
	 << "Each guess that you enter will " 
	 << "be a line containing 4 integers," << endl
	 << "separated by spaces, such as" << endl
	 << "     2 4 3 1" << endl
	 << "I will respond with the number of bulls and cows." << endl
	 << "For example, if the actual solution"
	 << "was 2 3 6 1, I'll respond" << endl
	 << "     Bulls: 2, Cows: 1" << endl
	 << "since two guesses (2 and 1) were in the "
	 << "correct position" << endl
	 << "and one guess (3) was in an incorrect position." << endl
	 << "See how many guesses it takes you to get "
	 << "the solution!" << endl
	 << endl
	 << "If you want to give up, type a negative number "
	 << "for one of" <<  endl 
	 << "your guesses, and we'll tell you " 
	 << "what the pattern was." << endl
	 << endl;
}

