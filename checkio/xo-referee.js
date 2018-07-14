#!/usr/bin/env node
'use strict';

function createArray(size) {
    var arr = new Array(size);
    var i = size;

    if (arguments.length > 1) {
        var args = [].slice.call(arguments, 1);
        while (i--) {
            arr[size - 1 - i] = createArray.apply(this, args);
        }
    }
    return arr;
}

function matrixRotate(data) {
    var dataLength = data.length;
    var rotatedMatrix = createArray(dataLength, dataLength);
    data.forEach((row, i) => {row.split('').forEach((el, j) => {rotatedMatrix[j][i] = el})});
    return rotatedMatrix.map((el) => el.join(''));
}

function matrixDiagonals(data) {
    var mainDiagonal = [];
    var minorDiagonal = [];
    var dataLength = data.length;
    for (var i = 0; i < dataLength; i++) {
        mainDiagonal.push(data[i][i]);
        minorDiagonal.push(data[i][dataLength - 1 - i])
    }
    return [mainDiagonal.join(''), minorDiagonal.join('')];
}

function countOccurances(arr, value) {
    return arr.split('').reduce((count, el) => {return count + (el === value)}, 0);
}

function checkWinner(arr, winCount) {
    var winner = null;
    if (countOccurances(arr, 'X') === winCount) {
        winner = 'X';
    } else if (countOccurances(arr, 'O') === winCount) {
        winner = 'O';
    }
    return winner;
}

function xoReferee(data) {
    var winCount = data.length;
    var winner = null;

    var [mainDiagonal, minorDiagonal] = matrixDiagonals(data);
    var rotatedData = matrixRotate(data);

    for (var matrix of [data, rotatedData]) {
        for (var row of matrix) {
            winner = checkWinner(row, winCount);
            if (winner) return winner;
        }
    }

    for (var diagonal of [mainDiagonal, minorDiagonal]) {
        winner = checkWinner(diagonal, winCount);
        if (winner) return winner;
    }

    return 'D';
}

 console.log(xoReferee([
    "X.OO",
    "XX.O",
    "XOXO",
    "O.OX",
 ]))
