/**
 * @param {string} num
 * @param {string[]} words
 * @return {string[]}
 */
const getValidT9Words = function (num, words) {
    const mapper = "22233344455566677778889999";
    const ans = [];
    let flag = true;
    for (let i = 0; i < words.length; ++i) {
        flag = true;
        for (let k = 0; k < num.length; ++k) {
            if (num[k] !== mapper[words[i].charCodeAt(k) - 97]) {
                flag = false;
                break;
            }
        }
        flag && ans.push(words[i]);
    }

    return ans;
};