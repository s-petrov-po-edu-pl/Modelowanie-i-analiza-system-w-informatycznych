#include <iostream>
#include <filesystem>
#include <chrono>

namespace fs = std::filesystem;

void copyFile(const fs::path &source, const fs::path &destination)
{
    try
    {
        fs::copy(source, destination, fs::copy_options::overwrite_existing);
    }
    catch (const fs::filesystem_error &e)
    {
        std::cerr << "Error copying file: " << e.what() << std::endl;
    }
}

void copyDirectory(const fs::path &sourceDir, const fs::path &destinationDir)
{
    if (!fs::exists(sourceDir) || !fs::is_directory(sourceDir))
    {
        std::cerr << "Source directory does not exist or is not a directory." << std::endl;
        return;
    }

    if (!fs::exists(destinationDir))
    {
        fs::create_directory(destinationDir);
    }

    for (const auto &file : fs::directory_iterator(sourceDir))
    {
        const auto &filePath = file.path();
        auto destPath = destinationDir / filePath.filename();

        if (fs::is_directory(filePath))
        {
            copyDirectory(filePath, destPath);
        }
        else
        {
            copyFile(filePath, destPath);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <source_directory> <destination_directory>" << std::endl;
        return 1;
    }

    fs::path sourceDir = argv[1];
    fs::path destinationDir = argv[2];

    auto start = std::chrono::high_resolution_clock::now();
    copyDirectory(sourceDir, destinationDir);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Total time taken: " << elapsed.count() << " seconds." << std::endl;

    return 0;
}
