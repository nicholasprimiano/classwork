import java.util.Scanner;

/**
 * A class that implements the abstract methods of <code>Abstract
 * HangmanClient</code>.
 * <p>
 * It provides a text-based interface, as well as a
 * <code>main()</code> method, giving an executable program.
 *
 * @author Nicholas Primiano
 * @version 2.0, 8 May 2014
 */

public class TextHangmanClient extends AbstractHangmanClient
{
  
  /**
   * The constructor for the <code>TextHangmanClient</code> class.
   * 
   * @param debugging True iff debugging output is enabled
   * @param serverName The host on which the hangman server resides
   * @param portNumber The port number on which the server is
   * listening
   */
  public TextHangmanClient(boolean debugging, String serverName, 
			   int portNumber)
  {
    super(debugging, serverName, portNumber);
  }

  /**
   * Obtain a guess from the user.
   * 
   * @return an uppercase letter for a GUESS
   */
  public char elicitGuess()
  {
    Scanner reader = new Scanner(System.in);
    String input;
    while (true) {
      System.out.println("Letter ? ");   
      input = reader.next().toUpperCase();
      // first char of input
      if (super.wordsSoFar.indexOf(input.substring(0, 1)) >= 0)
	System.out.println("Already guessed " + input.substring(0, 1));
      else
	return input.charAt(0);
    }
  } 

  /**
   * Display the current game state
   */
  public void displayGame()
  {
    System.out.println("Word: " + wordsSoFar); 
    System.out.println("Incorrect Guesses Remaining: " + guessesRemaining);   
  }

  /**
   * Congratulate the winner on her acumen.
   */
  public void congratulateWinner()
  {
    System.out.println("Word was: " + correct);
    System.out.println("Congratulations! You got the word!");
  }
  /**
   * Player didn't guess the word; hang him.
   */
  public void punishLoser()
  {
    System.out.println("Sorry you lose.");
    System.out.println("Word was: " + correct);
  }

  /**
   * Find out whether we want to play again.
   * 
   * @return true or false, according to whether we want to play again
   * or not
   */
  public boolean elicitPlayAgain()
  {
    while (true){
      System.out.println("Another game (Y/N)?");
      Scanner reader = new Scanner(System.in);
      String input;
      input = reader.next();
      if (input.equalsIgnoreCase("yes") || 
	  input.equalsIgnoreCase("y"))
	return true;
      else if (input.equalsIgnoreCase("no") || 
	       input.equalsIgnoreCase("n"))
	return false;
      System.out.println("Bad input try again.");
    }
  }

  /**
   * <p>The usual <code>main()</code> function, which gets things 
   * rolling.</p>
   * 
   * <p>After parsing the command line, it invokes the constructor 
   * for this class. That's it! Optional command line parameter:</p>
   * <ul>
   *    <li> Flag -d: enable debug output</li>
   *    <li>Flag -h: print help message </li>
   *    <li>Name of alternate Hangman server </li>
   * </ul>
   * <p>Any other flags (e.g., -x) will cause the help message 
   * to be printed, along with an error exit.</p>
   */
  public static void main(String args[])
  {
    String server = HANGMAN_DEFAULT_SERVER;
    boolean debugging = false;
    int currentArg = 0;                 // current argument number

    if (args.length > 0)                // look for flags
      if (args[0].charAt(0) == '-') {
	currentArg++;
	switch (args[0].charAt(1)) { // what's the flag?
	case 'd':
	  debugging = true;
	  break;
	case 'h':                   // ask for help
	  usage();
	  System.exit(0);
	default:                      // illegal flag
	  usage();
	  System.exit(1);
	}
      }
    if (args.length > currentArg)       // alternate server?
      server = args[currentArg];

    // okay, here we go!!
    new TextHangmanClient(debugging, server, HANGMAN_DEFAULT_PORT);
  }

  /**
   * Print usage message
   */
  public static void usage()
  {
    System.err.println("Usage: HangmanServer [-d] [-h] [server]");
    System.err.println("  -d: print debugging info");
    System.err.println("  -h: print this help msg");
  }  
} // TextHangmanClient
