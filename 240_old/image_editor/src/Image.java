import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Image {

  public Pixel[][] pixels; // [h][w]
  public String file_name;
  public int height;
  public int width;

  public Image() {
    file_name = "";
  }

  public Image(String file_name) {
    this.file_name = file_name;
    try { 
      generatePixelsFromFile() ;
    } catch(FileNotFoundException exception) {
      System.out.println("error: file not found");
    }
  }

  public void generatePixelsFromFile() throws FileNotFoundException {
    FileInputStream file_in = new FileInputStream(file_name);
    BufferedInputStream buffer_in = new BufferedInputStream(file_in);
    Scanner scanner = new Scanner(buffer_in);
    scanner.useDelimiter("(\\s+)(#[^\\n]*\\n)?(\\s*)|(#[^\\n]*\\n)(\\s*)");
    String token = scanner.next(); // burn P3
    int width = scanner.nextInt();
    int height = scanner.nextInt();
    this.width = width;
    this.height = height;
    pixels = new Pixel[height][width];
    token = scanner.next(); // burn max color range
    int red;
    int green;
    int blue;
    for (int i = 0; i < pixels.length; i++) {
      for (int j = 0; j < pixels[0].length; j++) {
        red = scanner.nextInt();
        green = scanner.nextInt();
        blue = scanner.nextInt();
        Pixel pxl = new Pixel(red, green, blue);
        pixels[i][j] = pxl;
      }
    }
    scanner.close();
  }

  public void pixelsToString() {
    for (Pixel[] row : pixels) {
      for (Pixel i : row) {
        System.out.printf("%d,%d,%d   ", i.getRed() ,i.getGreen() ,i.getBlue());
      }
      System.out.println();
    }
  }

}
