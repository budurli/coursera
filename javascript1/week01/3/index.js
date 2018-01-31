/**
 * @param {Number} hours
 * @param {Number} minutes
 * @param {Number} interval
 * @returns {String}
 */
module.exports = function (hours, minutes, interval) {
    var full_minutes = hours * 60 + minutes + interval,
        h = Math.floor(full_minutes / 60) % 24,
        m = full_minutes % 60;

    function formatNumber(n) {
        return n.toLocaleString('en-US', {minimumIntegerDigits: 2, useGrouping: false});
    };

    return formatNumber(h) + ':' + formatNumber(m);
};
