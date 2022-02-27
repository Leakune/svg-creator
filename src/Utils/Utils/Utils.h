//
// Created by Ludovic FAVIER on 26/02/2022.
//

#ifndef SVG_CREATOR_UTILS_H
#define SVG_CREATOR_UTILS_H

#include <string>

class Utils {
    public:
        static bool stringsAreEqualsCaseInsensitive(std::string&, std::string&);
        static std::string convertStringToLowerCase(std::string&);
};


#endif //SVG_CREATOR_UTILS_H
