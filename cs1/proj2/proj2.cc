/**********************************************************************
 *
 * Project 2: Quadratic Equation Solver
 *
 * Program that determines roots of linear and quadratic funtions.
 * This program also handels special floating point math error cases.
 *
 * Author: Nicholas Primiano <nprimiano@fordham.edu>
 * Date:   7 February 2013
 *
 **********************************************************************/

//include necessary componants 
#include <bjarne/std_lib_facilities.h>
 
// function declarations
void solve_linear(double b, double c);
void solve_quadratic(double a, double b, double c);
void floating_point_math(double a, double c, double root_1, double root_2);

//the usual main function
int main()
{
    // input the coefficients of the polynomial
    double a, b, c;         // coefficients of the polynomial

    // Get input from the user
    cout << "Enter the coefficients of a quadratic equation a*x**2 + b*x + c:" << endl;
    cout << " a? ";
    cin >> a;

    cout << " b? ";
    cin >> b;

    cout << " c? ";
    cin >> c;

    // handle degenerate case (linear equation) and quit
    if (a == 0) // linear equation, not quadratic
	solve_linear(b, c);
    else  // genuine quadratic equation ... forge ahead
	solve_quadratic(a, b, c);
    //Return 0 to indiacte successful completion of the main funtion
    return 0;  
}

// solve the linear equation b*x + c == 0
void solve_linear(double b, double c)
{
    cout << "Trying to solve linear equation "
         << b << "*x + " << c << " == 0\n";
 
    if (b == 0 && c != 0)   //Check for contradictions 
	cout << "This is a contradictory statement " << c << " == 0."<< endl;
    else if (b == 0 && c == 0)  //Check for a 0 == 0 identitiy 
	cout << "An Identity: 0 == 0." << endl;
    else{
	/*If the function satisifes no special cases, 
	  calculate and print the x intercept of the linear equation*/
	double x  = -c/b;
	if (x == 0)   //Determine if the root equals 0 to prevent -0 output 
	    cout << "Linear, One root: x = 0." << endl;
	else
	    cout << "Linear, One root: x = " << x << endl;
    }
}
// use classical quadratic formula to solve a genuine quadratic equation
// a*x^2 + b*x + c ==0, with a != 0
void solve_quadratic(double a, double b, double c)
{
    cout << "Trying to solve the quadratic equation "
	 << a << "*x*x + " << b << "*x + " << c << " == 0\n";
    
    //Check if the funtion has real roots
    //Variable to calculate the discriminant of a quadratic function
    double discriminant = (b*b)-(4*a*c); 
    if (discriminant < 0){
	//If the funtion has no real roots notify the user and close the program 
	cout << "No real roots." << endl;
    }
    else{
	//Variable declaration for single and double root funtions 
	double root_1 = 0;
	double root_2 = 0;				    
	//Determine if the funtion has one or two real roots
	if (discriminant == 0) { 
	    root_1 = -b/(2*a);
	    cout << "Using the classic formula: One double root, x = " << root_1 
		 << " and x = " <<  root_1 << endl;   
	}
	else{
	    //Calculate the first root of the funtion
	    root_1 = (-b + sqrt(discriminant))/(2*a);
	    //Calculate the second root of the funtion  						   
	    root_2 = (-b - sqrt(discriminant))/(2*a);
	    //Print the funtion and both roots

	    cout << "Using the classical formula: Two Roots, x = " << root_2 
		 << " and x = " << root_1 << endl;

	    //Check for a floating point math error case
                          			  
	    /*Determine the correct root and use the stable formula to
	      calculate and display the correct roots*/
	    if (root_1 == 0 || root_2 == 0)
		floating_point_math(a, c, root_1, root_2);
	}
    }
}
/*Function to calculate and print correct values for roots affected by
  floting point math erros for both positive and negative 
  classicaly calulated roots*/ 
void floating_point_math(double a, double c, double root_1, double root_2){
    if (root_1 == 0){
	//Variable to hold the correct non zero root
	double correct_root_1 = c/(a*root_2); 
	cout << "Using the stable formula: Two roots, x = " 
	     << root_2 << " and x = " <<  correct_root_1 << endl;
    }
    else{
	//Variable to hold the correct non zero root
	double correct_root_2 = c/(a*root_1); 
	cout << "Using the stable formula: Two roots, x = " 
	     << root_1 << " and x = " <<  correct_root_2 << endl;
    }
}

