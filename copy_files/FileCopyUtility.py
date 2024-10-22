import os
import shutil
import time

def copy_file(source, destination):
    try:
        shutil.copy2(source, destination)
    except Exception as e:
        print(f"Error copying file {source} to {destination}: {e}")

def copy_directory(source_dir, destination_dir):
    if not os.path.exists(source_dir) or not os.path.isdir(source_dir):
        print("Source directory does not exist or is not a directory.")
        return

    if not os.path.exists(destination_dir):
        os.makedirs(destination_dir)

    for root, dirs, files in os.walk(source_dir):
        for dir_ in dirs:
            dest_dir = os.path.join(destination_dir, os.path.relpath(os.path.join(root, dir_), source_dir))
            if not os.path.exists(dest_dir):
                os.makedirs(dest_dir)

        for file_ in files:
            source_file = os.path.join(root, file_)
            destination_file = os.path.join(destination_dir, os.path.relpath(source_file, source_dir))
            copy_file(source_file, destination_file)

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <source_directory> <destination_directory>")
        sys.exit(1)

    source_dir = sys.argv[1]
    destination_dir = sys.argv[2]

    start_time = time.time()
    copy_directory(source_dir, destination_dir)
    end_time = time.time()

    total_time = end_time - start_time
    print(f"Total time taken: {total_time:.6f} seconds")
