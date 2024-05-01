export function reversePrefix(word: string, ch: string): string {
    let reverseIndex = -1;

    for (let i = 0; i < word.length; i++) {
        if (word[i] === ch) {
            reverseIndex = i
            break
        }
    }

    if (reverseIndex !== -1) {
        let reversedWord = '';
        for (let i = reverseIndex; i >= 0; i--) {
            reversedWord += word[i];
        }

        reversedWord += word.substring(reverseIndex + 1)

        return reversedWord
    }

    return word
};
 