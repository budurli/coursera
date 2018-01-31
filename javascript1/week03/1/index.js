/**
 * @param {String} date (YYYY‒MM‒DD HH:SS)
 * @returns {Object}
 */
module.exports = function (date) {
    var pattern = /(\d{4})-(\d{2})-(\d{2}) (\d{2}):(\d{2})/gi;

    Number.prototype.pad = function (size) {
        var s = String(this);
        while (s.length < (size || 2)) {
            s = "0" + s;
        }
        return s;
    };

    function fromStr(v) {
        var chunks = v
            .split(pattern)
            .map(function (value) {
                return parseInt(value)
            });
        return new Date(chunks[1], chunks[2] - 1, chunks[3], chunks[4], chunks[5]);

    }

    function toStr(v) {
        return v.getFullYear().pad(4) + '-' +
            (v.getMonth() + 1).pad(2) + '-' +
            v.getDate().pad(2) + ' ' +
            v.getHours().pad(2) + ':' +
            v.getMinutes().pad(2);
    }

    return {
        value: date,


        add: function (value, type) {
            var real_value = fromStr(this.value);

            if (value < 0) throw TypeError();

            switch (type) {
                case 'years':
                    real_value.setFullYear(real_value.getFullYear() + value);
                    break;
                case 'months':
                    real_value.setMonth(real_value.getMonth() + value);
                    break;
                case 'days':
                    real_value.setDate(real_value.getDate() + value);
                    break;
                case 'hours':
                    real_value.setHours(real_value.getHours() + value);
                    break;
                case 'minutes':
                    real_value.setMinutes(real_value.getMinutes() + value);
                    break;
                default:
                    throw new TypeError();
            }

            this.value = toStr(real_value);

            return this;
        },
        subtract: function (value, type) {
            var real_value = fromStr(this.value);

            if (value < 0) throw TypeError();

            switch (type) {
                case 'years':
                    real_value.setFullYear(real_value.getFullYear() - value);
                    break;
                case 'months':
                    real_value.setMonth(real_value.getMonth() - value);
                    break;
                case 'days':
                    real_value.setDate(real_value.getDate() - value);
                    break;
                case 'hours':
                    real_value.setHours(real_value.getHours() - value);
                    break;
                case 'minutes':
                    real_value.setMinutes(real_value.getMinutes() - value);
                    break;
                default:
                    throw new TypeError();
            }

            this.value = toStr(real_value);

            return this;
        }
    };

};
