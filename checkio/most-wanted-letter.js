#!/usr/bin/env node
'use strict';

function mostWanted(data) {
    var isLetter = /[a-z]/;
    var letterCount = {};
    var letter;
    for (var i of data) {
        letter = i.toLowerCase();
        if (letter.match(isLetter)) {
            if (letterCount.hasOwnProperty(letter)) {
                letterCount[letter] += 1;
            } else {
                letterCount[letter] = 1;
            }
        }
    }
    var maxCount = Math.max.apply(null, Object.keys(letterCount).map((a) => letterCount[a]));
    return Object.keys(letterCount).filter((a) => {if (letterCount[a] === maxCount) return a}).sort()[0];
}

console.log(mostWanted(process.argv[2]));
