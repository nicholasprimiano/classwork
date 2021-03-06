import java.net.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.IOException;

/**
 * <pre> 
 * This class is used to find all the URLs on a given web page. More
 * precisely,it creates a Vector, each of whose elements is a 
 * String; these Strings are the URLs that appear on the page.
 *
 * This implementation assumes that any anchor tags containing URLs
 * must satisfy the following restrictions:
 *
 *   1. The opening part of an href tag must be either &lt;a href=" or &lt;A
 *   HREF=". That is:
 *      a. Mixed-case specification (such as &lt;A hReF=") is not
 *         supported.
 *      b. Only one space is allowed between the a (or A) and the href
 *         (or HREF).
 *      c. No spaces are allowed on either side of the equals sign.
 *   2. The entire opening href tag (from the opening &lt; to the closing
 *       &gt;) must be on one line. However, the anchor text and the 
 *       closing /href tag may be on subsequent lines.
 *
 * The default behavior of a URLGrepper object is to include both
 * relative and absolute URLs.This can be changed to only including 
 * absolute URLs at the time we construct the URLGrepper object. 
 * </pre>
 * @version 1.0, 12 March 2014
 * @author Nicholas Primiano 
 */

public class URLGrepper {
  private ArrayList<String>  allUrls;
  
  /**
   * Two-parameter constructor sets up the URLGrepper. 
   *
   * @param urlString the URL of the web page, as a String
   * @param includeRelative true iff we are including relative URLs
   * @throws java.net.MalformedURLException if the URLString is not a 
   * valid URL
   * @throws java.io.IOException if grepURLs throws an IOExcpetion
   */

  public URLGrepper(String urlString, boolean includeRelative)
    throws MalformedURLException,IOException {
    String line = null;
    URLConnection connection = null;
    try {
      connection =  new URL(urlString).openConnection();
      Scanner scanner = new Scanner(connection.getInputStream());
        
      scanner.useDelimiter("\n");
      allUrls = new ArrayList<String>();
        
      while (scanner.hasNext()) { 
	line = scanner.next();
	for (int i = 0; i < line.length(); i++) {  
	  if (line.charAt(i) == '<' && (line.charAt(i + 1) == 'a' || 
				       line.charAt(i + 1) == 'A') && 
	                               line.charAt(i + 2) == ' ') {  
	    String subLine = line.substring(i+9);
	    int j = 0;
	    while (j < subLine.length() && subLine.charAt(j) != '"') {
	      j++;
	    }
	    if(j < subLine.length()) { // found closing quote
	      String subLineURL = subLine.substring(0, j);
	      if (!includeRelative && subLine.startsWith("http") || subLine.startsWith("mailto")|| subLine.startsWith("ftp")) {
		allUrls.add(subLineURL);
	      }
	      else if (includeRelative){ 
	        allUrls.add(subLineURL);
	      }	      
	    }	  
	  }   
	}	    
      }	    
   scanner.close();
    }   
    catch (Exception ex) {
      ex.printStackTrace();
    }
  }  

  /**
   * Provide a String version of the list of URLs found by a
   * URLGrepper. Each URL is placed on a separate line.
   */

  public String toString() {
    String data = "";
    for (int i = 0 ; i < allUrls.size(); i++) {
      data = data + allUrls.get(i) + "\n";
    }
    return data;
  }
}

