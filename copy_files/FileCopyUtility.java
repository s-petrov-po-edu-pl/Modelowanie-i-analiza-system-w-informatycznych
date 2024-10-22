import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;

public class FileCopyUtility {

    public static void copyFile(File source, File destination) {
        try {
            Files.copy(source.toPath(), destination.toPath(), StandardCopyOption.REPLACE_EXISTING);
        } catch (IOException e) {
            System.err.println("Error copying file: " + e.getMessage());
        }
    }

    public static void copyDirectory(File sourceDir, File destinationDir) {
        if (!sourceDir.exists() || !sourceDir.isDirectory()) {
            System.err.println("Source directory does not exist or is not a directory.");
            return;
        }

        if (!destinationDir.exists()) {
            destinationDir.mkdir();
        }

        File[] files = sourceDir.listFiles();
        if (files == null) {
            System.err.println("Failed to list contents of directory: " + sourceDir.getAbsolutePath());
            return;
        }

        for (File file : files) {
            File destFile = new File(destinationDir, file.getName());

            if (file.isDirectory()) {
                copyDirectory(file, destFile);
            } else {
                copyFile(file, destFile);
            }
        }
    }

    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: java FileCopyUtility <source_directory> <destination_directory>");
            return;
        }

        File sourceDir = new File(args[0]);
        File destinationDir = new File(args[1]);

        long startTime = System.nanoTime();
        copyDirectory(sourceDir, destinationDir);
        long endTime = System.nanoTime();

        double elapsedTimeInSeconds = (endTime - startTime) / 1_000_000_000.0;
        System.out.printf("Total time taken: %.6f seconds\n", elapsedTimeInSeconds);
    }
}
