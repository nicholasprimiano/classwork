/**********************************************************************
 * 
 * Project 5: Operator Overloading
 *
 * Author: Nicholas J. Primiano <nprimiano@fordham.edu>
 * Date:
 *
 * Say something here.
 *
 **********************************************************************/
#include <bjarne/std_lib_facilities.h>

// This is where you'll define the Name_pair class and declare the
// global functions that provide the operations you're supposed to
// implement. 

struct Name_pair{
    string name;
    int age;
};

Name_pair operator>>(istream& input, const Name_pair& np);
ostream operator<<(ostream& output,const Name_pair& np);

bool operator==(const Name_pair& np0, const Name_pair& np1);
bool operator!=(const Name_pair& np0, const Name_pair& np1);
bool operator<(const Name_pair& np0, const Name_pair& np1);

// The usual main function
int main()
{
    cout << "Equality/inequality test.\n";
    while (true){
	cout << "Enter two name pairs.\n";

	cout << "#0? "; 
	Name_pair np0;
	cin >> np0;

	cout << "#1? ";
	Name_pair np1;
	cin >> np1;

	if (np0 == np1)
	    cout << np0 << " equals " << np1 << endl;
	if (np0 != np1)
	    cout << np0 << " does not equal " << np1 << endl;

	cout << "Try again (0/1)? ";
	int try_again;
	cin >> try_again;
	if (try_again == 0)
	    break;
	else
	    cout << endl;
    }

    cout << "\nSorting test.  "
	 << "How many name pairs do you want to test? ";
    int num_pairs;
    cin >> num_pairs;
    if (num_pairs <= 0)
	error("Number of name pairs must be positive!  Good-bye!");

    cout << "Please enter the name pairs (one per line).\n";
    vector<Name_pair> pairs(num_pairs);
    for (int i = 0; i < num_pairs; i++) {
	cout << "#" << i << "? ";
	cin >> pairs[i];
    }
    cout << endl;

    cout << "Here are the name pairs you entered:\n";
    for (unsigned int i = 0; i < pairs.size(); i++)
	cout << pairs[i] << endl;
    cout << endl;

    cout << "Here are the name pairs, sorted alphabetically:\n";
    sort(pairs.begin(), pairs.end());
    for (unsigned int i = 0; i < pairs.size(); i++)
	cout << pairs[i] << endl;
}

Name_pair operator>>(istream& input, const Name_pair& np)
{

    input >> Name_pair.name;
    input >> Name_pair.age;
    return input;
}

ostream operator<<(ostream& output, const Name_pair& np)
{
    output << Name_pair.name;
    output << Name_pair.age;
    return output;


}

bool operator==(const Name_pair& np0, const Name_pair& np1)
{
    if((np0.name == np1.name) && (np0.age == np1.age))
	return true;
    else 
	return false;
}


bool operator!=(const Name_pair& np0, const Name_pair& np1)
{
    if((np0.name != np1.name) && (np0.age != np1.age))
	return true;
    else 
	return false;
}

bool operator<(const Name_pair& np0, const Name_pair& np1)
{

    if(np0.name < np1.name)
	return true;
    else
	return false;
}
