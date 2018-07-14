function presses(phrase) {
    var result = 0, phrase_arr = phrase.toLowerCase().split('');
    var chars = {
        ' ': 1,
        'a': 1,
        'd': 1,
        'g': 1,
        'j': 1,
        'm': 1,
        'p': 1,
        't': 1,
        'w': 1,
        'b': 2,
        'e': 2,
        'h': 2,
        'k': 2,
        'n': 2,
        'q': 2,
        'u': 2,
        'x': 2,
        'c': 3,
        'f': 3,
        'i': 3,
        'l': 3,
        'o': 3,
        'r': 3,
        'v': 3,
        'y': 3,
        's': 4,
        'z': 4,
        '0': 2,
        '1': 1,
        '2': 4,
        '3': 4,
        '4': 4,
        '5': 4,
        '6': 4,
        '7': 5,
        '8': 4,
        '9': 5
    };
    for (var i = 0; i  < phrase_arr.length; i++) {
        result += chars[phrase_arr[i]];
    }
    return result;
}

console.log(presses('WHERE DO U WANT 2 MEET L8R'));