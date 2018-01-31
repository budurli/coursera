// Телефонная книга
var phoneBook = {};

/**
 * @param {String} command
 * @returns {*} - результат зависит от команды
 */
module.exports = function (command) {
    var args = command.split(' '),
        names = Object.keys(phoneBook).sort(),
        result = undefined;


    function deleteArrayElement(array, element) {
        if (array.indexOf(element) !== -1) {
            array.splice(array.indexOf(element), 1);
            return true;
        }
        return false;
    }

    if (args[0] === 'ADD') {
        var name = args[1];

        if (!phoneBook.hasOwnProperty(name)) {
            phoneBook[name] = [];
        }

        args[2].split(',').forEach(function (value) {
            phoneBook[name].push(value)
        });
    }

    if (args[0] === 'REMOVE_PHONE') {
        var phone = args[1];
        result = false;

        names.forEach(function (key) {
            result += deleteArrayElement(phoneBook[key], phone);
        });
    }


    if (args[0] === 'SHOW') {
        result = [];
        names.filter(function (name) {
            return (phoneBook[name].length !== 0)
        }).forEach(function (key) {
            result.push(key + ': ' + phoneBook[key].join(', '));
        });
    }

    return result;
};
