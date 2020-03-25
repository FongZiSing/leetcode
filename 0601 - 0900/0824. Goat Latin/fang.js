/**
 * @param {string} S
 * @return {string}
 */
const mapper = {
    'a': true, 'A': true,
    'e': true, 'E': true,
    'i': true, 'I': true,
    'o': true, 'O': true,
    'u': true, 'U': true
}
var toGoatLatin = function (S) {
    return S.split(' ').map((v, i) => {
        if (mapper[v[0]]) {
            v += 'ma';
        }
        else {
            v = v.slice(1) + v[0] + 'ma';
        }
        for (let j = i + 1; j--;)
            v += 'a';
        return v;
    }).join(' ');
};