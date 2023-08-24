#include <iostream>
#include <string>
#include <algorithm>

int pencariKata(std::string text, std::string keyword) {
    int count = 0;

    transform(text.begin(), text.end(), text.begin(), ::tolower);
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

    for (int i = 0; i < text.length(); i++) {
        int a = 0;

        while (a < keyword.length() && i + a < text.length() && text[i + a] == keyword[a]) {
            a++;
        }
        if (a == keyword.length()) {
            count++;
            std::cout << "\nKemunculan ke-" << count << " pada posisi " << i+1 << " : " << "\n" << std::endl;
            
            int start = i > 9 ? i - 10 : 0;
            for (int j = start; j < i; j++) {
                std::cout << text[j];
            }

            std::cout << "[" << keyword << "]";

            int end = i + keyword.length() + 10 < text.length() ? i + keyword.length() + 10 : text.length();
            for (int j = i + keyword.length(); j < end; j++) {
                std::cout << text[j];
            }
            std::cout << std::endl;
        }
    }
    return count;
}


auto main(int argc, char* argv[]) -> decltype(0) {
    std::string text;
    std::string keyword;
    char option;

    std::cout << "\n\t\t=== Pencari Kata ===" << std::endl;
    std::cout << "\nMasukkan teks : ";
    getline(std::cin, text);

    while (keyword.empty()) {
        std::cout << "\nMasukkan kata yang ingin dicari : ";
        getline(std::cin, keyword);
    }

    int pencari_kata = pencariKata(text, keyword);

    if (pencari_kata == 0) {
        std::cout << "\nKata \"" << keyword << "\" tidak ditemukan dalam teks." << std::endl;
    }
    else {
        std::cout << "\nJumlah kemunculan kata \"" << keyword << "\" dalam teks : " << pencari_kata << std::endl;
    }

    std::cout << "\nApakah Anda ingin melanjutkan pencarian? (y/t) : ";
    std::cin >> option;

    if (option == 'y' || option == 'Y') {
        std::cin.ignore();
        main(argc, argv);
    }
    return 0;
}
