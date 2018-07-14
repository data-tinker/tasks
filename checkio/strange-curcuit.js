#!/usr/bin/env node

'use strict';


function createMultidimensionalArray(size) {
    var arr = new Array(size);
    var i = size;

    if (arguments.length > 1) {
        var args = [].slice.call(arguments, 1);
        while (i--) {
            arr[size - 1 - i] = createMultidimensionalArray.apply(this, args);
        }
    }
    return arr;
}

function createSpiral(size) {
    var spiral = createMultidimensionalArray(size, size);

    var positionX = Math.floor(size / 2);
    var positionY = positionX - 1;

    spiral[positionY + 1][positionX] = 1;
    spiral[positionY][positionX] = 2;

    for (var i = 3; i < size * size + 1; i++) {
        if (positionX + 1 <= size - 1 && positionY + 1 <= size - 1 && spiral[positionY + 1][positionX] && !spiral[positionY][positionX + 1]) {
            positionX += 1;
            spiral[positionY][positionX] = i;
        } else if (positionX - 1 >= 0 && positionY + 1 <= size - 1 && spiral[positionY][positionX - 1] && !spiral[positionY + 1][positionX]) {
            positionY += 1;
            spiral[positionY][positionX] = i;
        } else if (positionX - 1 >= 0 && positionY - 1 >= 0 && spiral[positionY - 1][positionX] && !spiral[positionY][positionX - 1]) {
            positionX -= 1;
            spiral[positionY][positionX] = i;
        } else if (positionX + 1 <= size - 1 && positionY - 1 >= 0 && spiral[positionY][positionX + 1] && !spiral[positionY - 1][positionX]) {
            positionY -= 1;
            spiral[positionY][positionX] = i;
        }
    }
    return spiral;
}

function findPositions(first, second, spiral) {
    var positionXFirst;
    var positionYFirst;
    var positionXSecond;
    var positionYSecond;

    spiral.forEach((row, i) => {
        row.forEach((el, j) => {
            if (el === first) {
                positionXFirst = j;
                positionYFirst = i;
            } else if (el === second) {
                positionXSecond = j;
                positionYSecond = i;
            }
        });
    });
    return [positionXFirst, positionYFirst, positionXSecond, positionYSecond];
}

function findDistance(first, second) {
    var spiral = createSpiral(33);
    var [positionXFirst, positionYFirst, positionXSecond, positionYSecond] = findPositions(first, second, spiral);

    return Math.abs(positionXFirst - positionXSecond) + Math.abs(positionYFirst - positionYSecond);
}

console.log(findDistance(50, 16));
