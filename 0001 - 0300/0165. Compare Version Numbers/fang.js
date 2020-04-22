/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function (version1, version2) {
    const arr1 = version1.split(".");
    const arr2 = version2.split(".");
    const maxlen = Math.max(arr1.length, arr2.length);
    let num1 = 0, num2 = 0;
    for (let i = 0; i < maxlen; ++i) {
        num1 = num1 * 10 + (i >= arr1.length ? 0 : parseInt(arr1[i]));
        num2 = num2 * 10 + (i >= arr2.length ? 0 : parseInt(arr2[i]));
    }

    if (num1 > num2) return 1;
    if (num2 > num1) return -1;
    return 0;
};