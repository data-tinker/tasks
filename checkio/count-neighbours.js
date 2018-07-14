#!/usr/bin/env node

'use strict';

function isPositionValid(row, col, dimensions) {
    console.log(row, col);
    if (0 <= row && row <= dimensions && 0 <= col && col <= dimensions) {
        return true;
    } else {
        return false;
    }
}

function countNeighbours(data, row, col) {
    var dimensions = data.length - 1;
    var neighbours = 0;
    for (var rowDiff of [-1, 1, 0]) {
        for (var colDiff of [-1, 1, 0]) {
            if (rowDiff == 0 && colDiff == 0) {
                break;
            }
            if (isPositionValid(row + rowDiff, col + colDiff, dimensions)) {
                if (data[row + rowDiff][col + colDiff] == 1) {
                    neighbours += 1;
                }
            }
        }
    }
    return neighbours;
}
