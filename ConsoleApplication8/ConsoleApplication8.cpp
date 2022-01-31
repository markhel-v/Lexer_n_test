 

#include <iostream>
#include <tuple>
#include <vector>
#include <string>

using namespace std;
 

    enum class JSONTokenType { String, Number, Syntax, Boolean, Null };
    struct JSONToken {
        std::string value;
        JSONTokenType type;
        int location;
        std::shared_ptr<std::string> full_source;
    };

std::tuple<JSONToken, int, std::string> lex_number(std::string raw_json,
    int original_index) {
    int index = original_index;
    JSONToken token = { "", JSONTokenType::Number, index };
    std::string value = "";
    // TODO: обработать не только целые числа
    while (true) {
        if (index == raw_json.length()) {
             
            break;
        }

        auto c = raw_json[index];
        if (!(c >= '0' && c <= '9')) {
            break;
        }

        token.value += c;
        index++;
    }

    return { token, index, "" };
}


int main()
{

    string str = "554567";

    tuple<JSONToken, int, std::string>my;
      my = lex_number(str, 0);
         cout << get<0>(my).value;
 







}

