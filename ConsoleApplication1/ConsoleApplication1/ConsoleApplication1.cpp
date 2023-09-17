#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>

int main()
{
    std::string url = "";
    std::string file_path = "C:/MyMusic";
    std::string test = "'%%(title)s'";
    while (true) {
        std::cout << "insert url: ";
        std::cin >> url;

        std::ofstream batch_file;
        batch_file.open("download.cmd", std::ios::trunc);
        batch_file <<
            "yt-dlp -P " + file_path + " -f bestaudio -x --audio-format alac --add-metadata -o "
            << test
            << " --embed-thumbnail " + url << std::endl;
        batch_file.close();

        int batch_exit_code = system("cmd.exe /c download.cmd");
        if (batch_exit_code != 0) {
            std::cout << std::endl << "file not downloaded: error " << batch_exit_code << std::endl;
        } else
            std::cout << std::endl << "dl executed" << std::endl << std::endl;
    }
}
