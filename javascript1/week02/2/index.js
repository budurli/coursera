/**
 * @param {String[]} hashtags
 * @returns {String}
 */
module.exports = function (hashtags) {
    function toLower(item, index) {
        return item.toLowerCase();
    }

    function onlyUnique(item, index, self) {
        return self.indexOf(item) === index;
    }

    return hashtags.map(toLower).filter(onlyUnique).join(', ');

};
