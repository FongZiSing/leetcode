/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    const hashmap = [];
    let result = [];
    nums.map((val, idx) => {
        if (hashmap[target - val] !== undefined) {
            result = [hashmap[target - val], idx];
        }
        if (hashmap[val] === undefined) {
            hashmap[val] = idx;
        }
    });

    return result;
};