#!/usr/bin/env node

'use strict';

function baseCoverter(number, base) {
    var digits = "0123456789ABCDEF";
    var result = [];

    while (number >= 1) {
        result.unshift(digits[number % base]);
        number = Math.floor(number / base);
    }
    return result.join('');
}

function binaryCount(number) {
    return (baseCoverter(number, 2).match(/1/g) || []).length;;
}

console.log(binaryCount(process.argv[2]));
