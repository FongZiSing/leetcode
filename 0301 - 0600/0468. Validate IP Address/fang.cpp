class Solution {
public:
    string validIPAddress(string IP) {
        if (regex_match(IP, regex("^(25[0-5]|2[0-4][0-9]|((1[0-9]{2})|([1-9]?[0-9])))(\.(25[0-5]|2[0-4][0-9]|((1[0-9]{2})|([1-9]?[0-9])))){3}$")))
            return string("IPv4");
        if (regex_match(IP, regex("^(([0-9]|[a-f]|[A-F]){1,4})(\:([0-9]|[a-f]|[A-F]){1,4}){7}$")))
            return string("IPv6");
        return string("Neither");
    }
};