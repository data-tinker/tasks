#!/usr/bin/env node

function duplicateCount(text){
  const alphabetStart = 97;

  let input = text.toLowerCase();
  let occurances = {};
  let result = 0;

  for (let i = 0; i<26; i++) {
    occurances[String.fromCharCode(alphabetStart + i)] = 0;
  }

  for (let i = 0; i < input.length; i++) {
      occurances[input[i]]++;
  }

  for (key in occurances) {
      if (occurances[key] > 1) {
          result += 1;
      }
  }

  return result;
}

console.log(duplicateCount((process.argv[2])));
