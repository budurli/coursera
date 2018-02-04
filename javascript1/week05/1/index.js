var subscriptions = {};
var objects = [];


function checkKey(key, obj) {
    return obj.hasOwnProperty(key);
}

function hashObject(obj) {
    objects.forEach(function (value, index) {
        if (value === obj) {
            return index;
        }
    });
    objects.push(obj);
    return objects.indexOf(obj);
}

module.exports = {

    /**
     * @param {String} event
     * @param {Object} subscriber
     * @param {Function} handler
     */
    on: function (event, subscriber, handler) {

        var _sub = hashObject(subscriber);

        if (!checkKey(event, subscriptions)) {
            subscriptions[event] = {};
        }

        if (!checkKey(_sub, subscriptions[event])) {
            subscriptions[event][_sub] = [];
        }

        subscriptions[event][_sub].push(handler.bind(subscriber));

        return this;
    },

    /**
     * @param {String} event
     * @param {Object} subscriber
     */
    off: function (event, subscriber) {

        var _sub = hashObject(subscriber);

        if (checkKey(event, subscriptions)) {
            if (checkKey(_sub, subscriptions[event])) {
                delete subscriptions[event][_sub];
            }
        }
        return this;
    },

    /**
     * @param {String} event
     */
    emit: function (event) {

        if (checkKey(event, subscriptions)) {
            Object.keys(subscriptions[event]).forEach(function (subscriber) {
                subscriptions[event][subscriber].forEach(function (handler) {
                    handler();
                });
            });
        }
        return this;

    }
};
