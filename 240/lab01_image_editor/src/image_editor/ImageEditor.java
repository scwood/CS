package image_editor;

public class ImageEditor {

    private static final String USAGE = "usage: java ImageEditor INPUT_FILE OUTPUT_FILE COMMAND [ARGS]";

    public static void main(String[] args) {
        if (args.length < 3) {
            System.out.println(ImageEditor.USAGE);
        }
    }
}
