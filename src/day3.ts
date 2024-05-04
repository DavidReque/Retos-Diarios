function numRescueBoats(people: number[], limit: number): number {
    people.sort((a, b) => a - b)

    let left = 0
    let right = people.length - 1
    let boats = 0

    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            left++
            right--
        } else {
            right--
        }

        boats++
    }

    return boats
};

const personas = [3, 2, 2, 1]
const límite = 3
console.log(numRescueBoats(personas, límite))

const personas2 = [1, 2]
const límite2 = 3
console.log(numRescueBoats(personas2, límite2))

const personas3 = [3, 5, 3, 4]
const límite3 = 5
console.log(numRescueBoats(personas3, límite3))