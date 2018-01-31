/**
 * @param {Number} a Первое слагаемое
 * @param {Number} b Второе слагаемое
 * @returns {Number}
 */

module.exports = function (a, b) {
    var filterInt = function (value) {
        if (/^(\-|\+)?([0-9]+|Infinity)$/.test(value))
            return Number(value);
        return NaN;
    };

    var _a = filterInt(a),
        _b = filterInt(b);

    return _a + _b;

};
