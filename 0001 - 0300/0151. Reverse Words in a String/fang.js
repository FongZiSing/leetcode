/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function (s) {
    return s.trim().split(" ").filter(letter => !!letter).reverse().join(" ");
};