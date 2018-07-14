function myParseInt(str) {
    if (str.match(/^[\ \t\n]*[0-9]+[\ \t\n]*$/)) {
        str = str.replace(/ /g, '');
        str = str.replace(/\t/g, '');
        str = str.replace(/\n/g, '');
    }
    if (str.match(/^0+$/)) {
        return 0;
    }
    str = str.replace(/^0+/, '');
    var result = parseInt(str);
    if (result.toString() == str) {
        return result;
    } else {
        return "NaN";
    }
}

console.log(myParseInt(process.argv[2]));
