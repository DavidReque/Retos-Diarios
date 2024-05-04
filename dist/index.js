import { reversePrefix } from "./day1.js";
import { twoSum } from "./day2.js";
// dia 1
console.log(reversePrefix("abcdefd", "d"));
console.log(reversePrefix("xyxzxe", "z"));
console.log(reversePrefix("abcd", "z"));
// dia 2
const nums = [2, 7, 11, 15];
const target = 9;
const nums2 = [3, 2, 4];
const target2 = 6;
const nums3 = [3, 3];
const target3 = 6;
console.log(twoSum(nums, target));
console.log(twoSum(nums2, target2));
console.log(twoSum(nums3, target3));
//# sourceMappingURL=index.js.map