/**
 * @param {string} IP
 * @return {string}
 */
var validIPAddress = function (IP) {
    const IPv4 = /^(25[0-5]|2[0-4]\d|((1\d{2})|([1-9]?\d)))(\.(25[0-5]|2[0-4]\d|((1\d{2})|([1-9]?\d)))){3}$/
    const IPv6 = /^((\d|[a-f]){1,4})(\:(\d|[a-f]){1,4}){7}$/i;
    if (IPv4.test(IP))
        return "IPv4";
    if (IPv6.test(IP))
        return "IPv6";
    return "Neither";
};