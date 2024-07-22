#include <iostream>
#include <format>
#include <filesystem>
#include <fstream>
#include <memory>

#include <c++/29/experimental/smart_view>

#include "./frontend/parsing/lexer.hpp"
#include "./frontend/parsing/parser.hpp"
#include "./backend/execution/machine.hpp"

#define FILE_EXTENSION_NAME "killua"

std::vector<std::string> readFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;

    if (file.is_open()) {
        std::string line;

        while (getline(file, line)) {
            lines.push_back(line);
        }
        
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return lines;
}

int main(int argc, char **argv) {
    if (argc == 2) {
        std::string path = argv[1];

        if (std::smart_view::string::endsWith(path, std::format(".{0}", FILE_EXTENSION_NAME)) == false) {
            path += std::format(".{0}", FILE_EXTENSION_NAME);
        }

        if (std::filesystem::exists(path)) {
            const std::vector<std::string> text_file = readFile(path);

            if (text_file.size() > 0) {
                Lexer lexer;
                Parser parser;
                Machine machine;

                std::vector<Token> tokens = lexer.lexer(text_file);

                tokens = std::smart_view::vector::filter(tokens, std::function<bool(const Token&)>([](const Token& token) {
                    return token._type != TokenType::COMMENT;
                }));

                std::vector<std::unique_ptr<Expression>> ast = std::move(parser.parser(tokens));
                machine.launcher(std::move(ast));
            }
        } else {
            std::cerr << "File not exists" << std::endl;
        }
    } else {
        std::cerr << "no input files" << std::endl;
    }

    return 0;
}