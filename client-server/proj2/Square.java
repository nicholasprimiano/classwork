/**
 * The Square class is a class of two-dimensional shapes. Not
 * surprisingly, the objects of this class are square.  A square is
 * specified by its center and sidelength
 *
 * @version 1.0 28 Jan 2014
 * @author Nicholas Primiano
 */

public class Square extends Shape2D {
  private double sideLength = 0;

  /**
   * Zero-parameter constructor makes the origin the center of the
   * square and makes the sidelength of the square zero.
   */

  public Square(){
    this.centerX = 0;
    this.centerY = 0;
    this.sideLength = 0;
  }

  /**
   * One-parameter constructor sets the sidelength, ands makes the
   * origin the center of the square.
   *
   * @param sideLength the sidelength of the square
   */

  public Square(double sideLength) {
    // super(0,0);
    this.centerX = 0;
    this.centerY = 0;
    this.sideLength = sideLength;
  }

  /**
   * Two-parameter constructor sets the center, and makes the
   * sidelength of the square zero.
   *
   * @param centerX the center's x-coordinate
   * @param centerY the center's y-coordinate
   */
  
  public Square(double centerX, double centerY){
    // super(centerX, centerY);
    this.centerX = centerX;
    this.centerY = centerY;
    this.sideLength = 0;
  }

  /**
   * Three parameter constructor sets the sidelength and the center of
   * the square.
   *
   * @param sideLength the sideLength of the square
   * @param centerX the center's x-coordinate
   * @param centerY the center's y-coordinate 
   */

  public Square(double sideLength, double centerX, double centerY){
    this.centerX = centerX;
    this.centerY = centerY;
    this.sideLength = sideLength;
  }

  /**
   * Determine the square's sidelength.
   *
   * @return the sidelength of the square
   */

  public double getSideLength(double sideLength){
    return sideLength;
  }  
 
  /**
   * Determine the perimeter.
   *
   * @return the perimeter of the square
   */

  public double perimeter() {
    // perimeter of a square 4 * sidelength
    return 4 * sideLength;
  }

  /**
   * Determine the square's area.
   *
   * @return the area of the square
   */

  public double area() {
    return sideLength * sideLength;
  }

  /**
   * Create a string verson of the square, suitable for (e.g.)
   * printing
   *
   * @return the string representation of the square
   */

 public String toString() {
    return String.format("Square with:\n   side length %.1f\n" +
			 "   center at (%.1f, %.1f)\n" + 
			 "   perimeter of %.3f \n   area of %.3f", 
			 sideLength, centerX, centerY, perimeter(), area());
  }
}
