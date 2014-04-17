// Done by TheTutor -- 10/28/01

/*  If case you haven't noticed by now, there are lots of ways to 
	do the "same thing" when programming.  This tutorial is going to 
	go over "reading from a file" once again.

	So to read in from a file (our file will be a .txt file) there's 
	a few basic steps:

	1)  Create an ifstream (an ifstream stands for "input file stream" -- You use
		an ifstream to read in "data" from a file)

    2)  Open the file (we have our "ifstream", now we open a file and associate it
		with the "ifstream", this is the only way the "ifstream" knows where to read from)

	3)  Read the data (read the "data" into our program that we want)

	4)  Close the ifstream (when we don't need the "ifstream" anymore, be sure we close it
		and free up the memory associated with it)

	So with that lets get reading in some files...

*/

#include <iostream> // So we can use "cout"
#include <string> // So we can declare and use a "string" variable
#include <fstream> // We include this header file so we can declare and use a variable of
				  // type "ifstream" -- You will need to #include <fstream> when you want
				 // to read or write to a file

using namespace std; // We're using (and we'll always be using) the "standard namespace"

// Our main function (ie the CORE of our program)
int main()
{
	ifstream file_in("GT.txt");  // So what is this doing?  Well this is combining steps
								// 1 and 2 from above -- First we are creating a variable
							   // of type "ifstream" (we named it "file_in") -- Then at 
							  // same time (using a constructor which you'll get to when
							 // you get to classes :) we open the file we want our "ifstream"
						    // to read from -- The file is named "GT.txt" (it's a text file)

		// Error Check
		if(!file_in)
			return 1; // If we could NOT open the file (for whatever reason) we quit the
					 // program immediately -- Notice the syntax:  !file_in
					// This returns TRUE if "file_in doesn't have a valid file 
				   // associated with it"

	// If we get here, we've opened "GT.txt" and we're ready to read from it

	string a_word; // Here we're creating the string "a_word" -- We will use
				  // "a_word" to read in from the file we just opened each word (ie an English
				 // word for instance "hippopotamus") of the file until we reach the end of 
				// the file

	// Using the while loop, we're going to do step 3 from above
	// This says "while we have NOT reached the end of the file, keep looping"
	while(!file_in.eof())
	{
		file_in >> a_word; // Here we read in a "word"

		cout << a_word; // Now we're simply regurgitating the word we read in to the screen

		cout << " "; // *Note* we have to put a space between the "words" -- When we 
					// create an ifstream and read in a "string" the way we are, all white 
				   // space will get skipped over.  So for example say our text file looked
				  // like this:

				// My name is                  TheTutor

			    // After the first file read, a_word will equal "My"
			    // After the second file read, a_word will equal "name"
			    // After the third file read, a_word will equal "is"
			    // After the fourth file read, a_word will equal "TheTutor"
			   
			    // So you see all the white space (spaces or tabs) is skipped
	}

	file_in.close(); // Lastly we do step 4 from above an close the file (we're done with it)

	return 0;
}

// I hope this clears up "file reading" some.  As always, any questions can be directed to
// www.GameTutorials.com

/*----------------------------*\
|  TheTutor                    |
|  thetutor@gametutorials.com  |
|  © 2000-2003 GameTutorials   |
\*----------------------------*/

