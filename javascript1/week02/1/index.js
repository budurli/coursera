/**
 * @param {String} tweet
 * @returns {String[]}
 */
module.exports = function (tweet) {
    function filter_tweet(item, index) {
        return item.startsWith('#');
    }

    function map_tweet(item, index) {
        return item.slice(1);
    }

    return tweet.split(' ').filter(filter_tweet).map(map_tweet);
};
