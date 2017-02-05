#pragma once
#include<string>

namespace my{

std::string query(std::string url) {
    FILE *f = popen(("curl -s -k \"" + url + "\"").c_str(), "r");
    if (f == NULL) {
        perror("error!");
    }
    char buf[1024];
    std::string res;
    while (!feof(f)) {
        if (fgets(buf, 1024, f) == NULL) break;
        res += (std::string)(buf);
    }
    pclose(f);
    return res;
}

}
