import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter; 

public class ImageEditor {

  public static void main(String[] args) throws FileNotFoundException {
    if (args.length < 3) {
      System.out.println(
          "usage: ImageEditor IN_FILE OUT_FILE COMMAND [ARGS]...");
      return;
    }
    ImageEditor editor = new ImageEditor();
    Image img = new Image(args[0]);
    Image edited;
    switch (args[2]) {
      case "emboss": 
        edited = editor.emboss(img);
        break;
      case "grayscale":
        edited = editor.grayscale(img);
        break;
      case "invert":
        edited = editor.invert(img);
        break;
      case "motionblur":
        if (args.length < 4) {
          System.out.println("error: missing argument for motionblur");
        } else if (!args[3].matches("\\d+")) {
          System.out.println("error: invalid motionblur amount");
        }
        int amount = Integer.valueOf(args[3]);
        edited = editor.motionBlur(img, amount);
        break;
      default:
        System.out.println("error: invalid editing option");
        return;
    }
    editor.writeImage(edited, args[1]);
  }

  public Image emboss(Image img) {
    Image edited = new Image();
    edited.pixels = img.pixels.clone();
    for (int h = 0; h < img.pixels.length; h++) {
      for (int w = 0; w < img.pixels[0].length; w++) {
        if (h == 0 || w == 0) {
          edited.pixels[h][w].setRed(128);
          edited.pixels[h][w].setGreen(128);
          edited.pixels[h][w].setBlue(128);
        }
        else {
          int r_diff = img.pixels[h][w].getRed() -
            img.pixels[h - 1][w - 1].getRed();
          int g_diff = img.pixels[h][w].getGreen() -
            img.pixels[h - 1][w - 1].getGreen();
          int b_diff = img.pixels[h][w].getBlue() -
            img.pixels[h - 1][w - 1].getBlue();
          int max_diff;
          if (Math.abs(r_diff) >= Math.abs(g_diff) &&
             (Math.abs(r_diff) >= Math.abs(b_diff))) {
            max_diff = r_diff;
          } else if (Math.abs(g_diff) >= Math.abs(r_diff) &&
                    (Math.abs(g_diff) >= Math.abs(b_diff))) {
            max_diff = g_diff;
          } else {
            max_diff = b_diff;
          }
          int new_color = max_diff + 128;
          if (new_color < 0) {
            new_color = 0;
          } else if (new_color > 255) {
            new_color = 255;
          }
          edited.pixels[h][w].setRed(new_color);
          edited.pixels[h][w].setGreen(new_color);
          edited.pixels[h][w].setBlue(new_color);
        }
      }
    }
    return edited;
  }

  public Image grayscale(Image img) {
    Image edited = new Image();
    edited.pixels = img.pixels.clone();
    for (Pixel[] row : edited.pixels) {
      for (Pixel i: row) {
        int average = (i.getRed() + i.getGreen() + i.getBlue()) / 3;
        i.setRed(average);
        i.setGreen(average);
        i.setBlue(average);
      }
    }
    return edited;
  }

  public Image invert(Image img) {
    Image edited = new Image();
    edited.pixels = img.pixels.clone();
    for (Pixel[] row : edited.pixels) {
      for (Pixel i : row) {
        i.setRed(Math.abs(i.getRed() - 255));
        i.setGreen(Math.abs(i.getGreen() - 255));
        i.setBlue(Math.abs(i.getBlue() - 255));
      }
    }
    return edited;
  }

  public Image motionBlur(Image img, int amount) {
    Image edited = new Image();
    edited.pixels = img.pixels.clone();
    for (int h = 0; h < img.height; h++) {
      for (int w = 0; w < img.width; w++) {
        int r_total = 0;
        int g_total = 0;
        int b_total = 0;
        int index = w;
        if (w + amount >= img.width) {
          for (int i = w; i < img.width; i++) {
            r_total += edited.pixels[h][i].getRed();
            g_total += edited.pixels[h][i].getGreen();
            b_total += edited.pixels[h][i].getBlue();
          }
          int r_average = r_total / (img.width - w);
          int g_average = g_total / (img.width - w);
          int b_average = b_total / (img.width - w);
          edited.pixels[h][w].setRed(r_average);
          edited.pixels[h][w].setGreen(g_average);
          edited.pixels[h][w].setBlue(b_average);
        } else {
          for (int i = w; i < w + amount; i++) {
            r_total += edited.pixels[h][i].getRed();
            g_total += edited.pixels[h][i].getGreen();
            b_total += edited.pixels[h][i].getBlue();
          }
          int r_average = r_total / amount;
          int g_average = g_total / amount;
          int b_average = b_total / amount;
          edited.pixels[h][w].setRed(r_average);
          edited.pixels[h][w].setGreen(g_average);
          edited.pixels[h][w].setBlue(b_average);
        }
      }
    }
    return edited;
  }

  public void writeImage(Image img, String filename) {
    try {
      FileWriter f_writer = new FileWriter(filename);
      BufferedWriter b_writer = new BufferedWriter(f_writer);
      PrintWriter p_writer = new PrintWriter(b_writer);
      p_writer.println("P3");
      p_writer.println(img.pixels[0].length);
      p_writer.println(img.pixels.length);
      p_writer.println("255");
      for (Pixel[] row : img.pixels) {
        for (Pixel i : row) {
          p_writer.println(i.getRed());
          p_writer.println(i.getGreen());
          p_writer.println(i.getBlue());
        }
      }
      p_writer.close();
    } catch(IOException exception) {
      System.out.println("error: can't write file");
    }
  }

}
