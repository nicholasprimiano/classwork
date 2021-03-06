/**
 * An abstract class of two-dimensional shapes.
 * 
 * @version 1.0 28 January 2014
 * @author Nicholas Primiano
 */

public abstract class Shape2D extends Shape {
  
  protected double centerX = 0;
  protected double centerY = 0;

  /**
   * Zero-parameter constructor sets the center to be the origin (0.0, 0.0).
   */

  public Shape2D(){
    this.centerX = 0;
    this.centerY = 0;
  }

  /**
   * Two-parameter constructor allows user to specify the center's
   * x- and y-coordinates.
   *
   * @param centerX the center's x-coordinate
   * @param centerY the center's y-coordinate
   */
  
  public Shape2D(double centerX, double centerY) {
    this.centerX = centerX;
    this.centerY = centerY;
  }
  
  /**
   * Get the center's x-coordinate
   *
   * @return x-coordinate of the center
   */

  public double getCenterX(double centerX){
    return centerX;
  }
  
  /**
   * Get the center's y-coordinate
   *
   * @return y-coordinate of the center
   */

  public double getCenterY(double centerY){
    return centerY;
  }
  
  /**
   * Abstract method that computes the perimeter of a two-dimensional
   * shape.
   * 
   * @return the preimeter of the shape.
   */

  public abstract double perimeter();
  
  /**
   * Abstract method that computes the area of a three-dimensional
   * shape.
   * 
   * @return the area of the shape.
   */

  public abstract double area();
}
