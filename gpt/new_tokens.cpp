#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> tokenMemory;

// Função para gerar um token simples baseado na soma dos códigos ASCII
int generateToken(const std::string& word) {
    int token = 0;
    for (char c : word) token += (int)c;
    return token;
}

void learnWord(const std::string& word) {
    int token = generateToken(word);
    tokenMemory[word] = token;

    // Salva memória em arquivo
    std::ofstream file("memory.txt", std::ios::app);
    if (file.is_open()) {
        file << word << ":" << token << "\n";
        file.close();
    }
    std::cout << "Aprendi: " << word << " -> Token: " << token << "\n";
}

int main() {
    std::string input;
    std::cout << "LumaGPT (C++) pronto! Digite palavras:\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "sair") break;
        learnWord(input);
    }

    return 0;
}
