//
// Created by Ludovic FAVIER on 26/02/2022.
//

#include "Utils.h"
#include <algorithm>

bool Utils::stringsAreEqualsCaseInsensitive(std::string &string1, std::string &string2) {
    return std::equal(string1.begin(), string1.end(),
                      string2.begin(), string2.end(),
                      [](unsigned char char1, unsigned char char2) {
                          return tolower(char1) == tolower(char2);
                      });
}

std::string Utils::convertStringToLowerCase(std::string &string) {
    std::string res;
    std::transform(string.begin(), string.end(), std::inserter(res, std::end(res)),
                   [](unsigned char c) -> unsigned char { return std::tolower(c); });
    return res;
}