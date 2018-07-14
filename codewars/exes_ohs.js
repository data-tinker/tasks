function XO(str) {
    str = str.toLowerCase()
    var x_num = 0;
    var o_num = 0;
    for (var i = 0; i < str.length; i++) {
        if (str[i] == 'o') {
            o_num += 1;
        } else if (str[i] == 'x') {
            x_num += 1;
        }
    }
    if (x_num == o_num) {
        return true;
    } else {
        return false;
    }
}
