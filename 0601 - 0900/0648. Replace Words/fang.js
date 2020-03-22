// bad code, bullshit, but AC.
/**
 * @param {string[]} dict
 * @param {string} sentence
 * @return {string}
 */
var replaceWords = function (dict, sentence) {
    dict.sort((a, b) => a.length > b.length);
    return sentence.split(" ")
        .map(word => {
            dict.some((val, idx) => {
                if (word.indexOf(val) == 0) {
                    word = val;
                    return true;
                }
                return false;
            });
            return word;
        }).join(" ");
};
