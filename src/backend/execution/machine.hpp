#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <vector>
#include <regex>
#include <functional>
#include <string>
#include <optional>
#include <format>
#include <memory>
#include <cstdlib>

#include <c++/29/experimental/smart_view>
#include <c++/29/reflect>

#include "../../frontend/atomic/token.hpp"
#include "../../frontend/type/token.hpp"
#include "../../frontend/type/token.pair.hpp"
#include "../../frontend/type/expression.hpp"
#include "../../frontend/type/expression.type.hpp"

#include "../../frontend/type/expression/identifer.hpp"
#include "../../frontend/type/expression/literal.hpp"
#include "../../frontend/type/expression/object.hpp"
#include "../../frontend/type/expression/inizializer.hpp"

#include "../../exception/syntax.hpp"

class Machine {
public:
    Machine();
    void launcher(std::vector<std::unique_ptr<Expression>> ast);

    std::vector<std::__cxx11::basic_string<char>> LuminousCommandEnvironmentCatalogue {
        "shell",
    };

    enum class LuminousCommandEnvironmentCosmos {
        shell,
    };

    std::map<std::string, LuminousCommandEnvironmentCosmos> LuminousCommandEnvironmentMap {
        {"shell", LuminousCommandEnvironmentCosmos::shell},
    };

    LuminousCommandEnvironmentCosmos LuminousCommandEnvironmentScanner(std::__cxx11::basic_string<char> key) {
        auto it = LuminousCommandEnvironmentMap.find(key);

        if (it != LuminousCommandEnvironmentMap.end()) {
            return it->second;
        }
    };

private:
    std::vector<std::unique_ptr<Expression>> ast;
    int current;

    void scanExpression(const Expression&);
    void inc_current();
    bool isNext();
    Expression& peek();
};

#endif // MACHINE_H