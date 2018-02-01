/**
 * @param {Array} collection
 * @params {Function[]} – Функции для запроса
 * @returns {Array}
 */


function query(collection) {
    var _collection = [].slice.call(collection),
        args = [].slice.call(arguments),
        methods = args.slice(1);

    function functionName(func) {
        var result = /^function\s+([\w\$]+)\s*\(/.exec(func.toString());

        return result ? result[1] : '' // for an anonymous function there won't be a match
    }


    methods.sort(function (a, b) {
        return functionName(a) > functionName(b);
    });

    methods.forEach(function (method) {
        method(_collection);
    });


    return _collection.filter(function (value) {
        return value === value
    });
}

/**
 * @params {String[]}
 */
function select() {
    var args = [].slice.call(arguments);

    return function _select(collection) {
        collection.forEach(function (item) {
            var keys = Object.keys(item);
            keys.forEach(function (key) {
                if (args.indexOf(key) === -1) {
                    delete item[key];
                }
            })
        });
    };
}

/**
 * @param {String} property – Свойство для фильтрации
 * @param {Array} values – Массив разрешённых значений
 */
function filterIn(property, values) {

    return function _filterIn(collection) {
        collection.forEach(function (item, index) {
            if (values.indexOf(item[property]) === -1) {
                delete collection[index];
            }
        });
    };

}

module.exports = {
    query: query,
    select: select,
    filterIn: filterIn
};
